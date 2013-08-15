/* 
 * File:   main.cpp
 * Author: lprates
 *
 * Created on 25 de Junho de 2010, 17:24
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Ordena numeros double
 */

int comp(const void *i, const void *j)
{
    double t = (*(double *) i);
    double v = (*(double *) j);

    if ( t > v ) {
        return 1 ;
    } else if ( v < t ) {
        return -1 ;
    } else {
        return 0;
    }
}

/*
 * Ordena string
 */

int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;

    return strcmp(*ia, *ib);
}

void imprimir(char **c){
    for (int i=0 ; i<4 ; i++){
        printf("%s\n" , c[i] );
    }
}

void imprimir(double vetor[]){
    for (int i=0 ; i<6 ; i++){
        printf("%lf\n" , vetor[i] );
    }
}


/*
int main(void)
{
    char *strings[] = { "BDT20191001.txt", "BDT20190503.txt", "BDT20190203.txt", "BDT20190501.txt" };
    size_t strings_len = sizeof(strings) / sizeof(char *);

    puts("*** String sorting...");
    printf("Char: %d\n" , sizeof(char *));
    printf("Tamanho: %d\n" , sizeof(strings));

    imprimir(strings);
    
    qsort(strings, strings_len, sizeof(char *), cstring_cmp);

    puts("*** Ordenado ...");
    
    imprimir(strings);

}
 * */

int main(void)
{
    double vetor[]={ 23.8 , 34.7 , 24.4 , 98.7 , 54.69 , 34.87 };

    printf("Saida Desordenada:\n");

    imprimir(vetor);
    qsort ( vetor , 6 , sizeof(double) , comp);

    printf("Saida Ordenada:\n");
    imprimir(vetor);

}


