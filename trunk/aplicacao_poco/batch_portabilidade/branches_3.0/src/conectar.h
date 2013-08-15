#ifndef CONNECT
#define CONNECT

// includes para conexao com base de dados mysql 
#include "Poco/Data/MySQL/SessionImpl.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/Statement.h"
#include "Poco/Data/RecordSet.h"
#include "Poco/Data/MySQL/MySQLException.h"

// include do arquivo de log
#include "Poco/Logger.h"

// includes do sistema
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>

using namespace Poco::Data;
using namespace std;

using Poco::Logger;

#define RC_OK  0
#define RC_NOK 1
#define CREATE 0
#define DELETE 1

string montaString(const char *format , ...);

typedef struct  
{
	string nome_arquivo; 
	string data_geracao_arquivo;
	int numero_registro_arquivo;
	double numero_bilhete_portabilidade;
	int acao;
	double numero_telefone;
	int tipo_linha;
	int tipo_portabilidade;
	int spid; 
	int eot;
	string timestamp_ativacao;
	string timestamp_janela;
	string checksum;
} Tregistro;

class con 
{
	public: 
		con(string server, string user, string pwd, string dbname)
		{
			MySQL::Connector::registerConnector();
			dbConnString="user="+user+";"+"password="+pwd+";"+"db="+dbname+";"+"host="+server+";compress=true;auto-reconnect=true";
		}

		~con() 
		{
			MySQL::Connector::unregisterConnector();
		}

		string getdbConnString()
		{
			return dbConnString;
		}

	private: 
		std::string dbConnString;
};

class conectar : public con
{
     public:
		conectar(string server, string user, string pwd, string dbname , Logger *Log);
		~conectar() { } ;
		
		void inicioTransacao();
		void efetua_rollback();
		void efetua_commit();
		void dbClose();
		void dbInsert();
		int deletarRegistro(Tregistro *registro ); 
		int atualizarRegistro(Tregistro *registro);
		int inserirRegistro(Tregistro *registro);
		int inserirRegistroArquivo(Tregistro *registro);
		int inserirRegistroHistorico(Tregistro *registro);
		int selectRegistroArquivo(string &arquivo);
		long  searchRegisterDB(Tregistro *registro);
		int defineAction(Tregistro *registro);
		void imprimir(Tregistro *reg);

	private:
	    Session ses;
	    Logger *fileLogger;
};

#endif 
