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
/* Preenche os campos da estrutura tipo struct sockaddr_in */
nome.sin_family=AF_INET;	/* Selecona protocolo IPv4 */
nome.sin_port=htons(porta);	/* Numero da porta de serviço	*/
nome.sin_addr.s_addr=htonl(INADDR_ANY);	/* Aceita conexões vindas de qualquer IP */
/* bind: Liga um socket a uma porta de servico */
b=bind(sock, (struct sockaddr *)&nome, sizeof(nome));
if(b<0) erro_fatal("bind");
/* Libera para atender conexoes na porta */
/* listen(int socket, int tamanho_da_fila); */
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

/* Versão monocliente */
int main()
{
int sock, fd_sock;
struct sockaddr_in clientname;
size_t size;
/* Cria um socket para receber o contato inicial com um cliente */
sock=cria_soquete_serv(PORT);
printf("Socket inicial: handle=%d\n",sock);
size=sizeof(clientname);
/* Aceita a conexao e cria um socket para comunicar-se com este cliente */
fd_sock=accept(sock, (struct sockaddr *)&clientname, &size);
if(fd_sock < 0) erro_fatal("accept");
fprintf(stderr, "Servidor: aceitei conexão do host \"%s\", handle=%d\n",
		inet_ntoa(clientname.sin_addr), fd_sock);
/* Comunica-se com o cliente usando o socket gerado pelo accept */
while(recebe_do_cliente(fd_sock)>=0)
	envia_pro_cliente(fd_sock, "Funciona sim!!!");
close(fd_sock);
return 0;
}
