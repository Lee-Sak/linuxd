#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	pid_t pid;
	int i;

	for(i=0; i<5; i++) {
		if( (pid = fork()) < 0 ) {
			printf("fork error");
			exit(EXIT_SUCCESS);
		}
		else if (pid == 0) {
			printf("bye from child %d: %d\n", i, getpid());
			exit(EXIT_SUCCESS);
		}
	}
	sleep(60); // 부모 프로세스 60초동안 작동 x -> 자식 프로세스는 좀비 상태가됨
			   // 60 초후 다시 작동 -> 자식 프로세스는 부므 프로세스의 종료 상태를 
			   // 넘겨줌 -> 정상 종료
	printf("bye from parent\n");
	exit(EXIT_SUCCESS);
}
