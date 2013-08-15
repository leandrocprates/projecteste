/* 
 * File:   main.cpp
 * Author: amazon
 *
 * Created on 2 de Agosto de 2009, 13:11
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define RC_OK 0
#define RC_NOK -1

#define FALSE 0
#define TRUE  1 

struct dirent **estrutura;

/**
 * Funcao utilizada para selecionar apenas o arquivos/diretorios de
 * interesse
 * FALSE - desconsidera o arquivo/diretorio selecionado
 * TRUE  - considera o diretorio/arquivo selecionado
 * 
 * */

int file_select(const struct dirent *temp)
{
    if ( ( strcmp( temp->d_name  , "." ) ) == 0  ||  ( strcmp( temp->d_name  , ".." ) ) == 0 )
        return FALSE;
    else
        return TRUE;
}


int main(int argc, char** argv)
{
    int count=0, i=0;

    //scandir retorna o numero de objetos selecionados
    count=scandir("./" , &estrutura , file_select , alphasort );

    printf("Retornou [%d] Objetos.\n" , count );
    
    for ( i=0 ; i<count ; i++ )
    {
        printf ( "Valor [%s]\n" , estrutura[i]->d_name ) ;
    }

    return (EXIT_SUCCESS);
    
}

