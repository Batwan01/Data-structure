#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int search(int* num, int a, int *p) //num�迭�� �����ͷ� �ް�, main�Լ��� �ִ� a���� search�Լ� a�� ���޹���, p�� �����ͷ� main���� �����ϱ� ���� �뵵
{
	int i = 0; //for���� ���� i���� ����
	for (; i < 10; i++)
	{
		if ((*(num + i)) == a) //num[i]�� ���� ã�°�(a)�� ������ printf�� ��� �� break
		{
			*p = i; //p�� �ּҿ� i�� ����
			break;
		}
	}
	pritf("ã���� �ϴ� ���� �������� �ʽ��ϴ�."); //���� �޼���
}

int main()
{
	int a = 0,p=0; // for���� ���� i���� ����
	int num[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 }; //num �迭�� ������ ���� ����
	scanf("%d", &a); //ã�°� �Է� �ޱ�
	search(num, a, &p); //num�迭�� ���� ã�� �� �Է� &p�� ���� main���� p�� �ּҸ� �������� ����
	printf("%d�� ���� num[%d]�� ��ġ�ϰ� �ֽ��ϴ�.", a, p);
}