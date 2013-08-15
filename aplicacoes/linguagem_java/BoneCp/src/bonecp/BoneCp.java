/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package bonecp;

 
import com.jolbox.bonecp.BoneCP;
import com.jolbox.bonecp.BoneCPConfig;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory; 

/** A test project demonstrating the use of BoneCP in a JDBC environment.
 * @author wwadge
 *
 */
public class BoneCp {
 
	/** Start test
	 * @param args none expected.
	 */
	public static void main(String[] args) {
		BoneCP connectionPool = null;
		Connection connection = null;
                
                Integer id = null ; 
                String name=null;
                String phone=null;
                
                long inicio = System.currentTimeMillis();
 
		try {
			// load the database driver (make sure this is in your classpath!)
			Class.forName("com.mysql.jdbc.Driver");
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}
		
		try {
			// setup the connection pool
			BoneCPConfig config = new BoneCPConfig();
			config.setJdbcUrl("jdbc:mysql://127.0.0.1:3306/test"); // jdbc url specific to your database, eg jdbc:mysql://127.0.0.1/yourdb
			config.setUsername("root"); 
			config.setPassword("root");
			config.setMinConnectionsPerPartition(5);
			config.setMaxConnectionsPerPartition(10);
			config.setPartitionCount(1);
			connectionPool = new BoneCP(config); // setup the connection pool
			
			connection = connectionPool.getConnection(); // fetch a connection
			
			if (connection != null){
				System.out.println("Connection successful!");
				Statement stmt = connection.createStatement();
				ResultSet rs = stmt.executeQuery("SELECT *FROM test.registro"); // do something with the connection.
				while(rs.next()){
                                        id = rs.getInt("id");
                                        name=rs.getString("name");
                                        phone=rs.getString("phone");
					
                                        System.out.println("Id: "+id);
                                        System.out.println("Name: "+name);
                                        System.out.println("Phone: "+phone);
				}
			}
                        
                        System.out.println("Total connections ==> " + connectionPool.getTotalCreatedConnections());

                        long fim = System.currentTimeMillis();
                        
                        System.out.println("Inicio - Fim = "+(fim-inicio));
                        
                        Thread.sleep(3000);
                        
			connectionPool.shutdown(); // shutdown connection pool.
		} catch (SQLException e) {
			e.printStackTrace();
                } catch (Exception e) {
                    
		} finally {
			if (connection != null) {
				try {
					connection.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
	