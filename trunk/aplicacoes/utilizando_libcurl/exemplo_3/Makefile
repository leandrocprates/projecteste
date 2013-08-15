
INCLUDE=-I/home/leandro/programa/curl-7.19.3/include
LIBS=-L/home/leandro/programa/curl-7.19.3/lib/.libs -lcurl
GCC=gcc
OBJECTS=ftpget.o
NAME=ftpget

all: $(OBJECTS)
	$(GCC) $(LIBS) $^ -o $(NAME)

%.o:%.c
	$(GCC) $(INCLUDE) -c $< -o $@

clean:
	rm *.o ftpget

