/* 
 * File:   ClasseBase.cpp
 * Author: leandro
 * 
 * Created on 4 de Agosto de 2012, 10:29
 */

#include "ClasseBase.h"

ClasseBase::ClasseBase() {
    printf("Classe - ClasseBase\n");
}

ClasseBase::ClasseBase(const ClasseBase& orig) {
}

ClasseBase::~ClasseBase() {
}

void ClasseBase::base(){
    printf("Chamada da funcao base()");
}