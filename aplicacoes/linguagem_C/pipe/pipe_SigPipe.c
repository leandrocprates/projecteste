/* 
 * File:   pipe_SigPipe.cpp
 * Author: leandro
 *
 * Created on 22 de Agosto de 2009, 12:51
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
#include <string.h>


void trata_sinal (int sinal)
{
    printf("Sinal recebido [%d].\n" , sinal);
}

int main(int argc, char** argv)
{
    int fd[2];
    char msg[200]="Ola este e um teste";

    signal(SIGPIPE , trata_sinal );
    //signal(SIGPIPE , SIG_IGN );

    if ( pipe(fd) == -1 )
    {
        printf("Falha ao criar o pipe.\n");
    }

    close(fd[0]);

    if ( write(fd[1] , msg , strlen(msg) ) == -1 )
    {
        printf("Erro ao escrever no pipe.\n");
    }

    return (EXIT_SUCCESS);
}

