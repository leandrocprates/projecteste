
GCC= gcc
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
LIB= libsomar.so 
RM = rm 

all:$(LIB)

$(LIB):$(OBJ)
	$(GCC) -shared -fPIC  $^ -o  $@

%.o:%.c
	$(GCC) -c $< -o $@

clean:
	$(RM) *.o 
	

