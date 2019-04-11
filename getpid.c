#include <stdio.h> // 표준 입출력 
#include <stdlib.h> // 표준 라이브러리 exit() : 프로세스 종료
#include <unistd.h> // getpid()를 쓰기 위한 헤더파일

int main(int argc, char **argv) {
	printf("hello, world from process %d\n", getpid()); // 
	exit(EXIT_SUCCESS); // EXIT_SUCCESS = 0; return 0;과 같은 의미
}
