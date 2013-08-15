
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

#include "Poco/Net/HTMLForm.h"
#include "Poco/NumberParser.h"
#include "Poco/URI.h"

#include <iostream>
#include "conectar.h"

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

using Poco::Net::HTMLForm;
using Poco::NumberParser;
using Poco::URI;
using Poco::Net::HTTPRequest;
using Poco::Thread;


class TimeRequestHandler: public HTTPRequestHandler
{
public:
	TimeRequestHandler(conectar *conexao)
	{
            this->conexao=conexao ;
	}
	
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
	{
		//Application& app = Application::instance();
		//app.logger().information("Request from " + request.clientAddress().toString());

                // formato para funcionar com get ou post
                HTMLForm form(request,request.stream() );

                long int numero_do_ticket = NumberParser::parse(form.get("number_ticket" ,"0" ) );
                long int acao = NumberParser::parse(form.get("action", "0" ) );
                long int operadora = NumberParser::parse(form.get("spid","0") );
                long int telefone = NumberParser::parse(form.get("phone","0") );

                conexao->setNumeroTicket(numero_do_ticket);
                conexao->setAcao(acao);
                conexao->setOperadora(operadora);
                conexao->setTelefone(telefone);
                
                conexao->determinaAcao();

                Application::instance().logger().information(Poco::format("Numero_do_ticket [%li]", conexao->getNumeroTicket() ));
                Application::instance().logger().information(Poco::format("Acao [%li]", conexao->getAcao() ));
                Application::instance().logger().information(Poco::format("Operadora [%li]", conexao->getOperadora() ));
                Application::instance().logger().information(Poco::format("Telefone [%li]", conexao->getTelefone() ));

                
                response.setChunkedTransferEncoding(false);
		response.setContentType("text/html");
                response.setStatus(HTTPServerResponse::HTTP_OK);

                
                std::ostream& ostr =response.send();
                
                ostr << "<html><head><title>Valores das Variaveis</title>";
                ostr << "<body>";
                ostr << " Numero do Ticket: " << conexao->getNumeroTicket() ;
                ostr << " Acao: " << conexao->getAcao() ;
                ostr << " Operadora: " << conexao->getOperadora() ;
                ostr << " Telefone: " << conexao->getTelefone() ;
                ostr << " host: " << host ;
                ostr << " usuario: " << usuario ;
                ostr << " senha: " << senha ;
                ostr << " banco: " << banco ;
                ostr << "</body></html>";

	}	
private:
        std::string host;
        std::string usuario;
        std::string senha;
        std::string banco;
        conectar *conexao;

};


class TimeRequestHandlerFactory: public HTTPRequestHandlerFactory
{
public:
	TimeRequestHandlerFactory(const std::string urlIncluir, const std::string urlDeletar , conectar *conexao )
	{
            urlInclusao =  urlIncluir ;
            urlDelete  = urlDeletar ;
            this->conexao=conexao ;
            
            Application::instance().logger().information("Ola estou dentro de TimeRequestHandlerFactory");
	}


	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
	{
                URI uri(request.getURI());

                Application::instance().logger().information(Poco::format("Url de entrada [%s]", uri.getPath() ));

		if ( ( uri.getPath() == urlInclusao ) || ( uri.getPath() == urlDelete ) )
                {
                    return new TimeRequestHandler(conexao);
                }
                else
                {
			return 0;
                }
	}
	
private:
        std::string urlInclusao ;
        std::string urlDelete ;
        conectar *conexao;
	
};


class HTTPTimeServer: public Poco::Util::ServerApplication
{
public:
	HTTPTimeServer(): _helpRequested(false)
	{
	}
	
	~HTTPTimeServer()
	{
	}

protected:
	void initialize(Application& self)
	{
		loadConfiguration(); 
		ServerApplication::initialize(self);
                urlInclusao  = config().getString("MeuWebServer.urlInclusao", "/incluir");
                urlDelete    = config().getString("MeuWebServer.urlDelete", "/deletar");
                logger().information("Inicializando a aplicacao");

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

                        /********pegando configuracoes do banco e dados******/
                        logger().information("Pegando as configuracoes do banco");

                        std::string host = config().getString("MeuWebServer.host" , "localhost");
                        std::string usuario = config().getString("MeuWebServer.usuario" , "******");
                        std::string senha = config().getString("MeuWebServer.senha" , "******");
                        std::string banco = config().getString("MeuWebServer.banco" , "******");
                        int minimoConexoes = config().getInt("MeuWebServer.minimoConexoes" , 1 );
                        int maximoConexoes = config().getInt("MeuWebServer.maximoConexoes" , 100 );

                        conectar conexao(host, usuario , senha , banco , minimoConexoes , maximoConexoes );
                        /************************************************/

			unsigned short port = (unsigned short) config().getInt("MeuWebServer.port", 9980);
			
			int maxQueued  = config().getInt("MeuWebServer.maxQueued", 2000);
			int maxThreads = config().getInt("MeuWebServer.maxThreads", 300);
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
			
			HTTPServer srv(new TimeRequestHandlerFactory(urlInclusao,urlDelete, &conexao ), svs, pParams);

			srv.start();
			
			waitForTerminationRequest();
			
			srv.stop();
		}
		return Application::EXIT_OK;
	}
	
private:
	bool _helpRequested;
        std::string urlInclusao ;
        std::string urlDelete ;


};

// acao com 0 incluir na base de dados acao com 1 deleta o numero de telefone 
//exemplo de como executar GET:
//wget -q -O-  "http://localhost:9980/incluir?action=0&number_ticket=15&spid=9&phone=22333018"
//wget -q -O-  "http://localhost:9980/incluir?action=0&number_ticket=15&spid=9"
//wget -q -O-  "http://localhost:9980/deletar?action=0&number_ticket=15"

//exemplo de como executar POST:
//wget -q -O-  "http://localhost:9980/incluir" --post-data="action=8&number_ticket=15"

//exemplo de GET com acao 1 :
//http://localhost:9980/deletar?action=1&number_ticket=30&spid=4&phone=22333018


int main(int argc, char** argv)
{
	HTTPTimeServer app;
	return app.run(argc, argv);
}

