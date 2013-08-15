#include <stdlib.h>  
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// nao gera um processo zumbi
int main() {
     signal(SIGCLD,SIG_IGN) ;/* ignora o sinal SIGCLD */
     if (fork() != 0)
         while(1){} ;
     exit(0);
}
