#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#define MAX (100)

void carletto(int sig) {

  printf("\nGli eroi non muoion mai!\n");
  exit(0);
  
}

int main () {

  signal(SIGUSR1, carletto);
  int gigi = getpid();
  printf("ciao sono un pid bellissimo: %d\n", gigi);
  int gionni = open("/tmp/perezculo", O_WRONLY | O_CREAT, 0777);
  char gigetto[MAX];
  sprintf(gigetto, "%i", gigi);
  write(gionni, gigetto, strlen(gigetto));
  close(gionni);
  while(1) {
    printf(".");
    sleep(1);
  }
  return 0;
}


