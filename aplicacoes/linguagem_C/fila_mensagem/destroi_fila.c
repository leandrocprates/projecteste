/* 
 * File:   destroi_fila.c
 * Author: leandro
 *
 * Created on 29 de Agosto de 2009, 16:51
 */

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/signal.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 123

int main(int argc, char** argv)
{
    int msqid ;  /* ID da fila de mensagens */
    char *path = "nome_de_arquivo_existente" ;

    /*
     * destruindo a fila de mensagens
     */

    if (( msqid = msgget(ftok(path,(key_t)KEY), 0600)) == -1)
    {
      perror("Erro de msgget") ;
      exit(1) ;
    }

    if ( msgctl(msqid, IPC_RMID, NULL ) == -1)
    {
      perror( "Erro de destruir a fila." ) ;
      exit(1) ;
    }

    return (EXIT_SUCCESS);

}

