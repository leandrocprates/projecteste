
#include <stdio.h>
#include <string.h>
#include "debug.h"


int main () 
{

   startDebug("." , ".log" );

   debug("mais [%s] [%s] " , "um" , "teste" );


   return 0 ; 
}

