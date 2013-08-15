/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package jetty;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.mortbay.http.SocketListener;
import org.mortbay.jetty.Server;
import org.mortbay.jetty.servlet.ServletHttpContext;

public class Jetty {

    public static void main(String[] args) {

        try {
            
            Server server = new Server();
            SocketListener listener = new SocketListener();            
            listener.setHost("localhost");
            listener.setPort(8070);
            listener.setMinThreads(5);
            listener.setMaxThreads(250);
            server.addListener(listener);            

            ServletHttpContext context = (ServletHttpContext) server.getContext("/");
            context.addServlet("/MO", "jetty.HelloWorldServlet");
            
            server.start();
            server.join();
           
        /*//We will create our server running at http://localhost:8070
        Server server = new Server();
        server.addListener(":8070");

        //We will deploy our servlet to the server at the path '/'
        //it will be available at http://localhost:8070
        ServletHttpContext context = (ServletHttpContext) server.getContext("/");
        context.addServlet("/MO", "jetty.HelloWorldServlet");

        server.start();
        */
            
        } catch (Exception ex) {
            Logger.getLogger(Jetty.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
}




