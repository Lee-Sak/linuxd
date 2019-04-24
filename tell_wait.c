#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void charatatime(char *str) {
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for(ptr = str; (c = *ptr++) != 0;)
		putc(c, stdout);
}

int main(void) {
	pid_t pid;
	TELL_WAIT();

	if( (pid = fork()) < 0 ) {
		printf("fork error");
		exit(1);
	}
	else if( pid == 0 ) {
		WAIT_PARENT();
		charatatime("output from child\n");
	}
	else { 
		charatatime("output from parent\n");
		TELL_CHILD(pid);
	}
	exit(EXIT_SUCCESS);
}
