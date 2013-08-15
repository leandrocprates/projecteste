/* 
 * File:   principal.c
 * Author: leandro
 *
 * Created on 10 de Janeiro de 2009, 13:16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

void altera_mensagem(char aux_2[] , char aux_3[] )
{
 char vet_1[512];
 char vet_2[512];
 int t = 0 ;
 int i = 0;

 char str[512] ;
 char *pch;

 memset ( vet_1 , '\0' , sizeof( vet_1 ) );
 memset ( vet_2 , '\0' , sizeof( vet_2 ) );

 strcpy( str , aux_2 );

 printf ("Buscando caracters '+' em \"%s\"...\n",str);
 pch=strchr(str,'+');

 while (pch!=NULL)
 {
   printf ("found at %d\n",pch-str+1);
   i = pch-str ;

   printf ("i [%d] \n" ,  (i+1)-t );
   printf ("t [%d] \n" ,   t );

   strncpy(vet_1 , &str[t] , (i)-t );
   vet_1[i-t]='\0' ;
   printf ("vet_1 [%s] \n" ,  vet_1 );

// aqui esta certo
   strcat(vet_2 , vet_1);
   strcat(vet_2 , "%2b");
   vet_2[ strlen(vet_2) ] = '\0' ;

   printf ("vet_2 [%s] \n" ,  vet_2 );

//break;

   t = i+1;
   pch=strchr(pch+1,'+');
   i = pch-str-1 ;

 }

  strcat(vet_2 , &str[t]);
  printf ("vet_2 [%s] \n" ,  vet_2 );

  strcpy(aux_3 , vet_2);

  return ;

}


static void format_post_data ()
{
   char aux[255];
   char aux_2[512];
   char aux_3[512];
   char url[255];

   memset (aux_2,0, sizeof (aux_2));
   memset (aux_3,0, sizeof (aux_3));
   memset (url,0, sizeof (url));

   sprintf (url, "http:+~") ;
   

   // aqui colocar %2b no lugar do +

   strcpy(aux_2 ,url ); // copia mensagem para troca

   altera_mensagem(aux_2 , aux_3 ); // troca a mensagem

   // volta a mensagem trocada

   printf("memsagem trocada [%s]\n" , aux_3 );

}


int main(int argc, char** argv)
{
    printf("Ola tudo bem , estou aqui.\n");

    format_post_data ();
    
    return (EXIT_SUCCESS);
}

