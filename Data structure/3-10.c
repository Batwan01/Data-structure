#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일

void main()
{
	char* pc; //pc문자를 포인터로 선언
	pc = (char*)malloc(1); //문자(1byte) 동적할당으로 문자 한개 입력 가능
	*pc = 100; 
	//pc는 단일 바이트만 저장할 수 있는 문자에 대한 포인터기 때문에 정수가 입력되기에 적합하지 않음
	printf("c = %d\n", *pc); //100의 정수가 입력됐기 때문에 %d로 100의값 출력
	free(pc); //더이상 메모리를 사용할 필요가 없기 때문에 시스템에 반환
}