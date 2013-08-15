
// includes para gerar arquivo de log
#include "Poco/Logger.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Message.h"

// includes do programa
#include "conectar.h"
#include "processar.h"
#include "configuracao.cpp"

// includes do sistema
#include <iomanip>
#include <stdio.h>

#include "Poco/DateTime.h"

using Poco::DateTime;
using Poco::Logger;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using Poco::FileChannel;
using Poco::Message;

const string VERSAO="portabilidade-2.1.0";

int verifica_Processo()
{
  string comando ;
  FILE *f;
  char number[5];

  memset(number  , '\0' , sizeof(number));
  
  comando = "ps -ef | grep 'portabilidade' | grep -v 'portabilidade_' | grep -v 'portabilidade.' | grep -v grep | wc -l" ;

  if ( (f = popen (comando.c_str() , "r" )) == NULL )
  {
      puts ("Erro ao executar popen.\n");
  }

  fgets( number , sizeof(number)-1 , f );

  pclose (f);

  if ( atoi(number) > 1 )
  {
      puts("processo esta em execucao.\n" );
      exit(1);
  }

  return 0;
}

int main(int argc, char *argv[])
{
	//verifica se o processo esta em execucao	
	verifica_Processo();
	string cria_log;
        cout << VERSAO << endl ;

	//aqui carregar informacoes de arquivo de configuracao
	configuracao config;
	config.iniciar (argc, argv);

	DateTime now;
	ostringstream buffer;

	buffer << (argv[0]) << "_" << now.year() << setfill('0') << setw(2) << now.month() << setfill('0') << setw(2) << now.day() << ".log" ;

        cria_log = config.getLog_Dir();
        cria_log.append(buffer.str());

	//seta a data local para registar no log
	PatternFormatter *pattern = new PatternFormatter("%Y-%m-%d %H:%M:%S :%s:%q:%t") ; 
	pattern->setProperty("times", "local");
	FormattingChannel* pFCFile = new FormattingChannel(pattern);
	pFCFile->setChannel(new FileChannel(cria_log));
	pFCFile->open();

	Logger& fileLogger = Logger::create("Log", pFCFile, Message::PRIO_INFORMATION);

	fileLogger.information( fileLogger.format("--------- Execucao do programa [$0] iniciada. ---------" , VERSAO ) );

	//conecta nos bancos de dados
        conectar *conexao[config.getNumeroDeBancos()];

        // faz inicializacao para cada banco de dados
        for (int i=0  ; i<config.getNumeroDeBancos() ; i++)
        {
            conexao[i]= new conectar (config.getDb_Server(i), config.getDb_User(i), config.getDb_Password(i), config.getDb_Name(i), &fileLogger );
        }

        string diretorio(config.getDir_Arq_Proc());

	// processa o arquivo e cadastra os registros
	processar proc(&fileLogger);
	proc.processamento(conexao, &config ,diretorio);

        // desaloca vetor com as conexoes

	fileLogger.information(fileLogger.format("--------- Fim da Execucao do programa [$0]. -----------\n\n" , VERSAO ));

        return 0;

}


