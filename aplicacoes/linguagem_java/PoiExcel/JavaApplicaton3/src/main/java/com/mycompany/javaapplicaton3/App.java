package com.mycompany.javaapplicaton3;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        
        try{

            Connection conn = getConnection();
            conn.setAutoCommit(false);
            Statement st = conn.createStatement();

            st.setFetchSize(2);
            ResultSet rs = st.executeQuery(" select *from user ");

            while (rs.next()) {
                System.out.print( String.format("Id: [%d]  Nome: [%s]  Endereco: [%s] Telefone: [%s] " , 
                        rs.getInt("id"), rs.getString("nome") , rs.getString("endereco") , rs.getString("telefone") )  );
                System.out.println();
                
            }

            rs.close();
            st.close();
            conn.close();        
            
        } catch( Exception e ){
            
        }
        
    }
    
    
    private static Connection getConnection() throws Exception {
        Class.forName("com.mysql.jdbc.Driver");
        String url = "jdbc:mysql://localhost/cadastro";

        return DriverManager.getConnection(url, "admtiaxa", "tiaxa");
    }
}
