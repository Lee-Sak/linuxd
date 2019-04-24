#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "helpers.h"

char *cmd = "grep zack /etc/passwd | cut -f 5 -d:";

int main(void) {
	int status;
	if( (status = system(cmd)) == -1) {
		printf("system error");
		exit(1);
	}
	pr_exit(status);
	exit(EXIT_SUCCESS);
}
