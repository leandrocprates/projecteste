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

    std::cout<< "Nome :" << cadastro.getNome() << std::endl;
    std::cout<< "Endereco :" << cadastro.getEndereco() << std::endl;
    std::cout<< "Telefone :" << cadastro.getTelefone() << std::endl;

    //Cadastro cadastro2(cadastro);
    Cadastro cadastro2=cadastro;
    std::cout<< "Nome :" << cadastro2.getNome() << std::endl;
    std::cout<< "Endereco :" << cadastro2.getEndereco() << std::endl;
    std::cout<< "Telefone :" << cadastro2.getTelefone() << std::endl;

    std::cout<< "===========================================" << std::endl;

    Empresa empresa;
    empresa.setNome("Leandro");
    empresa.setEndereco("Vila Olimpia");
    empresa.setTelefone(30548602);
    empresa.setNomeEmpresa("Spring Wireless");

    std::cout<< "Nome :"     << empresa.getNome() << std::endl;
    std::cout<< "Endereco :" << empresa.getEndereco() << std::endl;
    std::cout<< "Telefone :" << empresa.getTelefone() << std::endl;
    std::cout<< "Empresa :"  << empresa.getNomeEmpresa() << std::endl;
    
    Empresa empresa2=empresa;

    std::cout<< "Nome :"     << empresa2.getNome() << std::endl;
    std::cout<< "Endereco :" << empresa2.getEndereco() << std::endl;
    std::cout<< "Telefone :" << empresa2.getTelefone() << std::endl;
    std::cout<< "Empresa :"  << empresa2.getNomeEmpresa() << std::endl;

    return (EXIT_SUCCESS);
}

