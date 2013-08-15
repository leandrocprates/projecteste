/* fichier test_shmget.c */ 
/* exemplo de utilizacap de shmget() */

#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 123

int main()
{
  int shmid ;  /* identificador da memoria comum */
  int size = 1024 ;
  char *path="/tmp/nome_de_arquivo_existente" ;
     
     if (( shmid = shmget(ftok(path,(key_t)KEY), size,
                    IPC_CREAT|IPC_EXCL|SHM_R|SHM_W)) == -1) {
          perror("Erro no shmget") ;
          exit(-1) ;
     }
     printf("Identificador do segmento: %d \n",shmid) ;
     printf("Este segmento e associado a chave unica: %d\n",
                   ftok(path,(key_t)KEY)) ;
     exit(0);
}


