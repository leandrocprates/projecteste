
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

#include <cstdlib>
#include <iostream>
#include <string>

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
              
          connect ()
          {
             inicializaObjeto();
          }
          
          ~connect ()
          {
             fechaConexao();
          }
          
          int inicializaObjeto()
          {
             if ( ( conexao = mysql_init(NULL) ) == NULL )
             {
                 debug("Erro ao criar objeto sql para conexao.");
                 return RC_NOK ;
             }
             return RC_OK ;
          }

          int conectarBD( string host, string user, string passwd, string db , int port)
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

          void fechaConexao()
          {
               mysql_close(conexao);
          }

          int criaBancoDeDados(string db)
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

          int deletaBancoDeDados(string db)
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

          int mudaDeBanco(string user, string passwd, string db)
          {
              if (mysql_change_user(conexao, user.c_str(), passwd.c_str(), db.c_str()) != RC_OK )
              {
                  debug("Erro ao tentar mudar de Banco de Dados. Erro numero : [%d] , Mensagem : [%s]" , mysql_errno(conexao), mysql_error(conexao) );
                  return RC_NOK ;
              }
              debug("Mudanca de Banco de Dados efetuada com sucesso.");
              return RC_OK ;
          }

          int verificaTipoDeCaracters()
          {
              debug("Tipo de caracters da Conexao Atual [%s]." , mysql_character_set_name(conexao));
          }


          int executarQuery( string query )
          {
               if ( mysql_query(conexao, query.c_str() ) != RC_OK )
               {
                   debug("Erro ao executar query: [%s]" , query.c_str() );
                   return RC_NOK ;
               }
               return RC_OK ;
          }
          
          int resgatarDados()
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
          
          void numeroResultados()
          {
              debug("Obtidas [%lu] linhas." , mysql_num_rows(resultado) );
          }
          
          void determinaNumeroDeColunas()
          {
              debug("Numero de Colunas: [%lu] " , mysql_num_fields(resultado)  );
          }


          void determinaNumeroDeRegistrosAfetados()
          {
              debug("Numero de Registros Afetados [%ld] ." , (long) mysql_affected_rows(conexao) );
          }
          
          int obterDados()
          {
              if ( ( linha = mysql_fetch_row(resultado) ) == NULL )
              {
                  debug("Fim dos dados.");
                  mysql_free_result(resultado);
                  return RC_NOK ;
              }
              return RC_OK ;
          }

          
          int efetuaCommit()
          {
              if ( mysql_commit(conexao) != RC_OK ) 
              {
                   debug("Erro ao efetuar commit.");
                   return RC_NOK ;
              }
              return RC_OK ;
          }
          
          int efetuaRollback()
          {
              if ( mysql_rollback(conexao) != RC_OK )
              {
                   debug("Erro ao efetuar rollback da transacao.");
                   return RC_NOK; 
              }
              return RC_OK;
          }
          
          void status()
          {
               string stat = mysql_stat(conexao);
               debug("Imprimindo status da conexao: [%s]" , stat.c_str() );
          }

          virtual void imprimir() = 0 ; 

      private:     
          MYSQL *conexao ;     
          MYSQL_RES *resultado;
          

      protected:     
          MYSQL_ROW linha;
          
};


struct portabilidade_arquivo
{
       string File_Name ; 
       string Date_Hour ;
       long   Number_Reg ; 
       string Checksum ; 
};


/****************************************************************************
 * Esta classe seria um exemplo de classe que deve extender classe connect  *
 * e implementar as funcoes especificas para sua utilizacao                 *
 ****************************************************************************/
class operacao : public connect 
{
      public : 

           operacao()
           {
           }  

           ~operacao()
           {
           }  

           void carregarDados()
           {
                 dados = new portabilidade_arquivo ;
                 dados->File_Name =  linha[0];
                 dados->Date_Hour =  linha[1];
                 dados->Number_Reg =  atoi(linha[2] ) ;
                 dados->Checksum =  linha[3];
           }

           void imprimir()
           {
                debug("**************************************************");
                debug("Nome do arquivo : [%s] "      , dados->File_Name.c_str() ) ;
                debug("Data e hora : [%s] "          , dados->Date_Hour.c_str() ) ;
                debug("Numero de registros : [%ld] " , dados->Number_Reg        ) ;
                debug("Checksum : [%s] "             , dados->Checksum.c_str()  ) ;
                debug("**************************************************");

                delete dados ; 
           }

            
      private :
           portabilidade_arquivo *dados ;   
      
};


int main(int argc, char *argv[])
{
    operacao  *acesso ; 
    
    acesso = new operacao();

    // cria o arquivo de log para a gravacao (libdebug)
    startDebug("." , ".log" );
    debug("Iniciando execucao do programa.");

    // cria conexao com o banco de dados 
    acesso->conectarBD("localhost","root" , "", "portabilidade", 3306);

    // cria banco de dados utilizando a classe generica "connect"
    acesso->criaBancoDeDados("Banco_De_Teste");

    // funcao criada para deletar banco de dados utilizando a classe generica "connect"
    //acesso->deletaBancoDeDados("Banco_De_Teste");

    // faz a selecao e carregamento dos dados utilizando a classe generica connect
    acesso->executarQuery("select *from arquivo");
    acesso->resgatarDados(); 
    acesso->determinaNumeroDeColunas();
    acesso->determinaNumeroDeRegistrosAfetados();

    
    // neste trecho os dados sao carregados um a um utilizando a funcao da classe
    // generica "connect" e preenchidos na funcao carregarDados implementada
    // na classe especifica "operacao".
    // A funcao imprimir tambem da classe especifica "operacao" imprime os dados
    // no arquivo de log criado 
    while ( acesso->obterDados() == RC_OK )
    {
        acesso->carregarDados();
        acesso->imprimir();
    }

    // imprime o status da conexao atual
    acesso->status();

    // funcao usada para mudar de banco de dados utilizando classe generica connect
    acesso->mudaDeBanco("root", "" , "portabilidade2");
    
    // exemplo de insercao de dados utilizando classe generica connect
    acesso->executarQuery("INSERT INTO arquivo VALUES('BDT_2.txt' , now() , 10 , 'ttes' ); ");
    acesso->efetuaCommit();

    // retorna tipo de caracters usado na oxenxao atual utilizando classe generica connect
    acesso->verificaTipoDeCaracters();


    // fechando conexao com o banco 
    acesso->fechaConexao();

    return EXIT_SUCCESS;
}

