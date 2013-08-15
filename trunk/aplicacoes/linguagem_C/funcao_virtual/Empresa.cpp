/* 
 * File:   Empresa.cpp
 * Author: lprates
 * 
 * Created on 9 de Novembro de 2009, 12:42
 */

#include "Empresa.h"

Empresa::Empresa() {
    std::cout<< "Contrutor Empresa" << std::endl ;
}

Empresa::Empresa( const Empresa& orig):Cadastro(orig)
{
    std::cout<< "Utilizando contrutor de copia declarado : Empresa" << std::endl ;
    this->nomeEmpresa=orig.nomeEmpresa;
}

Empresa::~Empresa() {
}

void Empresa::setNomeEmpresa(std::string nomeEmpresa)
{
    this->nomeEmpresa=nomeEmpresa;
}
std::string Empresa::getNomeEmpresa()
{
    return this->nomeEmpresa;
}

void Empresa::imprimir()
{
    Cadastro::imprimir();
    std::cout<< "Empresa :"  << getNomeEmpresa() << std::endl;
}

void Empresa::operator=(const Empresa &e)
{
    setNome("1");
    setEndereco("2");
    setTelefone(3);
    this->nomeEmpresa=e.nomeEmpresa;
}


