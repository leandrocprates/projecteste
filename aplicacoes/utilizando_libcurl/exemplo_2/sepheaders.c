/*****************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * $Id: sepheaders.c,v 1.10 2008-05-22 21:20:09 danf Exp $
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  int written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

int main(int argc, char **argv)
{
  CURL *curl_handle;
  static const char *headerfilename = "head.out";
  FILE *headerfile;
  static const char *bodyfilename = "body.out";
  FILE *bodyfile;

  curl_global_init(CURL_GLOBAL_ALL);

  /* init the curl session */
  curl_handle = curl_easy_init();

  /* set URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_URL, "http://www.uol.com.br");

  /* no progress meter please */
  curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

  //seta funcao que ira receber dados para escrita
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);


  // cria arquivos 
  headerfile = fopen(headerfilename,"w");
  if (headerfile == NULL) 
  {
    curl_easy_cleanup(curl_handle);
    return -1;
  }

  bodyfile = fopen(bodyfilename,"w");
  if (bodyfile == NULL) 
  {
    curl_easy_cleanup(curl_handle);
    return -1;
  }

  //seta arquivo para ser escrito o cabecalho de retorno
  curl_easy_setopt(curl_handle,   CURLOPT_WRITEHEADER, headerfile);
  //seta arquivo para ser escrito o corpo da pagina de retorno
  curl_easy_setopt(curl_handle,   CURLOPT_WRITEDATA, bodyfile);


  // faz a transferencia 
  curl_easy_perform(curl_handle);

  // fecha arquivos 
  fclose(headerfile);
  fclose(bodyfile);

 
  curl_easy_cleanup(curl_handle);

  return 0;
}
