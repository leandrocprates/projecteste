package dacurran.example;

import org.mortbay.jetty.Server;
import org.mortbay.jetty.servlet.ServletHttpContext;

public class JettyLauncher
{
    public static void main(String[] args) throws Exception
    {
        //We will create our server running at http://localhost:8070
        Server server = new Server();
        server.addListener(":8070");

        //We will deploy our servlet to the server at the path '/'
        //it will be available at http://localhost:8070
        ServletHttpContext context = (ServletHttpContext) server.getContext("/");
        context.addServlet("/MO", "dacurran.example.HelloWorldServlet");

        server.start();
    }
}

//http://wiki.eclipse.org/Jetty/Tutorial/Embedding_Jetty
//http://docs.codehaus.org/display/JETTY/Embedding+Jetty
//http://account.pacip.com/jetty/tut/overview.html
//http://api.dpml.net/jetty/5.1.6/org/mortbay/http/SocketListener.html
//http://www.cs.mun.ca/~yzchen/teaching/cs3715/notes/jetty/jetty.html
