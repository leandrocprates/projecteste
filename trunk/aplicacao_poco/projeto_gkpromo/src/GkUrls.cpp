
#include "GkUrls.h"

int GkUrls::busca_Url()
{
    int num_row=0;
    std::string url;
    int num_param=0;
    Application& app = Application::instance();

    Statement stmt( sessao << "SELECT url , num_param FROM gkurl " ) ;

    try
    {
        stmt.execute();
        RecordSet rs(stmt);
        num_row = rs.rowCount();

        bool more = rs.moveFirst();

        while (more)
        {
            url = rs.value("url").convert<std::string>() ;
            num_param= rs.value("num_param").convert<int>() ;

            gkurl.insert( mapas::value_type ( url , num_param )  );
            app.logger().information(Poco::format( "Url [%s] , Numero de Parametros [%d] " , url , num_param ) );
            more = rs.moveNext();
        }

    }
    catch (MySQL::MySQLException &e)
    {
        app.logger().information( "Erro ao executar query." ) ;
        //Application::EXIT_SOFTWARE;
    }
    catch ( Poco::Exception &e )
    {
        //app.logger().information(Poco::format( "Erro, Descricao: [%s] Classe [%s] Codigo [%d] What [%s] ." , e.name() , e.className() e.code() , e.what() ) );
        //Application::EXIT_SOFTWARE;
    }

    return num_row ;

}


int GkUrls::busca_Servico(const std::string &url , int &num_param )
{
    mapas::iterator it = gkurl.find(url) ;
    if ( it == gkurl.end() )
    {
        return -1;
    }
    //url = it->first;
    num_param = it->second;
    return 0 ;
}




