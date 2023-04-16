#include <stdio.h>

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;

	char c;
	int i;
	float f;
	double d;

	//printf("%lu %lu %lu\n", pi, pf, pd); //메모리 주소가 할당되지 않고 호출하기 때문에 오류가 발생한다.
	pi = &i; //메모리 할당
	pf = &f;
	pd = &d;
	printf("%lu %lu %lu\n", pi, pf, pd);
	*pi = 100; //i에 100 할당
	*pf = 100;
	*pd = 100;
	printf("i = %d\nf = %f\nd = %f", i, f, d);
}