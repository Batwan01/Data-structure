#include <stdio.h>
#define LIST_SIZE 10

int list[LIST_SIZE] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };

main()
{
	int i; // for문을 위한 i변수 선언
	for (i=0; i < 12; i++) //1월부터 12월까지 for문을 통한 출력
	{
		printf("list[%d]의 주소 = %p\n", i, &list[i]); 
	}
}