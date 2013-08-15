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
    sem_t *mutex;
    int flag = 0 , rv=0;

    
    if (( shmid = shmget(ftok(path,(key_t)KEY), sizeof(sem_t), IPC_CREAT|IPC_EXCL|SHM_R|SHM_W)) == -1)
    {
        perror("Erro no shmget");
        exit(1) ;
    }
  
    printf("Sou o processo com pid: %d \n",getpid()) ;
    printf("Identificador do segmento recuperado: %d \n",shmid) ;
    printf("Este segmento e associado a chave unica: %#x\n", ftok(path,(key_t)KEY)) ;

    if ((mutex = shmat (shmid, 0, flag)) == NULL)
    {
        perror("acoplamento impossivel") ;
        exit (1) ;
    }

    sem_init(mutex,0,1);

    sem_wait(mutex);
    
    if ( fork() == 0 )
    {
        printf("\n===============================\n" );
        printf("Filho numero %d.\n" , getpid() );
        execv("./le_memoria", argv );
    }
    
    sem_post(mutex);

    printf("Pai numero %d.\n" , getpid() );

    sem_close(mutex);
    
    return 0;
}

