/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author leandro
 */

package teste;

public class Cadastro
{
    private String Nome ;
    private String Telefone;

    public void setNome(String Nome){
        this.Nome=Nome;
    }

    public void setTelefone(String Telefone){
        this.Telefone=Telefone;
    }

    public String getNome(){
        return this.Nome;
    }

    public String getTelefone(){
        return this.Telefone;
    }

}



