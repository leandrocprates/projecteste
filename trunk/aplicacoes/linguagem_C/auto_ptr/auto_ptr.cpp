
#include <iostream>
#include <memory>

class ClasseQualquer
{
	public:
		int valor;
};


int main()
{
	std::auto_ptr<ClasseQualquer> ptr (new ClasseQualquer() ) ; 
	ptr->valor = 16 ; 
	std::cout << ptr->valor  << std::endl ;
	return 0 ;  

}

