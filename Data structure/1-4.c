#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int search(int* num, int a) //num�迭�� �����ͷ� �ް�, main�Լ��� �ִ� a���� search�Լ� a�� ���޹���
{
	int i = 0; //for���� ���� i���� ����
	for (; i < 10; i++)
	{
		if ((*(num + i)) == a) //num[i]�� ���� ã�°�(a)�� ������ printf�� ��� �� break
		{
			printf("%d�� num[%d]�� ��ġ�ϰ� �ֽ��ϴ�.", a,i);
			break;
		}
	}
}

int main()
{
	int a = 0; // for���� ���� i���� ����
	int num[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 }; //num �迭�� ������ ���� ����
	scanf("%d", &a); //ã�°� �Է� �ޱ�
	search(num, a); //num�迭�� ���� ã�� �� �Է�
}