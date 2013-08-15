//============================================================================
// Name        : projeto_debug.cpp
// Author      : leandro
// Version     :
// Copyright   : Your copyright notice
// Description : Criacao de biblioteca de debug
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#include "debug.h"

#define TAM_DATA        8
#define TAM_DATA_HORA  14
#define TAM_DEBUG       6 
#define NOME_ARQUIVO   "debug_"

// os parametros declarados acima (TAM_DEBUG e NOME_ARQUIVO ) 
// sao o nome do arquivo gerado por exemplo 'debug_20081018'
// onde o parametro NOME_ARQUIVO e concatenado na frente da 
// data em que o arquivo foi gerado 
// trocando o parametro NOME_ARQUIVO voce podera gerar o 
// arquivo com o nome que desejar . 

// ja o parametro TAM_DEBUG corresponde ao tamanho do nome 
// do arquivo que foi declarado em NOME_ARQUIVO , caso troque 
// o nome do arquivo voce tambem devera trocar o tamanho do 
// nome do arquivo para o comprimento dos caracteres do campo
// NOME_ARQUIVO 

FILE *f;

/*******************************************************
 * Funcao que imprime o logo da empresa                *
 *******************************************************/

void imprimirLogo()
{
    fprintf(f , "\n\n%s\n" , "**************************************************************************************" );
    fprintf(f , "%s\n"     , "*                                                                                    *" );
    fprintf(f , "%s\n"     , "*   Nome da Empresa : Home                                                           *" );
    fprintf(f , "%s\n"     , "*                                                                                    *" );
    fprintf(f , "%s\n"     , "*   Autor : Leandro                                                                  *" );
    fprintf(f , "%s\n"     , "*                                                                                    *" );
    fprintf(f , "%s\n"     , "*   Data : 18 / 10 / 2008                                                            *" );
    fprintf(f , "%s\n"     , "*                                                                                    *" );
    fprintf(f , "%s\n"     , "*   Projeto : Log de Debug                                                           *" );
    fprintf(f , "%s\n"     , "*                                                                                    *" );
    fprintf(f , "%s\n"     , "*                                                                                    *" );                        
    fprintf(f , "%s\n\n"   , "**************************************************************************************" );
     
}

/*******************************************************
 * Funcao que retorna a data corrente de processamento *
 *******************************************************/

char *geraData()
{
	time_t rawtime;
	struct tm * timeinfo;
	char *buffer;

	buffer = (char * )malloc (sizeof(char) *30 );

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	strftime (buffer,30,"%Y%m%d%H%M%S",timeinfo);

    return buffer ; 
}

 
/*********************************************************
 * Funcao que gera o nome do arquivo com a data corrente *
 *********************************************************/

char *geraNomeArquivo()
{
     char *data=geraData();
     char *nomeArq; 
     
     nomeArq= (char * ) malloc (sizeof(char) * (TAM_DEBUG + TAM_DATA + 1) );
     memset (nomeArq , '\0' , ( TAM_DEBUG + TAM_DATA + 1 ) );

     strcpy (nomeArq, NOME_ARQUIVO );
     strncpy(&nomeArq[TAM_DEBUG], data , TAM_DATA );
     
     nomeArq[TAM_DEBUG + TAM_DATA]='\0';

     return nomeArq;     

}


/*******************************************************
 * Funcao que ira imprimir a string enviada no arquivo *
 *******************************************************/
void debug (const char *format , ...)
{
    char *data = geraData();
    char buffer[500];

    va_list args;
    va_start (args, format);
    vsprintf( buffer  , format  , args );
    va_end (args);

    fprintf(f , "[%s]  " , data );
    fprintf(f , "%s\n"   , buffer );

}

/********************************************************
 * Funcao que ira criar e abrir o arquivo de debug      *
 ********************************************************/
void startDebug(const char *diretorio , const char *tipo )
{
   char *nomeArquivo = geraNomeArquivo();
   char *dir_arq ; 


   nomeArquivo = (char *) realloc (nomeArquivo, (strlen(tipo) + strlen(nomeArquivo)) * sizeof(char)) ; 
   
   strcpy(&nomeArquivo[strlen(nomeArquivo)] , tipo ); 
   
   // +2 e adicionado por causa da '/' colocada abaixo 
   dir_arq = (char *) malloc ( (strlen(diretorio) + strlen(nomeArquivo) + 2 ) * sizeof(char) ); 
   
   strcpy(dir_arq , diretorio ); 
   strcat(dir_arq , "/" );
   strcat(dir_arq , nomeArquivo );
   
   puts(dir_arq);
   
   if ( (f=fopen( dir_arq , "a")) == NULL ) 
   {
        printf("Erro ao gerar arquivo [%s] no diretorio [%s] \n" ,  nomeArquivo , diretorio ) ; 
        exit(1);
   }
   
   free(dir_arq);
   free(nomeArquivo);

   imprimirLogo();

    
}

/*******************************************************
 * Funcao main usada para mostrar o funcionamento da   *
 * biblioteca                                          *
 *******************************************************/
/*
int main(void)
{
    // a funcao startDebug recebe dois parametros , o primeiro e o diretorio onde 
    // sera gravado o arquivo de log e o segundo e a extensao do arquivo.
    // ela deve ser chamada para a inicializacao e criacao do arquivo de debug
    
    startDebug("." , ".log" );

    // a funcao debug e a funcao que ira escrever os dados passados no arquivo de 
    // debug gerado recebe como primeiro parametro a string a ser formatada 
    // e o resto sao os parametros a serem formatados
    
    debug("mais [%s] [%s] " , "um" , "teste" );
//    system("PAUSE");
	return EXIT_SUCCESS;
}

*/
