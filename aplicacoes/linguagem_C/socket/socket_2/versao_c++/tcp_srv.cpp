
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	struct sockaddr_in me, from;
	int newSock,sock=socket(AF_INET,SOCK_STREAM,0);
	int adl=sizeof(me); 
	char dataSize;
	int res;
	char linha[81];
	char *fileNotFound="File Not Found";
	FILE *f;
	
	bzero((char *)&me,adl);
	me.sin_family=AF_INET;
	me.sin_addr.s_addr=htonl(INADDR_ANY);
	me.sin_port=htons(8450); /* porta local  */
	if(-1==bind(sock,(struct sockaddr *)&me,adl))
		{close(sock);puts("Porta de servidor ocupada...");exit(1);}
	
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
					read(newSock,&dataSize,1);
					if(!dataSize) {puts("Child Server done.");close(newSock);exit(0);}
					read(newSock,linha,dataSize);
					f=fopen(linha,"r");
					if(!f)
					{
						dataSize=strlen(fileNotFound)+1;
						write(newSock,&dataSize,1);
						write(newSock,fileNotFound,dataSize);
					}
					else
					{
						while(fgets(linha,81,f))
						{
							dataSize=strlen(linha);linha[dataSize-1]=0;
							write(newSock,&dataSize,1);
							write(newSock,linha,dataSize);
						}
						close(f);
					}		
					dataSize=0;
					write(newSock,&dataSize,1);
				}
			}
		}
	}
}



