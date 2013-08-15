#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    struct sockaddr_in me, from;
    int newSock,sock=socket(AF_INET,SOCK_STREAM,0);
    int adl=sizeof(me);
    char linha[81];

    bzero((char *)&me,adl);
    me.sin_family=AF_INET;
    me.sin_addr.s_addr=htonl(INADDR_ANY); /* endereco IP local */
    me.sin_port=htons(8450); /* porta local  */

    if(-1==bind(sock,(struct sockaddr *)&me,adl))
    {
        close(sock);
        puts("Porta ocupada");
        exit(1);
    }

    listen(sock,5);

    newSock=accept(sock,(struct sockaddr *)&from,&adl);

    close(sock);
    
    do
    {
        read(newSock,linha,81);
        puts(linha);
    } while(strcmp(linha,"exit"));
    
    close(newSock);
    return 0 ; 
}
