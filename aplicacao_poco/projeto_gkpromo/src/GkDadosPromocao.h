/* 
 * File:   GkDadosPromocao.h
 * Author: amazon
 *
 * Created on 31 de Maio de 2009, 09:54
 */

#ifndef _GKDADOSPROMOCAO_H
#define	_GKDADOSPROMOCAO_H

#include "GkConectar.h"


class GkDadosPromocao
{
public :

    GkDadosPromocao( Session ses ):sessao(ses)
    {
        Application& app = Application::instance();
        std::string nome_promocao = app.config().getString("gkpromo.promo_nome","");
        app.logger().information(Poco::format( "Nome da promocao [%s] ..." , nome_promocao ) );
        if ( !DB_GetPromocao(nome_promocao) )
        {
            exit(-1);
        }

    }
    
    ~GkDadosPromocao() { };

    void setNomePromocao(std::string &nome_promocao)
    {
        this->nome_promocao=nome_promocao;
    }
    std::string getNomePromocao()
    {
        return this->nome_promocao;
    }

    void setMaxGanhadores(int max_ganhadores)
    {
        this->max_ganhadores=max_ganhadores;
    }
    int getMaxGanhadores()
    {
        return this->max_ganhadores;
    }

    void setDtFim(std::string &dt_fim)
    {
        this->dt_fim=dt_fim;
    }
    std::string getDtFim()
    {
        return this->dt_fim;
    }

    void setDtInicio(std::string &dt_inicio)
    {
        this->dt_inicio=dt_inicio;
    }
    std::string getDtInicio()
    {
        return this->dt_inicio;
    }

    void setMaskCupom(std::string &mask_cupom)
    {
        this->mask_cupom=mask_cupom;
    }
    std::string getMaskCupom()
    {
        return this->mask_cupom;
    }

    void setTamanhoSalto(int &tamanho_salto)
    {
        this->tamanho_salto=tamanho_salto;
    }
    int getTamanhoSalto()
    {
        return this->tamanho_salto;
    }

    void setTipoEmissao(std::string &tipo_emissao)
    {
        this->tipo_emissao=tipo_emissao;
    }
    std::string getTipoEmissao()
    {
        return this->tipo_emissao;
    }

    void setStatus(std::string &status)
    {
        this->status=status;
    }
    std::string getStatus()
    {
        return this->status;
    }

    void setSaida(std::string &saida)
    {
        this->saida=saida;
    }
    std::string getSaida()
    {
        return this->saida;
    }

    void setRotuloAutomatico(int &rotulo_automatico)
    {
        this->rotulo_automatico=rotulo_automatico;
    }
    int getRotuloAutomatico()
    {
        return this->rotulo_automatico;
    }

    void setSeriesIlimitadas(int &series_ilimitadas)
    {
        this->series_ilimitadas=series_ilimitadas;
    }
    int getSeriesIlimitadas()
    {
        return this->series_ilimitadas;
    }

    void setTipoSorteio(std::string &tipo_sorteio)
    {
        this->tipo_sorteio=tipo_sorteio;
    }
    std::string getTipoSorteio()
    {
        return this->tipo_sorteio;
    }

    void setUsarLock(int &usar_lock)
    {
        this->usar_lock=usar_lock;
    }
    int getUsarLock()
    {
        return this->usar_lock;
    }

    void setUsarSgrupo(int &usar_sgrupo)
    {
        this->usar_sgrupo=usar_sgrupo;
    }
    int getUsarSgrupo()
    {
        return this->usar_sgrupo;
    }

    int getIsGrupoCheio()
    {
        return this->isGrupoCheio;
    }


    static std::string ST_VALIDO;
    static std::string ST_ENCERRADO;
    static std::string ST_ATIVO;
    static std::string ST_INATIVO;
    static std::string ST_CANCELADO;
    static std::string ST_CONCLUIDO;
    static std::string ST_FINALIZADO;
    static std::string ST_SUSPENSO;
    static std::string ST_EMISSAO_SUP;


private :

    int DB_GetPromocao(std::string &promo_nome);
    void imprimiDadosPromocao(Application &app); 
    
    Session sessao ;
    std::string nome_promocao;
    int max_ganhadores;
    std::string dt_fim;
    std::string dt_inicio;
    std::string mask_cupom;
    int tamanho_salto;
    std::string tipo_emissao;
    std::string status;
    std::string saida;
    int rotulo_automatico;
    int series_ilimitadas;
    std::string tipo_sorteio;
    int usar_lock;
    int usar_sgrupo;
    int isGrupoCheio ;

};



#endif	/* _GKDADOSPROMOCAO_H */

