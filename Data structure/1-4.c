#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void search(int* num, int a, int *adress) //num배열은 포인터로 받고, main함수에 있는 a값을 search함수 a로 전달받음, p는 포인터로 main으로 전달하기 위한 용도
{
	int i = 0; //for문을 위한 i변수 선언
	for (; i < 10; i++)
	{
		if ((*(num + i)) == a)
		{
			*adress = i; //p의 주소에 i를 저장
			return; //search 함수 종료
		}
	}
	return; //search 함수 종료
}

int main()
{
	int a = 0, adress=-1; // for문을 위한 i변수 선언
	int num[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 }; //num 배열에 임의의 숫자 선언
	scanf("%d", &a); //찾는값 입력 받기
	search(num, a, &adress); //num배열의 값과 찾는 값 입력 &p은 값은 main에서 p의 주소를 가져오기 위함
	if(adress == -1) printf("찾고자 하는 값이 존재하지 않습니다."); //오류 메세지
	else printf("%d의 값은 num[%d]에 위치하고 있습니다.", a, adress); //찾는 값의 위치 출력
}