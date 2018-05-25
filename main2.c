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
	double ttot = difftime(tend,tstart);
//	snprintf(cttot, 20, "%f", ttot);
	tend = time(NULL);
	char buf[20], buf2[20], buftot[20];
	strftime(buf,20,"%Y-%m-%d %H:%M:%S",localtime(&tstart));
	strftime(buf2,20,"%Y-%m-%d %H:%M:%S",localtime(&tend));
	printf("buff: %s \n",buf);
	sprintf(buftot,"%f", ttot);
	int fd[2];
	char* start_str = "Start time = ";
	char* end_str = "End time = ";
  char* time_spent_str = "Time spent processing: ";
	fd[0] = open("log.txt", O_WRONLY | O_CREAT, 0777);
	write(fd[0], start_str, strlen(start_str));
	write(fd[0], buf, strlen(buf));
	write(fd[0], "\n", 1);
	write(fd[0], end_str, strlen(end_str));
	write(fd[0], buf2, strlen(buf2));
	write(fd[0], "\n", 1);
	write(fd[0], time_spent_str, strlen(time_spent_str));
	write(fd[0], buftot, strlen(buftot)); // **QUESTO NON VA**
  close(fd[0]);
	exit(0);
}

int main () {
	pid_t pid;
	pid = getpid();
	signal(SIGUSR1, StartTime);
	kill(pid,SIGUSR1);
	signal(SIGUSR2, EndTime);
	do {
		sleep(3);
	} while(0);
	kill(pid,SIGUSR2);

	exit(EXIT_SUCCESS);
}
