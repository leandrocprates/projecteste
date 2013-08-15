
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.PrintWriter;

import javax.servlet.ServletConfig;

public class CriandoServlet extends HttpServlet
{
    String banco;
    String servlet;

    @Override
    public void init (ServletConfig config){
        servlet=config.getServletName();
        banco=config.getInitParameter("host");
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) {

        PrintWriter resposta;
        try {
            resposta = resp.getWriter();
            resposta.println("<html>");
            resposta.println("<title>Resposta Do Get</title>");
            resposta.println("<body>Oi Tudo Bem Requisicao Bem Feita<br>");
            resposta.println("Seu banco de Dados esta em : " +banco+ "<br>" );
            resposta.println("Nome do Servlet : " +servlet+ "</body>");
            resposta.println("</html>");
            resposta.close();

        } catch (IOException ex) {
            Logger.getLogger(CriandoServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
