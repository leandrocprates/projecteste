
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/LocalDateTime.h"

#include <iostream>
#include <iomanip>

using Poco::DateTime;
using Poco::DateTimeFormat;
using Poco::DateTimeFormatter;
using Poco::LocalDateTime;
using namespace std;

int main(int argc, char** argv)
{
	DateTime now; // retorna a data do GMT 0 
        LocalDateTime local_time; // retorna a data local

	cout << "dia : "     << now.day()  << endl;
	cout << "mes : "     << now.month()<< endl;
	cout << "ano : "     << now.year() << endl;
	cout << "hora : "    << now.hour()<< endl;
	cout << "minuto : "  << now.minute() << endl;
	cout << "segundo : " << now.second()<< endl;
	
	cout << "calendario juliano: " << (long) now.julianDay() << endl;

	// verifica o periodo do dia
	if ( now.isPM() ) 
		cout << "Esta de tarde" << endl;
	else 
		cout << "Esta de manha" << endl;
	
	// valida se uma data passada e valida 
	if ( DateTime::isValid( 2008,  12 ,  9 , 11 ,  38 , 00 )  ) 
		cout << "Esta data e valida " << endl;
	else
		cout << "Esta data nao e valida " << endl;
				 	
	// retorna o nomero representando o dia da semana
	switch(now.dayOfWeek())
	{
		case 0 : 
			cout << "Dia da semana:" << "Domingo" << endl;break;
		case 1 :
			cout << "Dia da semana:" << "Segunda" << endl;break;
		case 2 :
			cout << "Dia da semana:" << "Terça"   << endl;break;
		case 3 :
			cout << "Dia da semana:" << "Quarta"  << endl;break;
		case 4 :
			cout << "Dia da semana:" << "Quinta"  << endl;break;
		case 5 :
			cout << "Dia da semana:" << "Sexta"   << endl;break;
		case 6 :
			cout << "Dia da semana:" << "Sabado"  << endl;break;
	}
	
        // faz o horario original avancar um minuto
        //now.makeLocal(60);
        // faz o horario original recuar 3 minutos
        now.makeLocal(-180);


	// retorna uma data formatada 
        cout << "Data formatada :" << DateTimeFormatter::format(now, "%e/%n/%Y-%H:%M:%S"  ) << endl ;

	cout << "hora   : " << local_time.hour()    << endl ;  
        cout << "minuto : " << local_time.minute()  << endl ;  
	cout << "segundo: " << local_time.second()  << endl ;  

	cout << "Data formatada local :" << DateTimeFormatter::format(local_time , "%e/%n/%Y-%H:%M:%S" ) << endl ;

	return 0 ; 
	
}






