#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#define DEFAULT_PROTOCOL 0
#define MAXLINE 100

int readLine(int fd, char* str);
void toUpper(char* in, char* out);

int main ()
{
    int listenfd, connfd, clientlen;
    char inmsg[MAXLINE], outmsg[MAXLINE];
    struct sockaddr_un serverAddr, clientAddr;

    signal(SIGCHLD, SIG_IGN);
    clientlen = sizeof(clientAddr);

    listenfd = socket(AF_UNIX, SOCK_STREAM, DEFAULT_PROTOCOL);
    serverAddr.sun_family = AF_UNIX;
    strcpy(serverAddr.sun_path, "convert");
    unlink("convert");
    bind(listenfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    listen(listenfd, 5);

    while (1) {  
        connfd = accept(listenfd, (struct sockaddr *) &clientAddr, &clientlen);
        if (fork ( ) == 0) {  
            readLine(connfd, inmsg);
            toUpper(inmsg, outmsg);
            write(connfd, outmsg, strlen(outmsg)+1);
            close(connfd);
            exit (0);
        } else close(connfd);
    }
}

void toUpper(char* in, char* out)  
{
    int i;
    for (i = 0; i < strlen(in); i++)
        if (islower(in[i]))
            out[i] = toupper(in[i]);
        else out[i] = in[i];
    out[i] = '\0';
}

int readLine(int fd, char* str)
{
    int n;
    do {
        n = read(fd, str, 1);
    } while(n > 0 && *str++ != '\0');
    return(n > 0);
}
