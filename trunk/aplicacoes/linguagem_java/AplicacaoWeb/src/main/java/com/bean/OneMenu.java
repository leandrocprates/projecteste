/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.bean;

import com.bd.UserBD;
import com.model.User;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.ViewScoped;


/**
 *
 * @author lprates
 */
@ManagedBean
@ViewScoped
public class OneMenu implements Serializable {

    private List<User> userList=null;
    private UserBD userBD=null;
    private User user;
    
    public OneMenu() {
        userBD=new UserBD();
        userList=new ArrayList<User>();
        user=new User();
    }
    
    public List<User> getUserList() {
        userList.clear();
        userList.addAll(userBD.getLista());
        return userList;
    }
    
    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        if(user==null){
            this.user=new User();
        }else{
            this.user = user;
        }
    }
    
    public String save(){
        System.out.println("Salvando Usuario : "+user.getNome());
        
        if(user.getId()==0){
            userBD.insert(user);
        }else{
            userBD.update(user);
        }
        
        user=new User();
        return "selectonemenu";
        
    }
    
    
}
