#include <stdio.h>
#include <stdlib.h> //rand함수를 위한 헤더 파일
#include <time.h> //rand함수의 초기화를 위한 헤더 파일

int main()
{
	int i = 0, max = 0, min = 0; // for문을 위한 i변수 선언
	int a[10];//크기가 10인 a 배열 선언
	srand((int)time(NULL)); //rand 함수 초기화
	for (; i < 10; i++)
	{
		a[i] = rand(); //rand함수로 a와 b배열 임의의 값으로 초기화
	}
	max = a[0]; //max값 배열 a[0]값 선언
	min = a[0]; //min값 배열 a[0]값 선언
	for (i=0; i < 10; i++)
	{
		if (a[i] > max) max = a[i];
		//만약 max보다 *(a + i)가 더 크면 max에 저장
		printf("%d\n", a[i]); //배열에 어떤 값이 있는지 출력
	}
	for (i = 0; i < 10; i++)
	{
		if (a[i] < min) min = a[i];
		//만약 min보다 *(a + i)가 더 작으면 min에 저장
	}
	printf("최댓값은 %d입니다.\n", max);
	printf("최솟값은 %d입니다.", min);
}