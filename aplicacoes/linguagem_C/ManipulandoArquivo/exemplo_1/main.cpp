/*
 * Manipulando arquivos binarios
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Teste
{
    int x ;
    int y ;
}T,U;

int main(int argc, char** argv)
{

    FILE *f=fopen("arquivo_escrita.txt" , "wb");
    if (f==NULL)
    {
        printf("Erro ao criar arquivo para escrita binaria.\n");
    }

    T.x=10;
    T.y=20;

    fwrite(&T,sizeof(T),1,f);

    fclose(f);

    fopen("arquivo_escrita.txt" , "rb");
    if (f==NULL)
    {
        printf("Erro ao abrir arquivo para leitura binaria.\n");
    }

    memset(&U,'\0', sizeof(U));

    fread(&U,sizeof(U),1,f);

    printf("Valor x: [%d] \n Valor y: [%d]\n" , U.x , U.y );
    
    fclose(f);

    return (EXIT_SUCCESS);
}

