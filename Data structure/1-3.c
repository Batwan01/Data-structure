#include <stdio.h>
#include <stdlib.h> //rand�Լ��� ���� ��� ����
#include <time.h> //rand�Լ��� �ʱ�ȭ�� ���� ��� ����

int main()
{
	int i = 0, max = 0, min = 0; // for���� ���� i���� ����
	int a[10];//ũ�Ⱑ 10�� a �迭 ����
	srand((int)time(NULL)); //rand �Լ� �ʱ�ȭ
	for (; i < 10; i++)
	{
		a[i] = rand(); //rand�Լ��� a�� b�迭 ������ ������ �ʱ�ȭ
	}
	max = a[0]; //max�� �迭 a[0]�� ����
	min = a[0]; //min�� �迭 a[0]�� ����
	for (i=0; i < 10; i++)
	{
		if (a[i] > max) max = a[i];
		//���� max���� *(a + i)�� �� ũ�� max�� ����
		printf("%d\n", a[i]); //�迭�� � ���� �ִ��� ���
	}
	for (i = 0; i < 10; i++)
	{
		if (a[i] < min) min = a[i];
		//���� min���� *(a + i)�� �� ������ min�� ����
	}
	printf("�ִ��� %d�Դϴ�.\n", max);
	printf("�ּڰ��� %d�Դϴ�.", min);
}