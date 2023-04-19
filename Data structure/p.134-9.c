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

void insert_node(Node* before, Node* new) {
	new->prev = before;
	new->next = before->next;
	before->next = new;
	new->next->prev = new;
}

Node* delete_node(List* before, Node* delete) {
	if (before == NULL) {
		delete->next->prev = before->tail;
		before->tail->next = delete->next;
	}
}

int main() {
	Node node, new;
	insert_node(&node, &new);
}