#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct student //student ����ü ����
{
	char name[100];
	int student_number;
	int score;
} student; //type�� �̸� student

student students[1000]; //����ü�� �迭 students�� 1000�� ũ��� ����

int get_mean(student* a, int n) //����� ���ϴ� �Լ� students�迭�� ������ a�� �Է¹ް�, �л����� ���� n���� �Է¹���
{
	int i = 0;
	float mean = 0, sum = 0;
	for (; i < n; i++)
	{
		sum += students[i].score;
	}
	return sum / n;
}

float get_deviation(student* a, int n)
{
	int i; //for���� ���� i����, ������ ���� sum ����, ����� ���� mean ����, 
	float deviation, sum1=0, sum2=0, mean, sum = 0; // �߰� ����� �����ϱ� ���� sum1, sum2���� ����, ��Ʈ�̱� ������ float�� ����
	for (i=0; i < n; i++)
	{
		sum += students[i].score;
	}
	mean = sum / n;
	for (i=0; i < n; i++)
	{
		sum1 = students[i].score - mean;
		sum2 += powf(sum1,2);
	}
	printf("%f %f %f", sum1, sum2, sqrt(sum2 / (n - 1)));
	return sqrt(sum2 / (n-1));
}

int main()
{
	int i = 0, n;
	float a, b;
	printf("�л����� �Է��ϼ���.\n");
	scanf("%d", &n);
	printf("�л� �̸�, �й�, ������ �Է��ϼ���.\n");
	for (; i < n; i++)
	{
		scanf("%s %d %d", students[i].name, &students[i].student_number, &students[i].score);
	}
	a = get_mean(students, n);
	b = get_deviation(students, n);
	printf("��� : %f ǥ������ : %f", a, b);
}