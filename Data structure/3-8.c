#include <stdio.h>

char * pa[20]; //int�� ������ �Ǿ�������, �Է°��� char�̶� ������ �߻�

char* pa[] = {
	"���� 1",
	"���� 2",
	"���� 3",
	"���� 4",
	"���� 5",
	"���� 6"
};
void error(int err_num)
{
	printf(pa[err_num]);
}
main()
{
	error(1);
}