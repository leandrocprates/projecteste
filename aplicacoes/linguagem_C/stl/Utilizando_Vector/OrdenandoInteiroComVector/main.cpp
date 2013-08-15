/* 
 * File:   main.cpp
 * Author: leandro
 *
 * Created on 22 de Março de 2010, 05:58
 */

#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    std::vector<int> vetor ;

    vetor.push_back(2);
    vetor.push_back(150);
    vetor.push_back(34);
    vetor.push_back(56);

    for (std::vector<int>::iterator it = vetor.begin() ; it!=vetor.end() ; it++){
        std::cout << "Inteiro nao Ordenado: "<< *it <<std::endl;
    }

    std::sort(vetor.begin(),vetor.end());

    for (std::vector<int>::iterator it = vetor.begin() ; it!=vetor.end() ; it++){
        std::cout << "Inteiro Ordenado: "<< *it <<std::endl;
    }

    return (EXIT_SUCCESS);
}

