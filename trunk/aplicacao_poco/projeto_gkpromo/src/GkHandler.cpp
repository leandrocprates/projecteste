
#include "GkHandler.h"

int GkHandler::processarRequisicao( HTTPServerRequest &request , std::string &resposta )
{
    Application& app = Application::instance();
    URI uri(request.getURI());
    
    int num_param=0;

    app.logger().information("processarRequisicao -- Inicio" );

    if ( gkurl->busca_Servico( uri.getPath() , num_param ) == -1 )
    {
        app.logger().information("Servico nao cadastrado.");
        // resposta <gkpromo><promo>gkconfig->get_Promo_Nome()</promo><status>ERRO_REQUISICAO</status></gkpromo>
        return RET_NOK;
    }

    app.logger().information(Poco::format( "Numero de Parametros da Requisicao [%d] " , num_param ) );

    // obtem os parametros da requisicao
    getParams( request );
    imprimeParams();

    // trocar por um switch case que define a funcao que ira processar
    
    if ( uri.getPath() == "/obter_cupom/aleatorio" )
    {
        obterCupom(resposta);
    }
    else if ( uri.getPath() == "/listar_cupons" )
    {

    }
    else
    {

    }

    
    app.logger().information("processarRequisicao -- Fim" );
    
    return RET_OK ;
}


// pega os parametros da requisicao
int GkHandler::getParams( HTTPServerRequest &request )
{
    Application& app = Application::instance();
    
    HTMLForm form ( request , request.stream() ) ;

    app.logger().information("Obtendo os parametros da requisicao.");

    try
    {
        std::string promocao = form.get(PARAM_PROMOCAO, "" ) ;
        std::string ident = form.get(PARAM_IDENT, "" ) ;
        std::string info = form.get(PARAM_INFO,"") ;
        std::string filtro = form.get(PARAM_FILTRO,"") ;
        std::string nome_super_grupo = form.get(PARAM_SGRUPO,"") ;

        std::string str_id_tipo;
        int idtipo;

        // obten campo id_tipo podendo ser phone, extern, 1 ou 2 (default)
        if ( ( str_id_tipo = form.get(PARAM_IDTIPO,"2") ) == IDTIPO_STR_FONE )
        {
            idtipo = IDTIPO_FONE;
        }
        else if ( str_id_tipo == IDTIPO_STR_EXTERN )
        {
            idtipo = IDTIPO_EXTERN;
        }
        else
        {
            idtipo = NumberParser::parse( str_id_tipo ) ;
        }


        unsigned qtde = NumberParser::parseUnsigned( form.get(PARAM_QTDE, "0" ) ) ;
        int  indice = NumberParser::parse( form.get(PARAM_INDICE, "0" ) );
        int  listar = NumberParser::parse( form.get(PARAM_LISTAR,"0") );
        int  ordem = NumberParser::parse( form.get(PARAM_ORDEM,"0") );
        int  si = NumberParser::parse( form.get(PARAM_SI,"0") );
        int  sf = NumberParser::parse( form.get(PARAM_SF,"0") );
        std::string slist = form.get(PARAM_SLIST,"") ;

        gkparams.setPromocao(promocao);
        gkparams.setIdentificador(ident);
        gkparams.setInfo    (info);
        gkparams.setFiltro  (filtro);
        gkparams.setNome_Super_Grupo(nome_super_grupo);

        gkparams.setIdTipo (idtipo);
        gkparams.setQtde   (qtde);
        gkparams.setIndice (indice);
        gkparams.setListar (listar);
        gkparams.setOrdem  (ordem);
        gkparams.setSi     (si);
        gkparams.setSf     (sf);
        gkparams.setSlist  (slist);
        
    }
    catch(Poco::RuntimeException &e )
    {
        app.logger().information(Poco::format( "Excecao : [%s] " , e.what() ) );
    }
    catch(Poco::Exception &e)
    {
        app.logger().information(Poco::format( "Class Name : [%s] , Excecao : [%s]  " , e.className() , e.what() ) );
    }
    catch (std::exception &e)
    {
        app.logger().information(Poco::format( "Excecao do C++ : [%s] " , e.what() ) );
    }

    app.logger().information("Conseguiu obter todos os parametros da requisicao.");

    return RET_OK ;
}


void GkHandler::imprimeParams()
{
    Application& app = Application::instance();

    app.logger().information("----------- Result of search: -----------");
    app.logger().information(Poco::format( "gkparams.promocao     = [%s]" , gkparams.getPromocao() ) );
    app.logger().information(Poco::format( "gkparams.ident     = [%s]" , gkparams.getIdentificador() ) );
    app.logger().information(Poco::format( "gkparams.info     = [%s]" , gkparams.getInfo() ) );
    app.logger().information(Poco::format( "gkparams.filtro     = [%s]" , gkparams.getFiltro() ) );
    app.logger().information(Poco::format( "gkparams.nome_super_grupo     = [%s]" , gkparams.getNome_Super_Grupo() ) );
    
    app.logger().information(Poco::format( "gkparams.idtipo     = [%d]" , gkparams.getIdTipo() ) );
    app.logger().information(Poco::format( "gkparams.qtde     = [%u]" , gkparams.getQtde() ) );
    app.logger().information(Poco::format( "gkparams.indice     = [%d]" , gkparams.getIndice() ) );
    app.logger().information(Poco::format( "gkparams.listar     = [%d]" , gkparams.getListar() ) );
    app.logger().information(Poco::format( "gkparams.ordem     = [%d]" , gkparams.getOrdem() ) );
    app.logger().information(Poco::format( "gkparams.si     = [%d]" , gkparams.getSi() ) );
    app.logger().information(Poco::format( "gkparams.sf     = [%d]" , gkparams.getSf() ) );
    app.logger().information(Poco::format( "gkparams.slist     = [%s]" , gkparams.getSlist() ) );
    app.logger().information("-----------------------------------------");
    
    
}




void GkHandler::obterCupom(std::string &resposta)
{
    if ( verificaEntradas() == RET_NOK )
    {
        
    }
}


int GkHandler::verificaEntradas()
{
    Application& app = Application::instance();
    app.logger().information("Dentro do construtor GkHandler.");

    // validando o nome da promocao
    if ( gkdados_promocao->getNomePromocao() != gkparams.getPromocao() )
    {
        app.logger().information("Nome da Promocao nao valido.");
        return RET_NOK;
    }

    // validando o identificador passado de acordo com o id_tipo
    verifyIdent();

    // validando a quantidade de acordo com o tipo de emissao da promocao
    if ( gkdados_promocao->getTipoEmissao() == TIPO_ALEATORIOV || gkdados_promocao->getTipoEmissao() == TIPO_ALEATORIOH )
    {
        if ( gkparams.getQtde() < 1 )
        {
            unsigned x=1;
            gkparams.setQtde( x );
        }
    }

    return RET_OK;
}




void GkHandler::verifyIdent()
{
    switch ( gkparams.getIdTipo() )
    {
        case IDTIPO_FONE:
            if ( !isValidPhone() ) {
                //*ret = RET_NOK;
                //return writeXmlResponseError( TELEFONE_INVALIDO );
            }
            break;

        case IDTIPO_EXTERN:
            if ( !isValidExtern() ) {
                //*ret = RET_NOK;
                //return writeXmlResponseError( EXTERN_INVALIDO );
            }
            break;

        default:
            {
                //*ret = RET_NOK;
                //return writeXmlResponseError( IDTIPO_INVALIDO );
            }
    }
}


/* isValidExtern
 **************************************************/
bool GkHandler::isValidExtern()
{
   std::string ident = gkparams.getIdentificador();

   if ( ident.empty() )
       return 0;

   for ( int i=0 ; i<ident.length() ; i++ )
   {
       //if ( ( !isdigit(ident[i]) ) || ( ident[i] < 'A' && ident[i] >'Z' ) || ( ident[i] < 'a' && ident[i] > 'z' )  )
       if ( ( !isdigit(ident[i]) ) || !( ident[i] >= 'A' && ident[i] <='Z' ) || !( ident[i] >= 'a' && ident[i] <= 'z' )  )
       {
           return 0;
       }
   }

   return 1;
}


/* isValidPhone
 **************************************************/
bool GkHandler::isValidPhone()
{
   std::string phone = gkparams.getIdentificador() ;

   if ( phone.empty() )
       return 0;

   if ( phone.size() != 10 )
       return 0;

   if ( phone[0] == '0' )
        return 0;

   for ( int i=0 ; i<phone.length() ; i++ )
   {
       if ( !isdigit(phone[i]) )
       {
           return 0;
       }
   }

   return 1;
}






