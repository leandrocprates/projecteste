/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package manipulandoarquivos;

/**
 *
 * @author leandro
 */
public class CadastroRegistro {
    private String nome ;
    private String endereco ;
    private String telefone ;

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome=nome;
    }

    public String getEndereco(){
        return endereco;
    }

    public void setEndereco(String endereco){
        this.endereco=endereco;
    }

    public String getTelefone(){
        return telefone;
    }

    public void setTelefone(String telefone){
        this.telefone=telefone;
    }

}
