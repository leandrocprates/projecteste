/* Linux threads: Create 10,000 threads */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define NPROCS 10000
pthread_t thread[NPROCS];

void * MyThread(void *arg)
{
  return NULL;
}

main(int argc, char *argv[])
{
  int i, nprocs, elapsedtime;
  struct timeval st, et;
  int retcode;
  void *retval;

  if( argc != 2) goto usage;

  nprocs = atoi( argv[1]);

  gettimeofday(&st, NULL);

  for(i = 0; i < nprocs; i++) {
    retcode = pthread_create(&thread[i], NULL, MyThread, NULL);
    if(retcode != 0) {
      printf("i = %d -->", i );
      perror("pthread_create");
      exit(0);
    }
  }

  for(i = 0; i < nprocs; i++) {
    retcode = pthread_join(thread[i], &retval);
    if(retcode != 0) {
      perror("phread_join");
    }
  }

  gettimeofday(&et, NULL);

  elapsedtime =  (et.tv_sec - st.tv_sec )*1000 +
                   (int) ((double)( et.tv_usec - st.tv_usec )*1.0e-3);

  printf( "elapsed time = %d ms, each fork = %f \n", 
          elapsedtime, (double)elapsedtime/(double)nprocs);

  exit(0);

 usage:
  printf("Usage: %s nprocs\n", argv[0]);
  exit(1);


}











