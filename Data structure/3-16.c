#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일

typedef struct test {
	int data;
	struct test* link;
} test_str;

void main()
{
	int i;
	test_str* ptest;
	ptest = (double*)malloc(sizeof(test_str)); //구조체 test 1개 공간 할당
	for (i = 0; i < 5; i++)
	{
		printf("%d", ptest[i].data);
	}
	ptest->data = 100; //구조체 test의 data에 100저장
	printf("%d", ptest->data);
	free(ptest);
}