/* 
 * File:   main.cpp
 * Author: lprates
 *
 * Created on 8 de Agosto de 2012, 17:39
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <memory>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

 auto_ptr<int> p1 (new int);
  *p1.get()=10;

  auto_ptr<int> p2 (p1);

  if ( p2.get() == 0 ) {
      cout << "É nulo"<<endl ; 
  } else if (p2.get() != 0){
      cout << "Valor " << *p2.get() << " Endereço " << p2.get() <<endl  ; 
  }
  
  cout << "p2 points to " << *p2 << "\n";
    
  string valor1("");
  string valor2("teste");
  
  if ( valor1.compare(valor2) == 0 ){
      cout << "Valores iguais \n" ; 
  }else if ( valor1.empty() ) { 
      cout << "Valor vazio \n" ; 
  } else { 
      cout << "Diferentes \n" ; 
  }
  
  if ( valor1.size() ==0 ) {
      cout << "Valor zerado\n" ; 
  } else {
      cout << "Valor :" << valor1.size() << "\n"; 
  }
  
  string valor3="";
  string valor4="";
  
  if ( valor3 == valor4 ){
      cout << "Valores iguais \n" ; 
  } else {
      cout << "Diferentes \n" ; 
  }
  
  if (valor3.empty() ){
      cout << "valor 3 vazio \n" ; 
  }
      
  
  return 0;
}

