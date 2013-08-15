/*
 * Monta um xml com os dados retornados do banco de dados
 *
 */


package javautilizandowebrowset;

import java.io.FileOutputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.sql.rowset.WebRowSet;

import com.sun.rowset.WebRowSetImpl;
import com.sun.rowset.internal.WebRowSetXmlReader;
import com.sun.rowset.internal.WebRowSetXmlWriter;

public class Main {

   public static void main(String[] args) throws Exception {

        Connection conn = getConnection();

        PreparedStatement p = conn.prepareStatement("SELECT * FROM Cadastro");

        ResultSet rs = p.executeQuery();

        WebRowSet wrs = new WebRowSetImpl();

        wrs.populate(rs);

        p.close();

        conn.close();

        wrs.writeXml(new FileOutputStream("tipoequipamento.xml"));

        wrs.close();

    }

    private static Connection getConnection() throws ClassNotFoundException,
              SQLException {

         try {
              Class.forName("com.mysql.jdbc.Driver").newInstance();
         } catch (InstantiationException e) {
              e.printStackTrace();
         } catch (IllegalAccessException e) {
              e.printStackTrace();
         }

         Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/teste", "root", "*******");

         return conn;

      }
}
