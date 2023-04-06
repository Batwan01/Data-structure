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
	if (pf == NULL) {
		printf("float 메모리 할당 실패");
		exit(1);
	}
	else
	{
		*pf = 100; //포인터값에 100 대입
		printf("f = %f\n", *pf); //출력
	}
	if (pd == NULL) {
		printf("double 메모리 할당 실패");
		exit(1);
	}
	else
	{
		*pd = 100; //포인터값에 100 대입
		printf("d = %lf\n", *pd); //출력
	}
	printf("pc = %lu\n", pf);
	printf("pc+1 = %lu\n", pf + 1);
	printf("pc-1 = %lu\n", pf - 1);
	printf("pi = %lu\n", pd);
	printf("pi+1 = %lu\n", pd + 1);
	printf("pi-1 = %lu\n", pd - 1);
}