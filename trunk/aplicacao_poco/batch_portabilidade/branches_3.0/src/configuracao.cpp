
#ifndef CONFIGURACAO
#define CONFIGURACAO

#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/AutoPtr.h"

#include <iostream>
#include <string>
#include <stdarg.h>
#include <sstream>
#include <cstdlib>

using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::AbstractConfiguration;
using Poco::Util::OptionCallback;
using Poco::AutoPtr;

using namespace std;

class configuracao: public Application
{
    public:
	configuracao(): _helpRequested(false)
	{
		
	}

	int iniciar (int argc, char** argv)
	{
	    try                                                               
	    {                                                                  
	           init(argc, argv);                
	    }                                                                      
	    catch (Poco::Exception& exc)            
	    {                                                                       
	            logger().log(exc);               
	            return Application::EXIT_CONFIG;
	    }                                                                       
	    return run();                                     
	}

	string getLog_Dir()
	{
		return param.log_dir; 
	}

	string getDb_User(int i)
	{
		return param.bd[i].db_user;
	}

	string getDb_Password(int i)
	{
		return param.bd[i].db_password;
	}

	string getDb_Server(int i)
	{
		return param.bd[i].db_server;
	}

        string getDb_Name(int i)
	{
		return param.bd[i].db_name;
	}

	string getDir_Arq_Proc()
	{
		return param.dir_arq_process;
	}

        string getTipo_Arquivo()
        {
            return param.tipo_arquivo;
        }

        int getNumeroDeBancos()
        {
                return param.numero_de_bancos;
        }


    protected:

        string formata(string palavra, int i)
        {
            ostringstream buffer;
            buffer << palavra << i ;
            return buffer.str();
        }

	void initialize(Application& self)
	{
		loadConfiguration(); 
		Application::initialize(self);

                param.log_dir = config().getString("portability.log_dir");
                param.trace_level = config().getInt("portability.trace_level");
                param.numero_de_bancos = config().getInt("portability.numero_de_bancos");
                param.tipo_arquivo = config().getString("portability.tipo_arquivo");

                param.bd = new bancos[param.numero_de_bancos];
                
                // carrega aqui no vetor alocado dados para n banco de dados
                for (int i =1 , t=0 ; i<= param.numero_de_bancos ; i++ , t++ )
                {
                    param.bd[t].db_user= config().getString( formata("portability.db_user_", i) );
                    param.bd[t].db_password = config().getString( formata("portability.db_password_", i) );
                    param.bd[t].db_server = config().getString( formata("portability.db_server_", i) );
                    param.bd[t].db_name = config().getString( formata("portability.db_name_", i) );

                }

                param.dir_arq_sucess = config().getString("portability.dir_arq_sucess");
                param.dir_arq_error = config().getString("portability.dir_arq_error");
                param.dir_arq_process = config().getString("portability.dir_arq_process");
		
	}
	
	
	void uninitialize()
	{
		Application::uninitialize();
	}
	
	void reinitialize(Application& self)
	{
		Application::reinitialize(self);
	}
	
	void defineOptions(OptionSet& options)
	{
		Application::defineOptions(options);

		options.addOption(
			Option("help", "h", "display help information on command line arguments")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<configuracao>(this, &configuracao::handleHelp)));

		options.addOption(
			Option("define", "D", "define a configuration property")
				.required(false)
				.repeatable(true)
				.argument("name=value")
				.callback(OptionCallback<configuracao>(this, &configuracao::handleDefine)));
				
		options.addOption(
			Option("config-file", "f", "load configuration data from a file")
				.required(false)
				.repeatable(true)
				.argument("file")
				.callback(OptionCallback<configuracao>(this, &configuracao::handleConfig)));

		options.addOption(
			Option("bind", "b", "bind option value to test.property")
				.required(false)
				.repeatable(false)
				.argument("value")
				.binding("test.property"));
	}
	
	void handleHelp(const std::string& name, const std::string& value)
	{
		_helpRequested = true;
		displayHelp();
		stopOptionsProcessing();
	}
	
	void handleDefine(const std::string& name, const std::string& value)
	{
		defineProperty(value);
	}
	
	void handleConfig(const std::string& name, const std::string& value)
	{
		loadConfiguration(value);
	}
	
	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("A sample application that demonstrates some of the features of the Poco::Util::Application class.");
		helpFormatter.format(std::cout);
	}
	
	void defineProperty(const std::string& def)
	{
		std::string name;
		std::string value;
		std::string::size_type pos = def.find('=');
		if (pos != std::string::npos)
		{
			name.assign(def, 0, pos);
			value.assign(def, pos + 1, def.length() - pos);
		}
		else name = def;
		config().setString(name, value);
	}

	int main(const std::vector<std::string>& args)
	{
		if (!_helpRequested)
		{
		
		}
		return Application::EXIT_OK;
	}


private:
	bool _helpRequested;

        struct bancos
        {
                string db_user;
                string db_password;
                string db_server;
                string db_name;
        };

        struct parametros
        {
            string log_dir;
            int trace_level;
            int numero_de_bancos;
            string tipo_arquivo;
            struct bancos *bd;
            string dir_arq_sucess;
            string dir_arq_error;
            string dir_arq_process;

        } param;

};

#endif

