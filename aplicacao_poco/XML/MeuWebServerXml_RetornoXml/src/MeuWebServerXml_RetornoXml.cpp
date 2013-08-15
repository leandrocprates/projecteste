

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
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"

#include <iostream>
#include <sstream>
#include "xmlResponse.h"


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


class TimeRequestHandler: public HTTPRequestHandler
{
public:
	TimeRequestHandler()
	{
	}
	
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
	{
		Application& app = Application::instance();
		app.logger().information("Request from " + request.clientAddress().toString());

		response.setChunkedTransferEncoding(false);
		response.setContentType("text/xml");

                std::ostringstream resposta;

                xmlResponse xml;

                xml.xmlWriteResponse(resposta);
                
		std::ostream& ostr = response.send();
                ostr << resposta.str() ;
                
	}
	
private:

};


class TimeRequestHandlerFactory: public HTTPRequestHandlerFactory
{
public:
	TimeRequestHandlerFactory()
	{
	}

	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
	{
		if (request.getURI() == "/")
			return new TimeRequestHandler();
		else
			return 0;
	}
	
private:

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
			unsigned short port = (unsigned short) config().getInt("MeuWebServerXml_RetornoXml.port", 9981);
			int maxQueued  = config().getInt("MeuWebServerXml_RetornoXml.maxQueued", 100);
			int maxThreads = config().getInt("MeuWebServerXml_RetornoXml.maxThreads", 16);
			ThreadPool::defaultPool().addCapacity(maxThreads);
			
			HTTPServerParams* pParams = new HTTPServerParams;
			pParams->setMaxQueued(maxQueued);
			pParams->setMaxThreads(maxThreads);
			
			ServerSocket svs(port);
			
			HTTPServer srv(new TimeRequestHandlerFactory(), svs, pParams);
			
			srv.start();
			
			waitForTerminationRequest();
			
			srv.stop();
		}
		return Application::EXIT_OK;
	}
	
private:
	bool _helpRequested;
};


int main(int argc, char** argv)
{
	HTTPTimeServer app;
	return app.run(argc, argv);
}
