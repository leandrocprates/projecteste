/* 
 * File:   Empresa.h
 * Author: lprates
 *
 * Created on 9 de Novembro de 2009, 12:42
 */

#ifndef _EMPRESA_H
#define	_EMPRESA_H
#include "Cadastro.h"

class Empresa : public Cadastro
{
public:
    Empresa();
    Empresa( const Empresa& orig);
    virtual ~Empresa();
    void setNomeEmpresa(std::string nomeEmpresa);
    std::string getNomeEmpresa();
    virtual void imprimir();
    void operator=(const Empresa &e);
    
private:
    std::string nomeEmpresa;

};

#endif	/* _EMPRESA_H */

