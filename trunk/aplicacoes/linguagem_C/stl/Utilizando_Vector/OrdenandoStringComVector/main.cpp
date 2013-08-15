/* 
 * File:   main.cpp
 * Author: leandro
 *
 * Created on 22 de Março de 2010, 05:50
 */

#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    std::vector<string> vetor ;

    vetor.push_back("Vanessa");
    vetor.push_back("Leandro");
    vetor.push_back("Ariane");

    for (std::vector<string>::iterator it = vetor.begin() ; it!=vetor.end() ; it++){
        std::cout << "Nome nao Ordenado: "<< *it <<std::endl;
    }

    std::sort(vetor.begin(),vetor.end());
    
    for (std::vector<string>::iterator it = vetor.begin() ; it!=vetor.end() ; it++){
        std::cout << "Nome Ordenado: "<< *it <<std::endl;
    }
    
    return (EXIT_SUCCESS);
}

