#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#define MAX 100
#define MAXCNT 10

int main () {

  int gionni = open("/tmp/perezculo", O_RDONLY);
  char gigetto[MAX];
  read(gionni, gigetto, MAXCNT);
  printf("%s\n", gigetto);
  close(gionni);
  int gigino = atoi(gigetto);
  printf("%i\n", gigino);
  kill(gigino, SIGUSR1);
  return 0;
}


