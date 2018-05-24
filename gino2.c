#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAX (100)

int main () {

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


