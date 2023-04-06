#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일

void main()
{
	int i;
	char* pc; //pc문자를 포인터로 선언
	pc = (char*)malloc(100); //문자 100개 공간 할당
	for (i = 0; i < 100; i++) {
		*pc = 100; //pc[0]에만 100의 정수가 선언
	}
	free(pc); //더이상 메모리를 사용할 필요가 없기 때문에 시스템에 반환
}