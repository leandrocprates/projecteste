/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package manipulandoarquivos;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;
import java.util.logging.Level;
import java.util.logging.Logger;


public class CarregandoArquivoCaractersEspeciais {

    public static void main (String args []){

        Properties properties = new Properties();
        String caracter_1,caracter_2;

        try {

            properties.load(new FileInputStream("/home/leandro/teste_carregamento.properties"));
            caracter_1=properties.getProperty("caracter_especial_1");
            caracter_2=properties.getProperty("caracter_especial_2");

            System.out.println("1="+caracter_1+"\n2="+caracter_2);

        } catch (IOException ex) {

            Logger.getLogger(CarregandoArquivoCaractersEspeciais.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
