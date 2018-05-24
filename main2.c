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



time_t tstart,tend;

void StartTime (int sig) {
//inizializzo il tempo iniziale
		tstart = time(NULL);

}

void EndTime () {
//inizializzo il tempo di fine e stampo nel file le cose
	char* cttot, ctend;
	tend = time(NULL);
	ctend = ctime(&tend);
	int fd[2];
  char* time_spent_str = {"Time spent processing: "};
	fd[0] = open("log.txt", O_WRONLY | O_CREAT, 0777);
	write(fd[0], tstart, 32);
	write(fd[0], ctend, 32);
	write(fd[0], time_spent_str, strlen(time_spent_str));
  close(fd[0]);
	exit(0);
}

int main () {
	pid_t pid;
	pid = getpid();
	signal(SIGUSR1, StartTime);
	signal(SIGUSR2, EndTime);
	while (1)
		sleep(1);
	return 0;
}
