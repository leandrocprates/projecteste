
#include <iostream>
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


int main(int argc, char** argv)
{
	std::string  palavra ; 
	
	FormattingChannel* pFCFile = new FormattingChannel(new PatternFormatter("%Y-%m-%d %H:%M:%S :%s:%q:%t"));
	pFCFile->setChannel(new FileChannel("sample.log"));
	pFCFile->open();

	Logger& fileLogger = Logger::create("Log", pFCFile, Message::PRIO_INFORMATION);
	
	fileLogger.error("An error message");
	
	fileLogger.error("A warning message");
	
	fileLogger.information("An information message");
	
	fileLogger.information(fileLogger.format("Ver : $0 " , "agora") ) ; 
	
	return 0;
}
