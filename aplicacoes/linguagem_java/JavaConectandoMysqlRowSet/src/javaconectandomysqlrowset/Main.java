/*
 * Utilizando a Interface JdbcRowSet para conectar ao banco de dados
 * 
 */

package javaconectandomysqlrowset;

import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.sql.rowset.JdbcRowSet;
import com.sun.rowset.JdbcRowSetImpl;

public class Main {

    public static void main(String[] args) {
        
        try {
            
            Class.forName("com.mysql.jdbc.Driver");
            JdbcRowSet conectando=new JdbcRowSetImpl();
            
            conectando.setUrl("jdbc:mysql://localhost/teste");
            conectando.setUsername("root");
            conectando.setPassword("******");
            conectando.setCommand("SELECT * FROM Cadastro");
            conectando.execute();

            while ( conectando.next()){
                System.out.printf("Nome: [%s] , Endereco: [%s] , Telefone: [%s]\n" , conectando.getString(1) , conectando.getString(2) , conectando.getString(3) );
                String nome = conectando.getString(1);
            }

        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
