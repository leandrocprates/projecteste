
#include "conectar.h"


int conectar::deletarRegistro()
{
   Session ses( _pool->get() );

   Statement stmt( ses << "DELETE FROM register  WHERE Phone_Number= " << getTelefone()  ) ;


   try 
   {
	stmt.execute();
   }
   catch (MySQL::MySQLException &e)
   {
        return RC_NOK;
   }
       
   return RC_OK;
}


int conectar::inserirRegistro()
{
   Session ses( _pool->get() );

   Statement stmt( ses << "INSERT INTO register ( Number_Ticket , Action , Phone_Number , SPID ) VALUES (" << getNumeroTicket() << ","
                       <<  getAcao() << "," << getTelefone() << "," << getOperadora() <<  ")" ) ;

   
   /****************************************************/
   //esta funcionando descomentando estas linhas abaixo
   //MySQL::Connector::registerConnector();
   //Session ses(MySQL::Connector::KEY, retornaConexao() );
   //Statement stmt(ses << " INSERT INTO register ( Number_Ticket , Action , Phone_Number , SPID ) VALUES (15,2,3,3) " ) ;
   /****************************************************/

   try 
   {
	stmt.execute();
   }
   catch (MySQL::MySQLException &e)
   {
        return RC_NOK;
   }
   
   return RC_OK ;

}


void conectar::determinaAcao()
{
    if ( getAcao() == 0 )
    {
        inserirRegistro();
    }
    else if ( getAcao() == 1 )
    {
        deletarRegistro();
    }

}




