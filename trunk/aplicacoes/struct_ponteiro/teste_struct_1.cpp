
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct cad 
{
   string nome;
   string rua;
};

struct cadastro 
{
   struct cad vet;
   string telefone;
};

int main ()
{

   struct cadastro x;

   x.telefone="22333018";
   x.vet.nome="Leandro";
   x.vet.rua="Av Joao Pessoa";

   cout << x.telefone << endl ;
   cout << x.vet.nome << endl ;
   cout << x.vet.rua  << endl ;

}



