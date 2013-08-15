
package utilizandolog4j;

import java.io.IOException;
import java.util.logging.Level;
import org.apache.log4j.PropertyConfigurator;
import org.apache.log4j.Logger;
import java.util.Properties;
import java.io.FileInputStream;
import org.apache.log4j.BasicConfigurator;

public class UtilizandoLog4jCarregandoArquivo {

    public static void main (String args [] ){

        Properties properties = new Properties();
        //BasicConfigurator.configure();
        
        try {
            properties.load(new FileInputStream("/home/leandro/log4j.properties"));
            PropertyConfigurator.configure(properties);
            Logger log  = Logger.getLogger("teste");
            log.trace("Mensagem TRACE");
            log.debug("Mensagem DEBUG");
            log.info("Mensagem INFO");
            log.warn("Mensagem WARN");
            
        } catch (IOException ex) {
            java.util.logging.Logger.getLogger(UtilizandoLog4jCarregandoArquivo.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
