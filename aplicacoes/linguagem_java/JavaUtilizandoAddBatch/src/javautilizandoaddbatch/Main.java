/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javautilizandoaddbatch;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Main {

  public static void main(String[] args) {
      
    Connection connection = null;
    PreparedStatement statement = null;
    
    try {
        
          Class.forName("com.mysql.jdbc.Driver").newInstance();
          String url = "jdbc:mysql://localhost/teste";
          connection = DriverManager.getConnection(url, "root", "******");

          String sql = "INSERT INTO Cadastro VALUES(?,?,?) ";
          statement = connection.prepareStatement(sql);

          statement.setString(1, "Teste_1");
          statement.setString(2, "Teste_1");
          statement.setInt(3, 00000000);
          statement.addBatch();

          statement.setString(1, "Teste_2");
          statement.setString(2, "Teste_2");
          statement.setInt(3, 000000);
          statement.addBatch();

          statement.setString(1, "Teste_3");
          statement.setString(2, "Teste_3");
          statement.setInt(3, 000000);
          statement.addBatch();

          statement.executeBatch();
          
    } catch (Exception e) {
        
          e.printStackTrace();
          
    } finally {

          if (statement != null) {
            try {
              statement.close();
            } catch (SQLException e) {

            } // nothing we can do
          }

          if (connection != null) {
            try {
              connection.close();
            } catch (SQLException e) {

            } // nothing we can do
          }
    }
  }
}
