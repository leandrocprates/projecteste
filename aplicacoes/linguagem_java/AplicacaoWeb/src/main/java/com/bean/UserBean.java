/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.bean;

import com.bd.UserBD;
import com.lowagie.text.Document;
import com.lowagie.text.PageSize;
import com.lowagie.text.Paragraph;
import com.lowagie.text.pdf.PdfWriter;
import com.model.User;
import java.awt.Desktop;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import javax.annotation.PostConstruct;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.ViewScoped;
import javax.faces.context.ExternalContext;
import javax.faces.context.FacesContext;
import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

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
    
    private Date date3;
    
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

    public Date getDate3() {
        return date3;
    }

    public void setDate3(Date date3) {
        this.date3 = date3;
    }

    
    public void gerarExcel(){
        
        HSSFWorkbook workbook = new HSSFWorkbook();
        HSSFSheet firstSheet = workbook.createSheet("Aba1");        
        
        HSSFRow row = firstSheet.createRow(0);
        HSSFCell cell = row.createCell(0);
        cell.setCellValue("Primeiro valor");
        cell = row.createCell(1);
        cell.setCellValue("Segundo valor");
        
        row = firstSheet.createRow(1);
        cell = row.createCell(0);
        cell.setCellValue("Segunda linha");
        
        try{
            FacesContext facesContext = FacesContext.getCurrentInstance();
            ExternalContext externalContext = facesContext.getExternalContext();
            externalContext.setResponseContentType("application/vnd.ms-excel");
            externalContext.setResponseHeader("Content-Disposition", "attachment; filename=\"my.xls\"");

            workbook.write(externalContext.getResponseOutputStream());
            facesContext.responseComplete();        
            
        }catch(Exception e){
            System.out.println(e);
        }
        
    }
    
    
    public void gerarPDF1(){
        
        try{
            
            Document doc = new Document(PageSize.A4);

            OutputStream os = new FileOutputStream("C:/Users/lprates/Downloads/out.pdf");
            PdfWriter.getInstance(doc, os);
            doc.open();        

            Paragraph p = new Paragraph("Meu primeiro arquivo PDF!");

            doc.add(p);
            
            doc.close();
            os.close();
            
            //abre pdf usando o PDF Reader instalado na maquina do Usuario
            Desktop.getDesktop().open(new File("C:/Users/lprates/Downloads/out.pdf"));
            
        }catch(Exception e){
            
        }
        
    }
    
    
    
    public void gerarPDF2(){
        
        try{
            
            Document doc = new Document();
            ByteArrayOutputStream baosPDF = new ByteArrayOutputStream();
            PdfWriter docWriter = null;
            docWriter = PdfWriter.getInstance(doc, baosPDF);            

            doc.open();
            
            doc.add(new Paragraph(
                "This document was created by a class named: "
                + this.getClass().getName()));

            doc.add(new Paragraph(
                "This document was created on "
                + new java.util.Date()));

            doc.close();
            docWriter.close();            

            FacesContext facesContext = FacesContext.getCurrentInstance();
            ExternalContext externalContext = facesContext.getExternalContext();
            externalContext.setResponseContentType("application/pdf");
            
            // com a opcao inline abre o PDF no browser do usuario
            //externalContext.setResponseHeader("Content-Disposition", "inline; filename=\"my.pdf\"");
            
            // com a opcao attachment faz download do PDF no computador do usuario
            externalContext.setResponseHeader("Content-Disposition", "attachment; filename=\"my.pdf\"");
            

            OutputStream responseOutputStream = externalContext.getResponseOutputStream();
            
            baosPDF.writeTo(responseOutputStream);
            responseOutputStream.flush();
            baosPDF.reset();
            
            facesContext.responseComplete();        
            
            
        }catch(Exception e){
            
        }
        
        
    }
    
    
}
