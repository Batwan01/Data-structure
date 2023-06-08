#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*int recur(int n) {
	printf("%d ", n);
	if (n < 1) return -1;
	else return (recur(n - 3) + 1);
}*/
 
int sum(int n) {
	if (n < 1) return 0;
	return sum(n - 1) + 1/n;
}

int main(void)
{
	printf("%d",sum(4));
}