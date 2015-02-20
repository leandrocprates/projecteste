package dacurran.example;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class HelloWorldServlet extends HttpServlet
{
    protected void doGet(HttpServletRequest httpServletRequest, HttpServletResponse httpServletResponse) throws ServletException, IOException
    {
        
        String appid = httpServletRequest.getParameter("appid");
        String conta = httpServletRequest.getParameter("conta");
        
        System.out.println("Appid : "+appid);
        System.out.println("Conta : "+conta);
        
        httpServletResponse.setContentType("text/plain");
        PrintWriter out = httpServletResponse.getWriter();
        out.println("Hello World!");
        out.close();
        
        
    }
    
}