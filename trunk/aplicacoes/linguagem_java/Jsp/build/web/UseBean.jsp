<%-- 
    Document   : UseBean
    Created on : 13/12/2009, 17:30:30
    Author     : leandro
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<%@page errorPage="Erro.jsp" %>

<jsp:useBean id="cadastro" scope="request" class="teste.Cadastro" />

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>

        <%
            String nome=request.getParameter("firstName");
            String telefone=request.getParameter("telefone");

            if (nome!=null)
            {
                cadastro.setNome(nome);
                cadastro.setTelefone(telefone);
        
        %>

       <jsp:forward page="mostraObjeto.jsp"/>

        <%
            }
            else
            {
        %>

        <form name="cad" action="UseBean.jsp" method="get">
            Nome:<input type="text" name="firstName" /><br>
            Telefone:<input type="text" name="telefone" />
            <input type="submit" value="Enviar" name="enviar" />
        </form>

        <%
            }
        %>
        
    </body>
</html>
