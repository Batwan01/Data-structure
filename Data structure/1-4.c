#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int search(int* num, int a) //num배열은 포인터로 받고, main함수에 있는 a값을 search함수 a로 전달받음
{
	int i = 0; //for문을 위한 i변수 선언
	for (; i < 10; i++)
	{
		if ((*(num + i)) == a) //num[i]의 값이 찾는값(a)와 같으면 printf로 출력 후 break
		{
			printf("%d은 num[%d]에 위치하고 있습니다.", a,i);
			break;
		}
	}
}

int main()
{
	int a = 0; // for문을 위한 i변수 선언
	int num[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 }; //num 배열에 임의의 숫자 선언
	scanf("%d", &a); //찾는값 입력 받기
	search(num, a); //num배열의 값과 찾는 값 입력
}