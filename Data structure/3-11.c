#include <stdio.h>
#include <memory.h>
#include <stdlib.h> //malloc�Լ��� ����ϱ� ���� ��� ����

void main()
{
	int i;
	char* pc; //pc���ڸ� �����ͷ� ����
	pc = (char*)malloc(100); //���� 100�� ���� �Ҵ�
	for (i = 0; i < 100; i++) {
		*pc = 100; //pc[0]���� 100�� ������ ����
	}
	free(pc); //���̻� �޸𸮸� ����� �ʿ䰡 ���� ������ �ý��ۿ� ��ȯ
}