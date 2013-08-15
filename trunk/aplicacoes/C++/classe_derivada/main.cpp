/* 
 * File:   main.cpp
 * Author: leandro
 *
 * Created on 1 de Agosto de 2012, 07:19
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "ClasseBase.h"
#include "TesteClasseBaseDerivada.cpp"

using namespace std;

/*
int main(int argc, char** argv) {

    printf("Ola meu primeiro teste.\n");
    
    //ClasseBase c;
    //c.base();
      
    
    return 0;
}
*/

int main()
{
    /*
    derived3 ob;
    ob.i = 10; // now unambiguous
    ob.j = 20;
    ob.k = 30;
    ob.sum = ob.i + ob.j + ob.k;// unambiguous
    cout << ob.i << " ";// unambiguous
    cout << ob.j << " " << ob.k << " ";
    cout << ob.sum;
    return 0;
     */
    
    derived1 d1;
    cout<< "Derived 1 J:"<< d1.j << " I:" << d1.i << endl; 
    cout<< "====================================="<< endl; 
    
    derived2 d2;
    cout<< "Derived 2 K:"<< d2.k << " I:" << d2.i << endl; 
    cout<< "====================================="<< endl;
    
    derived3 d3;
    cout<< "Derived 3 J:"<<d3.j << " K:" << d3.k << " I:" <<d3.i << endl; 
    cout<<"Sum:" << d3.sum << endl;
    
    cout<<"Derived1 i : " << d3.derived1::i << " Derived2 i : " << d3.derived2::i << endl ; 
    
    
}


