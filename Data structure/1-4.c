#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void search(int* num, int a, int *adress) //num�迭�� �����ͷ� �ް�, main�Լ��� �ִ� a���� search�Լ� a�� ���޹���, p�� �����ͷ� main���� �����ϱ� ���� �뵵
{
	int i = 0; //for���� ���� i���� ����
	for (; i < 10; i++)
	{
		if ((*(num + i)) == a)
		{
			*adress = i; //p�� �ּҿ� i�� ����
			return; //search �Լ� ����
		}
	}
	return; //search �Լ� ����
}

int main()
{
	int a = 0, adress=-1; // for���� ���� i���� ����
	int num[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 }; //num �迭�� ������ ���� ����
	scanf("%d", &a); //ã�°� �Է� �ޱ�
	search(num, a, &adress); //num�迭�� ���� ã�� �� �Է� &p�� ���� main���� p�� �ּҸ� �������� ����
	if(adress == -1) printf("ã���� �ϴ� ���� �������� �ʽ��ϴ�."); //���� �޼���
	else printf("%d�� ���� num[%d]�� ��ġ�ϰ� �ֽ��ϴ�.", a, adress); //ã�� ���� ��ġ ���
}