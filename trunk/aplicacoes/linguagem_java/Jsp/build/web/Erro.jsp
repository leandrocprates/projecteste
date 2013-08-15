<%-- 
    Document   : Erro
    Created on : 19/12/2009, 16:40:44
    Author     : leandro
--%>

<%@page isErrorPage="true"%>
<%@page import="java.util.*" %>
<%@page import="java.sql.*"%>


<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>

    <body>

        <%
        if (exception instanceof SQLException )
            {
        %>

        A SQLException

        <% 
            } else if ( exception instanceof ClassNotFoundException) {
        %>

        Classe ClassNotFoundException

        <% 
            }
        %>

        <%= "Excecao Gerada: " + exception.getMessage() %>

    </body>
</html>
