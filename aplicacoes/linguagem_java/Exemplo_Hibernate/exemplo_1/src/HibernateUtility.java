/*
 * Created on 11/05/2005
 *
 * Código desenvolvido por Maurício Linhares
 * 
 */


import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

/**
 * @author Maurício
 *
 * Código desenvolvido por Maurício Linhares
 * 
 */
public class HibernateUtility {

    private static SessionFactory factory;
        
    static {
    	//Bloco estático que inicializa o Hibernate
    	try {
    	
        factory = new Configuration().configure().buildSessionFactory();
    	
    	} catch (Exception e) {
    		
    		e.printStackTrace();
    		factory = null;
    	}
    }
    
    public static Session getSession() {
        //Retorna a sessão aberta
    	return factory.openSession();
        
    }
    
}
