
#ifndef PROCCESS
#define PROCCESS

#include "conectar.h"
#include "configuracao.cpp"
#include "obterArquivos.h"
#include <algorithm>
#include <exception>

// separa palavras em tokens
#include "Poco/StringTokenizer.h"
#include "Poco/DateTime.h"
#include "Poco/NumberParser.h"

using Poco::StringTokenizer;
using Poco::DateTime;
using Poco::NumberParser;

#define LEN_FILE 50

const int ACTION=0;
const int BASICA=0;
const int CNG=1;
const int DDR=2;
const int LSPP=0;
const int LISP=1;
const int DATAHORA=14;
const int TRAILLER=32;


class processar
{
	public:
		processar(Logger *Log)
		{
			fileLogger = Log ;
		}
		~processar() { }
		
		
		int validar_data(string data);
		int processaCabecalho(string cabecalho);
		int processaTrailler(string trailler);
		int determinaNumeroOcorrencias(string detalhe);
		int ehNumero(const char *numero);
		int validaTipoLinha( int tipo_linha );
		int validaTipoPortabilidade(int tipo_portabilidade);
		int validaAcao( int acao );
		int processaRegistro(string dados);
		int processarArquivo(string arquivo, string diretorio) ;
		int determinaArquivoSerProcessado( string nomeArquivoListado , string nomeArquivoBD, string diretorio );
		int processamento(conectar *con[] , configuracao *config , string diretorio );

        protected:
                Logger *obterLog ()
                {
                    return fileLogger;
                }

	private:
                
                conectar **conexao;
                configuracao *config;
		Tregistro registro;
		Logger *fileLogger;
		vector<string>  programasListados ; 
		
};

#endif 








