/* 
 * File:   insere_Fila.c
 * Author: leandro
 *
 * Created on 23 de Agosto de 2009, 11:50
 */

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 123
#define MSG_SIZE_TEXT 256

int main(int argc, char** argv)
{
    int i = 1 ;
    int msqid ;
    char *path = "nome_de_arquivo_existente" ;

    /* estrutura msg associada as mensagens */
    struct msgtext
    {
         long mtype ;
         char mtext[MSG_SIZE_TEXT] ;
    } msg ;

    /* recuperacao do identificador da fila de mensagens */
    if (( msqid = msgget(ftok(path,(key_t)KEY),0)) == -1 )
    {
          perror ("Erro msgget()") ;
          exit(1) ;
    }

    printf("A chave %#x esta associada a fila %d\n", ftok(path,(key_t)KEY), msqid);

    msg.mtype = 1 ;           /* tipo das mensagens */

    while(i<=30)
    {
        /* escreve o texto da mensagem */
        sprintf(msg.mtext,"mensagem no %d de tipo %ld",i,msg.mtype) ;
        /* envia a mensagem a fila */
        if(msgsnd(msqid,&msg,strlen(msg.mtext),IPC_NOWAIT) == -1)
        {
             perror("Envio de mensagem impossivel") ;
             exit(-1) ;
        }

        printf("mensagem no %d de tipo %ld enviada a fila %d\n", i,msg.mtype,msqid) ;
        printf("-->texto da mensagem: %s\n",msg.mtext) ;
        i++ ;
    }

    return (EXIT_SUCCESS);
}
