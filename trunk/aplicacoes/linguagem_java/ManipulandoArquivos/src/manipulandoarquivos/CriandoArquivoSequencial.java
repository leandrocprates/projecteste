/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package manipulandoarquivos;
import java.util.Formatter;
import java.io.FileNotFoundException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.lang.Exception;
import java.util.FormatterClosedException;

/**
 *
 * @author leandro
 */
public class CriandoArquivoSequencial {

    private Formatter arquivo;

    public void openFile(){
        try {
            arquivo = new Formatter("/home/leandro/arquivo.txt");
        } catch (FileNotFoundException ex) {
            Logger.getLogger(CriandoArquivoSequencial.class.getName()).log(Level.SEVERE, null, ex);
        } catch (Exception ex){
            Logger.getLogger(CriandoArquivoSequencial.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void escrevendoConteudo(){
        CadastroRegistro registro=new CadastroRegistro();
        registro.setNome("Leandro Cesar Prates");
        registro.setEndereco("Av JoaoPessoa 408");
        registro.setTelefone("75016032");
        //arquivo.format("\t%s\t%s\t%s\n", registro.getNome() , registro.getEndereco() , registro.getTelefone() );
        arquivo.format("%s\t%s\t%s\n", registro.getNome() , registro.getEndereco() , registro.getTelefone() );
        
        arquivo.flush();
        registro.setNome("Ariane Lucia Prates");
        registro.setEndereco("Av JoaoPessoa 408");
        registro.setTelefone("22333018");
        //arquivo.format("\t%s\t%s\t%s\n", registro.getNome() , registro.getEndereco() , registro.getTelefone() );
        arquivo.format("%s\t%s\t%s\n", registro.getNome() , registro.getEndereco() , registro.getTelefone() );
        
        arquivo.flush(); // envia a saida para o arquivo
        registro.setNome("Vanesa Aparecida Prates");
        registro.setEndereco("Av JoaoPessoa 408");
        registro.setTelefone("62333018");
        //arquivo.format("\t%s\t%s\t%s\n", registro.getNome() , registro.getEndereco() , registro.getTelefone() );
        arquivo.format("%s\t%s\t%s\n", registro.getNome() , registro.getEndereco() , registro.getTelefone() );

        arquivo.flush(); // envia a saida para o arquivo
        registro.setNome("Caracteres especiais ç ã á");
        registro.setEndereco("º ª ");
        registro.setTelefone("62333018");
        //arquivo.format("\t%s\t%s\t%s\n", registro.getNome() , registro.getEndereco() , registro.getTelefone() );
        arquivo.format("%s\t%s\t%s\n", registro.getNome() , registro.getEndereco() , registro.getTelefone() );

    }

    public void closeFile(){
        try {
            arquivo.close();
        } catch (FormatterClosedException ex){
            Logger.getLogger(CriandoArquivoSequencial.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void main(String args[]){
        CriandoArquivoSequencial geraArquivo=new CriandoArquivoSequencial();
        geraArquivo.openFile();
        geraArquivo.escrevendoConteudo();
        geraArquivo.closeFile();
    }

}
