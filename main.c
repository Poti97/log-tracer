#include "log.h"

int main(int argc, char* argv[]){
  signal(SIGUSR1,begin_time);
  clock_t begin = clock();
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
//  status= log_launch(toks);
  clock_t end = clock();
  double time_spent = (double)(tend - begin)*1000.0 / CLOCKS_PER_SEC;
  (void) printf("\n\n\n\n TIME SPENT = %f \n\n", time_spent);
  log_write(tempo,time_spent,R);
  }
  signal(SIGUSR2,end_time);
  exit(EXIT_SUCCESS);
}
