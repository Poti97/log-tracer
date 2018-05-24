#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAX (100)

int main (int argc, char *argv[]) {

  int gigi = getpid();
  printf("ciao sono un pid bellissimo: %d\n", gigi);
  int gionni = open(argv[1], O_WRONLY | O_CREAT, 0777);
  char gigetto[MAX];
  sprintf(gigetto, "%i", gigi);
  write(gionni, gigetto, strlen(gigetto));
  write(gionni, "\n", 2);
  close(gionni);
  
  return 0;
}


