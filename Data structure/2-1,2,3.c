#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct student //student 구조체 생성
{
	char name[100]; //이름
	int student_number; //학번
	int score; //성적
} student; //type의 이름 student

//평균을 구하는 함수
double get_mean(student students[], int n) //students배열의 포인터를 받음, 학생수를 정수 n으로 입력받음
{
	int i = 0;
	double mean = 0, sum = 0; //평균이 소수로 나올 수 있기 때문에 double로 선언
	for (; i < n; i++)
	{
		sum += students[i].score; //students배열의 score점수의 값을 sum에 더함
	}
	return sum / n; //score점수 합과 나눗셈을 나누어 반환
}

//표준편차를 구하는 함수
double get_deviation(student students[], int n) //students배열의 포인터를 받음, 학생수를 정수 n으로 입력받음
{
	int i; //for문을 위한 i변수, 총합을 위한 sum 변수, 평균을 위한 mean 변수, 
	double sum1=0, sum2=0, mean=0, sum = 0; // math함수 pow와 sqrt는 double로 처리하기 때문에 double로 선언
	for (i=0; i < n; i++)
	{
		sum += students[i].score; //students배열의 score점수의 값을 sum에 더함
	}
	mean = sum / n;
	for (i=0; i < n; i++)
	{
		sum1 = students[i].score - mean; //각 점수-평균
		sum2 += pow(sum1,2); //점수-평균을 제곱하여 sum2변수에 저장
	}
	return sqrt(sum2 / n); //sum2에 저장되어 있는 값에 루트를 하여 반환
}

int main()
{
	student static students[1000]; //구조체의 배열 students를 1000의 크기로 만듦
	int i = 0, n; //for문을 위한 i변수, 학생수 n변수 선언
	double a, b; //값이 double로 반환되기 때문에 double로 선언
	printf("학생수를 입력하세요.\n");
	scanf("%d", &n); //학생수 구하기
	printf("학생 이름, 학번, 점수를 입력하세요.\n"); 
	for (; i < n; i++) 
	{
		scanf("%s %d %d", students[i].name, &students[i].student_number, &students[i].score); 
		//students배열의 name, number, score에 각 값을 저장함
	}
	a = get_mean(students, n); //평균을 구하는 함수 students배열과 학생수 입력
	b = get_deviation(students, n); //표준편차를 구하는 함수 students배열과 학생수 입력
	printf("평균 : %f 표준편자 : %f", a, b);
}