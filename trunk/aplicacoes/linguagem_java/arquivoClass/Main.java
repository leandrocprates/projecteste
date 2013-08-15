/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package teste;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author lprates
 */
public class Main {

    public Main(){
        System.out.println("Criando objeto da classe");
    }

    public void teste(){
        System.out.println("Dentro da funcao Teste");
    }

    public static void main(String[] args) {

        try {
            Class x = Main.class;
            Object o = x.newInstance();
            Main m = (Main) o ;
            m.teste();
        } catch (InstantiationException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
