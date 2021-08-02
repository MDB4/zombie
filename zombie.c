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
	char *binVersion = "Zombie v0.015.7\n";
	char *opt_s = "9";
	int c;
	int shutTheFuckUp = '0';
	opterr = 0;
	while ((c = getopt (argc, argv, "hfqs:vw")) != -1)
		switch (c)
			{
				case 'h':
					fprintf(stderr, "%s", binVersion);
					printf("	-f	Fuck you. 🖕️\n");
					printf("	-q	Quiet\n");
					printf("	-s	Seconds to sleep the child process (default 9)\n");
					printf("	-v	Show version\n");
					printf("	-w	Watch ps for zombies\n\n");
					exit (0);
					break;
				case 'f':
					printf("Fuck you. 🖕️\n");
					exit (0);
					break;
				case 'q':
					shutTheFuckUp = '1';
					break;
				case 's':
					opt_s = optarg;
					break;
				case 'v':
					fprintf(stderr, "%s", binVersion);
					break;
				case 'w':
					system("tilix --action=session-add-down \
					-e 'watch -n 0.333 sudo ps axo stat,ppid,pid,comm | grep -w defunct'");
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
			fprintf(stderr, "\n%s", binVersion);
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
