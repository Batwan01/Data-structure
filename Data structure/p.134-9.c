#include <stdio.h>
#include <stdlib.h> //malloc�Լ��� ����ϱ� ���� ��� ����
#include <string.h>
#include <time.h>

typedef struct Node { //��� ����
	char* name;
	struct Node* next; //������
	struct Node* prev; //������
} Node;

typedef struct List { //head�� tail ����
	Node* head; //ù ��° �� ����Ŵ
	Node* tail; //������ �� ����Ŵ
	Node* first; //head, tail free�Ǹ� ù��° ��ġ����Ŵ
	int count;
}List;