#include "log.h"

int main(int argc, char* argv[]){
  pid_t pid, wpid;
  time_t temp_temp;
  int status, R;
  char* tempo;
  log_read(argc, argv);
  pid = fork();
  if(pid == 0){
      for(int i = 1; i < argc; i++){
        printf("pid = %d, times = %d\n", pid, i);
        R=system(argv[i]);
        temp_temp = log_time();
        printf("ID : %d\n",R);
      }
  }
  else{
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    for(int i = 1; i < argc; i++){
        printf("pid = %d,times = %d\n", pid, i);
        tempo = log_convert_time(temp_temp);
        (void) printf("Current time is %s", tempo);
    }
    log_write(tempo);
  }
//  status= log_launch(toks);
    exit(EXIT_SUCCESS);
}
