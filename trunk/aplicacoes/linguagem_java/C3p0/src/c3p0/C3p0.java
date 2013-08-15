/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package c3p0;

import com.mchange.v2.c3p0.*;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

public class C3p0 {

    public static void main(String[] args) {

        Connection con = null;
        Statement statement = null;
        ResultSet rs = null ; 
        
        Integer id = null ; 
        String name=null;
        String phone=null;
        
        long inicio = System.currentTimeMillis();

        try{
            ComboPooledDataSource cpds = new ComboPooledDataSource();
            cpds.setDriverClass( "com.mysql.jdbc.Driver" ); //loads the jdbc driver            
            cpds.setJdbcUrl( "jdbc:mysql://127.0.0.1:3306/test" );
            cpds.setUser("root");                                  
            cpds.setPassword("root");                        
            
            cpds.setMinPoolSize(10);
            cpds.setMaxPoolSize(10);
            cpds.setAcquireIncrement(5);
            
            con = cpds.getConnection();
            statement = con.createStatement();
            /*rs = statement.executeQuery("select *from registro");
            
            while (rs.next()){
                id=rs.getInt("id");
                name=rs.getString("name");
                phone=rs.getString("phone");

                System.out.println("Id: "+id);
                System.out.println("Name: "+name);
                System.out.println("Phone: "+phone);
                
            }*/

            int i=0;
            int telefone=1175016032;
            while(i<=10000){
                statement.execute("INSERT INTO registro (name,phone) VALUES('TESTE' , '"+telefone+"' ) " );
                i++;
                telefone++;
            }

            long fim = System.currentTimeMillis();

            System.out.println("Inicio - Fim = "+(fim-inicio));
            
            DataSources.destroy(cpds);
            
            
        }catch (Exception ex){
            System.out.println(ex);
        }
        
        
        
    }
}
