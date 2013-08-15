#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main()
{
int pid ;
int fd ; /* descritor de arquivo associado ao arquivo agenda */
char *telephone ;
int r ; /* retorno de read */
int i ;   
char c ;
     printf("Oi, eu sou o processo %d\n",getpid()) ;
     printf("Por favor, envie-me o seu numero de telefone\n") ;
     printf("E o 123456789 ? Ok, ja anotei na minha agenda\n") ;
     if((fd=open("agenda",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU))==-1) 
     {
          perror("impossivel de abrir a agenda") ;
          exit(1) ;
     }
     telephone="123456789" ; 
     if(write(fd,telephone,9)==-1)
     {
          perror("impossivel de escrever na agenda") ;
          exit(1) ;
     }
     printf("Enfim, acabei de anotar e estou fechando a agenda\n") ;
     close(fd) ;
     printf("O que ? Eu me enganei ? O que foi que eu anotei ?\n") ;
     printf("\tO pai reabre sua agenda\n") ;
                  if((fd=open("agenda",O_RDONLY,S_IRWXU))==-1)      {
          perror("impossivel de abrir a agenda") ;
          exit(1) ;
     }
     printf("\tNesse instante, o pai gera um filho\n") ;
     pid=fork() ;
     if(pid==-1) /* erro */
     {
          perror("impossivel de criar um filho") ;
          exit(1) ;
     }
     else if(pid==0) /* filho */
     {
          sleep(1) ; /* o filho dorme para agrupar as mensagens */
          printf("\t\tOi, sou eu %d\n",getpid()) ;
          printf("\t\tVoces sabem, eu tambem sei ler\n") ;
          printf("\tO filho entao comeca a ler a agenda\n") ;
          for(i=1;i<=5;i++)  
          {
               if(read(fd,&c,1)==-1)
               {
                    perror("impossivel de ler a agenda") ;
                    exit(1) ;
               }
               printf("\t\tEu li um %c\n",c) ;
          }
          printf("\tMinha agenda ! Diz o pai\n") ;
          printf("\te supreso o filho fecha a agenda...\n") ;
          close(fd) ;
          sleep(3) ;
          printf("\tO filho entao se suicida de desgosto!\n") ;
          exit(0) ;
     }
     else /* pai */
     {
          printf("De fato, eu apresento a voces meu filho %d\n",pid) ;
          sleep(2) ; 
          printf("Oh Deus ! Eu nao tenho mais nada a fazer\n");
          printf("Ah-ha, mas eu ainda posso ler minha agenda\n") ;   
          while((r=read(fd,&c,1))!=0)
          {
                
               if(r==-1)
               {
                    perror("impossivel de ler a agenda") ;
                    exit(-1) ;
               }
               printf("%c",c) ;
          }
          printf("\n") ;
          printf("ENFIM ! Mas onde estao todos ?\n") ;
          sleep(3) ;
          close(fd) ;
     }
     exit(0);
}
/*
Resultado da Execução:

euler:~> test_fork1
Oi, eu sou o processo 28339
Por favor, envie-me o seu numero de telefone
E o 123456789 ? Ok, ja anotei na minha agenda
Enfim, acabei de anotar e estou fechando a agenda
O que ? Eu me enganei ? O que foi que eu anotei ?
        O pai reabre sua agenda
        Nesse instante, o pai gera um filho
                Oi, sou eu 28340
                Voces sabem, eu tambem sei ler
        O filho entao comeca a ler a agenda
                Eu li um 1
                Eu li um 2
                Eu li um 3
                Eu li um 4
                Eu li um 5
        Minha agenda ! Diz o pai
        e supreso o filho fecha a agenda...
        O filho entao se suicida de desgosto!
Oi, eu sou o processo 28339
Por favor, envie-me o seu numero de telefone
E o 123456789 ? Ok, ja anotei na minha agenda
Enfim, acabei de anotar e estou fechando a agenda
O que ? Eu me enganei ? O que foi que eu anotei ?
        O pai reabre sua agenda
        Nesse instante, o pai gera um filho
De fato, eu apresento a voces meu filho 28340
Oh Deus ! Eu nao tenho mais nada a fazer
Ah-ha, mas eu ainda posso ler minha agenda
6789
ENFIM ! Mas onde estao todos ?
*/
