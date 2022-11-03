#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int signo);

int main( )
{
    int sec = 0;

    signal(SIGALRM,alarmHandler);
    alarm(5);  
    printf("infinite loop \n");
    while (1) {
        sleep(1);
        printf("%ds elapsed \n", ++sec);
    }
    printf("didn't reach here \n");
}

void alarmHandler(int signo)
{
    printf("Wake up!\n");
    exit(0);
}
