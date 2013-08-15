/* 
 * File:   main.cpp
 * Author: leandro
 *
 * Created on 28 de Março de 2010, 17:08
 */

#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;

void *imprimir(void *valor){

    int i = (*(int*) valor);
    cout<< "Thread ID: " << pthread_self() << endl;
    cout << "Valor: " << ++i << endl ;
    int *t = (int*) valor; // fazendo t apontar para o endereco de (void *valor)
    *t=i; // alterando o valor de (void *valor)
}

int main(int argc, char** argv) {

    pthread_t thread[2];
    int valor_1=1, valor_2=2;

    pthread_create(&thread[0] , NULL , imprimir , (void *)&valor_1 );
    pthread_create(&thread[1] , NULL , imprimir , (void *)&valor_2 );

    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);

    cout << "Valor_1:" << valor_1 << endl;
    cout << "Valor_2:" << valor_2 << endl;
    
    cout << "Terminando Execucao" <<endl;
    return (EXIT_SUCCESS);
}

