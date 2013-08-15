
GCC= gcc
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
INCLUDE=-I./lib
DEPENDENCIAS=-L./lib -lsomar
RM = rm 

all:$(OBJ)

%.o:%.c
	$(GCC)  $(DEPENDENCIAS) $(INCLUDE)  $< -o $*

clean:
	$(RM) *.o 
	

#gcc  -L./lib -lsomar    -I./lib    main.c -o main
