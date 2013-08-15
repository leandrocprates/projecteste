/* 
 * File:   le_pipe_Nomeado.c
 * Author: leandro
 *
 * Created on 22 de Agosto de 2009, 19:59
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
    FILE *fd2=NULL;
    char mensagem[100];

    memset(mensagem,'\0',sizeof(mensagem));

    sleep(1);
    
    if ( (fd2=fopen("fila_1" , "r")) == NULL )
    {
        printf("Erro ao obter pipe 'fila_1' para leitura.\n");
    }

    printf ("%s , %s , %d , PID [%d]\n", __FILE__ , __FUNCTION__ , __LINE__ , getpid() );
    
    fgets(mensagem,100,fd2);

    printf ("Mensagem obtida [%s] \n" , mensagem  );

    return (EXIT_SUCCESS);
}

