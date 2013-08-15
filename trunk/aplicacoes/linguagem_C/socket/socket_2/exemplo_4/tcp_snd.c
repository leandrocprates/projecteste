#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    struct sockaddr_in target;
    int sock=socket(AF_INET,SOCK_STREAM,0);
    int adl=sizeof(target);
    char linha[81];

    bzero((char *)&target,adl);
    target.sin_family=AF_INET;
    /* endereco IP de destino */
    target.sin_addr.s_addr=inet_addr("127.0.0.1"); /* host local */
    target.sin_port=htons(8450); /* porta de destino */

    if(-1==connect(sock,(struct sockaddr *)&target,adl))
    {
        puts("Connect Failed");
    }
    else
    {
        do
        {
            gets(linha);
            write(sock,linha,81);
        } while(strcmp(linha,"exit"));
    }

    close(sock);
    return 0 ;
}
