/*
 * programa para ler o conteudo de um segmento de memoria
 * compartilhada que foi preenchido anteriormente por outro processo
 */

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define KEY 123

int main()
{
    int shmid ;
    char *path="nome_de_arquivo_existente" ;
    sem_t *mutex;
    int flag = 0 ;

    if (( shmid = shmget(ftok(path,(key_t)KEY), sizeof(sem_t),0)) == -1)
    {
        perror("Erro no shmget") ;
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

    printf("Leitura do segmento de memoria compartilhada:\n");

    sem_wait(mutex);
        printf("Atravessou o mutex.\n");
    sem_post(mutex);
    
    return 0;
}


