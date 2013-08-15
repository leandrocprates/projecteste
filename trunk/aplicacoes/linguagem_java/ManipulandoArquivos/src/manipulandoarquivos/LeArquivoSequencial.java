/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package manipulandoarquivos;

import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.File;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author leandro
 */
public class LeArquivoSequencial {

    public static void separaString(String linha ){
        CadastroRegistro registro = new CadastroRegistro();
        Scanner entrada = new Scanner(linha).useDelimiter("\t");

        registro.setNome(entrada.next());
        registro.setEndereco(entrada.next());
        registro.setTelefone(entrada.next());

        System.out.println("Nome : " + registro.getNome() + "\nEndereco: " + registro.getEndereco() + "\nTelefone : " +  registro.getTelefone() );
        entrada.close();
    }

    public static void main(String args[]){

        try {
            Scanner entrada = new Scanner(new File("/home/leandro/arquivo.txt")).useDelimiter(System.getProperty("line.separator"));

            while (entrada.hasNext()){
                separaString(entrada.next());
            }

        } catch (FileNotFoundException ex) {
            Logger.getLogger(LeArquivoSequencial.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            
        }
    }
}
