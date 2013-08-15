
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

