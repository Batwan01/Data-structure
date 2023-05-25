#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef char element;
typedef struct {
	element* queue[MAX_QUEUE_SIZE];				//배열 포인터(하나의 노드에 문자열 이름이 들어가도록 설정)
	int front, rear, count;								//전단, 후단
}QueueType;

//에러 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화 함수
void init(QueueType* q)
{
	q->front = q->rear = q->count = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->count == 0);
}

//포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->count) == MAX_QUEUE_SIZE);
}

//삽입 함수
void enqueue(QueueType* q, element* name)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;				//rear 증가
	q->queue[q->rear] = name;							//rear에 이름 넣기
	q->count++;											//count변수 증가
}

//삭제 함수
void dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;				//원형 큐에서의 front를 증가
	q->queue[q->front] = NULL;							//front값 삭제
	q->count--;											//count변수 감소

}

//피크 함수
element* peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];		//이름 확인
}

//커플 완성, 큐에서 삭제
void weeding(QueueType* m, QueueType* f)
{
	if (is_empty(m) || is_empty(f))
	{
		printf(" queue is empty!\n");
	}
	else
	{
		dequeue(m);							//커플 완성, 남자와 여자 삭제
		dequeue(f);
	}
}

//서로 상대자가 있는지 검색하는 함수
void meeting(QueueType* m, QueueType* f)
{
	if (m->rear == m->front || f->rear == f->front)
	{
		printf("아직 대상자가 없습니다. 기다려주십시오. \n");
	}
	else {
		printf("커플이 탄생했습니다! %s과 %s \n", m->queue[(m->front + 1) % MAX_QUEUE_SIZE], f->queue[(f->front + 1) % MAX_QUEUE_SIZE]);
		weeding(m, f);								//커플 완성
	}
}



//주 함수
void main()
{
	QueueType	q_m, q_f;
	char str[20][20];
	char sex = NULL;
	int i = 0;

	init(&q_m);
	init(&q_f);

	printf("미팅 주선 프로그램 입니다.\n\n");
	do {
		printf("고객이름 : ");

		scanf("%s", str[i]);
		fflush(stdin);
		if (strcmp(str[i], "q"))
		{
			printf("성별을 입력하세요(f or m)  ");
			scanf("%c", &sex);
			fflush(stdin);
			switch (sex)
			{
			case 'm':
				enqueue(&q_m, str[i]);
				meeting(&q_m, &q_f);
				break;
			case 'f':
				enqueue(&q_f, str[i]);
				meeting(&q_m, &q_f);
				break;
			default:
				printf("잘못 입력하셨습니다.\n");
				break;
			}
			i++;
		}
		printf("\n");
	} while (strcmp(str[i], "q"));

}
