/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.bd;

import com.model.User;
import java.io.Serializable;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author lprates
 */
public class UserBD implements Serializable{
    
    private Connection con = null;
    
    public UserBD(){
        
        ConectaBD conectaBD=new ConectaBD();
        con=conectaBD.getInstance();
    }
    
    public List<User> getLista(){
        
        List<User> userList=new ArrayList<User>();
        
        try {
            
            System.out.println("select *from user");
            
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery("select *from user");
            
            while(rs.next()){
                
                User user = new User();
                user.setId(rs.getInt("id"));
                user.setNome(rs.getString("nome"));
                user.setEndereco(rs.getString("endereco"));
                user.setTelefone(rs.getString("telefone"));
                
                userList.add(user);
            }
            
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
        
        return userList;
        
    }
    
    public void insert(User user){
        
        try{
            
            System.out.println(" insert into user (nome,endereco,telefone) values ( ? , ? , ? )  ");
            
            PreparedStatement ps = con.prepareStatement(" insert into user (nome,endereco,telefone) values ( ? , ? , ? ) ");
            
            ps.setString(1, user.getNome());
            ps.setString(2, user.getEndereco());
            ps.setString(3, user.getTelefone());
            
            ps.execute();
            
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        
    }
    
    public void update(User user){
        
        try{
            
            System.out.println(" update user set nome = ? , endereco = ? ,telefone = ? where id = ? ");
            
            PreparedStatement ps = con.prepareStatement(" update user set nome = ? , endereco = ? ,telefone = ? where id = ? ");
            
            ps.setString(1, user.getNome());
            ps.setString(2, user.getEndereco());
            ps.setString(3, user.getTelefone());
            ps.setInt(4, user.getId());
            
            ps.execute();
            
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        
    }
    
    public void delete(User user){
        
        try{
            
            System.out.println(" delete from user  where id = ? " );
            
            PreparedStatement ps = con.prepareStatement(" delete from user  where id = ? ");
            ps.setInt(1, user.getId());
            
            ps.execute();
            
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        
    }
    
    
}
