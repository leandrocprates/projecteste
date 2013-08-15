#include <iostream>
#include <map>

#include <debug.h>

using std::map;

// ordena pela chave
// um map nao aceita chave duplicada
typedef map<int , double > mapas ;

int main ()
{
    mapas mapa;
    
    mapa.clear();	
    mapa.insert( mapas::value_type(1,20) ) ;
    mapa.insert( mapas::value_type(2,50) ) ;
    mapa.insert( mapas::value_type(9,40) ) ;
    mapa.insert( mapas::value_type(7,30) ) ;
    mapa.insert( mapas::value_type(8,80) ) ;
    mapa.insert( mapas::value_type(4,10) ) ;
    
    for ( mapas::const_iterator it = mapa.begin() ; it != mapa.end() ; it++ )
    {
        std::cout << "Chave:" << it->first << " Valor:" << it->second << std::endl ;
    }

    // digito a chave e retorna o valor associado imprimindo o numero 20 da chave 1 
    //std::cout<< mapa[1] << std::endl;
    int valor = mapa[1];
    std::cout<< "valor: " << valor  << std::endl;

    // efetua a busca do valor pela chave passada existente
    mapas::const_iterator it = mapa.find(2); 
    std::cout<< "Busca com find: " << it->first << " valor " << it->second << std::endl ; 


    // efetua a busca do valor pela chave passada nao existente
    mapas::const_iterator it2 = mapa.find(10);
    std::cout<< "Busca com find: "  <<  (  it2==mapa.end() ? "Nenhum valor existente" : "Valor existe" ) << std::endl ;

    startDebug("." , ".log" );
    debug("mais [%s] [%s] " , "um" , "teste" );

    return 0 ;
}
