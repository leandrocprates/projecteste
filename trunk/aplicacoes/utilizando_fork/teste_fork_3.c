#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

// O processo pai recebe o pid do processo filho que ele gerou , 
// O processo filho recebe zero 

int main()
{
       int pid;
       printf("Processo progenitor pid=%d\n", getpid());
       printf("Bifurcando o processo\n" );
       pid=fork();
       /* As instruções que seguem são executadas duas vezes:
          uma vez para o progenitor, outra vez para o progénito*/
       printf( "O processo progenitor id %d e o seu progenito %d\n", getpid(), pid);
       system("date");
}

/*

Resultado da Execução:

Processo progenitor pid=6997
Bifurcando o processo
O processo progenitor id 6998 e o seu progenito 0    // processo filho
Qui Fev 19 22:44:09 BRT 2009
O processo progenitor id 6997 e o seu progenito 6998 // processo pai
Qui Fev 19 22:44:09 BRT 2009

*/
