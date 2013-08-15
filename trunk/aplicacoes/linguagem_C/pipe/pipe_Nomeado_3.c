/* 
 * File:   pipe_Nomeado_3.c
 * Author: leandro
 *
 * Created on 23 de Agosto de 2009, 09:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/signal.h>

void remove_pipe(int signal)
{
    printf("Recebendo sinal [%d].\n" , signal);
    unlink("fifofile");
}

int main() {

  const char nomepipe[] = "fifofile";
  pid_t procID;
  char buffer[256];
  FILE *fp;

  signal(SIGTERM,remove_pipe);
  mkfifo(nomepipe, 0600);

  procID = fork();

  if (procID == 0)
  {

    fp = fopen(nomepipe, "w");

    printf("Introduza a mensagem a enviar ao pai:\n");

    fgets(buffer, 255, stdin);

    fputs(buffer, fp);

    fclose(fp);

  }
  else
  {

    fp = fopen(nomepipe,"r");

    fgets(buffer, 255, fp);

    printf("Recebida a mensagem do filho:\n");

    printf("%s",buffer);

    fclose(fp);

  }

  return (EXIT_SUCCESS);

}
