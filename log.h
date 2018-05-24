#ifndef LOG_H
#define LOG_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

void log_read(int argc, char* argv[]){
  for(int i = 1; i < argc; i++){
    printf("%s", argv[i]);
    printf("\n");
  }
}

time_t log_time(){
  time_t current_time;
  current_time = time(NULL); // current time
  if (current_time == ((time_t)-1)) {
    (void) fprintf(stderr, "Failure to obtain the current time.\n");
    exit(EXIT_FAILURE);
  };
  return current_time;
}

char* log_convert_time(time_t old_time){
  char* new_time;
  new_time = ctime(&old_time); // convert to readable format
  if (new_time == NULL) {
    (void) fprintf(stderr, "Failure to convert the current time.\n");
    exit(EXIT_FAILURE);
  };
  return new_time;
}

void log_write(char* tempo) {
  FILE* fp;
  fp = fopen("log.txt", "w");
  fputs(tempo, fp);
  fclose(fp);
  return;
}

#endif
