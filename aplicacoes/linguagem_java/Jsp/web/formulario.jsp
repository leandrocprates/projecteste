<%-- 
    Document   : formulario
    Created on : 13/12/2009, 10:22:29
    Author     : leandro
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<%@page errorPage="Erro.jsp" %>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page - Formulario.jsp</title>
    </head>
    <body>

        <% 
            String nome=request.getParameter("firstName");
            String telefone=request.getParameter("telefone");
        
            if (nome!=null)
            {
        %>

        O Nome obtido e: <%=nome%><br>
        O Telefone obtido e: <%=telefone%><br>

        <%
            }
            else
            {
        %>
        
        <form name="cad" action="formulario.jsp">
            <input type="text" name="firstName" />
            <input type="submit" value="Enviar" name="enviar" />
        </form>

        <%
            }
        %>

    </body>
</html>
