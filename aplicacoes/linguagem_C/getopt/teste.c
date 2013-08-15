#include <unistd.h>
#include <stdio.h>

// executando :  ./main -a GPA_Promo 20081020 -f admin.xml 
// executando :  ./main -a GPA_Promo 20081020 -f admin.xml admin

int main(int argc, char *argv[] )
{
	int c;
	int index;

	printf ("Dentro do programa\n" ) ; 

	while ((c = getopt(argc, argv, ":a:bf:o:")) != -1) 
	{
		printf("Comparando\n") ;
		switch(c)
		{
		     case 'a':
			printf("Passado a \n") ; 
			printf ( "Argumento [%s] \n" , optarg  ) ;  break ;

		     case 'b':
			printf("Passado b \n") ; break;

		     case 'f':
			printf ( "Passado f [%s] \n" , optarg  ) ;  break ;

		}
	}

	printf ("Indice [%d]\n" , optind ); 

	for (index = optind; index < argc; index++)
	{
	    printf ("Argumento [%s]\n", argv[index]);
	}

}





