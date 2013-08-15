#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
   
int main(int argc, char *argv[])  
{  
	int i = 0;  
	FILE *fptr = fopen("daemon-test","w");  

	daemon(0, 0);  

	for(;i<11;i++)  
	{  
		fprintf(fptr,"%d\n",i);  
	}  

	fclose(fptr);  

	sleep(10);

	return(0);  
}  


