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
	struct sockaddr_in me, server;
	int sock=socket(AF_INET,SOCK_DGRAM,0);
	int adl=sizeof(me), value=1;
	char linha[81];
	
	setsockopt(sock,SOL_SOCKET,SO_BROADCAST,&value,sizeof(value));
	bzero((char *)&me,adl);
	me.sin_family=AF_INET;
	me.sin_addr.s_addr=htonl(INADDR_ANY); /* endereco IP local */
	me.sin_port=htons(0); /* porta local (0=auto assign) */
	bind(sock,(struct sockaddr *)&me,adl);
	bzero((char *)&server,adl);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.255.255.255"); /* broadcast */
	/* no caso mais corrente (rede de classe C pode usar o endereco 255.255.255.255 */
	server.sin_port=htons(8450); /* porta do servidor */
	
	do
	{
		gets(linha);
		sendto(sock,linha,81,0,(struct sockaddr *)&server,adl);
		recvfrom(sock,linha,81,0,(struct sockaddr *)&server,&adl);
		puts(linha);
	}
	while(strcmp(linha,"EXIT"));
	
	close(sock);

}




