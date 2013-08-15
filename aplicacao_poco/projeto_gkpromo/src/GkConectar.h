

#ifndef _GKCONECTAR_H
#define	_GKCONECTAR_H

#include "Poco/Data/Session.h"
#include "Poco/Data/SessionPool.h"
#include "Poco/Data/Statement.h"
#include "Poco/Data/RecordSet.h"
#include "Poco/Data/MySQL/Connector.h"

#include "Poco/Data/DataException.h"
#include "Poco/Data/MySQL/MySQLException.h"
#include "Poco/Exception.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Format.h"

#include <iostream>
#include <string>
#include <map>

using namespace Poco::Data;
using namespace Poco::Data::MySQL;

using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Data::Statement;

#define RC_OK  0
#define RC_NOK 1

class GkConectar
{
public:
    GkConectar(std::string host, std::string usuario, std::string senha, std::string banco, int minimoConexoes, int maximoConexoes)
    {
        MySQL::Connector::registerConnector();
        dbConnString="user="+usuario+";"+"password="+senha+";"+"db="+banco+";"+"host="+host+";compress=true;auto-reconnect=true";
        _pool = new SessionPool ( MySQL::Connector::KEY, dbConnString, minimoConexoes, maximoConexoes );

        Application& app = Application::instance();
        app.logger().information( Poco::format("Conectando a : [%s]"  , dbConnString )  ) ;
    }

    ~GkConectar()
    {
        MySQL::Connector::unregisterConnector();
    }

    void dbBye()
    {
        MySQL::Connector::unregisterConnector();
    }

    std::string retornaConexao()
    {
        return dbConnString ; 
    }

    Session obterSessao()
    {
        return _pool->get();
    }

private:

    SessionPool *_pool;
    std::string dbConnString;
    
};

#endif

