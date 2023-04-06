#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int* pi;
	pi = (int*)malloc(100 * sizeof(char));
	//100바이트의 대한 메모리를 할당했기 때문에 정수는 400바이트가 필요하기 때문에 100개의 정수를 저장하기에는 공간이 부족
	*pi = 25600000000;
	printf("c = %d\n", *pi);
	free(pi);
}