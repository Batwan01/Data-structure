#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int recur(int n) {
	printf("%d ", n);
	if (n < 1) return -1;
	else return (recur(n - 3) + 1);
}
 
int main(void)
{
	int n = 13;
	recur(13);
}