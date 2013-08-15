
#include "Poco/Data/Session.h"
#include "Poco/Data/SessionPool.h"
#include "Poco/Data/Statement.h"
#include "Poco/Data/MySQL/Connector.h"

#include "Poco/Data/DataException.h"
#include "Poco/Data/MySQL/MySQLException.h"

#include <iostream>
#include <string>

using namespace Poco::Data;
using namespace Poco::Data::MySQL;

#define RC_OK  0
#define RC_NOK 1

class conectar
{
public:
    conectar(std::string host, std::string usuario, std::string senha, std::string banco, int minimoConexoes, int maximoConexoes)
    {
        MySQL::Connector::registerConnector();
        dbConnString="user="+usuario+";"+"password="+senha+";"+"db="+banco+";"+"host="+host+";compress=true;auto-reconnect=true";
        _pool = new SessionPool ( MySQL::Connector::KEY, dbConnString, minimoConexoes, maximoConexoes );
    }

    ~conectar()
    {
        MySQL::Connector::unregisterConnector();
    }

    void setNumeroTicket(long int numero_do_ticket)
    {
        this->numero_do_ticket=numero_do_ticket;
    }

    void setAcao(long int acao)
    {
        this->acao=acao;
    }

    void setOperadora(long int operadora)
    {
        this->operadora=operadora;
    }

    void setTelefone(long int telefone)
    {
        this->telefone=telefone;
    }


    long int getNumeroTicket()
    {
        return numero_do_ticket;
    }

    long int getAcao()
    {
        return acao;
    }

    long int getOperadora()
    {
        return operadora;
    }

    long int getTelefone()
    {
        return telefone;
    }

    int  inserirRegistro();
    int  deletarRegistro();
    void determinaAcao();

    std::string retornaConexao()
    {
        return dbConnString ; 
    }


private:

    long int numero_do_ticket ;
    long int acao ;
    long int operadora ;
    long int telefone ;

    SessionPool *_pool;
    std::string dbConnString;

};

