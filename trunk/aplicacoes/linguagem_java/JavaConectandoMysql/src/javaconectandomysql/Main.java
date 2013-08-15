/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javaconectandomysql;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * 
 * @author leandro
 * @version 1.0.0
 * @deprecated Este e um teste de conexao ao banco de dados
 */

public class Main {

    public static void main(String[] args)
    {
        Connection conexao=null;
        Statement statement=null;
        ResultSet resultado=null;
        PreparedStatement prepared=null;
        
        try {
            Class.forName("com.mysql.jdbc.Driver");

            conexao = DriverManager.getConnection("jdbc:mysql://localhost/teste", "root", "*****");
            statement=conexao.createStatement();

            resultado=statement.executeQuery("SELECT * FROM Cadastro");

            while (resultado.next() )
            {
                System.out.printf("Nome [%s] , Endereco [%s] , Telefone [%d]\n", resultado.getString("Nome") , resultado.getString("Endereco") , resultado.getInt("Telefone") );
            }

            prepared=conexao.prepareStatement("SELECT * FROM Cadastro where Nome=? ");
            prepared.setString(1, "Ariane");
            resultado=prepared.executeQuery();

            while (resultado.next() )
            {
                System.out.printf("Nome [%s] , Endereco [%s] , Telefone [%d]\n", resultado.getString("Nome") , resultado.getString("Endereco") , resultado.getInt("Telefone") );
            }

            statement.execute("INSERT INTO Cadastro VALUES('Teste' , 'Teste' ,  ****** )" );


        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
        finally
        {
            try {
                statement.close();
                resultado.close();
                conexao.close();
            } catch (SQLException ex) {
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
            }

        }


    }

}
