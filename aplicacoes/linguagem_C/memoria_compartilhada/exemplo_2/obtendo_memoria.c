/* arquivo test_shmctl.c */

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 123

struct shmid_ds buf ;

int main()
{
  char *path = "nome_de_arquivo_existente" ;
  int shmid ;

  /* recuperacao do identificador do segmento associado a chave 123 */
     if (( shmid = shmget(ftok(path,(key_t)KEY),sizeof(int),0)) == -1 ) {
          perror ("Erro shmget()") ;
          exit(1) ;
     }
      /* recuperacao das informacoes realtivas ao segmento */
     if ( shmctl(shmid,IPC_STAT,&buf) == -1){
          perror("Erro shmctl()") ;
          exit(1) ;
     }
     printf("ESTADO DO SEGMENTO DE MEMORIA COMPARTILHADA %d\n",shmid) ;
     printf("ID do usuario proprietario: %d\n",buf.shm_perm.uid) ;
     printf("ID do grupo do proprietario: %d\n",buf.shm_perm.gid) ;
     printf("ID do usuario criador: %d\n",buf.shm_perm.cuid) ;
     printf("ID do grupo criador: %d\n",buf.shm_perm.cgid) ;
     printf("Modo de acesso: %d\n",buf.shm_perm.mode) ;
     printf("Tamanho da zona de memoria: %d\n",buf.shm_segsz) ;
     printf("pid do criador: %d\n",buf.shm_cpid) ;
     printf("pid  (ultima operacao): %d\n",buf.shm_lpid) ;
 
     /* destruicao do segmento */
     if ((shmctl(shmid, IPC_RMID, NULL)) == -1){
          perror("Erro shmctl()") ;
          exit(1) ;
     }
     exit(0);
}

