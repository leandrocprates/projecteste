
#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/AutoPtr.h"
#include <iostream>
#include <string>

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

protected:	
	void initialize(Application& self)
	{
		loadConfiguration(); // load default configuration files, if present
		Application::initialize(self);

	    log_dir = config().getString("portability.log_dir");
	    trace_level = config().getInt("portability.trace_level");
	    db_user  = config().getString("portability.db_user");
	    db_password = config().getString("portability.db_password");
	    db_server = config().getString("portability.db_server");
	    db_name = config().getString("portability.db_name");
	    db_user_tmp = config().getString("portability.db_user_tmp");
	    db_password_tmp = config().getString("portability.db_password_tmp");
	    db_server_tmp = config().getString("portability.db_server_tmp");
	    db_name_tmp = config().getString("portability.db_name_tmp");
	    dir_arq_sucess = config().getString("portability.dir_arq_sucess");
	    dir_arq_error = config().getString("portability.dir_arq_error");
	    dir_arq_process = config().getString("portability.dir_arq_process");
		
		showVar();
	}
	
	void showVar()
	{
		cout<< "portability.log_dir:"     << log_dir     << endl;
		cout<< "portability.trace_level:" << trace_level << endl;
		cout<< "portability.db_user:"     << db_user << endl;
		cout<< "portability.db_password:" << db_password << endl;
		cout<< "portability.db_server:"   << db_server << endl;
		cout<< "portability.db_name:"     << db_name << endl;
		cout<< "portability.db_user_tmp:" << db_user_tmp << endl;
		cout<< "portability.db_password_tmp:" << db_password_tmp << endl;
		cout<< "portability.db_server_tmp:"   << db_server_tmp << endl;
		cout<< "portability.db_name_tmp:"     << db_name_tmp << endl;
		cout<< "portability.dir_arq_sucess:"  << dir_arq_sucess << endl;
		cout<< "portability.dir_arq_error:"   << dir_arq_error << endl;
		cout<< "portability.dir_arq_process:" << dir_arq_process << endl;
		
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

    string log_dir;
    int trace_level;
    string db_user;
    string db_password;
    string db_server;
    string db_name; 
    string db_user_tmp;
    string db_password_tmp;
    string db_server_tmp;
    string db_name_tmp;
    string dir_arq_sucess;
    string dir_arq_error;
    string dir_arq_process;

};


//POCO_APP_MAIN(configuracao)

int main(int argc, char** argv) 
{                                                                             
    Poco::AutoPtr<configuracao> pApp = new configuracao;   
    try                                                               
    {                                                                   
            pApp->init(argc, argv);                
    }                                                                      
    catch (Poco::Exception& exc)            
    {                                                                       
            pApp->logger().log(exc);               
            return Application::EXIT_CONFIG;
    }                                                                       
    return pApp->run();                                     
}




