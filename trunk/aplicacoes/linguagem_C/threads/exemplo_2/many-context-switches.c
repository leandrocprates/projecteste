
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include <pthread.h>

#define TICKS_PER_SEC CLK_TCK


#define NPROCS 10          /* Number of threads or processes to start */
#define NLOOPS 10000      /* Number of context switches to perform in each*/
#define CONTEXT_SWITCHES (NPROCS*NLOOPS)

struct tms thread_tms;

#ifdef PROCESSES
void
MyProc(void *arg)
#else
void * MyThread(void *arg)
#endif
{
  int i;

  for(i = 0; i < NLOOPS; i++) {
        /* Yield the processor (force a context switch) */
    sched_yield();
  }


#ifndef PROCESSES
  times(&thread_tms);
  *((clock_t *) arg ) = thread_tms.tms_utime; 
  return NULL;
#endif
}


void
main(int argc, char *argv[])
{
  int i, system_time;
  time_t st, et;
  clock_t ttime, ttimes[NPROCS];

  
#ifdef PROCESSES
  int status;
#else
  pthread_t thread[NPROCS];
  int retcode;
  void *retval;
#endif

   ttime = 0;
#ifdef PROCESSES
  /*
   * If we have an argument then assume we are being called as a new
   * process and just go to our context switching code.
   */
  if(argc > 1) {
          MyProc(&ttime);
          exit(0);
  }
#endif

  /* Initiate the threads or processes */

  for(i = 0; i < NPROCS; i++) {

#ifdef PROCESSES

    /*
     * Ok, we are going to start a number of new processes (not threads).
     * Our new processes will just be copies of this program but started
     * so that they know to just jump to the context switching subroutine
     * above.
     *
     */

    printf("mesauring context switches between processes \n");
    if(fork() == 0) {
	if(execl("many-process-context-switches",
		 "many-process-context-switches", "loop",NULL) < 0) {
        perror("Exec");
        exit(-1);
      }
    }

#else

    printf("mesauring context switches between threads \n");

    /* Posix threads */
    retcode = pthread_create(&thread[i], NULL, MyThread, &ttimes[i]);
    if(retcode != 0) {
      perror("Pthread_create");
      exit(-1);
    }
#endif
  }

 /*
 * The threads/processes are all started.  Note the time call below will be
   * slightly biased since some of the threads have been running for a
   * while.  That bias decreases as a function of the number of context
   * switching loops is increased.
   *
   */

  time(&st);

  
  for(i = 0; i < NPROCS; i++) {


    /*
     * In UNIX, with Posix threads, we use wait() for a process and
     * pthread_join() for a thread
     *
     */

#ifdef PROCESSES
    wait(&status);
#else
    retcode = pthread_join(thread[i], &retval);
    if(retcode != 0) {
      perror("phread_join");
    }
    ttime += ttimes[i];
#endif

  }

  time(&et);

  system_time = (((et-st) * TICKS_PER_SEC) - ttime) / TICKS_PER_SEC;

  printf("%d total context switches - ", CONTEXT_SWITCHES);

#ifndef PROCESSES
  printf("Thread user cpu totals = %f secs.\n",
         (float)ttime / TICKS_PER_SEC);
#endif

  printf("Non-process wallclock time: %d secs\n",system_time);

  printf("%d context switches per second (%d us per context switch)\n",
         CONTEXT_SWITCHES / system_time,
         (int)((float)system_time * 1000000.0 /
               (float)CONTEXT_SWITCHES));

}





