#include  <errno.h>
#include  <signal.h>
#include  <stdio.h>
#include  <unistd.h>
#include  <sys/types.h>
#include  <sys/wait.h>
#include <stdlib.h>

int main()
{
     int pid ;
     printf(" 1") ;
     //fflush(stdout);
     pid=fork() ;
     if(pid==-1) /* error */
     {
           perror("impossivel de criar um filho") ;
           exit(-1) ;
     }
     else if(pid==0) /* filho */
     {
           printf(" 2") ;
           exit(0) ;
     }
     else /* pai */
     {
           wait(0) ; /* o pai aguarda a morte de seu filho */
           printf(" 3\n") ;
           exit(0);
     }
     return 0 ; 
}


