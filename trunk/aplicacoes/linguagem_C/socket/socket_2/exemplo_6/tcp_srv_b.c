#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*
Leitura de caracteres do descritor "s" para o vector "b"
at� ao "\n" (newline) ou at� ai m�ximo de "m" caracteres.
Devolve o n�mero de caracteres lidos ou "-1" se passar o
m�ximo "m", ou em caso de falha de liga��o
*/

int read_linha(int s, char *b, int m)
{
    int i;

    for(i=0;i<m;i++)
    {
        /* ler um caractere */
        if(read(s,&b[i],1)!=1) return(-1);
        /* fim da linha */
        if(b[i]=='\n') {b[i]=0; return(i);}
        /* ignorar o \r do DOS-WINDOWS */
        if(b[i]=='\r') i--;
    }
    
    b[i]=0;
    return(-1);
}

/*
Escrita de uma linha no descritor "s" seguida
de "\n" (newline), em caso de erro devolve "-1"
*/

int write_linha(int s, char *b)
{
    char *aux="\n";
    int len=strlen(b);
    if(write(s,b,len)!=len) return(-1);
    if(b[len-1]=='\n') return(len); /* j� tinha \n */
    if(write(s,aux,1)!=1)
        return(-1);
    
    return(len);
}


int main(void)
{
    struct sockaddr_in me, from;
    int newSock,sock=socket(AF_INET,SOCK_STREAM,0);
    unsigned int adl=sizeof(me);
    int res;
    char linha[81];
    char *fileNotFound="File Not Found";
    char *eofString="\4\4\4\4";
    FILE *f;

    bzero((char *)&me,adl);
    me.sin_family=AF_INET;
    me.sin_addr.s_addr=htonl(INADDR_ANY);
    me.sin_port=htons(8450); /* porta local  */

    if(-1==bind(sock,(struct sockaddr *)&me,adl))
    {
        close(sock);
        puts("Porta de servidor ocupada...");
        exit(1);
    }

    listen(sock,5);

    for(;;)
    {
        newSock=accept(sock,(struct sockaddr *)&from,&adl);
        if(newSock!=-1) /* importante verificar */
        {
            res=fork();
            if(res)
            {
                if(res== -1) puts("Fork Failed...");
                else printf("New Child Server Process, PID=%i\n",res);
                /* Processo PAI continua a receber novas conexoes */
                close(newSock);
            }
            else
            {
                /* Processo FILHO serve o cliente */
                close(sock);
                for(;;)
                {
                    read_linha(newSock,linha,81);
                    if (!strcmp(linha,"sair"))
                    {
                        puts("Child Server done.");
                        close(newSock);
                        exit(0);
                    }
                    
                    f=fopen(linha,"r");
                    
                    if(!f)
                    {
                        write_linha(newSock,fileNotFound);
                        write_linha(newSock,eofString);
                    }
                    else
                    {
                        while(fgets(linha,81,f))
                        {
                            write_linha(newSock,linha);
                        }
                        fclose(f);
                        write_linha(newSock,eofString);
                    }
                }
            }
        }
    }
}
