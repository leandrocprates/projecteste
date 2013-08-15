#include <iostream>
#include <map>

using std::multimap;

// ordena pela chave
// um multimap aceita chave duplicada
typedef multimap<int , double > mapas ;

int main ()
{
    mapas mapa;
    
    mapa.clear();
    mapa.insert( mapas::value_type(1,20) ) ;
    mapa.insert( mapas::value_type(2,50) ) ;
    mapa.insert( mapas::value_type(9,50) ) ;
    mapa.insert( mapas::value_type(7,50) ) ;
    mapa.insert( mapas::value_type(8,50) ) ;
    mapa.insert( mapas::value_type(4,50) ) ;
    mapa.insert( mapas::value_type(1,50) ) ; // duplicando chave 1
    
    for ( mapas::const_iterator it = mapa.begin() ; it != mapa.end() ; it++ )
    {
        std::cout << "Chave:" << it->first << " Valor:" << it->second << std::endl ;
    }
	 
    // retorna busca com valor 1 
    mapas::const_iterator it = mapa.find(1);
    std::cout << "Retornando valor para a busca do valor 1. " << std::endl ;
    std::cout << "Chave:" << it->first << " Valor:" << it->second << std::endl ;
    it++ ; 	
    std::cout << "Chave:" << it->first << " Valor:" << it->second << std::endl ;

    std::cout<<  "Tamanho: " << mapa.size() << std::endl ;


    



    return 0 ;
}
