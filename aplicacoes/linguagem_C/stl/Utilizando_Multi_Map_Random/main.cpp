#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>

using std::multimap;
using std::vector;
using std::rand;

// ordena pela chave
// um multimap aceita chave duplicada
typedef multimap<int , double > mapas ;

int main ()
{
    mapas mapa;
    int num ;
    vector<int> cupom ;
    

    mapa.clear();
    mapa.insert( mapas::value_type(1,20) ) ;
    mapa.insert( mapas::value_type(2,50) ) ;
    mapa.insert( mapas::value_type(9,50) ) ;
    mapa.insert( mapas::value_type(7,50) ) ;
    mapa.insert( mapas::value_type(8,50) ) ;
    mapa.insert( mapas::value_type(4,50) ) ;

    mapa.insert( mapas::value_type(1,50) ) ; // duplicando chave 1
    mapa.insert( mapas::value_type(1,27) ) ;
    mapa.insert( mapas::value_type(1,39) ) ;
    mapa.insert( mapas::value_type(1,36) ) ;
    mapa.insert( mapas::value_type(1,12) ) ;

    
    for ( mapas::const_iterator it = mapa.begin() ; it != mapa.end() ; it++ )
    {
        std::cout << "Chave:" << it->first << " Valor:" << it->second << std::endl ;
    }

    // retorna quantidade de chaves com valor um
    num = mapa.count(1);
    std::cout << "Numero de chaves com valor 1 : " << num << std::endl ;

    // retorna busca com valor 1 
    mapas::const_iterator it = mapa.find(1);
    std::cout << "Retornando valor para a busca do valor 1. " << std::endl ;
    std::cout << "Chave:" << it->first << " Valor:" << it->second << std::endl ;
    it++ ; 	
    std::cout << "Chave:" << it->first << " Valor:" << it->second << std::endl ;

    std::cout<<  "Tamanho: " << mapa.size() << std::endl ;


    for ( mapas::const_iterator it2 = mapa.find(1) ;  it2!=mapa.end() ; it2++ )
    {
        cupom.push_back(it2->second) ;
    }

    std::random_shuffle( cupom.begin() , cupom.end() );
    
    vector<int>::iterator it3 = cupom.begin() ;
    std::cout<< "Numero do cupom : " << *it3 << std::endl ;

    
    return 0 ;
    
}



