#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <termios.h>

#define GPIO_BASE 0xFE200000
#define GPIO_SIZE 256

#define GPIO_IN(g) (*(gpio+((g)/10)) &= ~(7<<(((g)%10)*3)))
#define GPIO_OUT(g) (*(gpio+((g)/10)) |= (1<<(((g)%10)*3)))

#define GPIO_SET(g) (*(gpio+7) = 1<<g)
#define GPIO_CLR(g) (*(gpio+10) = 1<<g)
#define GPIO_GET(g) (*(gpio+13)&(1<<g))

volatile unsigned *gpio;

#define PI 3.14

int main(int argc, char **argv)
{
    int mem_fd;
	int g_sw;
    int status;
	void* gpio_map;

	g_sw = 23;

 	if((mem_fd = open("/dev/mem", O_RDWR | O_SYNC) ) < 0)
	{
		perror("open() /dev/mem\n");
		return -1;
	}

 	gpio_map = mmap(NULL, GPIO_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, GPIO_BASE);
	if(gpio_map == MAP_FAILED)
	{
		printf("[Error] mmap() : %d\n", (int)gpio_map);
		return -1;
	}

	gpio = (volatile unsigned*)gpio_map;

 	GPIO_IN(g_sw);

	int buffer[64] = {0, };
    int buf_size = 64;

	//shared memory
    int shmid;
    key_t key;
    void *shmaddr;

    key = ftok("day4_shm",1);
    shmid = shmget(key, 1024, IPC_CREAT|0644);
    if(shmid == -1)
    {
        perror("shmget failed");
        exit(1);
    }
    if((shmaddr = shmat(shmid, NULL, 0)) == (void*)-1)
    {
        perror("shmat failed");
        exit(1);        
    }

    //pipe
    int fd[2];
    pipe(fd);

    //uart
    int uart0_filestream = -1;

    uart0_filestream = open("/dev/ttyAMA1", O_RDWR | O_NOCTTY | O_NDELAY);
    if (uart0_filestream == -1) 
    {
        printf("Error - Unable to open UART. Ensure it is not in use by another application\n"); 
    }

    struct termios options; 
    tcgetattr(uart0_filestream, &options); 
    options.c_cflag = B19200 | CS8 | CLOCAL | CREAD; //<Set baud rate 
    options.c_iflag = IGNPAR; 
    options.c_oflag = 0; 
    options.c_lflag = 0; 
    tcflush(uart0_filestream, TCIFLUSH); 
    tcsetattr(uart0_filestream, TCSANOW,&options);


	int pid1 = 0; //data input
	int pid2 = 0; //data process(shared memory)
    int pid3 = 0; //pipe

	int pnum = 1;

	pid2 = fork();
	if(pid2==0)
	{
		pnum = 2;
		pid1 = getppid();
		pid3 = fork();
	} 
	if(pid1!=0 && pid3==0)
	{
		pnum = 3;
		pid2 = getppid();
	}
    
    if(pnum==1)
    {
        while(1)
        {
            if(GPIO_GET(g_sw)>0)
            {
                for(int i=0;i<buf_size;i++)
                {
                    buffer[i] = (int)((sin(i*12*PI/180)+1)*32) + rand()%8;
                }
                memcpy((int*)shmaddr,buffer,sizeof(buffer));
            }
            usleep(200*1000);
        }
        shmctl( shmid, IPC_RMID, 0);
    }
    else if(pnum==2)
    {
        int shm_buf[128] = {0, };
		int win_size = 5;
		int window = 0;
        int err_rate_b = 0;
        int err_rate_a = 0;

        close(fd[0]);

        while(1)
        {
            memcpy(shm_buf,(int*)shmaddr,sizeof(buffer));
            err_rate_b = 0;
            err_rate_a = 0;
            for(int i=0;i<buf_size;i++)
            {
                if(i>=(win_size/2) && i<buf_size-(win_size/2))
                {
                    window = 0;
                    err_rate_b += abs((shm_buf[i+64]-(int)((sin(i*12*PI/180)+1)*32)));
                    for(int j=0;j<win_size;j++)
                    {
                        window += shm_buf[i-(win_size/2)+j];
                    }
                    shm_buf[i+64] = window/win_size;
                }
                else
                {
                    shm_buf[i+64] = shm_buf[i];
                }
                err_rate_a += abs((shm_buf[i+64]-(int)((sin(i*12*PI/180)+1)*32)));
            }
            write(fd[1],shm_buf,sizeof(shm_buf));
            printf("\nError level | before : %d  after : %d\n",err_rate_b,err_rate_a);
            sleep(1);
        }
    }
    else if(pnum==3)
    {
        int pipe_buf[128] = {0,};
        unsigned char tx_buf[256];
        close(fd[1]);
        while(1)
        {
            strcpy(tx_buf,"\0");   
            read(fd[0],pipe_buf,sizeof(pipe_buf));
            for(int i=0;i<buf_size;i++)
            {
                sprintf(tx_buf,"%d %d\n",pipe_buf[i], pipe_buf[i+64]);
                write(uart0_filestream, &tx_buf[0], strlen(tx_buf));
            }
            sprintf(tx_buf,"\n");
            write(uart0_filestream, &tx_buf[0], strlen(tx_buf));
        }
    }
	return 0;
}