#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc�Լ��� ����ϱ� ���� ��� ����

typedef struct test {
	int data;
	struct test* link;
} test_str;

void main()
{
	int i;
	test_str* ptest;
	ptest = (double*)malloc(sizeof(test_str));
	ptest->data = 100;
	printf("%d", ptest->data);
	free(ptest);
}