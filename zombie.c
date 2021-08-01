/*
Run to compile:
gcc zombie.c -o zombie
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main ( int argc, char *argv[]) {
/**Options***************************************************************************************/			
	char *opt_s = "9";
	int c;
	int shutTheFuckUp = '0';
	opterr = 0;
	while ((c = getopt (argc, argv, "fqs:v")) != -1)
		switch (c)
			{
				case 'f':
					printf("Fuck you. 🖕️\n");
					break;
				case 'q':
					shutTheFuckUp = '1';
					break;
				case 's':
					opt_s = optarg;
					break;
				case 'v':
					printf("zombie v0.009\n");
					break;
				case '?':
					if (optopt == 's')
						fprintf (stderr, "Option -%c requires an argument.\n", optopt);
					else if (isprint (optopt))
						fprintf (stderr, "Unknown option `-%c'.\n", optopt);
					else
						fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
				return 1;
			default:
				abort ();
			}
/************************************************************************************************/			
	/*if (argc<2) {
		argv[1] = "9";
	}*/
	
	char* sleepDur_S = opt_s; //argv[1];
	int sleepDur = strtol(sleepDur_S, NULL, 0), selfPid=getpid();

	pid_t child_pid;
	child_pid = fork ();
	if (child_pid > 0) {
		if (shutTheFuckUp != '1') {
			printf("Child: %d sleeping %ss. . .\n", child_pid, sleepDur_S);
		}
		sleep (sleepDur);
	} else {
		if (shutTheFuckUp != '1') {
			printf("Parent: %d exiting. . .\n", selfPid);
		}
		exit (0);
	}
	
	if (shutTheFuckUp != '1') {
		printf("Child: %d returning. . .\n", child_pid);
	}
	return 0;
}
