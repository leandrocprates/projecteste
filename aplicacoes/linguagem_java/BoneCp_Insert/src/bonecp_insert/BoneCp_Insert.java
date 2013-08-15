/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package bonecp_insert;

 
import com.jolbox.bonecp.BoneCP;
import com.jolbox.bonecp.BoneCPConfig;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

/** A test project demonstrating the use of BoneCP in a JDBC environment.
 * @author wwadge
 *
 */
public class BoneCp_Insert {
 
	/** Start test
	 * @param args none expected.
	 */
	public static void main(String[] args) {
		BoneCP connectionPool = null;
		Connection connection = null;
                
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
			config.setPartitionCount(2);
			connectionPool = new BoneCP(config); // setup the connection pool
			
			connection = connectionPool.getConnection(); // fetch a connection
			
			if (connection != null){
				System.out.println("Connection successful!");
				Statement stmt = connection.createStatement();
                                
                                int i=0;
                                int telefone=1175016032;
                                while(i<=10000){
                                    stmt.execute("INSERT INTO registro (name,phone) VALUES('TESTE' , '"+telefone+"' ) " );
                                    i++;
                                    telefone++;
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
	