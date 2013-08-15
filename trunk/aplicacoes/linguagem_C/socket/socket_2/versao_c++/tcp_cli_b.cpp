#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



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
	b[i]=0; return(-1);
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
	if(write(s,aux,1)!=1) return(-1);
	return(len);
}


int main(int argc, char **argv)
{
	struct sockaddr_in target;
	int sock, adl=sizeof(target);
	char linha[81];
	char *eofString="\4\4\4\4";
	struct hostent *server;
	
	if(argc!=2) {puts("Target host missing from command line");exit(1);}
	sock=socket(AF_INET,SOCK_STREAM,0);
	bzero((char *)&target,adl);
	target.sin_family=AF_INET;
	/* endereco IP de destino */
	server=gethostbyname(argv[1]);
	if(!server) {printf("Unknown Host: %s\n",argv[1]);close(sock);exit(1);}
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
			fgets(linha,80,stdin);
			write_linha(sock,linha);
			if(!strcmp(linha,"sair\n")) 
			{
				close(sock);exit(0);
			}
			else
			{
				read_linha(sock,linha,81);
				while(strcmp(linha,eofString))
				{
					puts(linha);
					read_linha(sock,linha,81);
				}
			}
		}
	}

	return(0);
}
