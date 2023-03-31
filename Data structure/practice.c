#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct student //student 구조체 생성
{
	char name[100]; //이름
	int student_number; //학번
	int score; //성적
} student; //type의 이름 student

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
	for (i=0; i < n; i++)
	{
		printf("\n이름 : %s 학번 : %d 성적 : %d", students[i].name, students[i].student_number, students[i].score);
		//students배열의 name, number, score에 각 값을 출력함
	}
}