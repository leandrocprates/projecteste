
CC=g++
EXECUTAVEL=main
LIBS= -L/usr/lib -lmysqlclient -L/home/amazon/teste/libdebug -lDebug  -L/home/amazon/teste/libmysql -lMysql
INCLUDE= -I/usr/include/mysql -I/home/amazon/teste/libdebug -I/home/amazon/teste/libmysql

OBJECTS=main.o


all:$(OBJECTS)
	g++ $(LIBS) -o $(EXECUTAVEL) $^


%.o:%.cpp
	g++ $(INCLUDE) -c $< -o $@


clean:
	rm -rf *.o  $(EXECUTAVEL)


