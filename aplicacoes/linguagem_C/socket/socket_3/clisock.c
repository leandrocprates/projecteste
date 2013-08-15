/*****************************************************
Programa para testar comunica��o usando sockets (posix)
cliente
baseado no exemplo do livro
The GNU C Library Reference Manual
modificado por
Marcos A. Stemmer
*****************************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#define MAXMSG 512

/* Rotina geral de tratamento de erro fatal
   escreve a mensagem e termina o programa */
void erro_fatal(char *mensagem)
{
printf("%s:%s\n",mensagem,strerror(errno));
exit(EXIT_FAILURE);
}

/* Cria um soquete e estabelece a conex�o */
int cria_soquete(const char *hostname, int port)
{
int sock;
struct hostent *hostinfo;
struct sockaddr_in sockinfo;
char buf[256];
sock=socket(PF_INET, SOCK_STREAM, 0);
if(sock < 0) erro_fatal("socket");
sockinfo.sin_family=AF_INET;
/* Configura a porta de servi�o do socket */
/* A fun��o htons converte n�meros do host para o formato padr�o da internet */
sockinfo.sin_port=htons(port);
/* Pede informa��es a partir do nome do host */
hostinfo=gethostbyname(hostname);
if(hostinfo==NULL)
  {
  sprintf(buf, "Unknown host: \"%s\"", hostname);
  erro_fatal(buf);
  }
/* Coloca o IP do host no sin_addr */
sockinfo.sin_addr= *(struct in_addr *)hostinfo->h_addr;
/* conecta com o host */
if(connect(sock, (struct sockaddr *)&sockinfo, sizeof(sockinfo)) < 0)
  erro_fatal("Connect (client)");
return sock;
}

/* Espera pela chegada de dados no soquete */
/* Retorna 0 em caso de timeout */
int espera(int sock, int tempo)
{
struct timeval timeout;
fd_set sock_fd_set;
int r;
timeout.tv_sec=tempo;
timeout.tv_usec=0;
FD_ZERO(&sock_fd_set);
FD_SET(sock,&sock_fd_set);
r=select(FD_SETSIZE, &sock_fd_set, NULL, NULL, tempo>0? &timeout: NULL);
if(r<0)	erro_fatal("select");
return r;
}

/* Escreve uma mensagem no soquete */
int escreve_soq(int sock, char *mensagem)
{
int n;
n = write(sock, mensagem, strlen(mensagem)+1);
if(n < 0) erro_fatal("write");
return n;
}

/*
Programa principal:
recebe o nome do host na linha de comando
envia uma mensagem e espera receber uma resposta
*/
int main(int argc, char **argv)
{
int soq, nbytes;
char *hostname;
char buf[MAXMSG];
/* O nome do host vem da linha de comando ou � "localhost" */
hostname = argc > 1? argv[1]: "localhost";
/* Cria o soquete com o nome do host e o numero da porta */
soq = cria_soquete(hostname, 5555);
/* Envia uma mensagem pro soquete */
escreve_soq(soq, "Ser� que funciona?");
/* Espera pela resposta */
if(espera(soq,5)==0) erro_fatal("Ninguem responde");
/* Le a resposta */
nbytes = read(soq, buf, MAXMSG);
if(nbytes<0) erro_fatal("read");
/* Escreve na sa�da padr�o qual foi a resposta recebida */
printf("\nRecebi a seguinte resposta do servidor:\n%s\n", buf);
return 0;
}
