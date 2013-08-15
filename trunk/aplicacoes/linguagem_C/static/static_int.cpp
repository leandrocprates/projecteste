
#include <iostream>
#include <string>

class  teste 
{
	public : 
	
	teste() { };
	
	void imprimir()
	{
		std::cout << "teste OK" << "valor x : " << x << std::endl ; 
	}

	static int x;
};

int teste::x=18;

int main () 
{
	teste z ;
	z.imprimir(); 
	return 0 ; 
}

