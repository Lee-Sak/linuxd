#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;

	if( (pid = fork()) < 0 ) {
		printf("fork error");
		exit(1);
	}
	else if( pid == 0 ) {
		if( (pid = fork()) < 0) {
			printf("fork error");
			exit(1);
		}
		else if( pid > 0 )
			exit(1);
		
		sleep(2);
		printf("2nd child, parent pid = %d\n", getppid());
		exit(EXIT_SUCCESS);
	}
	if( waitpid(pid, NULL, 0) != pid)
		printf("waitppid error");
	exit(1);
}
	
