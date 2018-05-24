#include <signal.h>
#include <stdlib.h>
#include <dtdio.h>
#include <sys/types.h>

void StartTime (int sig) {
//inizializzi il tempo iniziale


}

void EndTime () {
//inizializzi il tempo di fine e stampi nel file le cose


	exit(0);
}

int main () {
	pid_t pid;
	pid = getpid()
	signal(SIGUSR1, StartTime);
	signal(SIGUSR2, EndTime);
	while (1)
		sleep(1);
	return 0;
}
