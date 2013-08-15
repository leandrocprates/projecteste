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
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;

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
                AtomicInteger telefone = new AtomicInteger(1175016032);
                ExecutorService pool = Executors.newFixedThreadPool(20);
                
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
			config.setMinConnectionsPerPartition(10);
			config.setMaxConnectionsPerPartition(10);
			config.setPartitionCount(1);
			connectionPool = new BoneCP(config); // setup the connection pool
			
                        int i=0;
                        while(i<10){
                            pool.execute(new Worker(connectionPool,telefone));
                            i++;
                        }
                        
                        pool.shutdown();

				//espera todas as threads terminarem para continuar a execucao
                        pool.awaitTermination(1, TimeUnit.DAYS);
                        
                        System.out.println("Total connections ==> " + connectionPool.getTotalCreatedConnections());

                        long fim = System.currentTimeMillis();
                        
                        System.out.println("Inicio - Fim = "+(fim-inicio));
                        
			connectionPool.shutdown(); // shutdown connection pool.
                        
		} catch (SQLException e) {
			e.printStackTrace();
                } catch (Exception e) {
                        System.err.println(e);
		}
                
	}
        
}
	

class Worker implements Runnable{

    AtomicInteger telefone = null;
    BoneCP connectionPool = null ; 
    
    public Worker(BoneCP connectionPool, AtomicInteger telefone){
        this.connectionPool = connectionPool;
        this.telefone=telefone;
    }
    
    @Override
    public void run() {
        
        try{
            int i=0;
            while(i<1000){
                Connection con = connectionPool.getConnection();
                Statement statement = con.createStatement();
                statement.execute("INSERT INTO registro (name,phone) VALUES('TESTE' , '"+telefone.getAndIncrement()+"' ) " );
                con.close();
                i++;
            }
            
        }catch (Exception ex){
            System.err.println("Worker:"+ex);
        }
        
    }

}
