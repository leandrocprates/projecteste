/* 
 * File:   popen.c
 * Author: amazon
 *
 * Created on 9 de Agosto de 2009, 17:37
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    FILE *f;
    char line[1000];
    int i=1;

    f = popen("ps -ef " , "r");
    while ( fgets ( line , 1000,  f) )
    {
        printf("Linha [%d] %s\n" , i , line);
        i++;
    }

    pclose(f);

    return (EXIT_SUCCESS);
}

