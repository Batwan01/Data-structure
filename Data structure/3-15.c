#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc�Լ��� ����ϱ� ���� ��� ����

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
		printf("float �޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		*pf = 100; //�����Ͱ��� 100 ����
		printf("f = %f\n", *pf); //���
	}
	if (pd == NULL) {
		printf("double �޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		*pd = 100; //�����Ͱ��� 100 ����
		printf("d = %lf\n", *pd); //���
	}
	printf("pc = %lu\n", pf);
	printf("pc+1 = %lu\n", pf + 1);
	printf("pc-1 = %lu\n", pf - 1);
	printf("pi = %lu\n", pd);
	printf("pi+1 = %lu\n", pd + 1);
	printf("pi-1 = %lu\n", pd - 1);
}