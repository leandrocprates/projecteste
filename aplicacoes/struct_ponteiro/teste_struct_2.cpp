
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct cad 
{
   string nome;
   string rua;
};

struct cadastro 
{
   struct cad *vet;
   string telefone;
};

int main ()
{
   cadastro *x;

   x= new cadastro;
   x->vet=new cad ; 

   x->telefone="22333018";
   x->vet->nome="Leandro";
   x->vet->rua="Av Joao Pessoa";

   cout << "telefone :" << x->telefone << endl ;
   cout << "Nome :"     << x->vet->nome<< endl ;
   cout << "Rua : "     << x->vet->rua << endl ;  
 
   return 0; 
}



