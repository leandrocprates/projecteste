/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package manipulandoarquivos;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.ObjectInputStream;
import java.io.EOFException;

/**
 *
 * @author leandro
 */
public class UtilizandoFileInputStream {

    private FileInputStream f;
    private ObjectInputStream file; 

    public void abrindoArquivo(){

        try {
            f = new FileInputStream("/home/leandro/arquivo_2.txt");
            file = new ObjectInputStream (f);
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(UtilizandoFileOutputStream.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(UtilizandoFileOutputStream.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public void leArquivo(){

        int numero =0;
        String palavra;

        try {
            
            while (true)
            {
                numero = file.readInt();
                palavra =(String) file.readObject();
                System.out.println("Numero=" + numero + " Mensagem=" + palavra );
            }
            
        } catch (EOFException ex){
            //Logger.getLogger(UtilizandoFileOutputStream.class.getName()).log(Level.SEVERE, null, ex);
            return ; 
        } catch (IOException ex){
            Logger.getLogger(UtilizandoFileOutputStream.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex){
            Logger.getLogger(UtilizandoFileOutputStream.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    public void fecharArquivo(){

        try {
            file.close();
        } catch (IOException ex) {
            Logger.getLogger(UtilizandoFileOutputStream.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    public static void main (String args[]){
        UtilizandoFileInputStream executar = new UtilizandoFileInputStream();
        executar.abrindoArquivo();
        executar.leArquivo();
        executar.fecharArquivo();
    }
}


