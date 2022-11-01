 #include <sys/types.h>
 #include <sys/wait.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <signal.h>

void intHandler(int signo)
{
    printf("Interrupt Signal Handler\n");
    printf("Signal number: %d\n", signo);
    exit(0);
} 

int main(int argc, char *argv[])
{  
    int child, pid, status;

    signal(SIGINT, SIG_IGN);
    pid = fork( );
    if (pid == 0) {   
        execvp(argv[1], &argv[1]);
	      fprintf(stderr, "%s:실행 불가\n",argv[1]);
    } else {           
        child = wait(&status);
        signal(SIGINT, intHandler);
        printf("[%d] Child process %d end \n", getpid(), pid);
        printf("\ttermination code %d \n", status>>8);
    }
}
