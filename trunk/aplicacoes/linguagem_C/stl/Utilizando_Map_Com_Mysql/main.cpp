#include <iostream>
#include <map>
#include <iomanip>

extern "C" {
#include "debug.h"
}

#include "connect.h"
#include "string"

#define RC_OK   0
#define RC_NOK  1

using std::map;

struct registro
{
    double phone;
    long int number_ticket ;
    int spid ;
    std::string file_name;
};

typedef map<double , registro > mapas ;

class operacao : public connect
{
      public :

           operacao()
           {
           }

           ~operacao()
           {
           }

           void carregarDados()
           {
                 dados.phone =  atof(linha[0]);
                 dados.number_ticket =  atol(linha[1]);
                 dados.spid =  atol(linha[2] ) ;
                 dados.file_name =  linha[3];
                 mapa.insert(mapas::value_type(dados.phone , dados) );
           }

           void imprimir()
           {
               for (mapas::const_iterator it=mapa.begin() ; it!=mapa.end() ; it++ )
               {
                   //std::cout<< "Phone : " << std::setprecision(0) << fixed << it->first
                   //<< " Ticket : "    << it->second.number_ticket  << " SPID : " << it->second.spid
                   //<< " File_Name : " << it->second.file_name << std::endl  ;

                   debug( "Phone : %10.0lf  Ticket : %10li SPID : %5li File_Name : %15s" , it->first , it->second.number_ticket ,
                          it->second.spid , it->second.file_name.c_str() );
               }
           }


      private :
           registro dados ;
           mapas mapa;

};


int main ()
{
    startDebug("." , ".log" );
    debug( "Iniciando a Aplicacao" );

    operacao conexao;
    conexao.conectarBD("localhost", "******", "*****", "******", 3306 );

    conexao.executarQuery("SELECT phone_number , number_ticket , spid, file_name FROM register  ");
    conexao.resgatarDados();

    while ( conexao.obterDados() == RC_OK )
    {
        conexao.carregarDados();
    }

    conexao.imprimir();

    closeDebug(); // fecha arquivo de debug

    return 0 ; 

}






