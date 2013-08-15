/***************************************************************************************************************
Foi criado como exemplo pois o malloc nao estava funcionando nas versoes em c++ e foi colocado aqui e funcionou
****************************************************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct cad 
{
   char nome[30];
   char rua[50];
};

struct cadastro 
{
   struct cad *vet;
   char telefone[30];
};

int main ()
{
   struct cadastro *x;

   x = ( struct cadastro * ) malloc (sizeof ( struct cadastro) ) ; 
   x->vet=(struct cad * ) malloc (sizeof(struct cad )) ;

   strcpy ( x->telefone,  "22333018" ) ;
   strcpy ( x->vet->nome ,"Leandro" ) ; 
   strcpy ( x->vet->rua ,"Av Joao Pessoa" ) ; 

   printf ( "Telefone : [%s]\n" , (*x).telefone ) ;
   printf ( "Nome: [%s]\n" , (*x).vet->nome ) ;
   printf ( "Rua: [%s]\n" , (*x).vet->rua ) ;

}



