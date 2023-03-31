#include <stdio.h>
#include <stdlib.h> //rand함수를 위한 헤더 파일
#include <time.h> //rand함수의 초기화를 위한 헤더 파일

void matrix_diif(int* a, int* b, int* c) //a배열 b배열 c배열 포인터로 전달 받음(1-2번문제)
{
	int i=0; //for문을 위한 i변수 선언
	for (; i < 10; i++)
	{
		(*(c + i)) = (*(a + i)) - (*(b + i)); // (*(a+i))는 a[i]와 같습니다.
		printf("%d - %d = %d\n", (*(a + i)) , (*(b + i)), (*(c + i))); //c배열 출력
	}
}

void max_min(int* a) //a배열 b배열 포인터로 전달 받음(1-3번 문제)
{
	int i = 0, max = 0, min = 0; //for문을 위한 i변수 선언, 최댓값, 최솟값 출력을 위해 max, min 변수 선언
	max = *a; //max값 배열 a[0]값 선언
	min = *a; //min값 배열 a[0]값 선언
	for (; i < 10; i++)
	{
		if ((*(a + i)) > max) max = (*(a + i)); //만약 max보다 *(a + i)가 더 크면 max에 저장
		printf("%d\n", (*(a + i))); //배열에 어떤 값이 있는지 출력
	}
	printf("최댓값은 %d입니다.\n", max);
	for (i=0; i < 10; i++)
	{
		if ((*(a + i)) < min) min = (*(a + i)); //만약 min보다 *(a + i)가 더 작으면 min에 저장
	}
	printf("최솟값은 %d입니다.", min);
}

int main()
{
	int i = 0; // for문을 위한 i변수 선언
	int a[10], b[10], c[10]; //크기가 10인 a,b,c 배열 선언
	srand((int)time(NULL)); //rand 함수 초기화
	for (; i < 10; i++)
	{
		a[i] = rand(); //rand함수로 a와 b배열 임의의 값으로 초기화
		b[i] = rand();
	}
	//matrix_diif(a, b, c); //임의로 선언된 배열 a,b,c배열 전달
	max_min(a); //임의로 선언된 배열 a배열 전달
}