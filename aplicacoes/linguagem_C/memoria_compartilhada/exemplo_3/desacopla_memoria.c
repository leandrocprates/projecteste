#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 123

int main()
{
  int shmid ;  /* identificador da memoria comum */
  char *path="nome_de_arquivo_existente" ;
  int *mem ;
  int flag = 0;

     /*
     * recuperacao do shmid 
     */
     if (( shmid = shmget(ftok(path,(key_t)KEY), sizeof(int),0)) == -1) {
          perror("Erro no shmget") ;
          exit(1) ;
     }
     printf("Sou o processo com pid: %d \n",getpid()) ;
     printf("Identificador do segmento recuperado: %d \n",shmid) ;
     printf("Este segmento e associado a chave unica: %d\n",
                   ftok(path,(key_t)KEY)) ;
    /*
     * acoplamento do processo a zona de memoria 
     * recuperacao do ponteiro sobre a zona de memoria comum
     */
     if ((mem = shmat (shmid, 0, flag)) == NULL){
          perror("acoplamento impossivel") ;
          exit (1) ;
     }
    /*
     * tratamento do conteudo do segmento
     */
     printf("leitura do segmento de memoria compartilhada:\n");
     printf("\t==>%d\n",*mem);
    /*
     * desacoplamento do segmento
     */
     if (shmdt(mem)== -1){
          perror("acoplamento impossivel") ;
          exit(1) ;
     }
    /*
     * destruicao do segmento
     */
     if ( shmctl(shmid, IPC_RMID,0) == -1){
          perror("destruicao impossivel") ;
          exit(1) ;
     }
     exit(0);
}


