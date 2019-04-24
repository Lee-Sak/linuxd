#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char buf[] = "write to stdout\n";
int main(void) {
	pid_t pid;
	if( write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf) ) {
		printf("write error");
		exit(1);
	}
	printf("before fork (%d)\n", getpid());
	if( (pid = fork()) < 0) {
		printf("fork error");
		exit(EXIT_SUCCESS);
	}
	else if(pid == 0) 
		printf("hi from child! %d\n", getpid());
	else 
		printf("hi from parnet! (%d)\n", getpid());
	
	printf("bye (%d)\n", getpid());
	exit(EXIT_SUCCESS);
}
