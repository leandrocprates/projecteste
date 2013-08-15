
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char *palavra=NULL;

	palavra=malloc (25);

	strcpy(palavra , "ola este e um teste");

	printf ( "Resultado: [%s]\n" , palavra );

	free (palavra);

	return 0 ; 
}


