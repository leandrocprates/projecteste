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
	struct sockaddr_in me, target;
	int sock=socket(AF_INET,SOCK_DGRAM,0);
	char linha[81];
	bzero((char *)&me,sizeof(me));
	me.sin_family=AF_INET;
	me.sin_addr.s_addr=htonl(INADDR_ANY); /* endereco IP local */
	me.sin_port=htons(0); /* porta local (0=auto assign) */
	bind(sock,(struct sockaddr *)&me,sizeof(me));
	bzero((char *)&target,sizeof(target));
	target.sin_family=AF_INET;
	/* endereco IP de destino */
	target.sin_addr.s_addr=inet_addr("127.0.0.1"); /* host local */
	target.sin_port=htons(8450); /* porta de destino */

	do
	{
		gets(linha);
		sendto(sock,linha,81,0,(struct sockaddr *)&target,
		sizeof(target));
	}
	while(strcmp(linha,"exit"));

	close(sock);
}
