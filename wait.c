#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "helpers.h"

int main(void) {
	pid_t pid;
	int status;
	if ((pid = fork()) < 0) {
		printf("fork error");
		exit(1);
	}
	else if (pid == 0) { // child
		printf("i'm child\n");
		exit(7);
	}
	else {
		if (wait(&status) != pid) {
			printf("wait error");
			exit(1);
		}
		printf("i'm parent\n");
		pr_exit(status);
	}
	exit(EXIT_SUCCESS);
}
