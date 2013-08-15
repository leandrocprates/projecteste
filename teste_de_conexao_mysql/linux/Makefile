
CC=g++
INCLUDE=-I/usr/include -I/home/leandro/programa/libdebug
LIB=-L/usr/lib -lmysqlclient -L/home/leandro/programa/libdebug -lDebug
EXECUTAVEL=main
OBJ=main.o


all:$(OBJ)
	$(CC) $(LIB) -o $(EXECUTAVEL) $^

%.o:%.cpp
	$(CC) $(INCLUDE) -c $< -o $@

clean:
	rm main *.o

