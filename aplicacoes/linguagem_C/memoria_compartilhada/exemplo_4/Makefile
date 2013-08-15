
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
GCC=gcc
LIB=-L/usr/lib -lpthread

all:$(OBJ)

%.o: %.c
	$(GCC) $(LIB)  $< -o  $* 

clean:
	find . -perm -guo+x  -type f | xargs rm

