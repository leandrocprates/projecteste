/* 
 * File:   GkParametros.h
 * Author: amazon
 *
 * Created on 12 de Junho de 2009, 16:19
 */

#ifndef _GKPARAMETROS_H
#define	_GKPARAMETROS_H

#include <string>
#include <iostream>

typedef struct  {

public:
    void setPromocao(std::string &promocao)
    {
        this->promocao=promocao;
    }
    std::string getPromocao()
    {
        return this->promocao;
    }

    void setIdentificador(std::string &ident)
    {
        this->ident=ident;
    }
    std::string getIdentificador()
    {
        return this->ident;
    }

    void setInfo(std::string &info)
    {
        this->info=info;
    }
    std::string getInfo()
    {
        return this->info;
    }

    void setFiltro(std::string &filtro)
    {
        this->filtro=filtro;
    }
    std::string getFiltro()
    {
        return this->filtro;
    }
    
    void setNome_Super_Grupo(std::string &nome_super_grupo)
    {
        this->nome_super_grupo=nome_super_grupo;
    }
    std::string getNome_Super_Grupo()
    {
        return this->nome_super_grupo;
    }

    void setIdTipo(int &idtipo)
    {
        this->idtipo=idtipo;
    }
    int getIdTipo()
    {
        return this->idtipo;
    }

    void setQtde(unsigned &qtde)
    {
        this->qtde=qtde;
    }
    unsigned getQtde()
    {
        return this->qtde;
    }

    void setIndice(int &indice)
    {
        this->indice=indice;
    }
    int getIndice()
    {
        return this->indice;
    }

    void setListar(int &listar)
    {
        this->listar=listar;
    }
    int getListar()
    {
        return this->listar;
    }

    void setOrdem(int &ordem)
    {
        this->ordem=ordem;
    }
    int getOrdem()
    {
        return this->ordem;
    }

    void setSi(int &si)
    {
        this->si=si;
    }
    int getSi()
    {
        return this->si;
    }

    void setSf(int &sf)
    {
        this->sf=sf;
    }
    int getSf()
    {
        return this->sf;
    }

    void setSlist(std::string &slist)
    {
        this->slist=slist;
    }
    std::string getSlist()
    {
        return this->slist;
    }


private:
    std::string promocao;
    std::string ident;
    std::string info;
    std::string filtro;
    std::string nome_super_grupo;
    int  idtipo;
    unsigned qtde;
    int  indice;
    int  listar;
    int  ordem;
    int  si;
    int  sf;
    std::string slist;
} GkParams ;


/* Parametros da requisicao
 **********************************************/
#define PARAM_PROMOCAO      "promo"
#define PARAM_IDENT         "id"
#define PARAM_INFO          "info"
#define PARAM_INDICE        "i"
#define PARAM_QTDE          "qtde"
#define PARAM_IDTIPO        "idtipo"
#define PARAM_FILTRO        "filtro"
#define PARAM_LISTAR        "listar"
#define PARAM_SI            "si"
#define PARAM_SF            "sf"
#define PARAM_SLIST         "slist"
#define PARAM_ORDEM         "ordem"
#define PARAM_SGRUPO        "sgrupo"


/* Codigo de erro
 **********************************************************/
#define RET_OK                            0
#define RET_NOK                           -1
#define MAKE_NUMBER_IN_DB                 -10
#define ERR_HTTP_OK                       200
#define ERR_HTTP_BAD_REQUEST              400
#define ERR_HTTP_FORBIDDEN                403
#define ERR_HTTP_NOT_FOUND                404
#define ERR_HTTP_METHOD_NOT_ALLOWED       405
#define ERR_HTTP_LENGTH_REQUIRED          411
#define ERR_HTTP_INTERNAL_SERVER_ERROR    500
#define ERR_HTTP_SERVICE_UNAVAILABLE      503
#define ERR_HTTP_GATEWAY_TIMEOUT          504

/* Tipo de Emissao
 **********************************************************/
#define TIPO_SSIMPLES       "salto_simples"
#define TIPO_SSERIES        "salto_entre_series"
#define TIPO_ALEATORIOV     "aleatorio_v"
#define TIPO_ALEATORIOH     "aleatorio_h"
#define TIPO_INTERVALO      "intervalo"

/* Id Tipo Verifica entrada do campo id 
 **********************************************************/
#define IDTIPO_STR_FONE     "fone"
#define IDTIPO_STR_EXTERN   "extern"

#define IDTIPO_FONE         1
#define IDTIPO_EXTERN       2




#endif	/* _GKPARAMETROS_H */

