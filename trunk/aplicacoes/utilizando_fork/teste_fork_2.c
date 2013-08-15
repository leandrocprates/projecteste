
/* Testa as reacoes do console quando um pai 
 * morre e o filho continua vivo */

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
int pid ;
   printf("Eu sou o pai %d e eu vou criar um filho \n",getpid()) ;
   pid=fork() ; /* criacao do filho */
   if(pid==-1) /* erro */
   {
      perror("impossivel de criar um filho\n") ;
   }    
   else if(pid==0) /* acoes do filho */
   {
      printf("\tOi, eu sou o processo %d, o filho\n",getpid()) ;
      printf("\tO dia esta otimo hoje, nao acha?\n") ;
      printf("\tBom, desse jeito vou acabar me instalando para sempre\n");
      printf("\tOu melhor, assim espero!\n") ;
      for(;;) ; /* o filho se bloqueia num loop infinito */
   }
   else /* acoes do pai */
   {
       sleep(1) ; /* para separar bem as saidas do pai e do filho */
       printf("As luzes comecaram a se apagar para mim, %d\n",getpid()) ;
       printf("Minha hora chegou : adeus, %d, meu filho\n",pid) ;
       /* e o pai morre de causas naturais */ 
    }
    return(0);
}

/*
Resultado da Execução:

euler:~> test_fork2
Eu sou o pai 28637 e eu vou criar um filho 
        Oi, eu sou o processo 28638, o filho
        O dia esta otimo hoje, nao acha?
        Bom, desse jeito vou acabar me instalando para sempre
        Ou melhor, assim espero!
As luzes comecaram a se apagar para mim, 28637
Minha hora chegou : adeus, 28638, meu filho
*/

