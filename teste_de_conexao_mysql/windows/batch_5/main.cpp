#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>

extern "C" {
#include "mysql/mysql.h"
}

#define RC_OK   0 
#define RC_NOK  1

using namespace std;

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
          
          void inicializaObjeto() 
          {
             conexao = mysql_init(NULL);    
          } 

          void conectarBD( string host, string user, string passwd, string db , int port) 
          {
             if ( mysql_real_connect(conexao, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, NULL, 0) == NULL ) 
             {
                  cout << "Erro de conexao a base de dados." << mysql_errno(conexao) << mysql_error(conexao) <<  endl ; 
                  system("PAUSE");
                  //exit (1) ; 
             }

             if ( mysql_autocommit(conexao, 0) != RC_OK ) 
             {
                 cout << " auto commit nao desabilitado " << endl  ; 
             }  
             
             cout << "conectado ao banco de dados " << endl ; 
          }

          void fechaConexao()
          {
               mysql_close(conexao);
          }
    
          void executarQuery( string query ) 
          {
               if ( mysql_query(conexao, query.c_str() ) != RC_OK )
               {
                    cout << "Erro ao executar query :" << query << endl ; 
               }
          } 
          
          void resgatarDados()
          {
              if ( ( resultado = mysql_store_result(conexao) ) == NULL  ) 
              {
                   cout << "Erro ao buscar dados." << mysql_errno(conexao) << mysql_error(conexao) <<  endl ; 
              }
              else if ( resultado == 0 )
              {
                   cout << "Consulta nao retornou resultados." <<  endl ; 
              }
              else
              {
                  numeroResultados();
              }
          }
          
          void numeroResultados()
          {
              cout << "Obtidas [" << mysql_num_rows(resultado) << "] linhas" << endl ; 
          }
          
          void determinaNumeroDeColunas()
          {
              cout << "Numero de Colunas: [" <<  mysql_field_count(conexao) << "]" << endl ;  
          }
          
          int  obterDados()
          {
              if ( ( linha = mysql_fetch_row(resultado) ) == NULL ) 
              {
                  cout << "Fim dos dados ." << endl ; 
                  mysql_free_result(resultado);
                  return RC_NOK ; 
              } 
                 
              return RC_OK ;
          }

          
          void efetuaCommit()
          {
              if ( mysql_commit(conexao) != RC_OK ) 
              {
                   cout << "Erro ao efetuar commit." << endl  ; 
              }
          }
          
          int efetuaRollback()
          {
              if ( mysql_rollback(conexao) != RC_OK ) 
              {
                   cout << "Erro ao efetuar rollback da transacao" << endl ; 
                   return RC_NOK; 
              }
              return RC_OK;
          }
          
          void status()
          {
               stat = mysql_stat(conexao);
               cout << "Imprimindo status da conexao: " << endl ;  
               cout << "[" << stat << "]" << endl ;  
          }

          virtual void imprimir() = 0 ; 

      private:     
          MYSQL *conexao ;     
          MYSQL_RES *resultado;
          string stat ; 

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
                cout<< "**************************************************" << endl ; 
                cout<< "Nome do arquivo : ["     << dados->File_Name  << "]" << endl ; 
                cout<< "Data e hora : ["         << dados->Date_Hour  << "]" << endl ; 
                cout<< "Numero de registros : [" << dados->Number_Reg << "]" << endl ; 
                cout<< "Checksum : ["            << dados->Checksum   << "]" << endl ; 
                cout<< "**************************************************" << endl ;
                cout << endl << endl ; 
                delete dados ; 
           }

            
      private :
           portabilidade_arquivo *dados ;   
      
};


int main(int argc, char *argv[])
{
    operacao  *acesso ; 
    
    acesso = new operacao();
    
    acesso->conectarBD("localhost","root" , "", "portabilidade", 3306) ; 
    acesso->executarQuery("select *from arquivo") ; 
    acesso->resgatarDados(); 
    acesso->determinaNumeroDeColunas();

    while ( acesso->obterDados() == RC_OK ) 
    { 
        acesso->carregarDados();
        acesso->imprimir(); 
    }
    
    acesso->status(); 
    acesso->fechaConexao();
    system("PAUSE");
    return EXIT_SUCCESS;
}

