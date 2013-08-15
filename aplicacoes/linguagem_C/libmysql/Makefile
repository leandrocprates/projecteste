
CC=g++
INCLUDE=-I./ -I/usr/include -I/home/amazon/teste/libdebug
DEPENDENCIAS=-L/usr/lib -lmysqlclient -L/home/amazon/teste/libdebug -lDebug
SOURCE=connect.o
LIB=libMysql.so

all:$(LIB)

$(LIB):$(SOURCE)
	@echo nome da lib que sera criada $@
	@echo criando lib com os arquivos $^
	@$(CC) $(DEPENDENCIAS) -shared -fPIC -o $@ $^


%.o:%.cpp
	$(CC) $(INCLUDE) -c $< -o $@

clean:
	rm  *.o $(LIB)



#g++  -I/usr/include/ -I/home/amazon/teste/libdebug/    -c connect.cpp  -o connect.o
#g++  -L/usr/lib -lmysqlclient -L/home/amazon/teste/libdebug -lDebug    -shared -fPIC -o   libMysql.so   connect.o
#export LD_LIBRARY_PATH=~/teste/libmysql:/usr/lib:~/teste/libdebug

