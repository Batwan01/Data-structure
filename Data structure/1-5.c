#include <stdio.h>
#define LIST_SIZE 10

int list[LIST_SIZE] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };

main()
{
	int i; // for���� ���� i���� ����
	for (i=0; i < 12; i++) //1������ 12������ for���� ���� ���
	{
		printf("list[%d]�� �ּ� = %p\n", i, &list[i]); 
	}
}