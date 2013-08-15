
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int  main(void)
{
    struct sockaddr_in me, from;
    int sock=socket(AF_INET,SOCK_DGRAM,0);
    int adl=sizeof(me);
    char linha[81];

    bzero((char *)&me,sizeof(me));
    
    me.sin_family=AF_INET;
    me.sin_addr.s_addr=htonl(INADDR_ANY); /* endereco IP local */
    me.sin_port=htons(8450); /* porta local  */

    if(-1!=bind(sock,(struct sockaddr *)&me,sizeof(me)))
    {

        do
        {
            recvfrom(sock,linha,81,0,(struct sockaddr *)&from,&adl);
            printf("Conteudo Recebido [%s].\n" , linha );
            printf("Porta de Quem Enviou : [%i]\n" , ntohs(from.sin_port) ) ;
            printf("Endereco : [%s]\n" , inet_ntoa(from.sin_addr ) );
            
        }  while(strcmp(linha,"exit"));
    }
    else
    {
        puts("Porta ocupada");
    }

    close(sock);
    return 0 ;
}
