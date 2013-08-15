/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javaappletcomacessobd;

import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.Connection;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Conectar {

    Connection conexao=null;
    Statement statement=null;
    ResultSet resultset=null;

    public Conectar() throws ClassNotFoundException, SQLException
    {
        Class.forName("com.mysql.jdbc.Driver");
        conexao = DriverManager.getConnection("jdbc:mysql://127.0.0.1/teste","root","********");
        statement = conexao.createStatement();
    }

    public ResultSet buscaRegistro() throws SQLException {
        resultset = statement.executeQuery("SELECT * FROM registro ");
        while (resultset.next()){
            System.out.println( resultset.getString(1) );
            System.out.println( resultset.getInt(2) );
        }
        return resultset;
    }

    public static void main(String[] args) {
        
        Conectar conectar=null;
        
        try {
            conectar = new Conectar();
            conectar.buscaRegistro();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Conectar.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(Conectar.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
