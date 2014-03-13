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
import javax.annotation.PostConstruct;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.ViewScoped;
import javax.faces.context.FacesContext;

/**
 *
 * @author lprates
 */
@ManagedBean
@ViewScoped
public class UserBean implements Serializable{

    private List<User> userList=null;
    private List<User> filteredUsers; 
    private boolean list;
    private boolean edit;
    private boolean result;
    private User user=null;
    private UserBD userBD=null;
    
    public UserBean() {
        
        list=true;
        edit=false;
        result=false;
        user=new User();
        userBD=new UserBD();
        userList=new ArrayList<User>();
    }
    
    
    @PostConstruct
    public void init() {
        System.out.println("Invocando Post-Construct");
    }    
    
    public List<User> getUserList() {
        
        if ( FacesContext.getCurrentInstance().getRenderResponse() ){
            userList.clear();
            userList.addAll(userBD.getLista());
        }

        return userList;
    }


    public List<User> getFilteredUsers() {
        return filteredUsers;
    }

    public void setFilteredUsers(List<User> filteredUsers) {
        this.filteredUsers = filteredUsers;
    }
    
    
    public void novo(){
        list=false;
        edit=true;
        result=false;
        user=new User();
    }
    
    public void editar(){
        list=false;
        edit=true;
        result=false;
    }
    
    public void deletar(){
        list=true;
        edit=false;
        result=false;
        
        userBD.delete(user);
    }
    
    public void listar(){
        list=true;
        edit=false;
        result=false;
    }

    public void salvar(){
        
        if(user.getId()>0){
            userBD.update(user);
        } else{
            userBD.insert(user);
        }
        
        list=false;
        edit=false;
        result=true;
    }
    
    public boolean isList() {
        return list;
    }

    public boolean isEdit() {
        return edit;
    }

    public boolean isResult() {
        return result;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }
    
    
    
    
}
