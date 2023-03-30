#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct student //student 구조체 생성
{
	char name[100];
	int student_number;
	int score;
} student; //type의 이름 student

student students[1000]; //구조체의 배열 students를 1000의 크기로 만듦

int get_mean(student* a, int n) //평균을 구하는 함수 students배열을 포인터 a로 입력받고, 학생수를 정수 n으로 입력받음
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
	int i; //for문을 위한 i변수, 총합을 위한 sum 변수, 평균을 위한 mean 변수, 
	float deviation, sum1=0, sum2=0, mean, sum = 0; // 중간 계산을 저장하기 위한 sum1, sum2변수 제곱, 루트이기 때문에 float로 선언
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
	printf("학생수를 입력하세요.\n");
	scanf("%d", &n);
	printf("학생 이름, 학번, 점수를 입력하세요.\n");
	for (; i < n; i++)
	{
		scanf("%s %d %d", students[i].name, &students[i].student_number, &students[i].score);
	}
	a = get_mean(students, n);
	b = get_deviation(students, n);
	printf("평균 : %f 표준편자 : %f", a, b);
}