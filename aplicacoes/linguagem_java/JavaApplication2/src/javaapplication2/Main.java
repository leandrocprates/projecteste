/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication2;

import java.sql.DriverManager;
import java.sql.SQLException;

public class Main{
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            System.out.println("Driver carregado com sucesso!");
        }
        catch (Exception ex) {
            System.out.println("Driver nao pode ser carregado!");
        }
    }
}

