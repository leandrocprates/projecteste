
#include <iostream>
#include <string>

class  teste 
{
	public : 
	
	teste() { };
	
	void imprimir()
	{
		std::cout << "teste OK" << "valor url : " << url << std::endl ; 
	}

	static std::string url;
};

std::string teste::url="/obter_cuponAleatorio";

int main () 
{
	teste z ;
	z.imprimir(); 
	return 0 ; 
}

