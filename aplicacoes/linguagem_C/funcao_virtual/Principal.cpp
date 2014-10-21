/* 
 * File:   Principal.cpp
 * Author: lprates
 *
 * Created on 9 de Novembro de 2009, 11:31
 */

#include <stdlib.h>
#include "Empresa.h"

/*
 * 
 */
int main(int argc, char** argv) {

    Cadastro cadastro;
    cadastro.setNome("Leandro");
    cadastro.setEndereco("Av Joao Pessoa");
    cadastro.setTelefone(75016032);
    cadastro.imprimir();

    Cadastro cadastro2=cadastro;
    cadastro2.imprimir();

    std::cout<< "===========================================" << std::endl;

    Empresa empresa;
    empresa.setNome("Leandro");
    empresa.setEndereco("Vila Olimpia");
    empresa.setTelefone(30548602);
    empresa.setNomeEmpresa("Spring Wireless");
    empresa.imprimir();
    
    Empresa empresa2=empresa;
    empresa2.imprimir();


    std::cout<< "============Criando Objecto Dinamico=========" << std::endl;


    Empresa *empresa3=new Empresa;
    *empresa3=empresa;
    empresa3->imprimir();

    std::cout<< "=================POLIMORFISMO=======================" << std::endl;
    Cadastro *cadastro3=empresa3;
    cadastro3->imprimir();


    std::cout<< "=================Empresa::operator =   =======================" << std::endl;

    Empresa empresa4;
    empresa4=empresa;
    empresa4.imprimir();


    return (EXIT_SUCCESS);
}

