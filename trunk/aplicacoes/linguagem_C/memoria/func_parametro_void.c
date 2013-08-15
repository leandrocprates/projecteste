
#include <stdio.h>

int altera(void *x)
{
  int *z= (int * ) x ;  // convertendo o ponteiro void para um ponteiro inteiro
  int r = *((int * )x) ; // desreferenciando o ponteiro e pegando o valor

  printf ( "Valor [%d] \n" , *z );
  printf ( "Valor [%d] \n" , r );

  *z = 39; // alterando o valor do parametro void *x

  return *( (int *)x ); // retornando o valor alterado

}

int main ()
{
   int valor = 15 ; 
   int retorno = 0;	

   retorno = altera( (void * ) &valor);

   printf ( "Valor retornado [%d] \n" , retorno );
   printf ( "Valor novo [%d] \n" , valor );

   return 0 ; 
}


