#include <stdio.h>
#include <stdlib.h> //rand�Լ��� ���� ��� ����
#include <time.h> //rand�Լ��� �ʱ�ȭ�� ���� ��� ����

int matrix_diif(int* a, int* b, int* c) //a�迭 b�迭 c�迭 �����ͷ� ���� ����(1-2������)
{
	int i=0; //for���� ���� i���� ����
	for (; i < 10; i++)
	{
		(*(c + i)) = (*(a + i)) - (*(b + i)); // (*(a+i))�� a[i]�� �����ϴ�.
		printf("%d ", (*(c + i))); //c�迭 ���
	}
}

int max_min(int* a, int* b) //a�迭 b�迭 �����ͷ� ���� ����(1-3�� ����)
{
	int i = 0, max = 0, min = 0; //for���� ���� i���� ����, �ִ�, �ּڰ� ����� ���� max, min ���� ����
	max = *a; //max�� �迭 a[0]�� ����
	min = *a; //min�� �迭 a[0]�� ����
	for (; i < 10; i++)
	{
		if ((*(a + i)) > max) max = (*(a + i)); //���� max���� *(a + i)�� �� ũ�� max�� ����
		if ((*(b + i)) > max) max = (*(b + i));
	}
	printf("%d ", max);
	for (; i < 10; i++)
	{
		if ((*(a + i)) < min) min = (*(a + i)); //���� min���� *(a + i)�� �� ������ min�� ����
		if ((*(b + i)) < min) min = (*(b + i));
	}
	printf("%d ", min);
}

int search(int* a, int b, int ) //a�迭 b�迭 �����ͷ� ���� ����(1-4�� ����)
{

}

int main()
{
	int i = 0; // for���� ���� i���� ����
	int a[10], b[10], c[10]; //ũ�Ⱑ 10�� a,b,c �迭 ����
	srand((int)time(NULL)); //rand �Լ� �ʱ�ȭ
	for (; i < 10; i++)
	{
		a[i] = rand(); //rand�Լ��� a�� b�迭 ������ ������ �ʱ�ȭ
		b[i] = rand();
	}
	matrix_diif(a, b, c); //���Ƿ� ����� �迭 a,b,c ����
	max_min(a, b); //���Ƿ� ����� �迭 a,b ����
}