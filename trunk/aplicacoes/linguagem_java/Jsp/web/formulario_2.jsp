<%-- 
    Document   : formulario_2
    Created on : 13/12/2009, 11:22:17
    Author     : leandro
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<%@page errorPage="Erro.jsp" %>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page - Formulario_2.jsp</title>
    </head>
    <body>

        <%
            String nome=request.getParameter("firstName");

            if (nome!=null)
            {
        %>

        <jsp:forward page = "formulario.jsp" >
          <jsp:param name="telefone" value="9999-9999" />
        </jsp:forward>

        <%
            }
            else
            {
        %>

        <form name="cad" action="formulario_2.jsp">
            Nome:<input type="text" name="firstName" /><br>
            Telefone:<input type="text" name="telefone" />
            <input type="submit" value="Enviar" name="enviar" />
        </form>

        <%
            }
        %>
        
    </body>
</html>
