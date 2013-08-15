
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

#include "connect.h"

/****************************************************************************
 * Classe Generica implementando as funcoes de conexao ao MYSQL             *
 *                                                                          *
 ****************************************************************************/
connect::connect()
{
    inicializaObjeto();
}

connect::~connect()
{
    fechaConexao();
}

int connect::inicializaObjeto()
{
     if ( ( conexao = mysql_init(NULL) ) == NULL )
     {
         debug("Erro ao criar objeto sql para conexao.");
         return RC_NOK ;
     }
     return RC_OK ;
}

int connect::conectarBD(string host, string user, string passwd, string db, int port)
{
     if ( mysql_real_connect(conexao, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, NULL, 0) == NULL )
     {
         debug("Erro de conexao a base de dados: [%s]. Erro numero : [%d] , Mensagem : [%s]" , db.c_str() , mysql_errno(conexao), mysql_error(conexao) );
         exit (1) ;
     }

     if ( mysql_autocommit(conexao, 0) != RC_OK )
     {
         debug("Auto Commit nao desabilitado.");
     }

     debug("Conectado ao Banco de Dados.");
     return RC_OK ;

}
          
void connect::fechaConexao()
{
     mysql_close(conexao);
}

int connect::criaBancoDeDados(string db)
{
      string query;
      query="CREATE DATABASE " +db;

      if ( executarQuery(query) != RC_OK )
      {
           debug("Erro ao criar Banco de Dados: [%s]. Erro numero : [%d] , Mensagem : [%s]" , db.c_str() , mysql_errno(conexao), mysql_error(conexao) );
           return RC_NOK ;
      }
      debug("Banco de Dados: [%s] criado com sucesso." , db.c_str() );
      return RC_OK ;
}

int connect::deletaBancoDeDados(string db)
{
  string query;
  query="DROP DATABASE " +db;

  if ( executarQuery(query) != RC_OK )
  {
       debug("Erro ao deletar Banco de Dados: [%s]. Erro numero : [%d] , Mensagem : [%s]" , db.c_str() , mysql_errno(conexao), mysql_error(conexao) );
       return RC_NOK ;
  }
  debug("Banco de Dados: [%s] deletado com sucesso." , db.c_str() );
  return RC_OK ;
}

int connect::mudaDeBanco(string user, string passwd, string db)
{
  if (mysql_change_user(conexao, user.c_str(), passwd.c_str(), db.c_str()) != RC_OK )
  {
      debug("Erro ao tentar mudar de Banco de Dados. Erro numero : [%d] , Mensagem : [%s]" , mysql_errno(conexao), mysql_error(conexao) );
      return RC_NOK ;
  }
  debug("Mudanca de Banco de Dados efetuada com sucesso.");
  return RC_OK ;
}

int connect::verificaTipoDeCaracters()
{
  debug("Tipo de caracters da Conexao Atual [%s]." , mysql_character_set_name(conexao));
}

int connect::executarQuery(string query)
{
   if ( mysql_query(conexao, query.c_str() ) != RC_OK )
   {
       debug("Erro ao executar query: [%s]" , query.c_str() );
       return RC_NOK ;
   }
   return RC_OK ;
}
          
int connect::resgatarDados()
{
  if ( ( resultado = mysql_store_result(conexao) ) == NULL )
  {
       debug("Erro ao buscar dados. Erro numero : [%d] , Mensagem : [%s]" , mysql_errno(conexao) , mysql_error(conexao) );
       return RC_NOK ;
  }
  else if ( resultado == 0 )
  {
       debug("Consulta nao retornou resultados." );
  }
  else
  {
      numeroResultados();
  }
  return RC_OK ;
}

void connect::numeroResultados()
{
  debug("Obtidas [%lu] linhas." , mysql_num_rows(resultado) );
}

void connect::determinaNumeroDeColunas()
{
  debug("Numero de Colunas: [%lu] " , mysql_num_fields(resultado)  );
}

void connect::determinaNumeroDeRegistrosAfetados()
{
  debug("Numero de Registros Afetados [%ld] ." , (long) mysql_affected_rows(conexao) );
}
          
int connect::obterDados()
{
  if ( ( linha = mysql_fetch_row(resultado) ) == NULL )
  {
      debug("Fim dos dados.");
      mysql_free_result(resultado);
      return RC_NOK ;
  }
  return RC_OK ;
}

int connect::efetuaCommit()
{
  if ( mysql_commit(conexao) != RC_OK )
  {
       debug("Erro ao efetuar commit.");
       return RC_NOK ;
  }
  return RC_OK ;
}

int connect::efetuaRollback()
{
  if ( mysql_rollback(conexao) != RC_OK )
  {
       debug("Erro ao efetuar rollback da transacao.");
       return RC_NOK;
  }
  return RC_OK;
}

void connect::status()
{
   string stat = mysql_stat(conexao);
   debug("Imprimindo status da conexao: [%s]" , stat.c_str() );
}

