#include <sys/types.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>

void main(int argc, char **argv)
{
    struct sockaddr_in me, server;
    int sock=socket(AF_INET,SOCK_DGRAM,0);
    int adl=sizeof(me);
    int try, retrys=5, timeout=1, ok, ready;
    char linha[81];
    struct timeval tt;
    fd_set fds;

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
    server.sin_addr.s_addr=inet_addr(argv[1]); 
    server.sin_port=htons(8450); /* porta do servidor */

    do
    {
        gets(linha);
        try=retrys;ok=0;

        while(try && !ok)
        {
            sendto(sock,linha,81,0,(struct sockaddr *)&server,adl);
            FD_ZERO(&fds);FD_SET(sock,&fds);
            tt.tv_sec=timeout;tt.tv_usec=0;
            ready=select(sock+1,&fds,0,0,&tt);
            if(ready<0)
            {
                perror("Select");
            }
            else
            {
                if(ready && FD_ISSET(sock,&fds))
                {
                    if(recvfrom(sock,linha,81, 0,(struct sockaddr *)&server,&adl)!=-1)
                    {
                        ok=1;
                    }
                }
                try--;
            }
        }

        if(ok) 
        {
           puts(linha);
        }
        else
        {
            puts("No reply from server");
        }
        
    } while(strcmp(linha,"EXIT"));

    close(sock);

}
