#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct student //student ����ü ����
{
	char name[100]; //�̸�
	int student_number; //�й�
	int score; //����
} student; //type�� �̸� student

int main()
{
	student static students[1000]; //����ü�� �迭 students�� 1000�� ũ��� ����
	int i = 0, n; //for���� ���� i����, �л��� n���� ����
	double a, b; //���� double�� ��ȯ�Ǳ� ������ double�� ����
	printf("�л����� �Է��ϼ���.\n");
	scanf("%d", &n); //�л��� ���ϱ�
	printf("�л� �̸�, �й�, ������ �Է��ϼ���.\n");
	for (; i < n; i++)
	{
		scanf("%s %d %d", students[i].name, &students[i].student_number, &students[i].score);
		//students�迭�� name, number, score�� �� ���� ������
	}
	for (i=0; i < n; i++)
	{
		printf("\n�̸� : %s �й� : %d ���� : %d", students[i].name, students[i].student_number, students[i].score);
		//students�迭�� name, number, score�� �� ���� �����
	}
}