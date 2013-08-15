
CC=g++
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)


all:$(OBJECTS)

%.o:%.cpp
	$(CC) $< -o  $* 

clean:
	./script_remove.sh



