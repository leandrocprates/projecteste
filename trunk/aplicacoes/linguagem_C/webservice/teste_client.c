
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "soapH.h"
#include "BatchFilePortBinding.nsmap"

int main()
{
  struct soap soap;

  int temp;

  struct ns1__totalRegister  ns1__totalRegister ; 

  struct ns1__totalRegisterResponse  ns1__totalRegisterResponse ; 

  struct ns1__sentMessage ns1__sentMessage ; 

  struct ns1__sentMessageResponse ns1__sentMessageResponse ; 

  struct ns1__send  ns1__send ; 

  struct ns1__sendResponse  ns1__sendResponse ; 

  soap_init(&soap);

 /* ============================================================*/

  ns1__totalRegister.client =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__totalRegister.client , "webservice");

  ns1__totalRegister.user =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__totalRegister.user , "admin");

  ns1__totalRegister.password =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__totalRegister.password , "admin");

  ns1__totalRegister.idBatch = 5; 

 /* ============================================================*/

  ns1__sentMessage.client =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__sentMessage.client , "webservice");

  ns1__sentMessage.user =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__sentMessage.user , "admin");

  ns1__sentMessage.password =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__sentMessage.password , "admin");

  ns1__sentMessage.idBatch = 5; 

 /* ============================================================*/

  ns1__send.client =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__send.client , "webservice");

  ns1__send.user =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__send.user , "admin");

  ns1__send.password =  (char * )malloc( 15 * sizeof(char) ) ; 
  strcpy(ns1__send.password , "admin");

  ns1__send.startTime =  (char * )malloc( 15 * sizeof(char) ) ;  
  strcpy(ns1__send.startTime , "201106211900");

  ns1__send.endTime  =  (char * )malloc( 15 * sizeof(char) ) ;  
  strcpy(ns1__send.endTime , "201106212000");

  ns1__send.idMessage = 1 ; 

  ns1__send.mail =  (char * )malloc( 50 * sizeof(char) ) ;  
  strcpy(ns1__send.mail , "leandro.prates@gmail.com");

/*
  ns1__send.file =  ( ns3__stringArray*) malloc ( 1 * sizeof(ns3__stringArray ) ) ;  
  ns1__send.file[0].item =  (char ** ) 	malloc ( 3 * sizeof ( char * ) ) ; 
  ns1__send.file[0].item[0] = ( char *)  malloc ( 50 * sizeof(char)) ;
  ns1__send.file[0].item[1] = ( char *)  malloc ( 50 * sizeof(char)) ; 
  ns1__send.file[0].item[2] = ( char *)  malloc ( 50 * sizeof(char)) ;  


  strcpy( ns1__send.file[0].item[0] , "1175016032"  ) ; 
  strcpy( ns1__send.file[0].item[1] , "Leandro Cesar Prates"  ) ; 
  strcpy( ns1__send.file[0].item[2] , "0145263"  ) ; 

  ns1__send.__sizefile = 1;  // numero de registros enviados 
  ns1__send.file[0].__sizeitem=3; // numeros de campos enviados
*/

  ns1__send.file =  ( ns3__stringArray*) malloc ( 2 * sizeof(ns3__stringArray ) ) ;  

  ns1__send.file[0].item =  (char ** ) 	malloc ( 3 * sizeof ( char * ) ) ; 
  ns1__send.file[1].item =  (char ** ) 	malloc ( 3 * sizeof ( char * ) ) ;  

  ns1__send.file[0].item[0] = ( char *)  malloc ( 50 * sizeof(char)) ;
  ns1__send.file[0].item[1] = ( char *)  malloc ( 50 * sizeof(char)) ; 
  ns1__send.file[0].item[2] = ( char *)  malloc ( 50 * sizeof(char)) ;  

  ns1__send.file[1].item[0] = ( char *)  malloc ( 50 * sizeof(char)) ;
  ns1__send.file[1].item[1] = ( char *)  malloc ( 50 * sizeof(char)) ; 
  ns1__send.file[1].item[2] = ( char *)  malloc ( 50 * sizeof(char)) ;  

  strcpy( ns1__send.file[0].item[0] , "1175016032"  ) ; 
  strcpy( ns1__send.file[0].item[1] , "Leandro Cesar Prates"  ) ; 
  strcpy( ns1__send.file[0].item[2] , "0145263"  ) ; 

  strcpy( ns1__send.file[1].item[0] , "1122333018"  ) ; 
  strcpy( ns1__send.file[1].item[1] , "Ariane Lucia Prates"  ) ; 
  strcpy( ns1__send.file[1].item[2] , "0145514"  ) ; 

  ns1__send.__sizefile = 2;  // numero de registros enviados 
  ns1__send.file[0].__sizeitem=3; // numeros de campos enviados
  ns1__send.file[1].__sizeitem=3; // numeros de campos enviados


 /* ============================================================*/


  printf("Buscando Total de Registros \n");

  if(soap_call___ns1__totalRegister(&soap, 
                              NULL  , 
                              NULL  , 
                              &ns1__totalRegister ,    
                              &ns1__totalRegisterResponse 
                             ) == SOAP_OK ){

    printf("Total Register: %d\n",  ns1__totalRegisterResponse.return_ );
  }
  else {
    soap_print_fault(&soap, stderr); 
  }

 /* ============================================================*/

   printf("Buscando Total de Mensagens enviadas .\n");

  if (soap_call___ns1__sentMessage(
			    &soap, 
			    NULL, 
			    NULL, 
			    &ns1__sentMessage,
			    &ns1__sentMessageResponse
			     ) == SOAP_OK ) {

    printf("Sent Message : %d\n",  ns1__sentMessageResponse.return_ );	

  } else {
     soap_print_fault(&soap, stderr); 
  }

 /* ============================================================*/

   printf("Enviando Arquivo.\n");

  if (soap_call___ns1__send(
			    &soap, 
			    NULL, 
			    NULL, 
			    &ns1__send,
			    &ns1__sendResponse
			     ) == SOAP_OK ) {

    printf("Retorno Numero do Lote : %d\n",  ns1__sendResponse.return_ );	

  } else {
     soap_print_fault(&soap, stderr); 
  }

 /* ============================================================*/

  soap_destroy(&soap); 
  soap_end(&soap); 
  soap_done(&soap); 

  return 0;

}


