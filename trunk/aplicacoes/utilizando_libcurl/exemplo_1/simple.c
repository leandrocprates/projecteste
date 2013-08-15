/*****************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * $Id: simple.c,v 1.6 2004-08-23 14:22:52 bagder Exp $
 */

#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  // se retorno nao NULL

  if(curl) 
  {
    // define opcoes para requisicoes
    curl_easy_setopt(curl, CURLOPT_URL, "terra.com.br");
    
    // seta um tempo maximo para transferencia
    curl_easy_setopt(curl, CURLOPT_TIMEOUT , 1 );

    // efetua tranferencia
    res = curl_easy_perform(curl);

    // define opcoes para requisicoes
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.uol.com.br");
    
    // efetua tranferencia
    res = curl_easy_perform(curl);

    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  return 0;
}






