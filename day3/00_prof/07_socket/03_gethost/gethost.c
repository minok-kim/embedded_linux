#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main (int argc, char* argv[]) 
{
    char *host;
    struct hostent *hp;

    if (argc != 2) {
        fprintf(stderr, "Usage : %s <host>\n", argv[0]);
        exit(0);
    }

    host = argv[1];
    if ((hp = gethostbyname(host)) == NULL)
        perror("gethostbyname error");   

    printf("%s -> %s\n", host, inet_ntoa(*(struct in_addr*) hp->h_addr_list[0]));
}

