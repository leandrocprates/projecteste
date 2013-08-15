/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package c3p0;

import com.mchange.v2.c3p0.ComboPooledDataSource;
import com.mchange.v2.c3p0.DataSources;
import java.sql.Connection;
import java.sql.Statement;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;

public class C3p0 {

    public static void main(String[] args) {

        AtomicInteger telefone = new AtomicInteger(1175016032);
        ExecutorService pool = Executors.newFixedThreadPool(20);
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
            
            int i=0;
            
            while(i<10){
                pool.execute(new Worker(cpds,telefone));
                i++;
            }

            pool.shutdown();
            
            pool.awaitTermination(1, TimeUnit.DAYS);
            
            long fim = System.currentTimeMillis();

            System.out.println("Inicio - Fim = "+(fim-inicio));
            
            DataSources.destroy(cpds);
            
        }catch (Exception ex){
            System.out.println("Main:"+ex);
        }
        
    }
}

class Worker implements Runnable{

    AtomicInteger telefone = null;
    ComboPooledDataSource cpds = null ; 
    
    public Worker(ComboPooledDataSource cpds, AtomicInteger telefone){
        this.cpds = cpds;
        this.telefone=telefone;
    }
    
    @Override
    public void run() {
        
        try{
            int i=0;
            while(i<1000){
                Connection con = cpds.getConnection();
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



