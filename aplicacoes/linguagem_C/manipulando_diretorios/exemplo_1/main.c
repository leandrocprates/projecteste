/* 
 * File:   main.cpp
 * Author: amazon
 *
 * Created on 2 de Agosto de 2009, 13:11
 */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define THREADS 2
#define RC_OK 0
#define RC_NOK -1

pthread_t th[THREADS];

DIR *diretorio ;
struct dirent *estrutura;
struct stat caracteristica;

int main(int argc, char** argv)
{

    diretorio=opendir ("./");
    if ( diretorio == NULL )
    {
        printf("Nao conseguiu abrir o diretorio.\n");
        exit(-1);
    }
    
    while ( (estrutura=readdir(diretorio)) != NULL)
    {
        if ( (lstat(estrutura->d_name , &caracteristica )) != RC_OK )
        {
            printf("Erro ao buscar os dados do arquivo [%s].\n" , estrutura->d_name );
        }
        
        switch ( caracteristica.st_mode & S_IFMT )
        {
            case __S_IFREG :
                    printf ("Nome do Arquivo : [%s]\n" , estrutura->d_name );  break;

            case __S_IFDIR :
                    printf ("Nome do Diretorio : [%s]\n" , estrutura->d_name );  break;

            case __S_IFLNK :
                    printf ("Nome do Link : [%s]\n" , estrutura->d_name );  break;

            default : break;
        }

    }
    
    if ( closedir(diretorio) != RC_OK)
    {
        printf ("Erro ao fechar o diretorio.\n");
    }
   
    return (EXIT_SUCCESS);
    
}

