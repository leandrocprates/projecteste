#include <stdio.h>

int main ()
{

printf("Numero do processo PID [%d] , processo Pai [%d] , GRUPO [%d] \n" , getpid() , getppid() , getpgrp());

sleep (2);

return 0 ; 
}
