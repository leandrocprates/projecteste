CC = gcc
CFLAGS = -g
LDFLAGS = -lpthread

all: many-threads many-forks many-forks-execs many-process-context-switches many-thread-context-switches

many-threads: many-threads.c
	$(CC) -D_REENTRANT $(CFLAGS) -o $@ $< $(LDFLAGS)

many-forks: many-forks.c
	$(CC) $(CFLAGS) -o $@ $<

many-forks-execs: many-forks-execs.c
	$(CC) $(CFLAGS) -o $@ $<

many-process-context-switches: many-context-switches.c
	$(CC) -DPROCESSES $(CFLAGS) -o $@ $<

many-thread-context-switches: many-context-switches.c
	$(CC) -D_REENTRANT $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f *~ *.o  many-threads many-forks many-forks-execs many-process-context-switches many-thread-context-switches
