
/*Data de criacao : 24-01-2009
 *Nome do Criador : Leandro Cesar Prates
 *
 *Nome da Classe Principal : class connect
 *
 *Utilizacao : Criacao de uma classe generica em C++ para a conexao ao Banco
 *             de Dados MYSQL.
 *             Utilizar para a compilacao a libDebug onde sera escrito o log
 *             da aplicacao.
 *
 *Implementacao: Estender a Classe connect e implementar as funcoes especificas
 *               para manipulacao dos dados.
 *
 */

#ifndef CONNECT
#define CONNECT

// includes do sistema
#include <cstdlib>
#include <iostream>
#include <string>

// include pessoais
extern "C" {
#include "debug.h"
#include "mysql/mysql.h"
}

#define RC_OK   0 
#define RC_NOK  1

using namespace std;

/****************************************************************************
 * Classe Generica implementando as funcoes de conexao ao MYSQL             *
 *                                                                          *
 ****************************************************************************/
class connect
{
      public: 
              
          connect ();
          ~connect ();
          int inicializaObjeto();
          int conectarBD( string host, string user, string passwd, string db , int port);
          void fechaConexao();

          int criaBancoDeDados(string db);
          int deletaBancoDeDados(string db);
          int mudaDeBanco(string user, string passwd, string db);
          int verificaTipoDeCaracters();

          int executarQuery( string query );
          int resgatarDados();
          void numeroResultados();
          void determinaNumeroDeColunas();
          void determinaNumeroDeRegistrosAfetados();
          int obterDados();
          int efetuaCommit();
          int efetuaRollback();
          void status();

          virtual void imprimir() = 0 ; 

      private:     
          MYSQL *conexao ;     
          MYSQL_RES *resultado;
          
      protected:     
          MYSQL_ROW linha;
};

#endif
