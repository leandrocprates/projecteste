/* 
 * File:   obtem_Dados_Fila.c
 * Author: leandro
 *
 * Created on 23 de Agosto de 2009, 11:46
 */

/*
 * o programa recupera o ID de uma fila existente (criada com o
 * programa test_msgget.c e mostra a estrutura msqid_ds
 * associada a essa fila
 */

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY 123

int main(int argc, char** argv) 
{
    struct msqid_ds buf ;
    char *path = "nome_de_arquivo_existente" ;
    int msqid ;

    /* recuperacao do ID da fila de mensagens associada a chave 123 */
    if (( msqid = msgget(ftok(path,(key_t)KEY),0)) == -1 )
    {
        perror ("Erreur msgget()") ;
        exit(1) ;
    }
    
    printf("A chave %#x esta associada a fila %d\n",  ftok(path,(key_t)KEY), msqid);

    /* recuperacao na estrutura buf dos parametros da fila */
    if (msgctl(msqid,IPC_STAT,&buf) == -1)
    {
        perror("Erreur msgctl()") ;
        exit(1) ;
    }
    else
    {
        printf("id da fila de mensagens     : %d\n",msqid) ;
        printf("id do proprietario          : %d\n",buf.msg_perm.uid) ;
        printf("id do grupo do proprietario : %d\n",buf.msg_perm.gid) ;
        printf("id do criador               : %d\n",buf.msg_perm.cuid) ;
        printf("id do grupo do criador      : %d\n",buf.msg_perm.cgid) ;
        printf("direitos de acesso          : %d\n",buf.msg_perm.mode) ;
        printf("nb atual de bytes na fila   : %d\n",buf.msg_cbytes) ;
        printf("nb de mensagens na fila     : %d\n",buf.msg_qnum) ;
        printf("nb maximal de bytes na fila : %d\n",buf.msg_qbytes) ;
        printf("pid do ultimo escritor      : %d\n",buf.msg_lspid) ;
        printf("pid do ultimo leitor        : %d\n",buf.msg_lrpid) ;
        printf("data da ultima escrita      : %s\n",ctime(&buf.msg_stime)) ;
        printf("data da ultima leitura      : %s\n",ctime(&buf.msg_rtime)) ;
        printf("data da ultima modificacao  : %s\n",ctime(&buf.msg_ctime)) ;
    }

    return (EXIT_SUCCESS);
}
