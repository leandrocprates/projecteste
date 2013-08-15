
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
GCC=g++
LIB=#-L/usr/lib -lpthread
BIN=main

$(BIN):$(OBJ)
	$(GCC) $^ -o $@

main:$(OBJ)

%.o:%.cpp
	$(GCC) $(LIB)  -c $< -o  $@

clean:
	 find . -perm -guo+x  -type f | xargs rm

