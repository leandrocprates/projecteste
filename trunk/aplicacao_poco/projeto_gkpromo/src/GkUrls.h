/* 
 * File:   GkUrls.h
 * Author: amazon
 *
 * Created on 30 de Maio de 2009, 16:13
 */

#ifndef _GKURLS_H
#define	_GKURLS_H

#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Application.h"
#include "Poco/Format.h"

#include "GkConectar.h"

using Poco::Util::ServerApplication;
using Poco::Util::Application;


class GkUrls
{

public :

    GkUrls( Session ses ):sessao(ses)
    {
        int ret=0;
        Application& app = Application::instance();

        gkurl.clear();

        if ( ( ret = busca_Url() ) == 0  )
        {
            app.logger().information( "Nenhuma Url cadastrada na tabela gkurl." ) ;
            //Application::EXIT_SOFTWARE;
        }
        else if (ret < 0 )
        {
            app.logger().information( "Erro ao buscar Urls cadastradas na tabela gkurl." ) ;
            //Application::EXIT_SOFTWARE;
        }

    };

    int busca_Servico(const std::string &url , int &num_param );
    int busca_Url();

private :

    Session sessao ;
    
    typedef struct
    {
        std::string url ;
        int num_param;
    } Tgkconfig_gkurl ;

    typedef std::map < std::string , int > mapas;
    mapas gkurl;

};


#endif	/* _GKURLS_H */

