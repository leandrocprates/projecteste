<%-- 
    Document   : mostraObjeto
    Created on : 13/12/2009, 17:39:27
    Author     : leandro
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<%@page errorPage="Erro.jsp" %>

<jsp:useBean id="cadastro" scope="request" class="teste.Cadastro"/>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page - Mostra Objeto</title>
    </head>
    <body>
        <table border="1">
            <thead>
                <tr>
                    <th>Nome</th>
                    <th>Telefone</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><%=cadastro.getNome()%></td>
                    <td><%=cadastro.getTelefone()%></td>
                </tr>
            </tbody>
        </table>

    </body>
</html>
