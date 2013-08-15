
#include "Poco/Checksum.h"
#include "Poco/StreamCopier.h"
#include <fstream>
#include <iostream>
#include <string>

using Poco::Checksum;
using Poco::StreamCopier;
using namespace std;

int main(int argc, char** argv)
{
        string conteudo;

	if (argc != 2)
	{
		std::cout << "usage: " << argv[0] << ": <input_file>" << std::endl
		          << "       create the cksum digest for <input_file>" << std::endl;
		return 1;
	}


        std::ifstream istr(argv[1], std::ios::binary);
        if (!istr)
        {
                std::cerr << "cannot open input file: " << argv[1] << std::endl;
                return 2;
        }

        // inicializacao dos dois tipos de algoritmos utilizados
        //Checksum cksum(Checksum::TYPE_ADLER32);
        Checksum cksum(Checksum::TYPE_CRC32);
        StreamCopier::copyToString(istr, conteudo);

        // argumento 1 enviado para calculo
        cksum.update(conteudo);
        istr.close();
        
        cout<<"Valor: " <<  cksum.checksum() << endl;
        cout<<"Tipo : " <<  cksum.type() << endl ;

	return 0;
}


