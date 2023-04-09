#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc�Լ��� ����ϱ� ���� ��� ����

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;
	pc = (char*)malloc(100 * sizeof(char)); //����(1byte)*100 = 100byte �Ҵ�
	pi = (int*)malloc(100 * sizeof(int)); //����(4byte)*100 = 400byte �Ҵ�
	pf = (float*)malloc(100 * sizeof(float)); //float(4byte)*100 = 400byte �Ҵ�
	pd = (double*)malloc(100 * sizeof(double)); //double(8byte)*100 = 800byte �Ҵ�

	if (pf == NULL) {
		printf("float �޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		*pf = 100; //�����Ͱ��� 100 ����
		printf("pf = %f\n", *pf); //���
	}
	if (pd == NULL) {
		printf("double �޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		*pd = 100; //�����Ͱ��� 100 ����
		printf("pd = %lf\n", *pd); //���
	}
	printf("pf = %lu\n", pf);
	printf("pf+1 = %lu\n", pf + 1);
	printf("pf-1 = %lu\n", pf - 1);
	printf("pd = %lu\n", pd);
	printf("pd+1 = %lu\n", pd + 1);
	printf("pd-1 = %lu\n", pd - 1);

	free(pc);
	free(pi);
	free(pf);
	free(pd);
}