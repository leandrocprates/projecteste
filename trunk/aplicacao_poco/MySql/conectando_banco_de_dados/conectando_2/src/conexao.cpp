

#include "Poco/Data/MySQL/SessionImpl.h"
#include "Poco/Data/SessionPool.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/Statement.h"

#include <mysql.h>
#include <iostream>
#include <string>

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
    std::string dbConnString_tmp = "user=root;password=;db=portabilidade2;host=localhost;compress=true;auto-reconnect=true";

    Session ses(MySQL::Connector::KEY, dbConnString );

    Session ses_tmp(MySQL::Connector::KEY, dbConnString_tmp );

    int count = 0;

    ses << "SELECT COUNT(*) FROM file", into(count), now;
    std::cout << "People in DB " << count << std::endl;

    Statement stmt = ( ses << "INSERT INTO file VALUES('ariane',22333018 )" );

    Statement stmt_emp = ( ses_tmp << "INSERT INTO file VALUES('vanessa',22333018 )" );

    stmt.execute();
    stmt_emp.execute();

    MySQL::Connector::unregisterConnector();

    shutdown();
}

