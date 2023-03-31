#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct student //student ����ü ����
{
	char name[100]; //�̸�
	int student_number; //�й�
	int score; //����
} student; //type�� �̸� student

//����� ���ϴ� �Լ�
double get_mean(student students[], int n) //students�迭�� �����͸� ����, �л����� ���� n���� �Է¹���
{
	int i = 0;
	double mean = 0, sum = 0; //����� �Ҽ��� ���� �� �ֱ� ������ double�� ����
	for (; i < n; i++)
	{
		sum += students[i].score; //students�迭�� score������ ���� sum�� ����
	}
	return sum / n; //score���� �հ� �������� ������ ��ȯ
}

//ǥ�������� ���ϴ� �Լ�
double get_deviation(student students[], int n) //students�迭�� �����͸� ����, �л����� ���� n���� �Է¹���
{
	int i; //for���� ���� i����, ������ ���� sum ����, ����� ���� mean ����, 
	double sum1=0, sum2=0, mean=0, sum = 0; // math�Լ� pow�� sqrt�� double�� ó���ϱ� ������ double�� ����
	for (i=0; i < n; i++)
	{
		sum += students[i].score; //students�迭�� score������ ���� sum�� ����
	}
	mean = sum / n;
	for (i=0; i < n; i++)
	{
		sum1 = students[i].score - mean; //�� ����-���
		sum2 += pow(sum1,2); //����-����� �����Ͽ� sum2������ ����
	}
	return sqrt(sum2 / n); //sum2�� ����Ǿ� �ִ� ���� ��Ʈ�� �Ͽ� ��ȯ
}

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
	a = get_mean(students, n); //����� ���ϴ� �Լ� students�迭�� �л��� �Է�
	b = get_deviation(students, n); //ǥ�������� ���ϴ� �Լ� students�迭�� �л��� �Է�
	printf("��� : %f ǥ������ : %f", a, b);
}