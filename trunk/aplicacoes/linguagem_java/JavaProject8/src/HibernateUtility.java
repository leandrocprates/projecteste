/*
 * Created on 11/05/2005
 *
 * C�digo desenvolvido por Maur�cio Linhares
 * 
 */


import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

/**
 * @author Maur�cio
 *
 * C�digo desenvolvido por Maur�cio Linhares
 * 
 */
public class HibernateUtility {

    private static SessionFactory factory;
        
    static {
    	//Bloco est�tico que inicializa o Hibernate
    	try {
    	
        factory = new Configuration().configure().buildSessionFactory();
    	
    	} catch (Exception e) {
    		
    		e.printStackTrace();
    		factory = null;
    	}
    }
    
    public static Session getSession() {
        //Retorna a sess�o aberta
    	return factory.openSession();
        
    }
    
}
