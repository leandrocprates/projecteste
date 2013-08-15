/* 
 * File:   main.cpp
 * Author: amazon
 *
 * Created on 9 de Agosto de 2009, 16:40
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    int fd[2];
    int pid=0;
    char *mensagem="Testando o processo filho.";
    char *busca=NULL;

    if (pipe(fd)==-1)
    {
        printf("Erro ao criar pipe.\n");
    }

    if ( (pid=fork()) < 0 )
    {
        printf("Erro ao criar proceso filho.\n");
    }

    if ( pid == 0)
    {
        printf("Filho - Processo filho numero[%d].\n" , getpid() );
        close(fd[0]);
        write (fd[1] , mensagem , strlen(mensagem) ) ;
    }
    else
    {
        waitpid(pid,NULL,0);
        close(fd[1]);
        printf("Pai - Processo pai numero[%d].\n" , getpid() );
        printf("Pai - Processo filho numero[%d].\n" , pid );
        busca = ( char * ) malloc( strlen(mensagem) * sizeof(char) ) ;
        read(fd[0] , busca , strlen(mensagem) );
        printf ("Pai - Valor retornado [%s] \n" , busca );
    }

    return (EXIT_SUCCESS);
}

