package utilizandolog4j;

import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.Logger;
import org.apache.log4j.Level;
import org.apache.log4j.FileAppender;
import org.apache.log4j.PatternLayout;

public class UtilizandoLog4JSetandoConfiguracao {

    public static void main(String[] args) {
        BasicConfigurator.configure();
        Logger log = Logger.getLogger(UtilizandoLog4JSetandoConfiguracao.class);

        FileAppender fileappender = new FileAppender ();
        fileappender.setAppend(true);
        fileappender.setFile("/home/leandro/teste_novo.log");
        fileappender.setName("FileAppenderLog");
        
        PatternLayout patternLayout=new PatternLayout();
        patternLayout.setConversionPattern(PatternLayout.TTCC_CONVERSION_PATTERN);
        
        fileappender.setLayout(patternLayout);
        fileappender.activateOptions();

        log.addAppender(fileappender);
        log.setLevel(Level.DEBUG);
        log.trace("LOG TRACE");
        log.debug("LOG DEBUG");
        log.info("LOG INFO");
    }
}

