#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>

void  p1();
void intHandler();
jmp_buf env;

int main() 
{
    signal(SIGINT, intHandler);

    if (setjmp(env) != 0) {
	    printf("go back here by interrupt\n");
	    exit(0);
    }
    else printf("\n");

    p1(); 
} 

void  p1()
{ 
    while (1) {
        printf("loop\n");
        sleep(1);
    }
}

void intHandler() 
{
    printf("Interrupt happens\n");
    longjmp(env, 1);
}
