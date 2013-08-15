/* 
 * File:   Cadastro.h
 * Author: lprates
 *
 * Created on 9 de Novembro de 2009, 11:17
 */

#ifndef _CADASTRO_H
#define	_CADASTRO_H

#include <string>
#include <iostream>

class Cadastro {
public:
    Cadastro();
    Cadastro(const Cadastro& orig);
    virtual ~Cadastro();

    void setNome(std::string nome);
    void setEndereco(std::string endereco);
    void setTelefone(long int telefone);
    std::string getNome();
    std::string getEndereco();
    long int getTelefone();

private:
    std::string nome;
    std::string endereco;
    long int telefone;
};

#endif	/* _CADASTRO_H */

