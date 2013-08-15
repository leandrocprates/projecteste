
#include "GkSeries.h"

int GkSeries::db_AjeitaSeries( int promo_ilimitadas )
{
    Application& app = Application::instance();
    Statement stmt( sessao_read << "CALL promo_"<<promo_nome<<".flushall_series()" ) ;

    app.logger().information(Poco::format( "Executando a procedure [%s]..." , stmt.toString() ) );

    try
    {
        stmt.execute();

        if ( promo_ilimitadas==0 )
        {
            Statement stmt2 ( sessao_read << "UPDATE promo_"<< promo_nome << ".ctrl_series SET status = 'Esgotada' "
                 << "WHERE qtde_emitidos = max_cupons AND status = 'Ativa'" ) ;

            app.logger().information(Poco::format( "Executando a query [%s]..." , stmt2.toString() ) );
            stmt2.execute();
        }

    }
    catch (MySQL::MySQLException &e)
    {
        app.logger().information( "Erro ao ajeitar as series." ) ;
        return -1;

    }
    catch ( Poco::Exception &e )
    {
        app.logger().information( Poco::format( "Outra excecao gerada [%s] ."  , e.what() ) ) ;
        return -1;
    }

    return 0 ;

}


int GkSeries::db_GetNumberOfSeries()
{
    int num_row = 0;
    Application& app = Application::instance();
    Statement stmt( sessao_read << "SELECT count(*) FROM promo_" <<promo_nome<<".ctrl_series"  ) ;

    app.logger().information(Poco::format( "Executando a query [%s]..." , stmt.toString() ) );

    try
    {
        stmt.execute();
        RecordSet rs(stmt);
        num_row = rs.rowCount();

        bool more = rs.moveFirst();

        if ( more )
        {
            num_row = rs[0].convert<int>();
        }

        app.logger().information(Poco::format( "Quantidade de series pegas [%d]..." , num_row ) );
    }
    catch (MySQL::MySQLException &e)
    {
        app.logger().information( "Erro ao obter numero de series." ) ;
        return -1;
    }
    catch ( Poco::Exception &e )
    {
        app.logger().information( Poco::format( "Outra excecao gerada [%s] ."  , e.what() ) ) ;
        return -1;
    }
    
    num_series = num_row ;

    return 0 ;
}


int GkSeries::db_CarregaSeries()
{
    int num_row = 0;
    Tseries series;
    Application& app = Application::instance();
    Statement stmt( sessao_read << "SELECT id_serie, promocao, id_grupo , max_cupons , DATE_FORMAT(dt_inicio , '%Y%m%d%H%i%S' ) as data_inicio , "
     " DATE_FORMAT(dt_fim, '%Y%m%d%H%i%S' ) as data_fim , status , qtde_emitidos FROM promo_" <<promo_nome<<".ctrl_series where status='Ativa' "  ) ;

    app.logger().information(Poco::format( "Executando a query [%s]..." , stmt.toString() ) );

    try
    {
        stmt.execute();
        RecordSet rs(stmt);
        num_row = rs.rowCount();

        bool more = rs.moveFirst();

        while ( more )
        {
            series.id_serie = rs.value("id_serie").convert<long int>();
            series.promocao = rs.value("promocao").convert<std::string>();
            series.id_grupo = rs.value("id_grupo").convert<long int>();
            series.max_cupons = rs.value("max_cupons").convert<long int>();
            series.dt_inicio = rs.value("data_inicio").convert<std::string>();
            series.dt_fim = rs.value("data_fim").convert<std::string>();
            series.status = rs.value("status").convert<std::string>();
            series.qtde_emitidos = rs.value("qtde_emitidos").convert<long int>();
            map_gkseries.insert( mapas::value_type( series.id_serie, series ) );
            more=rs.moveNext();
        }
        app.logger().information(Poco::format( "Quantidade de series pegas [%d]..." , num_row ) );
        
    }
    catch (MySQL::MySQLException &e)
    {
        app.logger().information( "Erro ao carregar as series." ) ;
        return -1;
    }
    catch ( Poco::Exception &e )
    {
        app.logger().information( Poco::format( "Outra excecao gerada [%s] ."  , e.what() ) ) ;
        return -1;
    }
    app.logger().information("...Series Carregadas..." );

    return 0 ;
}

int GkSeries::imprimir_SeriesCarregadas()
{
    Application& app = Application::instance();
    app.logger().information("==== Imprimindo as Series carregadas ====" );

    for ( mapas::const_iterator it = map_gkseries.begin() ;  it!=map_gkseries.end() ; it++ )
    {
        app.logger().information(Poco::format( "Serie [%d]..." , it->first  ) );
    }
    return 0;
}


/******************  implementacao para carregar tabela de gabarito ******************/

int GkSeries::db_CarregaGabarito()
{
    int num_row = 0;
    int num_coluns=0;
    Application& app = Application::instance();
    Statement stmt( sessao_read << "SELECT  * FROM promo_" <<promo_nome<<".gab  order by rand() "  ) ;

    app.logger().information(Poco::format( "Executando a query [%s]..." , stmt.toString() ) );

    try
    {
        stmt.execute();
        RecordSet rs(stmt);
        num_row = rs.rowCount(); // numero de linhas
        num_coluns = rs.columnCount(); // numero de colunas

        app.logger().information(Poco::format( "Numero de linhas obtidas do gabarito  [%d]... " , num_row  ) );
        app.logger().information(Poco::format( "Numero de colunas obtidas do gabarito  [%d]..." , num_coluns  ) );

        bool more = rs.moveFirst();
        
        
        while ( more )
        {
            //itera pelo numero de linhas do gabarito
            for (int i=0 ; i < num_row ; i++  )
            {
                // obtendo o numero de cupons de forma randomica 
                int cupom_rand =  rs.value("cupom").convert<int>();

                // itera pelo numero de colunas
                for ( int j=0 ; j < (num_coluns-1) ; j++  )
                {
                    std::string name_flag =  Poco::format( "flag%d" , j );

                    app.logger().information(Poco::format( "column flag :  [%s] " , name_flag ) );

                    std::string flag =  rs.value(name_flag).convert<std::string>();

                    app.logger().information(Poco::format( "data flag :  [%s] " , flag ) );

                    StringTokenizer tokenizer(flag, ",", StringTokenizer::TOK_TRIM);

                    for (StringTokenizer::Iterator it = tokenizer.begin(); it != tokenizer.end(); ++it)
                    {
                        std::string s_serie = *it;
                        s_serie = s_serie.substr(0, s_serie.length()-1 );
                        int i_serie = atoi(s_serie.c_str()) ;
                        map_gab.insert(multi_map::value_type( i_serie , cupom_rand ) ) ;
                        app.logger().information(Poco::format( " Serie do gabarito  [%d] , Cupom [%d]  ..." ,  i_serie , cupom_rand  ) );
                        
                    }

                }
                more=rs.moveNext();
            }
            
        }

    }
    catch (MySQL::MySQLException &e)
    {
        app.logger().information( "Erro ao carregar dados da tabela de gabarito." ) ;
        return -1;
    }
    catch ( Poco::Exception &e )
    {
        app.logger().information( Poco::format( "Outra excecao gerada [%s] ."  , e.what() ) ) ;
        return -1;
    }
    
    app.logger().information("...Gabarito Carregado com Sucesso..." );

    return 0 ;
}



    


