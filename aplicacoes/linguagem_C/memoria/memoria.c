/*
 * Imprime uma mensagem quando um SIGSEGV é recebido
 * e restabelece o tratador padrão.
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void trata_SIGSEGV(int signum) {
   printf("Acesso indevido `a memoria.\n"); 
   printf("Nao vou esconder este erro do meu pai. :-)\n"); 
   signal(SIGSEGV, SIG_DFL); 
   raise(SIGSEGV); 

}
 
int main() {
  int *px = (int*) 0x01010101;
  signal(SIGSEGV, trata_SIGSEGV); 

  *px = 0;
  
  return 0;
}

