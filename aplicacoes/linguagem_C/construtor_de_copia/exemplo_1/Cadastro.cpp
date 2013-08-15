/* 
 * File:   Cadastro.cpp
 * Author: lprates
 * 
 * Created on 9 de Novembro de 2009, 11:17
 */

#include "Cadastro.h"

Cadastro::Cadastro() {
    std::cout<< "Contrutor Cadastro" << std::endl ;
}

Cadastro::Cadastro(const Cadastro& orig) {
    std::cout<< "Utilizando contrutor de copia declarado" << std::endl ;
    nome=orig.nome;
    endereco=orig.endereco;
    telefone=orig.telefone;
}

Cadastro::~Cadastro() {
}

void Cadastro::setNome(std::string nome)
{
    this->nome=nome;
}
void Cadastro::setEndereco(std::string endereco)
{
    this->endereco=endereco;
}
void Cadastro::setTelefone(long int telefone)
{
    this->telefone=telefone;
}
std::string Cadastro::getNome()
{
    return this->nome;
}
std::string Cadastro::getEndereco()
{
    return this->endereco;
}
long int Cadastro::getTelefone()
{
    return this->telefone;
}


