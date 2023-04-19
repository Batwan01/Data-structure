#include <stdio.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일
#include <string.h>
#include <time.h>

typedef struct Node { //노드 생성
	char* name;
	struct Node* next; //다음값
	struct Node* prev; //이전값
} Node;

typedef struct List { //head와 tail 정의
	Node* head; //첫 번째 값 가르킴
	Node* tail; //마지막 값 가르킴
	Node* first; //head, tail free되면 첫번째 위치가르킴
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