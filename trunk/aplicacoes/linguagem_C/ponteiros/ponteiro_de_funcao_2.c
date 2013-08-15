
#include <stdio.h>
#include <stdlib.h>

int soma ( int x , int z ) 
{
   return (x+z);
}

int main ()
{
	int valor=0;
	int (*handler) (int , int );
	handler=soma; 

	valor=(*handler) (10,10);

	printf("Valor retornado [%d]\n" , valor);
	return 0;

}




