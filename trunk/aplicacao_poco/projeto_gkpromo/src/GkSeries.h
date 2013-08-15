/* 
 * File:   GkSeries.h
 * Author: amazon
 *
 * Created on 6 de Junho de 2009, 07:47
 */

#ifndef _GKSERIES_H
#define	_GKSERIES_H

#include "GkConectar.h"

#include "Poco/StringTokenizer.h"
using Poco::StringTokenizer;

class GkSeries
{
public:

    GkSeries(Session ses_read , Session ses_write , std::string promo_nome ):sessao_read(ses_read) , sessao_write(ses_write)
    {
        this->promo_nome=promo_nome;
    }
    
    ~GkSeries(){};

    int db_AjeitaSeries( int promo_ilimitadas );
    int db_GetNumberOfSeries();
    int db_CarregaSeries();
    int imprimir_SeriesCarregadas();

    int db_CarregaGabarito();
    //int imprimir_GabaritoCarregado();

private:
    Session sessao_read ;
    Session sessao_write ;
    std::string promo_nome;
    int num_series;

    typedef struct
    {
        long int id_serie;
        std::string promocao;
        long int id_grupo;
        long int max_cupons;
        std::string dt_inicio;
        std::string dt_fim;
        std::string status;
        long int qtde_emitidos;
    } Tseries;

    typedef std::map < int , Tseries > mapas;
    mapas map_gkseries;

    typedef struct
    {
        int serie ;
        int cupom;
    } Tgab;
    
    typedef std::multimap <int , int > multi_map;
    multi_map map_gab ; 

};


#endif	/* _GKSERIES_H */

