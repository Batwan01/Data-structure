#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int* pi;
	pi = (int*)malloc(100 * sizeof(char));
	*pi = 25600000000;
	printf("c = %d\n", *pi);
	free(pi);
}