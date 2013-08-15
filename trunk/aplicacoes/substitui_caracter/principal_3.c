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

void altera_mensagem ( char *mensagem ,char *caracter , char *caracter_substitui )
{
 char vet_1[512];
 char vet_2[512];
 int t = 0 ;
 int i = 0;

 char *pch;
 char *str ; // armazena a mensagem a ser trocada

 memset ( vet_1 , '\0' , sizeof( vet_1 ) );
 memset ( vet_2 , '\0' , sizeof( vet_2 ) );

 str = ( char * ) malloc ( strlen(mensagem) * sizeof(char) );

 strcpy( str , mensagem ); // copia a mensagem para ser trocado os caracteres

 printf ("Buscando caracters '%c' em \"%s\"...\n", *caracter , str);
 pch=strchr(str, *caracter );

 // aqui sera feita a substituicao do caracter
 while (pch!=NULL)
 {
   printf ("found at %d\n",pch-str+1);
   i = pch-str ;

   strncpy(vet_1 , &str[t] , (i)-t );
   vet_1[i-t]='\0' ;

   strcat(vet_2 , vet_1);
   strcat(vet_2 , caracter_substitui );
   vet_2[ strlen(vet_2) ] = '\0' ;

   t = i+1;
   pch=strchr(pch+1, *caracter );
   i = pch-str-1 ;

 }

  strcat(vet_2 , &str[t]);

  strcpy(mensagem , vet_2); // copia a mensagem ja alterada 

  return ;

}


static void format_post_data (char *mensagem ,char *caracter , char *caracter_substitui)
{

   printf("memsagem original [%s]\n" , mensagem );

   altera_mensagem( mensagem , caracter , caracter_substitui ); // troca a mensagem

   printf("memsagem trocada [%s]\n" , mensagem );

}

/*************************************************************
Exemplo de execucao : ./main "ola+ teste" "+" "%T9595"

Fara a substituicao do caracter '+' por '%T9595' na mensagem 
passada.

Esta funcao podera ser usada para fazer a substituicao de 
qualquer caracter.
**************************************************************/

int main(int argc, char** argv)
{
    // argv[1]  a mensagem que sera alterada
    // argv[2]  sera o caracter que sera substituido
    // argv[3]  sera o caracter que ira substituir o caracter passado em argv[2]

    format_post_data ( argv[1] , argv[2] , argv[3] );
    
    return (EXIT_SUCCESS);
}

