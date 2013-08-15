#include <stddef.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


void MyProc(){
  exit(0);
}


void
main(int argc, char *argv[])
{
  int i, nprocs;
  struct timeval st, et;
 
  int s, status;
  int elapsedtime;

  if( argc > 2 ) goto usage;
  else if (argc == 1 ) MyProc();    /* filhos so' com 1 argumento 
                                       depois do exec ... */

  nprocs = atoi( argv[1]);

  /* Initiate the processes */
  gettimeofday(&st, NULL);

  for(i = 0; i < nprocs; i++) {
    s = fork();
    if(s == 0) {
      if(execl(argv[0], argv[0], NULL) < 0) {
        perror("Exec");
        exit(-1);
      }
    }
    else
      if ( s < 0){
	printf("i = %d \n", i);
	perror(" fork ");
	exit(1);
      }
     
  }


  for(i = 0; i < nprocs; i++) 
    wait(&status);

  gettimeofday(&et,NULL);

  elapsedtime =  (et.tv_sec - st.tv_sec )*1000 +
                   (int) ((double)( et.tv_usec - st.tv_usec )*1.0e-3);

  printf( "elapsed time = %d ms, each fork/exec = %f \n", 
	  elapsedtime, (double)elapsedtime/(double)nprocs);

  exit(0);

usage:
  printf("Usage: %s nprocs\n", argv[0]);
  exit(1);

}
















