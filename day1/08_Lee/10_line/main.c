#include <stdio.h>
#define MAXLINE 80
 
int main(int argc, char *argv[])
{
    FILE *fp;
    int line = 0;
    char           ;

    if (argc != 2) {
        fprintf(stderr, "Usage:main filename\n");
        return 1;
    }
 
    if (                     == NULL) {
        fprintf(stderr, "file read error\n");
        return 2;
    }

    while (                        ) {  
        line++;
        printf("%3d %s", line, buffer);
    }
    return 0;
 }
