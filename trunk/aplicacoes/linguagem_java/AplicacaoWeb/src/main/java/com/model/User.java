/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.model;

import java.io.Serializable;
import org.apache.commons.lang3.StringUtils;

/**
 *
 * @author lprates
 */
public class User implements Serializable {
    
    private static final long serialVersionUID = 1L;
    
    private Integer id=0;
    private String nome=StringUtils.EMPTY;
    private String endereco=StringUtils.EMPTY;
    private String telefone=StringUtils.EMPTY;
    
    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    
    @Override
    public boolean equals(Object other) {
        return (other instanceof User) && (id != null)
            ? id.equals(((User) other).id)
            : (other == this);
    }

    @Override
    public int hashCode() {
        return (id != null)
            ? (this.getClass().hashCode() + id.hashCode())
            : super.hashCode();
    }

    @Override
    public String toString() {
        return String.format("%s[id=%d]", getClass().getSimpleName(), id);
    }
    
}
