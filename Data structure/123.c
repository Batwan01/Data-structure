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

	//printf("%lu %lu %lu\n", pi, pf, pd); //�޸� �ּҰ� �Ҵ���� �ʰ� ȣ���ϱ� ������ ������ �߻��Ѵ�.
	pi = &i; //�޸� �Ҵ�
	pf = &f;
	pd = &d;
	printf("%lu %lu %lu\n", pi, pf, pd);
	*pi = 100; //i�� 100 �Ҵ�
	*pf = 100;
	*pd = 100;
	printf("i = %d\nf = %f\nd = %f", i, f, d);
}