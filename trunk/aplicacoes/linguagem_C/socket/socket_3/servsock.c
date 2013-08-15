/*****************************************************
Programa para testar comunicação usando sockets (posix)
servidor
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
#include <arpa/inet.h>

#define PORT 5555
#define MAXMSG 512

/* Rotina geral de tratamento de erro fatal
   escreve a mensagem e termina o programa */
void erro_fatal(char *mensagem)
{
perror(mensagem);
exit(EXIT_FAILURE);
}

/*Função cria socket para o servidor*/
int cria_soquete_serv(int porta)
{
int sock, b;
struct sockaddr_in nome;
/* Cria um soquete */
sock=socket(PF_INET, SOCK_STREAM, 0);
if(sock < 0) erro_fatal("socket");
nome.sin_family=AF_INET;
nome.sin_port=htons(porta);
nome.sin_addr.s_addr=htonl(INADDR_ANY);
/* bind: Liga um socket a uma porta de servico */
b=bind(sock, (struct sockaddr *)&nome, sizeof(nome));
if(b<0) erro_fatal("bind");
/* Libera para atender conexoes na porta */
if(listen(sock,1)<0)  erro_fatal("socket");
return sock;
}

int recebe_do_cliente(int filedes)
{
char buffer[MAXMSG];
int nbytes;
nbytes = read(filedes, buffer, MAXMSG-1);
if(nbytes<0) erro_fatal("read");
if(nbytes==0) return -1;
printf("Recebi a seguinte mensagem:\n%s\n", buffer);
return nbytes;
}

int envia_pro_cliente(int filedes, char *msg)
{
int nbytes;
nbytes=write(filedes, msg, strlen(msg)+1);
if(nbytes<0) erro_fatal("write");
return nbytes;
}

int main()
{
int sock, fd_sock, i;
struct sockaddr_in clientname;
fd_set ativo_fd_set, le_fd_set;
size_t size;

sock=cria_soquete_serv(PORT);
printf("Socket inicial: handle=%d\n",sock);
FD_ZERO(&ativo_fd_set);
FD_SET(sock, &ativo_fd_set);
do{
  le_fd_set=ativo_fd_set;
  i=select(FD_SETSIZE, &le_fd_set, NULL, NULL, NULL); 
  if(i<0) erro_fatal("select");
  for(i=3; i<FD_SETSIZE; i++)
    {
    if(!FD_ISSET(i, &le_fd_set)) continue;
    if(i==sock)
      {
      size=sizeof(clientname);
      fd_sock=accept(sock, (struct sockaddr *)&clientname, &size);
      if(fd_sock < 0) erro_fatal("accept");
      fprintf(stderr, "Servidor: aceitei conexão do host \"%s\", handle=%d\n",
		inet_ntoa(clientname.sin_addr), fd_sock);
      FD_SET(fd_sock, &ativo_fd_set);
      continue;
      }
    if(recebe_do_cliente(i)<0)
      {
      close(i);
      FD_CLR(i, &ativo_fd_set);
      }
    else envia_pro_cliente(i, "Funciona sim!!!");
    }	/* for */
  }while(1);
}
