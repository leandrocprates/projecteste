/*
 * exemplo de utilizacao de shmat()
 * escrita num segmento de memoria compartilhada
 */

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

#define KEY 123

int main(int argc , char *argv[])
{
    int shmid ;
    char *path="nome_de_arquivo_existente" ;
    int *mem ;
    int flag = 0 , rv=0;

    if (( shmid = shmget(ftok(path,(key_t)KEY), sizeof(int), IPC_CREAT|IPC_EXCL|SHM_R|SHM_W)) == -1)
    {
        perror("Erro no shmget") ;
        exit(1) ;
    }
  
    printf("Sou o processo com pid: %d \n",getpid()) ;
    printf("Identificador do segmento recuperado: %d \n",shmid) ;
    printf("Este segmento e associado a chave unica: %d\n", ftok(path,(key_t)KEY)) ;

    if ((mem = shmat (shmid, 0, flag)) == NULL)
    {
        perror("acoplamento impossivel") ;
        exit (1) ;
    }

    *mem=155;

    if ( fork() == 0 )
    {
        printf("\n===============================\n" );
        printf("Filho numero %d.\n" , getpid() );
        execv("./le_memoria", argv );
    }

    printf("Pai numero %d.\n" , getpid() );
    wait(&rv);

    printf("Leitura do segmento de memoria compartilhada:\n");
    printf("\t==>%d\n",*mem) ;

    return 0;
}

