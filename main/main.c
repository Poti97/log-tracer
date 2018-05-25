#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#define MAX 5

int main () {
	int pid_log = open("/tmp/log", O_RDONLY);
	char c_log[MAX];
	read(pid_log, c_log, MAX);
	printf("%s\n",c_log);
	close(pid_log);
	int pid = atoi(c_log);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	return 0;
}
