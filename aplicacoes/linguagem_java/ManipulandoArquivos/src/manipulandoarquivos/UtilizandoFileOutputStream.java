/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package manipulandoarquivos;

import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.SecurityException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.ObjectOutputStream;

/**
 *
 * @author leandro
 */
public class UtilizandoFileOutputStream {

    private FileOutputStream f;
    private ObjectOutputStream file;
    
    public void abrindoArquivo(){

        try {
            f = new FileOutputStream("/home/leandro/arquivo_2.txt");
            file = new ObjectOutputStream(f);

        } catch (FileNotFoundException ex) {
            Logger.getLogger(UtilizandoFileOutputStream.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(UtilizandoFileOutputStream.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    public void escreveArquivo(){

        try {
            file.writeInt(234);
            file.writeObject("Ola234");
            file.flush();
            file.writeInt(456);
            file.writeObject("Ola456");
            file.flush();

        } catch (IOException ex) {
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
        UtilizandoFileOutputStream executar = new UtilizandoFileOutputStream();
        executar.abrindoArquivo();
        executar.escreveArquivo();
        executar.fecharArquivo();
    }

}
