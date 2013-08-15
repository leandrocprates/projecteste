/* 
 * File:   GkConfig.h
 * Author: amazon
 *
 * Created on 30 de Maio de 2009, 11:26
 */

#ifndef _GKCONFIG_H
#define	_GKCONFIG_H

#include <string>

class GkConfig
{
public:

    GkConfig() {};
    ~GkConfig(){};
    
    void set_Host_Read(std::string host_read)
    {
        this->host_read=host_read;
    }

    void set_Host_Write(std::string host_write)
    {
        this->host_write=host_write;
    }

    void set_Host_User(std::string host_user)
    {
        this->host_user=host_user;
    }

    void set_Host_Passwd(std::string host_passwd)
    {
        this->host_passwd=host_passwd;
    }

    void set_DB(std::string db)
    {
        this->db=db;
    }

    void set_Url_Admin(std::string url_admin)
    {
        this->url_admin=url_admin;
    }

    void set_Promo_Nome(std::string promo_nome)
    {
        this->promo_nome=promo_nome;
    }

    std::string get_Host_Read()
    {
        return this->host_read;
    }

    std::string get_Host_Write()
    {
        return this->host_write;
    }

    std::string get_Host_User()
    {
        return this->host_user;
    }

    std::string get_Host_Passwd()
    {
        return this->host_passwd;
    }

    std::string get_DB()
    {
        return this->db;
    }

    std::string get_Url_Admin()
    {
        return this->url_admin;
    }

    std::string get_Promo_Nome()
    {
        return this->promo_nome;
    }


private :

    std::string host_read;
    std::string host_write;
    std::string host_user;
    std::string host_passwd;
    std::string db;
    std::string url_admin;
    std::string promo_nome;

};


#endif	/* _GKCONFIG_H */

