#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;
	pc = (char*)malloc(100 * sizeof(char));
	pi = (int*)malloc(100 * sizeof(int));
	pf = (float*)malloc(100 * sizeof(float));
	pd = (double*)malloc(100 * sizeof(double));
	if (pc == NULL) {
		printf("문자 메모리 할당 실패");
		exit(1);
	}
	else
	{
		*pc = 100; //포인터값에 100 대입
		printf("c = %d\n", *pc); //출력
	}
	if (pi == NULL) {
		printf("정수 메모리 할당 실패");
		exit(1);
	}
	else
	{
		*pi = 100; //포인터값에 100 대입
		printf("i = %d\n", *pi); //출력
	}
	printf("pc = %lu\n", pc);
	printf("pc+1 = %lu\n", pc + 1);
	printf("pc-1 = %lu\n", pc - 1);
	printf("pi = %lu\n", pi);
	printf("pi+1 = %lu\n", pi + 1);
	printf("pi-1 = %lu\n", pi - 1);
}