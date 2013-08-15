<%-- 
    Document   : index
    Created on : 13/12/2009, 09:55:41
    Author     : leandro
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<%@page errorPage="Erro.jsp" %>

<html>
    <head>
        <meta http-equiv="refresh" content="2">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Ola Mundo!</h1>
        <%= new java.util.Date() %>

        <table border="1">
            <thead>
                <tr>
                    <th>Link</th>
                    <th>Descricao</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><a href="formulario.jsp">link_1</a></td>
                    <td>Requisicoes recebidas num mesmo arquivo</td>
                </tr>
                <tr>
                    <td><a href="formulario_2.jsp">link_2</a></td>
                    <td>Redireciona requisicao para um arquivo JSP</td>
                </tr>
                <tr>
                    <td><a href="formulario_3.jsp">link_3</a></td>
                    <td>Redireciona requisicao para um Servlet</td>
                </tr>
                <tr>
                    <td><a href="UseBean.jsp">Utilizando Objetos</a></td>
                    <td>Utiliza objetos de uma classe em um JSP</td>
                </tr>
            </tbody>
        </table>

    </body>
</html>
