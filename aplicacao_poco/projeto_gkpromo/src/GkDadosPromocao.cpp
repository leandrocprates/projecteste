
#include "GkDadosPromocao.h"

// status da promocao
std::string GkDadosPromocao::ST_VALIDO = "Valida";
std::string GkDadosPromocao::ST_ENCERRADO = "Encerrada";
std::string GkDadosPromocao::ST_ATIVO = "Ativa";
std::string GkDadosPromocao::ST_INATIVO =  "Inativa";
std::string GkDadosPromocao::ST_CANCELADO = "Cancelada";
std::string GkDadosPromocao::ST_CONCLUIDO = "Esgotada";
std::string GkDadosPromocao::ST_FINALIZADO = "Finalizada";
std::string GkDadosPromocao::ST_SUSPENSO = "Suspensa";
std::string GkDadosPromocao::ST_EMISSAO_SUP = "Emissão Suspensa";

void GkDadosPromocao::imprimiDadosPromocao(Application &app)
{
    app.logger().information("----------- Result of search: -----------");
    app.logger().information(Poco::format( "ctrl_promocao.nome     = [%s]" , getNomePromocao() ) );
    app.logger().information(Poco::format( "ctrl_promocao.max_ganhadores     = [%d]" , getMaxGanhadores() ) );
    app.logger().information(Poco::format( "ctrl_promocao.dt_fim     = [%s]" , getDtFim() ) );
    app.logger().information(Poco::format( "ctrl_promocao.dt_inicio     = [%s]" , getDtInicio() ) );
    app.logger().information(Poco::format( "ctrl_promocao.mask_cupom     = [%s]" , getMaskCupom() ) );
    app.logger().information(Poco::format( "ctrl_promocao.tamanho_salto     = [%d]" , getTamanhoSalto() ) );
    app.logger().information(Poco::format( "ctrl_promocao.tipo_emissao     = [%s]" , getTipoEmissao() ) );
    app.logger().information(Poco::format( "ctrl_promocao.status     = [%s]" , getStatus() ) );
    app.logger().information(Poco::format( "ctrl_promocao.saida_app     = [%s]" , getSaida() ) );
    app.logger().information(Poco::format( "ctrl_promocao.rotulo_automatico     = [%d]" , getRotuloAutomatico() ) );
    app.logger().information(Poco::format( "ctrl_promocao.series_ilimitadas     = [%d]" , getSeriesIlimitadas() ) );
    app.logger().information(Poco::format( "ctrl_promocao.tipo_sorteio     = [%s]" , getTipoSorteio() ) );
    app.logger().information(Poco::format( "ctrl_promocao.usar_lock     = [%d]" , getUsarLock() ) );
    app.logger().information(Poco::format( "ctrl_promocao.usar_sgrupo     = [%d]" , getUsarSgrupo() ) );
    app.logger().information("-----------------------------------------");
}


int GkDadosPromocao::DB_GetPromocao(std::string &promo_nome)
{
   int num_row=0;

   Application& app = Application::instance();

   Statement stmt( sessao << "SELECT p.nome, p.max_ganhadores, DATE_FORMAT( p.dt_fim , '%Y%m%d%H%i%S' ) as dataFim , DATE_FORMAT(p.dt_inicio , '%Y%m%d%H%i%S' ) as dataInicio ,"
                           " p.mask_cupom, tamanho_salto , tipo_emissao, status, saida_app, "
                           " rotulo_automatico, series_ilimitadas, tipo_sorteio, usar_lock, usar_sgrupo "
                           " FROM promo_" << promo_nome << ".ctrl_promocao p WHERE p.nome = '" << promo_nome << "';" );


   app.logger().debug(Poco::format( "Executando a query [%s]..." , stmt.toString() ) );

   try
   {
        stmt.execute();
        RecordSet rs(stmt);
        num_row = rs.rowCount();

        bool more = rs.moveFirst();

        if (more)
        {
            nome_promocao = rs.value("nome").convert<std::string>();
            max_ganhadores = rs.value("max_ganhadores").convert<int>() ;
            dt_fim = rs.value("dataFim").convert<std::string>();
            dt_inicio = rs.value("dataInicio").convert<std::string>();
            mask_cupom = rs.value("mask_cupom").convert<std::string>() ;
            tamanho_salto = rs.value("tamanho_salto").convert<int>() ;
            tipo_emissao = rs.value("tipo_emissao").convert<std::string>() ;
            status = rs.value("status").convert<std::string>();
            saida = rs.value("saida_app").convert<std::string>();
            rotulo_automatico = rs.value("rotulo_automatico").convert<int>() ;
            series_ilimitadas = rs.value("series_ilimitadas").convert<int>();
            tipo_sorteio = rs.value("tipo_sorteio").convert<std::string>() ;
            usar_lock = rs.value("usar_lock").convert<int>() ;
            usar_sgrupo = rs.value("usar_sgrupo").convert<int>() ;

            isGrupoCheio = (tipo_sorteio == "grupo_cheio") ? 1: 0 ;

            imprimiDadosPromocao(app);
        }
        else
        {
            app.logger().information(Poco::format( "Nao encontrado dados da promocao [%s]..." , promo_nome ) );
        }

   }
   catch (MySQL::MySQLException &e)
   {
        app.logger().information( "Erro ao executar query." ) ;

   }
   catch ( Poco::Exception &e )
   {
        app.logger().information( Poco::format( "Outra excecao gerada [%s] ."  , e.what() ) ) ;
   }

   app.logger().information(Poco::format( "Numero de regitros obtidos [%d]" , num_row ) );
   return num_row ;

}




