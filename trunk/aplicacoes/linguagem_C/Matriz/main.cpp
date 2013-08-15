/* 
 * File:   main.cpp
 * Author: leandro
 *
 * Created on 4 de Abril de 2010, 12:42
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

    int **matriz = NULL;

    matriz = (int **) malloc (  3 * sizeof (int *));
    
    for ( int i =0 ; i <  3 ; i++){
        matriz[i] =  (int *) malloc (  3 * sizeof (int ));
        for (int t =0 ; t < 3 ; t++) {
            matriz[i][t] = t ; 
        }
    }

    for ( int i =0 ; i <  3 ; i++){
        for (int t =0 ; t < 3 ; t++) {
            printf ("%d\n" , matriz[i][t]  ) ;
        }
    }

    for ( int i =0 ; i <  3 ; i++){
            free(matriz[i]) ;
    }

    return (EXIT_SUCCESS);
}

