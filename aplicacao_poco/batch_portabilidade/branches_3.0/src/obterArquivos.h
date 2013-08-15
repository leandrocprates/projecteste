#ifndef __DIR_LS__
#define __DIR_LS__

//includes de leitura de diretorio
#include "Poco/DirectoryIterator.h"
#include "Poco/File.h"
#include "Poco/Path.h"
#include "Poco/Exception.h"

// include para log
#include "Poco/Logger.h"

#include  <string>
#include  <iostream>
#include  <vector>

using Poco::DirectoryIterator;
using Poco::File;
using Poco::Path;
using Poco::Logger;
using std::string;
using std::cout;
using std::endl;
using std::vector;

class obterArquivos
{

    public:
        obterArquivos()
        {
            
        }

        obterArquivos( Logger *Log)
        {
            fileLogger = Log ; 
        }
        
        int dir_ls(string dirname , string arquivo , vector<string> &vetor , string tipo_arquivo  ) ;

    private:
        Logger *fileLogger;
        string diretorio;
        string arq;

};


#endif

