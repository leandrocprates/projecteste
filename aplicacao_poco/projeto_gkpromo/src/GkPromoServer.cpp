
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Exception.h"
#include "Poco/ThreadPool.h"
#include "Poco/Thread.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"


#include "Poco/URI.h"
#include "Poco/Format.h"

#include <iostream>

#include "GkConfig.h"
#include "GkUrls.h"
#include "GkDadosPromocao.h"
#include "GkSeries.h"
#include "GkHandler.h"

using Poco::Net::ServerSocket;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;
using Poco::ThreadPool;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;

using Poco::URI;
using Poco::Net::HTTPRequest;
using Poco::Thread;



class GkPromoRequestHandler: public HTTPRequestHandler
{
public:
	GkPromoRequestHandler(GkConfig *gkconfig, GkConectar *connect_write, GkConectar *connect_read , GkUrls *gkurl , GkDadosPromocao *gkdados_promocao , GkSeries *gkseries  )
	{
            this->gkconfig=gkconfig ;
            this->connect_write=connect_write;
            this->connect_read=connect_read;
            this->gkdados_promocao=gkdados_promocao;
            this->gkurl=gkurl;
            this->gkseries=gkseries;
	}
	
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
	{
		Application& app = Application::instance();
                std::string resposta ;
                
		app.logger().information("Request from " + request.clientAddress().toString());

                // faz o tratamento da requisicao e gera os cupons e a resposta
                gkhandler = new GkHandler( gkconfig , connect_write , connect_read , gkurl , gkdados_promocao , gkseries  ) ;
                gkhandler->processarRequisicao( request , resposta  );

                delete (gkhandler);
                
                // resposta gerada
                response.setChunkedTransferEncoding(true);
		response.setContentType("text/html");
                response.setStatus(HTTPServerResponse::HTTP_OK);

                resposta="OK\n"; 

                std::ostream& ostr =response.send();
                ostr << resposta ;

	}
        
private:
	GkConfig *gkconfig;
        GkConectar *connect_write;
        GkConectar *connect_read;
        GkDadosPromocao *gkdados_promocao;
        GkUrls *gkurl;
        GkSeries *gkseries;
        GkHandler *gkhandler;

};


class GkPromoRequestHandlerFactory: public HTTPRequestHandlerFactory
{
public:
	GkPromoRequestHandlerFactory(GkConfig *gkconfig)
	{
            Application& app = Application::instance();

            this->gkconfig=gkconfig ;
            connect_write = new GkConectar( gkconfig->get_Host_Write() , gkconfig->get_Host_User() , gkconfig->get_Host_Passwd() , gkconfig->get_DB() , 1 , 30 );
            connect_read  = new GkConectar( gkconfig->get_Host_Read() , gkconfig->get_Host_User() , gkconfig->get_Host_Passwd() , gkconfig->get_DB() , 1 , 10 );
            
            app.logger().information("Ola estou dentro de GkPromoRequestHandlerFactory");

            gkurl = new GkUrls( connect_read->obterSessao() );
            gkdados_promocao = new GkDadosPromocao ( connect_read->obterSessao() ) ;


            if ( gkdados_promocao->getStatus() == GkDadosPromocao::ST_FINALIZADO )
            {
                app.logger().information("Promocao FINALIZADA. Processo nao ira subir!" );
                exit (-1);
            }
            
            gkseries = new GkSeries ( connect_read->obterSessao() , connect_write->obterSessao() , gkdados_promocao->getNomePromocao() );
            if ( gkseries->db_AjeitaSeries( gkdados_promocao->getSeriesIlimitadas() ) ||  gkseries->db_GetNumberOfSeries() )
            {
                exit (-1);
            }

            app.logger().information(Poco::format("Tipo de Emissao [%s]." , gkdados_promocao->getTipoEmissao() ));

            gkseries->db_CarregaSeries();
            //gkseries->imprimir_SeriesCarregadas();

            // carrega o gabarito em memoria para emitir cupons
            //gkseries->db_CarregaGabarito();
            
            
            app.logger().information(Poco::format("Promocao [%s] carregada com sucesso." , gkdados_promocao->getNomePromocao()  ));

	}

        
	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
	{
                URI uri(request.getURI());

                Application::instance().logger().information(Poco::format("Url de entrada [%s]", uri.getPath() ));


		if ( uri.getPath() != gkconfig->get_Url_Admin() )
                {
                    return new GkPromoRequestHandler( gkconfig , connect_write , connect_read , gkurl , gkdados_promocao , gkseries );
                }
                else
                {
			return 0;
                }
                
	}
	
private:
	GkConfig *gkconfig;
        GkConectar *connect_write;
        GkConectar *connect_read;
        GkDadosPromocao *gkdados_promocao;
        GkUrls *gkurl;
        GkSeries *gkseries;
};


class GkPromoServer: public Poco::Util::ServerApplication
{
public:
	GkPromoServer(): _helpRequested(false)
	{
	}
	
	~GkPromoServer()
	{
	}

protected:
	void initialize(Application& self)
	{
		loadConfiguration(); 
		ServerApplication::initialize(self);

                gkconfig.set_DB( config().getString("gkpromo.banco","" )  );
                gkconfig.set_Host_User( config().getString("gkpromo.usuario","" ) );
                gkconfig.set_Host_Passwd(config().getString("gkpromo.senha","" ) );
                gkconfig.set_Host_Read( config().getString("gkpromo.host_read","" ) );
                gkconfig.set_Host_Write( config().getString("gkpromo.host_write","" ) );

                gkconfig.set_Url_Admin( config().getString("gkpromo.url_admin","/admin/gkpromo" ) );
                gkconfig.set_Promo_Nome( config().getString("gkpromo.promo_nome", "" ) );
                
                logger().information("Inicializando a aplicacao");

                logger().information(Poco::format("Banco de Dados [%s]", gkconfig.get_DB() ));
                logger().information(Poco::format("Usuario do Banco [%s]", gkconfig.get_Host_User() ));
                logger().information(Poco::format("Senha do Banco [%s]", gkconfig.get_Host_Passwd() ));
                logger().information(Poco::format("Banco de Leitura [%s]", gkconfig.get_Host_Read() ));
                logger().information(Poco::format("Banco de Escrita [%s]", gkconfig.get_Host_Write() ));
                logger().information(Poco::format("Url de Administracao [%s]", gkconfig.get_Url_Admin() ));
                logger().information(Poco::format("Promo Nome [%s]", gkconfig.get_Promo_Nome() ));
                
	}
		
	void uninitialize()
	{
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet& options)
	{
		ServerApplication::defineOptions(options);
		
		options.addOption(
			Option("help", "h", "display help information on command line arguments")
				.required(false)
				.repeatable(false));
	}

	void handleOption(const std::string& name, const std::string& value)
	{
		ServerApplication::handleOption(name, value);

		if (name == "help")
			_helpRequested = true;
	}

	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("A web server that serves the current date and time.");
		helpFormatter.format(std::cout);
	}

	int main(const std::vector<std::string>& args)
	{
		if (_helpRequested)
		{
			displayHelp();
		}
		else
		{

			unsigned short port = (unsigned short) config().getInt("gkpromo.port", 8001);
			int maxQueued  = config().getInt("gkpromo.maxQueued", 2000);
			int maxThreads = config().getInt("gkpromo.maxThreads", 300);
			ThreadPool::defaultPool().addCapacity(maxThreads);
			
			HTTPServerParams* pParams = new HTTPServerParams;
			pParams->setMaxQueued(maxQueued);
			pParams->setMaxThreads(maxThreads);

                        pParams->setKeepAlive(true);
                        pParams->setKeepAliveTimeout(10);
                        pParams->setMaxKeepAliveRequests(0);
                        //pParams->setThreadIdleTime(10);
                        pParams->setThreadPriority(Thread::PRIO_NORMAL);
                        pParams->setSoftwareVersion("Versao 1.0");
                        pParams->setTimeout(30);
			
			
			ServerSocket svs(port);
			
			HTTPServer srv(new GkPromoRequestHandlerFactory(&gkconfig), svs, pParams);

			srv.start();
			
			waitForTerminationRequest();
			
			srv.stop();
		}
		return Application::EXIT_OK;
	}
	
private:
	bool _helpRequested;
        GkConfig gkconfig;

};


int main(int argc, char** argv)
{
	GkPromoServer app;
	return app.run(argc, argv);
}

