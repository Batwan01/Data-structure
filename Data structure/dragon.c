#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef char element;
typedef struct {
	element* queue[MAX_QUEUE_SIZE];				//�迭 ������(�ϳ��� ��忡 ���ڿ� �̸��� ������ ����)
	int front, rear, count;								//����, �Ĵ�
}QueueType;

//���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ �Լ�
void init(QueueType* q)
{
	q->front = q->rear = q->count = 0;
}

//���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->count == 0);
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->count) == MAX_QUEUE_SIZE);
}

//���� �Լ�
void enqueue(QueueType* q, element* name)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;				//rear ����
	q->queue[q->rear] = name;							//rear�� �̸� �ֱ�
	q->count++;											//count���� ����
}

//���� �Լ�
void dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;				//���� ť������ front�� ����
	q->queue[q->front] = NULL;							//front�� ����
	q->count--;											//count���� ����

}

//��ũ �Լ�
element* peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];		//�̸� Ȯ��
}

//Ŀ�� �ϼ�, ť���� ����
void weeding(QueueType* m, QueueType* f)
{
	if (is_empty(m) || is_empty(f))
	{
		printf(" queue is empty!\n");
	}
	else
	{
		dequeue(m);							//Ŀ�� �ϼ�, ���ڿ� ���� ����
		dequeue(f);
	}
}

//���� ����ڰ� �ִ��� �˻��ϴ� �Լ�
void meeting(QueueType* m, QueueType* f)
{
	if (m->rear == m->front || f->rear == f->front)
	{
		printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�. \n");
	}
	else {
		printf("Ŀ���� ź���߽��ϴ�! %s�� %s \n", m->queue[(m->front + 1) % MAX_QUEUE_SIZE], f->queue[(f->front + 1) % MAX_QUEUE_SIZE]);
		weeding(m, f);								//Ŀ�� �ϼ�
	}
}



//�� �Լ�
void main()
{
	QueueType	q_m, q_f;
	char str[20][20];
	char sex = NULL;
	int i = 0;

	init(&q_m);
	init(&q_f);

	printf("���� �ּ� ���α׷� �Դϴ�.\n\n");
	do {
		printf("���̸� : ");

		scanf("%s", str[i]);
		fflush(stdin);
		if (strcmp(str[i], "q"))
		{
			printf("������ �Է��ϼ���(f or m)  ");
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
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
				break;
			}
			i++;
		}
		printf("\n");
	} while (strcmp(str[i], "q"));

}
