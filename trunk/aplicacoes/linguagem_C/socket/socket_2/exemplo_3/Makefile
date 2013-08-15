
CC=gcc
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)


all:$(OBJECTS)

%.o:%.c
	$(CC) $< -o  $* 

clean:
	rm  udp_cli1 udp_cli2 udp_srv1



