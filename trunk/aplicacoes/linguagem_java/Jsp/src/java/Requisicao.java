/*
 * Classe que Recebe uma requisicao vindo de uma pagina JSP
 * 
 */

/**
 *
 * @author leandro
 */

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.PrintWriter;

public class Requisicao extends HttpServlet
{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
    {
        String nome=req.getParameter("firstName");
        String telefone=req.getParameter("telefone");
        
        try {
            PrintWriter resposta = resp.getWriter();
            resposta.print("<html>");
            resposta.print("<head>");
            resposta.print("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
            resposta.print("<title>Retornando Status do Servlet</title>");
            resposta.print("</head>");
            resposta.print("<body>");
            resposta.print("Nome: " +nome );
            resposta.print("<br>" );
            resposta.print("Telefone: " +telefone );
            resposta.print("</body>");
            resposta.print("</html>");
            resposta.close();

        } catch (IOException ex) {
            Logger.getLogger(Requisicao.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
