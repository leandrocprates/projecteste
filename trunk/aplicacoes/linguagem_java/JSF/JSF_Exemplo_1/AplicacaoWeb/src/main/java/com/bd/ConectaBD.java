/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.bd;

import java.sql.Connection;
import java.sql.DriverManager;

/**
 *
 * @author lprates
 */
public class ConectaBD {
    
    private static Connection con = null;
    
    public ConectaBD(){
        try{
            Class.forName("com.mysql.jdbc.Driver");
            con=DriverManager.getConnection("jdbc:mysql://localhost/cadastro", "admtiaxa", "tiaxa");
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
    }
    
    
    public Connection getInstance(){
        return con;
    }
    
    
    
}
