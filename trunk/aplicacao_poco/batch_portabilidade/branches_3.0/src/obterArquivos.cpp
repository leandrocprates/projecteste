
#include "obterArquivos.h"

int obterArquivos::dir_ls(string dirname , string arquivo , vector<string> &vetor , string tipo_arquivo )
{
    diretorio=dirname;
    arq=arquivo;

    if (diretorio.empty() )
    {
        fileLogger->error("Diretorio em branco.");
        exit(0);
    }


    try
    {
            DirectoryIterator it(diretorio);
            DirectoryIterator end;
            
            while (it != end)
            {
                    Path p(it->path());
                    if (  (p.getFileName() > arquivo) && (p.getFileName().substr(0,3) == tipo_arquivo ) && (p.isFile() == true) )
                    {
                        cout <<"Arquivo obtido : " <<  p.getFileName() << endl;
                        vetor.push_back(p.getFileName());
                    }

                    ++it;
            }
    }
    catch (Poco::Exception& exc)
    {
            std::cerr << exc.displayText() << std::endl;
            return 1;
    }

}


