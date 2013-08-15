
extern "C" {
#include <windows.h>
#include <stdio.h>
#include <mysql/mysql.h>
}

int  main ()
{
    MYSQL *mysql; 
    char query[1000];
    
    mysql=mysql_init(NULL);
    
    if ( mysql == NULL) 
        printf ("Falha de coneccao!\n");
    else
        printf ("Conectado com sucesso!\n"); 


    if( mysql_real_connect(mysql, "localhost", "root", "", "portabilidade", 3306, NULL, 0) == NULL) 
    {
       printf("erro na conexao\n" ); 
       return(-1);
    }
    
 // mysql_autocommit(mysql, 0) ;

    sprintf(query , "%s"  , " DELETE FROM file " );  

    if ( mysql_query( mysql , query ) != 0  )
    {
         printf("erro ao deletar registro \n" ) ; 
    }

  //  mysql_commit(mysql); 

  //  mysql_close(mysql); 

    system("PAUSE");
    return EXIT_SUCCESS;
}

