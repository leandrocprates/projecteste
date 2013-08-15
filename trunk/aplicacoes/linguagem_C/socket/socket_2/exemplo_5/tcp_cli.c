#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    struct sockaddr_in target;
    int sock, adl=sizeof(target);
    char dataSize, linha[81];
    struct hostent *server;

    if(argc!=2)
    {
        puts("Target host missing from command line");
        exit(1);
    }

    sock=socket(AF_INET,SOCK_STREAM,0);
    bzero((char *)&target,adl);
    target.sin_family=AF_INET;
    /* endereco IP de destino */
    server=gethostbyname(argv[1]);
    
    if(!server)
    {
        printf("Unknown Host: %s\n",argv[1]);
        close(sock);
        exit(1);
    }

    target.sin_addr=*(struct in_addr *) *server->h_addr_list;
    target.sin_port=htons(8450); /* porta de destino */

    if(-1==connect(sock,(struct sockaddr *)&target,adl))
    {
        puts("Connect Failed");
    }
    else
    {
        for(;;)
        {
            printf("\n\nFileName:");
            gets(linha);
            if(!strcmp(linha,"sair"))
            {
                dataSize=0;
                write(sock,&dataSize,1);
                close(sock);
                exit(0);
            }
            else
            {
                dataSize=strlen(linha)+1;
                write(sock,&dataSize,1);
                write(sock,linha,dataSize);
                read(sock,&dataSize,1);

                while(dataSize)
                {
                    read(sock,linha,dataSize);
                    puts(linha);
                    read(sock,&dataSize,1);
                }
            }
        }
    }
    
    return 0 ;
}
