<%-- 
    Document   : formulario_3
    Created on : 13/12/2009, 12:02:51
    Author     : leandro
    Objetivo : Encaminhar o request para o servelt Requisicao


--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<%@page errorPage="Erro.jsp" %>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page - Formulario_3.jsp</title>
    </head>
    <body>

        <%
            String nome=request.getParameter("firstName");

            if (nome!=null)
            {
        %>

        <jsp:forward page = "Requisicao" >
            <jsp:param name="telefone" value="85016033" />
        </jsp:forward>


        <%
            }
            else
            {
        %>

        <form name="cad" action="formulario_3.jsp" method="get">
            Nome:<input type="text" name="firstName" /><br>
            Telefone:<input type="text" name="telefone" />
            <input type="submit" value="Enviar" name="enviar" />
        </form>

        <%
            }
        %>

    </body>
</html>
