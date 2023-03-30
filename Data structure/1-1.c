#include <stdio.h>

int main()
{
	int i=0; // for문을 위한 i변수 선언
	int day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //일(日)에 필요한 배열 선언
	for (; i < 12; i++)
	{
		printf("%d월은 %d일까지 있습니다.\n", i+1, day[i]);
	}
}