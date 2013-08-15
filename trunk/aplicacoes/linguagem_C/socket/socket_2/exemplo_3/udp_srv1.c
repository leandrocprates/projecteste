#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    struct sockaddr_in me, client;
    int sock=socket(AF_INET,SOCK_DGRAM,0);
    int adl=sizeof(me);
    char linha[81], *aux;
    
    bzero((char *)&me,adl);
    me.sin_family=AF_INET;
    me.sin_addr.s_addr=htonl(INADDR_ANY); /* endereco IP local */
    me.sin_port=htons(8450); /* porta local  */
    
    if(-1!=bind(sock,(struct sockaddr *)&me,adl))
    {
        do
        {
            recvfrom(sock,linha,81,0,(struct sockaddr *)&client,&adl);
            puts("-----------\nRequest from:");
            printf("Port:%i Address:%s\n",ntohs(client.sin_port),inet_ntoa(client.sin_addr));

            aux=linha;
            while(*aux)
            {
                *aux=toupper(*aux);
                aux++;
            }

            sendto(sock,linha,81,0,(struct sockaddr *)&client,adl);

        } while(strcmp(linha,"EXIT"));
    }
    else
    {
        puts("Porta ocupada");
    }

    close(sock);
    return 0 ; 
}

