
#include <cstdlib>
#include <ctype.h>

#include "processar.h"


int processar::validar_data( string data )
{
    string ano , mes, dia;
    string hora , minuto, segundo;

    segundo = data.substr(12,2);
    minuto = data.substr(10,2);
    hora = data.substr(8,2);
    dia = data.substr(6,2);
    mes = data.substr(4,2);
    ano = data.substr(0,4);

    //cout<<ano<< mes<< dia<< hora<< minuto<< segundo<<endl;

    if ( !(DateTime::isValid( NumberParser::parse(ano), NumberParser::parse(mes), NumberParser::parse(dia), NumberParser::parse(hora), NumberParser::parse(minuto), NumberParser::parse(segundo) )))
    {
        return RC_NOK;
    }

    return RC_OK;

}

int processar::processaCabecalho(string cabecalho)
{
        string dataHora;
        string numeroRegistros;
        
        StringTokenizer tokenizer(cabecalho, ";,", StringTokenizer::TOK_TRIM);

        int i=0;
        for (StringTokenizer::Iterator it = tokenizer.begin(); it != tokenizer.end(); ++it)
	{
		switch(i)
		{
			case 0:
			    dataHora = *it ;

			case 1:
			    numeroRegistros= *it;
		}
		i++;
	}

        fileLogger->information(fileLogger->format("Data: [$0] ", dataHora ));
        fileLogger->information(fileLogger->format("Numero de regitros: [$0] ", numeroRegistros ));


	if ( dataHora.size() != DATAHORA )
	{
		fileLogger->information("Erro ao validar o comprimento do campo data no header.");
		return RC_NOK ;
	}

	if ( validar_data(dataHora) != RC_OK )
	{
		fileLogger->information("Erro ao validar data ou hora no cabecalho.");
		return RC_NOK ;
	}

        if (atof(numeroRegistros.c_str()) < 2 )
        {
		fileLogger->information("Erro ao validar o campo numero de registro.");
		return RC_NOK ;
        }

        registro.data_geracao_arquivo = dataHora;
        registro.numero_registro_arquivo = NumberParser::parse( numeroRegistros );

	return RC_OK;

}

int processar::processaTrailler(string trailler)
{
        fileLogger->information(fileLogger->format("trailler:$0", trailler ) ) ;
        

	if ( (trailler.size()-1) != TRAILLER )
	{
		fileLogger->information("Erro ao validar o comprimento do campo checksum no header.") ;	
		return RC_NOK ; 
	}
    
        registro.checksum = trailler ;
    
        return RC_OK;

}

int processar::determinaNumeroOcorrencias(string detalhe)
{
        int ocorrencia=0;
        StringTokenizer tokenizer(detalhe, ";,", StringTokenizer::TOK_TRIM);

        for (StringTokenizer::Iterator it = tokenizer.begin(); it != tokenizer.end(); ++it)
	{
            ocorrencia++;
	}

 	return ocorrencia;
}

int processar::ehNumero(const char *numero)
{

	while ( (*numero) != '\0' ) 
	{
		if ( !isdigit( *numero ) )   
		{
			fileLogger->information( "Erro - deve ser preenchido com numeros." ) ;		
                        return RC_NOK ;
		}
		numero++;
	}
	
	return RC_OK;
	
}

int processar::validaTipoLinha( int tipo_linha )
{
	if (  tipo_linha  != BASICA &&  tipo_linha  != CNG  &&  tipo_linha  != DDR ) 
	{
		fileLogger->information( "Erro ao validar o campo tipo de linha." ) ;	
		return RC_NOK ;
	}
        return RC_OK ;
}

int processar::validaTipoPortabilidade( int tipo_portabilidade )
{
	if (  tipo_portabilidade  != LSPP &&  tipo_portabilidade  != LISP  ) 
	{
		fileLogger->information( "Erro ao validar o campo tipo de portabilidade." ) ;	
		return RC_NOK ;
	}
        return RC_OK ;
}


int processar::validaAcao( int acao )
{
	if ( acao != CREATE &&  acao  != DELETE  ) 
	{
		fileLogger->information( "Erro ao validar o campo acao.");	
		return RC_NOK ;
	}
        return RC_OK ;
}

int processar::processaRegistro(string dados)
{
	string numero_bilhete_portabilidade;
	string acao;
	string tipo_linha;
	string tipo_portabilidade;
	string spid;
	string eot;
	string timestamp_janela;
	string timestamp_ativacao;
	string numero_telefone;

        string reg=dados;

        fileLogger->information("--------- processaRegistro - Inicio ---------");

	StringTokenizer tokenizer(reg, ";,", StringTokenizer::TOK_TRIM);
        
        int i=0;
        for (StringTokenizer::Iterator it = tokenizer.begin(); it != tokenizer.end(); ++it)
	{

		switch(i)
		{
			case 0:
			    numero_bilhete_portabilidade = *it ;

			case 1:
			    acao= *it;

			case 2:
			    numero_telefone =*it;

                        case 3:
			    tipo_linha = *it;

			case 4:
			    tipo_portabilidade = *it;

			case 5:
			    spid = *it ;

			case 6:
			    eot = *it;

                        case 7:
			   timestamp_ativacao = *it ;

                        case 8:
			   timestamp_janela = *it ;

		}

		i++;

	}
	


    fileLogger->information(fileLogger->format("numero_bilhete_portabilidade: [$0] ", numero_bilhete_portabilidade ) ) ;
    fileLogger->information(fileLogger->format("acao: [$0] ", acao ) ) ;
    fileLogger->information(fileLogger->format("numero_telefone: [$0] ", numero_telefone ) ) ;
    fileLogger->information(fileLogger->format("tipo_linha: [$0] ", tipo_linha ) ) ;
    fileLogger->information(fileLogger->format("tipo_portabilidade: [$0] ", tipo_portabilidade ) ) ;
    fileLogger->information(fileLogger->format("spid: [$0] ", spid ) ) ;
    fileLogger->information(fileLogger->format("eot:  [$0] ", eot ) ) ;
    fileLogger->information(fileLogger->format("timestamp_ativacao: [$0] ", timestamp_ativacao ) ) ;
    fileLogger->information(fileLogger->format("timestamp_janela:   [$0] ", timestamp_janela   ) ) ;


        if ( ehNumero( numero_bilhete_portabilidade.c_str() ) != RC_OK  )
	{
	    fileLogger->information("Erro ao validar o campo numero do bilhete de portabilidade." ) ;	
            return RC_NOK;
	}
	
        if ( ehNumero( acao.c_str() ) != RC_OK  )
	{
	    fileLogger->information("Erro ao validar o campo acao." ) ;	
            return RC_NOK;
	}

        if ( validaAcao( NumberParser::parse( acao ) )  != RC_OK )
        {
	    fileLogger->information("Erro ao validar o campo acao." ) ; 
            return RC_NOK;
        }

        if ( ehNumero( numero_telefone.c_str() ) != RC_OK  )
	{
	    fileLogger->information("Erro ao validar o campo numero do telefone." ) ;	
            return RC_NOK;
	}

	if ( NumberParser::parse(acao) == ACTION )
	{
		
                if ( ehNumero( tipo_linha.c_str() ) != RC_OK  )
		{
		    fileLogger->information("Erro ao validar o campo tipo de linha." );		
                    return RC_NOK;
		}
		
		if ( validaTipoLinha( NumberParser::parse(tipo_linha) ) != RC_OK )
		{
		    fileLogger->information("Erro ao validar o campo tipo de linha." ) ;		
                    return RC_NOK;
                }
	
                if ( ehNumero( tipo_portabilidade.c_str() ) != RC_OK  )
		{
		    fileLogger->information("Erro ao validar o campo tipo de portabilidade." ) ;		
                    return RC_NOK;
		}
	
		if ( validaTipoPortabilidade( NumberParser::parse(tipo_portabilidade) ) != RC_OK )
		{
		    fileLogger->information("Erro ao validar o campo tipo de portabilidade." ) ;		
                    return RC_NOK;
                }
	
                if ( ehNumero( spid.c_str() ) != RC_OK  )
		{
		    fileLogger->information("Erro ao validar o campo SPID." ) ;		
                    return RC_NOK;
		}
	
                if ( ehNumero( eot.c_str() ) != RC_OK  )
		{
		    fileLogger->information("Erro ao validar o campo EOT." ) ;		
                    return RC_NOK;
		}
	
                if ( ehNumero( timestamp_ativacao.c_str() ) != RC_OK  )
		{
		    fileLogger->information("Erro ao validar o campo timestamp de ativacao." );		
                    return RC_NOK;
		}
		
		if ( validar_data(timestamp_ativacao) != RC_OK  )
		{
		    fileLogger->information("Erro ao validar o campo timestamp de ativacao."); 
                    return RC_NOK ;
		}
	
                // alterado pois o campo 9 nao estava vindo no registro 1 como estava na especificacao
                if ( ehNumero( timestamp_janela.c_str() ) != RC_OK  )
		{
		    fileLogger->information("Erro ao validar o campo timestamp do inicio da janela.");	
                    return RC_NOK;
		}
	
		if ( validar_data(timestamp_janela) != RC_OK  )
		{
		    fileLogger->information("Erro ao validar o campo timestamp do inicio da janela.");	
                    return RC_NOK ;
		}

	}
	
	// copia valores para a estrutura
    registro.numero_bilhete_portabilidade = atof(numero_bilhete_portabilidade.c_str());
    registro.acao = NumberParser::parse(acao) ;
    registro.numero_telefone = atof(numero_telefone.c_str());
    registro.tipo_linha = NumberParser::parse(tipo_linha) ;
    registro.tipo_portabilidade = NumberParser::parse(tipo_portabilidade) ;
    registro.spid = NumberParser::parse(spid);
    registro.eot = NumberParser::parse(eot);
    registro.timestamp_ativacao =  timestamp_ativacao ;
    registro.timestamp_janela   =  timestamp_janela ; 

    fileLogger->information("--------- processaRegistro - Fim ---------");
	
	return RC_OK;

}


int processar::processarArquivo(string arquivo , string diretorio )
{

    char frase[100+1] ;
    string detalhe;
    FILE *f ; 
    int numeroDeOcorrencia;
    int linha = 0 ; 
    string arq_temp ;
    int status=0; // status da insercoes do banco , se igual a tres inseriu nos tres
    
    bool cabecalhoProcessado = false;
    bool traillerProcessado  = false; 

    fileLogger->information("processarArquivo - Inicio");
    
    memset(frase,'\0' , sizeof(frase) ) ; 
   
    arq_temp  = diretorio ; 
    arq_temp += "/" + arquivo ;

    fileLogger->information(fileLogger->format("Abrir arquivo:  [$0]", arq_temp ) ) ;

    f=fopen(arq_temp.c_str() , "r" ) ; 
    
    if ( f == NULL ) 
    {
	    fileLogger->information("Erro ao abrir arquivo.") ;    
	    exit(-1);
    }
    
    while (fgets(frase,100,f)) 
    {
          linha++; 
    	  fileLogger->information(fileLogger->format("frase:  [$0] ", frase ) ) ;
              
          detalhe = frase ;
          
          numeroDeOcorrencia=determinaNumeroOcorrencias(detalhe);
 
     	  //fileLogger->information(montaString("numero de campos : %d ", numeroDeOcorrencia ) ) ;
          
          switch (numeroDeOcorrencia)
          {  
          case 2 :
                 
                if ( cabecalhoProcessado == false ) 
                {
                    if ( processaCabecalho(detalhe) == RC_NOK ) 
                    {
     	  		fileLogger->information("Erro cabecalho invalido.");                    
                    	exit(-1); 
                    }
                    
                    cabecalhoProcessado=true;
                    break;
                }
                else
                {
                    fileLogger->information("Erro formato do arquivo invalido.") ;
                    exit(-1); 
                    return RC_NOK;
                }

            case 9 :
                
                if ( (cabecalhoProcessado == true) &&  (traillerProcessado == false) ) 
                {
                	if ( processaRegistro(detalhe) == RC_OK ) 
                	{
                            // coloca um for para todas as conexoes abertas e cadastradas no ponteiro
                            for ( int i=0 ; i<config->getNumeroDeBancos() ; i++ )
                            {
                                conexao[i]->inicioTransacao();
                		if ( conexao[i]->defineAction(&registro) == RC_OK )
                		{
                                    status++;
                		}
                		else
                		{
                                    conexao[i]->efetua_rollback();
                		}

                            }
                            
                            // da commit nas bases de dados cadastradas
                            for ( int i=0 ; i< config->getNumeroDeBancos() ; i++ )
                            {
                                if ( status == config->getNumeroDeBancos())
                                    conexao[i]->efetua_commit();
                                else
                                    conexao[i]->efetua_rollback();
                            }
                            status=0; // zera para voltar denovo

                            // insere na base de dados de historico de telefones
                            for (int i=0 ; i<config->getNumeroDeBancos() ; i++ )
                            {
                                    conexao[i]->inicioTransacao();
                                    if ( conexao[i]->inserirRegistroHistorico(&registro) == RC_OK )
                                    {
                                        status++;
                                    }
                                    else
                                    {
                                        conexao[i]->efetua_rollback();
                                    }

                            }

                            // da commit nas bases de dados cadastradas
                            for ( int i=0 ; i< config->getNumeroDeBancos() ; i++ )
                            {
                                if ( status == config->getNumeroDeBancos())
                                    conexao[i]->efetua_commit();
                                else
                                    conexao[i]->efetua_rollback();
                            }
                            status=0; // zera para voltar denovo

                	}

                    break;
                    
                }
                else
                {
                    fileLogger->information("Erro arquivo nao possui cabecalho ou cabecalho invalido.");
                    exit(-1);
                    return RC_NOK;
                }
            
            case 1 :

                if (  (cabecalhoProcessado == true) &&  (traillerProcessado== false)  ) 
                {
                    processaTrailler(detalhe);
                    traillerProcessado= true;
                    break;
                }
                else if ( traillerProcessado == true ) 
                {
                    fileLogger->information("Erro-Formato do arquivo invalido.Trailler ja processado.");
                    return RC_NOK;
                } 
                else
                {
                    fileLogger->information("Erro arquivo nao possui cabecalho.");
                    exit(-1);
                    return RC_NOK;
                }


            default : 
		fileLogger->information(montaString("Erro na linha [$0], numero de campos invalidos. ", linha ) ) ;            
		break;
          
          }
          
    }

    if ( cabecalhoProcessado == false ) 
    {
	fileLogger->information("Erro - Arquivo nao possui cabecalho.");    
    	exit(-1); 
    }
     
    if ( traillerProcessado == false ) 
    {
	fileLogger->information("Erro - Arquivo nao possui trailler.");    
    }
    
    fclose(f); 

    traillerProcessado = false;
    cabecalhoProcessado= false;
    
    fileLogger->information("processarArquivo - Fim");

    return RC_OK;
    
}


int processar::determinaArquivoSerProcessado( string nomeArquivoListado , string nomeArquivoBD , string diretorio )
{
    string arqList;
    string arqBD;
    string temp;
    string tempBD;
    int status=0;

    temp   = nomeArquivoListado;
    tempBD = nomeArquivoBD;

    try {
        arqList = temp.substr(3, DATAHORA );
    }
    catch(exception &e)
    {
        fileLogger->information( e.what() );
    }

    try{
        arqBD   = tempBD.substr(3, DATAHORA );
    }
    catch (exception &e){
        fileLogger->information( e.what() );
    }

    
    if ( ehNumero( arqList.c_str() ) != RC_OK )
	{
		fileLogger->information( "Erro ao validar data do arquivo." );		
		exit (-1);
	}
    
    if ( validar_data( arqList ) != RC_OK  )
	{
		fileLogger->information( "Erro ao validar data do arquivo." );
		exit (-1);
	}
    
    if ( atof( arqList.c_str() ) > atof( arqBD.c_str() ) )
    {
       registro.nome_arquivo =  nomeArquivoListado ;
       fileLogger->information(fileLogger->format("Registro Nome_Arquivo: [$0] " , registro.nome_arquivo ) ) ;
       
       // faz o processamento de todos os registros do arquivo passado 
       if ( processarArquivo(registro.nome_arquivo , diretorio ) == RC_NOK ) 
       {
		fileLogger->information( "Erro no processamento do arquivo." );       	
       }

        // funcao que sera usada para inserir o registro do arquivo processado no bd tabela portability.file
        for ( int i=0 ; i<config->getNumeroDeBancos() ; i++ )
        {
            conexao[i]->inicioTransacao();
            if ( conexao[i]->inserirRegistroArquivo(&registro) == RC_OK )
            {
                status++;
            }
            else
            {
                conexao[i]->efetua_rollback();
            }

        }

        // da commit nas bases de dados cadastradas
        for ( int i=0 ; i< config->getNumeroDeBancos() ; i++ )
        {
            if ( status == config->getNumeroDeBancos())
                conexao[i]->efetua_commit();
            else
                conexao[i]->efetua_rollback();
        }
        status=0; // zera para voltar denovo

    }
    else
    {
       fileLogger->information(fileLogger->format("Arquivo nao sera processado - data invalida: [$0]" , registro.nome_arquivo ) ) ;
       return RC_NOK;
    }

    
	
    return RC_OK;

}

int processar::processamento(conectar *con[] , configuracao *configuracao , string diretorio )
{

    // atribui dados pegos no arquivos de configuracao a ponteiro da classe
    config = configuracao ;
    string nome_arquivo_BD[config->getNumeroDeBancos()];

    conexao = (conectar ** ) malloc ( ( config->getNumeroDeBancos() ) * sizeof(conectar *) );
    
    for ( int i=0 ; i< config->getNumeroDeBancos() ; i++ )
    {
        conexao[i] = con[i];
    }


    // verifica ultimo arquivo processado na base de dados
    for ( int i = 0 ; i< config->getNumeroDeBancos() ; i++ )
    {
        con[i]->selectRegistroArquivo(nome_arquivo_BD[i]);
    }

    //obtem os arquivos para processamento
    obterArquivos obter(obterLog());
    obter.dir_ls(diretorio , nome_arquivo_BD[0] , programasListados , config->getTipo_Arquivo() );
    
    // ordena os arquivos para processamento 
    sort(programasListados.begin() , programasListados.end() );
    
    fileLogger->information(fileLogger->format("Ultimo arquivo cadastrado no BD: [$0]", nome_arquivo_BD[0] ) ) ;
  
    for (vector<string>::iterator iter = programasListados.begin(); iter != programasListados.end(); iter++)
    {
        string nomeArquivoListado = *iter ;
        determinaArquivoSerProcessado( nomeArquivoListado , nome_arquivo_BD[0] , diretorio );
    }

    // desaloca vetor com as conexoes
    

    return RC_OK;

}





