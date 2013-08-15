
#include <iostream>
#include <time.h>
#include <string>

#include "Poco/Logger.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Message.h"


using Poco::Logger;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using Poco::FileChannel;
using Poco::Message;

char *geraData()
{
        time_t rawtime;
        struct tm * timeinfo;
        char *buffer;

        buffer = (char * )malloc (sizeof(char) *30 );

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        strftime (buffer,30,"%Y%m%d",timeinfo);

        return buffer ;
}


int main(int argc, char** argv)
{
        std::string  arq_log ;

        // gera nome de arquivo de log 
        arq_log="arq_log_";
        arq_log.append(geraData());
        arq_log.append(".txt");
        
        // registra a hora local no arquivo de log
	PatternFormatter *pattern = new PatternFormatter("%Y-%m-%d %H:%M:%S :%s:%q:%t");
        pattern->setProperty("times", "local");

        // gera o arquivo de log podendo passar o nome e o diretorio onde sera criado
	FormattingChannel* pFCFile = new FormattingChannel(pattern);
	pFCFile->setChannel(new FileChannel(arq_log.c_str()));
	pFCFile->open();

	Logger& fileLogger = Logger::create("Log", pFCFile, Message::PRIO_INFORMATION);
	
	fileLogger.error("An error message");
	
	fileLogger.error("A warning message");
	
	fileLogger.information("An information message");
	
	fileLogger.information(fileLogger.format("Ver : $0 " , "agora") ) ; 
	
	return 0;
}

