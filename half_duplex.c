#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024
int main(void) {
	int n, fd[2];
	pid_t pid;
	char line[MAXLINE];

	if( pipe(fd) < 0 ) {
		printf("pipe error");
		exit(1);
	}
	if( (pid = fork()) < 0 ) {
		printf("fork error");
		exit(1);
	}
	else if( pid > 0 ) { // parent
		close(fd[0]); // 0 입력 , 1 출력
		write(fd[1], "Hello, World!\n", 14);
	}
	else { // child
		close(fd[1]);
		n = read(fd[0], line, MAXLINE); // fd[0]으로 받고 line에 저장, 크기는 맥스
		write(STDOUT_FILENO, line, n); // 크기 n 만큼 line에 저장된 문자열 출력
	}
	exit(1);
}
