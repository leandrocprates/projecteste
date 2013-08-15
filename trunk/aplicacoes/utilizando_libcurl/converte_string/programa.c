
/*  Para testar a implementacao da funcao passar a string na chamada do programa
 *  executar :  ./programa "teste~de encode"
 *
 */

#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char**argv) 
{
    CURL *curl;
    int outlength;

    //exemplo de utilizacao o code e encode 

    // esta funcao codifica os caracteres especiais 
    printf("%s\n", curl_easy_escape( curl , argv[1] , 0 ) );

    // esta funcao decodifica os caracteres especiais
    printf("%s\n", curl_easy_unescape( curl , curl_easy_escape( curl , argv[1] , 0 ) , 0 ,  &outlength ) ) ; 

    return 0;
}



