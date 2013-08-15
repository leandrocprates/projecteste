#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h>

//gera um processo zumbi
int main() {
     if (fork() != 0) 
        while(1){} ;
     exit(0);
}
