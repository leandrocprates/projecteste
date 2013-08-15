#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "pthread.h"

int var;

void * process(void * arg)
{
  int i,j;
  fprintf(stderr, "Starting process %s\n", (char *) arg);

  for( i = 0 ; i < 10000000; i++) {
    j = var + 1;
    var = j;
  }

  return NULL;
}

int main()
{
  int retcode;
  pthread_t th_a, th_b;
  void * retval;

  var = 0;

  retcode = pthread_create(&th_a, NULL, process, "a");
  if (retcode != 0) fprintf(stderr, "create a failed %d\n", retcode);
  retcode = pthread_create(&th_b, NULL, process, "b");
  if (retcode != 0) fprintf(stderr, "create b failed %d\n", retcode);
  retcode = pthread_join(th_a, &retval);
  if (retcode != 0) fprintf(stderr, "join a failed %d\n", retcode);
  retcode = pthread_join(th_b, &retval);
  if (retcode != 0) fprintf(stderr, "join b failed %d\n", retcode);
  printf("var = %d \n", var);
  return 0;

}

