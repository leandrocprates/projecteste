

#include "Poco/Data/MySQL/SessionImpl.h"
#include "Poco/Data/SessionPool.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/Statement.h"

#include <mysql.h>
#include <iostream>
#include <string>

extern "C" {
#include "debug.h"
}

using namespace Poco::Data;

void init()
{
   MySQL::Connector::registerConnector();
}

void shutdown()
{
}

int main(int argc, char* argv[])
{
    init();

    std::string dbConnString = "user=root;password=;db=portabilidade;host=localhost;compress=true;auto-reconnect=true";

    Session ses(MySQL::Connector::KEY, dbConnString );
    int count = 0;

    ses << "SELECT COUNT(*) FROM file", into(count), now;
    std::cout << "People in DB " << count;

    Statement stmt = ( ses << "INSERT INTO file VALUES('leandro',75016032 )" ); 

    stmt.execute();

    MySQL::Connector::unregisterConnector();

    shutdown();

    startDebug("." , ".log" );

    debug("mais [%s] [%s] " , "um" , "teste" );

    debug("mais [%d] [%lf]" , 7 , 9.877 ); 

}

