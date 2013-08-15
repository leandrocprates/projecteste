/* 
 * File:   pipe_Nomeado.c
 * Author: leandro
 *
 * Created on 22 de Agosto de 2009, 15:07
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/signal.h>


void fecha_Tudo(int sinal)
{
    printf("Recebido sinal [%d]\n", sinal);
    unlink ("fila_1");
}

int main(int argc, char** argv)
{
    int status=0;
    FILE *fd1=NULL,*fd2=NULL;
    char mensagem[100]="Primeira mensagem enviada";

    signal(SIGTERM,fecha_Tudo);
    
    if ( mkfifo("fila_1" , 0600 ) == -1 )
    {
        printf("Erro ao criar pipe : fila_1.\n");
    }

    if (fork()==0)
    {
        execv("le_pipe_Nomeado",argv);
    }
    else
    {
        if ( (fd1=fopen("fila_1" , "w" )) == NULL )
        {
            printf("Erro ao obter pipe 'fila_1' para escrita.\n");
        }

        fputs(mensagem,fd1);
        fclose(fd1);

        wait(&status);
        printf("Processo Pai [%d].\n",getpid());
    }

    unlink ("fila_1");

    return (EXIT_SUCCESS);
}


