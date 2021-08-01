/*
Run to compile:
gcc zombie.c -o zombie
*/
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main ( int argc, char *argv[]) {

	if (argc<3) {
		if (argv[2] = "-w") {
			child_pid = fork ();
			if (child_pid == 0) {
				execve ("watch", "-n 0.333 sudo ps axo stat,ppid,pid,comm | grep -w defunct");
			}
		}
	}
	
	if (argc<2) {
		argv[1] = "9";
	}
	
	char* sleepDur_S = argv[1];
	int sleepDur = strtol(sleepDur_S, NULL, 0), selfPid=getpid();

	pid_t child_pid;
	child_pid = fork ();
	if (child_pid > 0) {
		printf("Child: %d sleeping %ss. . .\n", child_pid, sleepDur_S);
		sleep (sleepDur);
	} else {
		printf("Parent: %d exiting. . .\n", selfPid);
		exit (0);
	}
	
	printf("Child: %d returning. . .\n", child_pid);
	return 0;
}
