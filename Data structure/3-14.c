#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;
	pc = (char*)malloc(100 * sizeof(char)); //문자(1byte)*100 = 100byte 할당
	pi = (int*)malloc(100 * sizeof(int)); //정수(4byte)*100 = 400byte 할당
	pf = (float*)malloc(100 * sizeof(float)); //float(4byte)*100 = 400byte 할당
	pd = (double*)malloc(100 * sizeof(double)); //double(8byte)*100 = 800byte 할당

	if (pc == NULL) { //만약 할당이 안 되었으면 오류 메세지 출력
		printf("문자 메모리 할당 실패");
		exit(1);
	}
	else
	{
		*pc = 100; //포인터값에 100 대입
		printf("pc = %d\n", *pc); //출력
	}
	if (pi == NULL) {
		printf("정수 메모리 할당 실패");
		exit(1);
	}
	else
	{
		*pi = 100; //포인터값에 100 대입
		printf("pi = %d\n", *pi); //출력
	}

	printf("pc = %lu\n", pc);
	printf("pc+1 = %lu\n", pc + 1);
	printf("pc-1 = %lu\n", pc - 1);
	printf("pi = %lu\n", pi);
	printf("pi+1 = %lu\n", pi + 1);
	printf("pi-1 = %lu\n", pi - 1);
}