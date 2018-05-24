#ifndef LOG_H
#define LOG_H
#define MAX_DIM 100

#include<signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

time_t tbegin, tend;

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

void begin_time(int sig){
  tbegin = time(NULL);
}

void end_time(int sig){
  tend = time(NULL);
}

void log_write(char* tempo, double ms,int id) {
  FILE* fp;
  char* time_spent_str = {"Time spent processing: "};
  fp = fopen("log.txt", "w");
  fputs(tempo, fp);
  fputs(time_spent_str, fp);
//  fputs((char)id, fp);
  fclose(fp);
  return;
}

#endif
