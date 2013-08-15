import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.PrintWriter;

public class Welcome2 extends HttpServlet
{
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response  )
    {
        try {
            PrintWriter resposta = response.getWriter();

            resposta.println("<html>");
            resposta.println("<title>Resposta Do Get</title>");
            resposta.println("<body>Oi Tudo Bem Requisicao Bem Feita<br>");
            resposta.println("Servelet : " + request.getServerName()+ "<br>" );
            resposta.println("</html>");
            resposta.close();

        } catch (IOException ex) {
            Logger.getLogger(Welcome2.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

