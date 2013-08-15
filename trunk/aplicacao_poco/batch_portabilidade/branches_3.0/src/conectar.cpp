
#include "conectar.h"
#include <stdarg.h>
#include <sstream>

string montaString(const char *format , ...)
{
    ostringstream stream;
    char buffer[500];
	
    va_list args;
    va_start(args, format);
    vsprintf( buffer , format  , args );    
    va_end (args);	
	
    stream << buffer ;
    return stream.str();
}

conectar::conectar(string server, string user, string pwd, string dbname , Logger *Log ): con( server,  user,  pwd,  dbname) , ses( MySQL::Connector::KEY, getdbConnString() )
{
    fileLogger = Log ;
    fileLogger->information( fileLogger->format("Conectado a: [$0]" , getdbConnString() ) ) ;	
}

void conectar::inicioTransacao()
{
	ses.begin();
}

void conectar::efetua_rollback()
{
    ses.rollback();
}

void conectar::efetua_commit()
{
    ses.commit();
}

void conectar::imprimir(Tregistro *reg)
{

    fileLogger->information( montaString("numero do bilhete: [%lf]." , reg->numero_bilhete_portabilidade ) ) ;
    fileLogger->information( montaString("numero da acao: [%d]. "    , reg->acao ) ) ;	
    fileLogger->information( montaString("telefone: [%lf]. "         , reg->numero_telefone  ) ) ;
    fileLogger->information( montaString("tipo de linha: [%d]. "     , reg->tipo_linha  ) ) ;
    fileLogger->information( montaString("tipo de portabilidade: [%d]. ", reg->tipo_portabilidade   ) ) ;
    fileLogger->information( montaString("spid: [%d]. "              , reg->spid ) ) ;    
    fileLogger->information( montaString("eot: [%d]. "               , reg->eot  ) ) ;
    fileLogger->information( fileLogger->format("timestamp_ativacao: [$0]. " , reg->timestamp_ativacao  ) ) ;    
    fileLogger->information( fileLogger->format("timestamp_janela: [$0]. "   , reg->timestamp_janela   ) ) ;
    fileLogger->information( fileLogger->format("nome_arquivo: [$0]. "       , reg->nome_arquivo ) ) ;

}

int conectar::deletarRegistro(Tregistro *registro )
{
    char query[2000];
	
    memset (query , '\0', sizeof(query));
    
    snprintf(query, sizeof(query) , "delete from register WHERE Phone_Number = '%lf' " , registro->numero_telefone );
	
    fileLogger->information(fileLogger->format("Query: [$0]", query ));

   try 
   {
		Statement stmt = ( ses << query );
		stmt.execute();
   }
   catch (MySQL::MySQLException &e)
   {
	    fileLogger->information("Erro ao deletar na base de dados register." );   	
	    return RC_NOK;
   }
       
   return RC_OK;
}

int conectar::atualizarRegistro(Tregistro *registro)
{
    char query[2000];
	
    memset ( query , '\0' , sizeof(query));
	

	snprintf(query, sizeof(query) , "UPDATE  register SET  Number_Ticket = '%lf' , Action = '%d' , Phone_Number = '%lf' , "
    "Type_Line  = '%d' , Type_Portability = '%d' , SPID = '%d' , EOT = '%d' , Timestamp_Activ =  '%s' , Timestamp_Begin = '%s' , " 
    "  File_Name = '%s' WHERE  Phone_Number = '%lf' " , registro->numero_bilhete_portabilidade ,  registro->acao ,
            registro->numero_telefone , registro->tipo_linha , registro->tipo_portabilidade,  registro->spid , registro->eot,
            registro->timestamp_ativacao.c_str()  , registro->timestamp_janela.c_str() , registro->nome_arquivo.c_str() , registro->numero_telefone ) ;

	fileLogger->information(fileLogger->format("Query: [$0]", query ) );

   try 
   {
		Statement stmt = ( ses << query );
		stmt.execute();
   }	
   catch (MySQL::MySQLException &e)
   {
	    fileLogger->information("Erro ao atualizar na base de dados register." );
	    return RC_NOK;   	
   }


    return RC_OK ;

}

int conectar::inserirRegistro(Tregistro *registro)
{
    char query[2000];
	
    memset ( query , '\0' , sizeof(query));	

	
	snprintf(query, sizeof(query) , "INSERT INTO  register ( Number_Ticket , Action , Phone_Number , Type_Line , " 
     " Type_Portability ,  SPID ,  EOT  ,  Timestamp_Activ , Timestamp_Begin ,  File_Name  )  VALUES (  '%lf' ,  '%d' , '%lf' , " 
     "  '%d'  , '%d'  , '%d' , '%d' ,  '%s' ,  '%s' , '%s'  ) " , registro->numero_bilhete_portabilidade ,  registro->acao , 
        registro->numero_telefone , registro->tipo_linha , registro->tipo_portabilidade,  registro->spid , registro->eot, 
        registro->timestamp_ativacao.c_str()  , registro->timestamp_janela.c_str() , registro->nome_arquivo.c_str() );

	fileLogger->information(fileLogger->format("Query: [$0]", query ) );

   try 
   {
		Statement stmt = ( ses << query );
		stmt.execute();
   }
   catch (MySQL::MySQLException &e)
   {
	    fileLogger->information("Erro ao inserir na base de dados register." );
	    return RC_NOK;
   }
   
   return RC_OK ;

}

int conectar::inserirRegistroArquivo(Tregistro *registro)
{
    char query[2000];

    memset(query,'\0', sizeof(query)); 

	snprintf(query, sizeof(query) ,  " INSERT INTO  file ( File_Name , Date_Hour , Number_Reg , Checksum ) "
      " VALUES (  '%s' ,  '%s' , '%d' , '%s'  ) " ,  registro->nome_arquivo.c_str() ,  registro->data_geracao_arquivo.c_str() ,  
      registro->numero_registro_arquivo  , registro->checksum.c_str() ) ;

	fileLogger->information(fileLogger->format("Query: [$0]", query ) );
	
   try 
   {
	    Statement stmt = ( ses << query );
	    stmt.execute();
   }
   catch (MySQL::MySQLException &e)
   {
	    fileLogger->information("Erro ao inserir na base de dados file." );
	    return RC_NOK;   	
   }
   
   return RC_OK ;

}

int conectar::inserirRegistroHistorico(Tregistro *registro)
{
   char query[2000];

   memset(query,'\0', sizeof(query)); 
    	
   snprintf(query, sizeof(query) ,  " INSERT INTO  history ( Number_Ticket , Action , Phone_Number , SPID , File_Name , Date ) "     
          "VALUES (  '%lf' ,  '%d' , '%lf' , '%d' , '%s' , now() ) " , registro->numero_bilhete_portabilidade , registro->acao , registro->numero_telefone , registro->spid ,  registro->nome_arquivo.c_str() ) ;     
      
	fileLogger->information(fileLogger->format("Query: [$0]", query ) );

   try 
   {
	    Statement stmt = ( ses << query );
	    stmt.execute();
   }
   catch (MySQL::MySQLException &e)
   {
	    fileLogger->information("Erro ao inserir na base de dados history." );
	    return RC_NOK;   	
   }
   
   return RC_OK ;

}

int conectar::selectRegistroArquivo(string &arquivo)
{
	
	try 
	{
	    Statement stmt = ( ses << "SELECT file_name FROM  file order by file_name desc LIMIT 1");
	    stmt.execute();
	
	    RecordSet rs(stmt);
	
	    bool more = rs.moveFirst();
		
        	while (more)
		{
		    for (std::size_t col = 0; col < 1; ++col)
		    {
		        arquivo = rs[col].convert<std::string>() ;
		    }
		    std::cout << std::endl;
		    more = rs.moveNext();
		}

	}
	catch(MySQL::MySQLException &e )
	{
	    fileLogger->information("Erro ao consultar a base de dados file.");
	    return RC_NOK;		
	}
   
	return RC_OK ;
}


long conectar::searchRegisterDB(Tregistro *registro)
{
   int  valor=0;
   char query[2000];

   memset ( query , '\0' , sizeof(query));

   
   try 
   {
	    snprintf(query, sizeof(query), "select Phone_Number from register where Phone_Number = '%lf' " , registro->numero_telefone ) ; 
    	
            fileLogger->information(fileLogger->format("Query: [$0]", query ) );

	    Statement stmt = ( ses << query );
	    stmt.execute();

	    RecordSet rs(stmt);

	    valor = rs.rowCount();
     
   }
   catch (MySQL::MySQLException &e)
   {
	    fileLogger->information("Erro ao consultar telefone na base de dados register.");
	    return RC_NOK;   	
   }

   
   return valor ;

}

int conectar::defineAction(Tregistro *registro)
{
        
	if ( registro->acao == CREATE )
	{
		if (  searchRegisterDB(registro) == RC_OK )
		{
			if ( inserirRegistro(registro) != RC_OK )
			{
				return RC_NOK ;
			}
		} 
		else 
		{
			if ( deletarRegistro(registro) != RC_OK )
			{
				return RC_NOK ;
			}

			if ( inserirRegistro(registro) != RC_OK )
			{
				return RC_NOK;
			}
		}
	}
        else if ( registro->acao == DELETE )
	{
		if ( deletarRegistro(registro) != RC_OK )
		{
			return RC_NOK ;
		}
	}
	
        
	return RC_OK ; 
}




