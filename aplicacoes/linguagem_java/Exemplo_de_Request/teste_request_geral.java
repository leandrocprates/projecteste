/* Bibliotecas que este exemplo depende :
 *
 * commons-httpclient-3.1-rc1.jar
 * commons-logging-api-1.0.4.jar
 * commons-codec-1.4.jar
 *
 * 
 */

package com.example.tests;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpException;
import org.apache.commons.httpclient.methods.GetMethod;

public class teste_request_geral {

    public static void main(String args[]){

        HttpClient httpclient = new HttpClient();
        GetMethod get = new GetMethod ("http://www.uol.com.br");
        
        try {
            int status = httpclient.executeMethod(get);
            String response = new String ( get.getResponseBody() );
            System.out.println("Status: " + status);
            System.out.println("Resposta: " + response);

        } catch (HttpException ex) {
            Logger.getLogger(teste_gkpromo_request.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(teste_gkpromo_request.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}



