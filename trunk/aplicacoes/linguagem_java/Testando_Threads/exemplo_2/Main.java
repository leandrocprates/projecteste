/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package acessandobancocomthreads;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.logging.Level;
import java.util.logging.Logger;


class InserindoNoBanco implements Runnable{

    private Connection conection = null ;
    private Statement statement ;
    private String query = " INSERT INTO registro VALUES('Leandro',0000000) ";

    public void run() {

        try {
            Class.forName("com.mysql.jdbc.Driver");
            conection = DriverManager.getConnection("jdbc:mysql://localhost/teste", "root", "00000");
            statement = conection.createStatement();
            statement.execute(query);

        } catch (Exception ex) {
            Logger.getLogger(InserindoNoBanco.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

}

public class Main {

    public static void main(String[] args) {

        ExecutorService service = Executors.newFixedThreadPool(5);

        for (int i=0 ; i<5 ; i++){
            service.execute(new InserindoNoBanco());
        }
        service.shutdown();
    }

}
