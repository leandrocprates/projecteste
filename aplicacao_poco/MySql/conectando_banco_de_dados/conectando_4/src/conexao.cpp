

#include "Poco/Data/MySQL/SessionImpl.h"
#include "Poco/Data/SessionPool.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/Statement.h"
#include "Poco/Data/MySQL/MySQLException.h"

#include <mysql.h>
#include <iostream>
#include <string>

using namespace Poco::Data;
using namespace std;

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


// esta implementacao esta correta e como deve ficar no programa
//    ses.begin();
//    ses << "INSERT INTO file VALUES ( 'meu teste' , '2108-02-10 00:00:00' , 9 , 'ofnf' ) " , now ; 
//    ses.commit();
//    ses.rollback();
     
// try {
//    ses.begin(); 
//    ses << "INSERT INTO meu VALUES ( 'meu teste' , '2108-02-10 00:00:00' , 9 , 'ofnf' ) " , now ;
//    ses.commit();
//}
//catch ( MySQL::MySQLException &e ) 
//{
//    cout << "	exception" << endl ;  
//}


    try {

    ses.begin();
    Statement stmt = ( ses << "INSERT INTO file VALUES('ariane',22333018 )" );
    stmt.execute();

    }catch ( MySQL::MySQLException &e )
    {
        cout << " exception" << endl ;
        ses.rollback();
    }

    //ses.commit();
    ses.rollback();

    MySQL::Connector::unregisterConnector();

    shutdown();
} // fim main

