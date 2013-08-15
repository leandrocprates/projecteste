
CC=gcc
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)


all:$(OBJECTS)

%.o:%.c
	$(CC) $< -o  $* 

clean:
	 rm udp_rcv  udp_snd



