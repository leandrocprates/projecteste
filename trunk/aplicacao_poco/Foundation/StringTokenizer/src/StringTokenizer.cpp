#include "Poco/StringTokenizer.h"
#include <iostream>


using Poco::StringTokenizer;


int main(int argc, char** argv)
{
	std::string tokens = " white;; black; magenta, blue, green; yellow";

        // StringTokenizer::TOK_TRIM utilizado para retirar espacos em branco
        // StringTokenizer::TOK_IGNORE_EMPTY mantem espacos em branco

	StringTokenizer tokenizer(tokens, ";,", StringTokenizer::TOK_TRIM);
        //StringTokenizer tokenizer(tokens, ";,", StringTokenizer::TOK_IGNORE_EMPTY);

        for (StringTokenizer::Iterator it = tokenizer.begin(); it != tokenizer.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;

}
