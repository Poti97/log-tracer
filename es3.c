#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

void pippo (int sig) {
	printf("\n FOTTITI \n");
	exit(0);
}

void pluto (int sig) {
	printf ("\nCOSE\n");
}

int main () {
	pid_t pid1;
	pid1 = getpid();
	signal(SIGINT, pippo);
	signal(SIGUSR1, pluto);
	while (1) {
		printf(".");
		sleep (1);
		kill (pid1,SIGUSR1);
		fflush(stdout);
	}
	return 0;
}


