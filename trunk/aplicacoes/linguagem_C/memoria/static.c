
#include <stdio.h>

static int x  ; 

void teste ( int *x ) 
{
	printf ("Valor de x em teste [%d]\n" , *x  ) ; 

	*x=25;

}

void teste_3 ( int *x ) 
{
	printf ("Valor de x em teste_3 [%d]\n" , *x  ) ; 

	*x=32;
}

int main ()
{
	x = 90;
	teste (&x);

	teste_3(&x);

	printf ("Valor de x em main [%d]\n" , x ) ; 

	return 0 ;
}



