/* 
 * File:   main.cpp
 * Author: amazon
 *
 * Created on 2 de Agosto de 2009, 13:11
 */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MAX_THREADS 300

static int valor=0;

pthread_t th[MAX_THREADS];
pthread_mutex_t mutex;

typedef struct
{
    int id;
    char *mensagem;
}Tmessage;

Tmessage param[MAX_THREADS];

void *funcao_Thread(void *param)
{
    Tmessage *param_n = (Tmessage *)  param ;
    printf ("Parametro ID [%d], Mensagem [%s] \n" , param_n->id , param_n->mensagem);

    pthread_exit( (void*) &param_n->id );
}

void *funcao_Thread_count(void *param)
{
    Tmessage *param_n = (Tmessage *)  param ;
    printf ("Parametro ID [%d], Mensagem [%s] \n" , param_n->id , param_n->mensagem);
    sleep(rand()%2);
    printf ("Valor : [%d] ID [%d] \n" , (valor+param_n->id) , param_n->id ) ;
}

void *funcao_Thread_Incremet(void *param)
{
    Tmessage *param_n = (Tmessage *)  param ;

    // acesso exclusivo uma thread por vez
    pthread_mutex_lock(&mutex);
    sleep(rand()%2);
    printf ("funcao_Thread_Incremet : Valor : [%d] ID [%d] \n" , valor++ , param_n->id ) ;
    pthread_mutex_unlock(&mutex);
}


int main(int argc, char** argv)
{
    int i = 0 , *res=NULL;

    pthread_mutex_init (&mutex,NULL);

    for ( i=0 ; i<MAX_THREADS ;i++ )
    {
        param[i].id=i;
        param[i].mensagem=(char *) "Oi";
        pthread_create( &th[i] , NULL , funcao_Thread , (void *) &param[i] );
    }

    for ( i=0 ; i<MAX_THREADS ;i++ )
    {
        pthread_join( th[i] , (void **) &res );
        printf ("Valor retornado da thread: [%d] id : [%d] \n" , i  , *res );
    }

    // espera o retorno da thread 5
    //pthread_join( th[5] , (void **) &res );
    //printf ("Valor retornado da thread: [5] [%d] \n" , *res );

    //obs : Nunca executar duas vezes seguida a funcao pthread_join para a mesa thread

    for ( i=0 ; i<MAX_THREADS ;i++ )
    {
        param[i].id=i;
        param[i].mensagem=NULL;
        pthread_create( &th[i] , NULL , funcao_Thread_count , (void *) &param[i] );
    }

    for ( i=0 ; i<MAX_THREADS ;i++ )
    {
        pthread_join( th[i] , NULL );
    }

    // incrementando valor estatico

    for ( i=0 ; i<MAX_THREADS ;i++ )
    {
        param[i].id=i;
        param[i].mensagem=NULL;
        pthread_create( &th[i] , NULL , funcao_Thread_Incremet , (void *) &param[i] );
    }

    for ( i=0 ; i<MAX_THREADS ;i++ )
    {
        pthread_join( th[i] , NULL );
    }

    return (EXIT_SUCCESS);
    
}

