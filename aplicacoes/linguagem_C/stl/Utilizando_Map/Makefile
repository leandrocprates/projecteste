
CC=g++
EXECUTAVEL=main
LIBS= -L/usr/lib  -lmysqlclient  -L/home/amazon/teste/libdebug  -lDebug
INCLUDE= -I/usr/include/mysql -I/home/amazon/teste/libdebug
OBJECTS=main.o


all:$(OBJECTS)
	g++ $(LIBS) -o $(EXECUTAVEL) $^


%.o:%.cpp
	g++ $(INCLUDE) -c $< -o $@


clean:
	rm -rf *.o  $(EXECUTAVEL)


