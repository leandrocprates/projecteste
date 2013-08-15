#este makefile serve para criar uma lib

CXX=gcc
RM=rm
SOURCES=debug.c
OBJECTS=$(SOURCES:.c=.o)
LIB=libDebug.so

all: $(LIB)

$(LIB): $(OBJECTS)
	@echo nome da lib que sera criada $@
	@echo criando lib com os arquivos $^
	@$(CXX) -shared -fPIC -o $@ $^

.c.o:
	@echo compilando arquivo $<
	@$(CXX) -c $< -o $@

clean:
	$(RM) *.o
	$(RM) $(LIB)

distclean: clean
	$(RM) $(LIB)  


