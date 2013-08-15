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

int main(int argc, char** argv)
{
    int status=0;
    int fd1=0;
    char mensagem[100]="Primeira mensagem enviada";
    char mensagem_2[100]="Segunda mensagem enviada";
    char mensagem_3[100];

    memset(mensagem_3, '\0', sizeof(mensagem_3));

    if ( mknod("fila_1" , S_IFIFO | O_RDWR | 0600,0) == -1 )
    {
        printf("Erro ao criar pipe : fila_1.\n");
    }

    if ( fork() == 0 )
    {
        execv("le_pipe_Nomeado" , argv );
    }
    else
    {
        if ( (fd1=open("fila_1" , S_IFIFO | O_RDWR )) == -1 )
        {
            printf("Erro ao obter pipe 'fila_1' para escrita.\n");
        }
        write (fd1 , mensagem , 100 ) ;
        
        wait(&status);
    }

    // escrevendo no pipe
    write (fd1 ,mensagem_2 ,100);
    read(fd1,mensagem_3,100);
    
    printf ("Mensagem obtida [%s] \n" , mensagem_2 );

    // destruindo pipe
    unlink ("fila_1");

    return (EXIT_SUCCESS);
}

