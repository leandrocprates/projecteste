/* 
 * File:   TesteClasseBaseDerivada.cpp
 * Author: leandro
 * 
 * Created on 5 de Agosto de 2012, 08:59
 */
#include <iostream>

using namespace std; 

class TesteClasseBaseDerivada 
{
public:
        TesteClasseBaseDerivada(){
            cout<<"Construtor TesteClasseBaseDerivada 1 " << endl; 
        }
    
        TesteClasseBaseDerivada(int i){
            cout<<"Construtor TesteClasseBaseDerivada 2 " << endl; 
            this->i=i;
        };
        int i;
};

class derived1 : virtual public TesteClasseBaseDerivada // derived1 inherits base as virtual.
{
public:
        derived1():TesteClasseBaseDerivada(111){
            cout<<"Construtor derived1 " << endl;
            j=11;
        };
        int j;
};

class derived2 : virtual public TesteClasseBaseDerivada // derived2 inherits base as virtual.
{
public:
        derived2():TesteClasseBaseDerivada(222){
            cout<<"Construtor derived2 " << endl;
            k=22;
        }
        int k;
};


class derived3 : public derived1, public derived2
{ 
public:
        derived3():TesteClasseBaseDerivada(333){
            cout<<"Construtor derived3 " << endl;
            sum = k+j+i;
            i= 334;
        }
        int sum;
};
        
