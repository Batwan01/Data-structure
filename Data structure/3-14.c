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
	if (pc == NULL) {
		printf("���� �޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		*pc = 100; //�����Ͱ��� 100 ����
		printf("c = %d\n", *pc); //���
	}
	if (pi == NULL) {
		printf("���� �޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		*pi = 100; //�����Ͱ��� 100 ����
		printf("i = %d\n", *pi); //���
	}
	printf("pc = %lu\n", pc);
	printf("pc+1 = %lu\n", pc + 1);
	printf("pc-1 = %lu\n", pc - 1);
	printf("pi = %lu\n", pi);
	printf("pi+1 = %lu\n", pi + 1);
	printf("pi-1 = %lu\n", pi - 1);
}