/* 
 * File:   GkHandler.h
 * Author: amazon
 *
 * Created on 12 de Junho de 2009, 18:08
 */

#ifndef _GKHANDLER_H
#define	_GKHANDLER_H

#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/NumberParser.h"
#include "Poco/URI.h"

// tratamento de excecao
#include "Poco/Exception.h"

#include "GkConfig.h"
#include "GkUrls.h"
#include "GkDadosPromocao.h"
#include "GkSeries.h"
#include "GkParametros.h"

using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTMLForm;
using Poco::NumberParser;
using Poco::URI;


class GkHandler
{
public:
    
    GkHandler(  GkConfig *gkconfig, GkConectar *connect_write, GkConectar *connect_read , GkUrls *gkurl , GkDadosPromocao *gkdados_promocao , GkSeries *gkseries  )
    {
        Application& app = Application::instance();
        app.logger().information("Dentro do construtor GkHandler.");
        this->gkconfig=gkconfig ;
        this->connect_write=connect_write;
        this->connect_read=connect_read;
        this->gkdados_promocao=gkdados_promocao;
        this->gkurl=gkurl;
        this->gkseries=gkseries;
        
    }
    
    ~GkHandler(){};

    int processarRequisicao( HTTPServerRequest &request , std::string &resposta );
    int getParams(HTTPServerRequest &request);
    void imprimeParams();

    void obterCupom(std::string &resposta);
    int verificaEntradas();

    // verifica e valida identificador da requisicao
    void verifyIdent();
    bool isValidExtern();
    bool isValidPhone();

    
private:
	GkConfig *gkconfig;
        GkConectar *connect_write;
        GkConectar *connect_read;
        GkDadosPromocao *gkdados_promocao;
        GkUrls *gkurl;
        GkSeries *gkseries;
        GkParams gkparams;
        HTTPServerRequest *request ; 

};


#endif	/* _GKHANDLER_H */

