#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    struct sockaddr_in me, server;
    int sock=socket(AF_INET,SOCK_DGRAM,0);
    int adl=sizeof(me);
    char linha[81];

    if(argc!=2)
    {
        close(sock);
        puts("Utilizar o end. IP do servidor na linha de comando");
        exit(1);
    }

    bzero((char *)&me,adl);

    me.sin_family=AF_INET;
    me.sin_addr.s_addr=htonl(INADDR_ANY); /* endereco IP local */
    me.sin_port=htons(0); /* porta local (0=auto assign) */

    bind(sock,(struct sockaddr *)&me,adl);
    bzero((char *)&server,adl);

    server.sin_family=AF_INET;
    /* endereco IP de destino */
    server.sin_addr.s_addr=inet_addr(argv[1]); /* host local */
    server.sin_port=htons(8450); /* porta do servidor */

    do
    {
        gets(linha);
        sendto(sock,linha,81,0,(struct sockaddr *)&server,adl);
        recvfrom(sock,linha,81,0,(struct sockaddr *)&server,&adl);
        puts(linha);
        
    } while(strcmp(linha,"EXIT"));
    
    close(sock);
    return 0 ; 
}

