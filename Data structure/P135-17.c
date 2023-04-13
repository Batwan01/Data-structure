#include <stdio.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일
#include <string.h>

typedef struct Node { //노드 생성
	char *name;
	struct Node* next; //이중 연결리스트 생성
	struct Node* prev;
} Node;

typedef struct List { //head와 tail 정의
	Node* head;
	Node* tail;
	Node* first;
	int count;
}List;

Node* Newnode(char *names) //노드 새로 만들기
{
	Node* new = (Node*)malloc(sizeof(Node)); //구조체 1개 공간 할당
	new->name = (char*)malloc(strlen(names) + 1);
	strcpy(new->name, names);
	new->next = new->prev = NULL;
	return new;	
}

void Setnode(List* list) { //노드 초기설정
	list->head = Newnode(" ");
	list->tail = Newnode(" ");
	list->head->next = list->tail; //head의 다음은 tail
	list->head->prev = list->tail; //head의 뒤는 tail
	list->tail->next = list->head; //tail의 다음은 head
	list->tail->prev = list->head; //tail의 뒤는 head
	list->count = 0;
}

void Adddata(List* list, char* names) {
	Node *add = Newnode(names);
	if (list->count == 0) { //첫번째 tail 설정
		add->next = list->head->next;
		add->prev = list->head;
		list->head->next = add;
		list->tail->prev = add;
	}
	else {
		add->next = list->head->next;
		add->prev = list->head;
		list->head->next = add;
		list->first = add; //첫번째 값
	}
	list->count++;
}
void Freelist(List* list) { //head와 tail값 free하기
	Node* heads = list->head;
	Node* tails = list->tail;
	list->head->next->prev = list->tail->prev; //head다음 첫 번쨰 값의 prev는 tail의 prev값
	list->tail->prev->next = list->head->next;//tail뒤의 값의 next값은 tail의 next값
}

void Viewall(List* list) {
	Node* check = list->first;
	int i = 0;
	while (i!=list->count)
	{
		printf("%s",check->name);
		check = check->next;
		i++;
	}
}
void main()
{
	int i;
	char names[10];
	List list;
	Setnode(&list);
	printf("학생의 이름을 입력하세요.(종료를 원하면 0을 입력하세요.)\n");
	while (1) {
 		scanf("%s", names);
		if (names[0] == '0') break;
		Adddata(&list, names);
	}
	Freelist(&list);
	Viewall(&list);
}	
//오늘 할 거 rand함수로 랜덤 사람 뽑기, n번 입력받아서 사람 없애기, 남은사람 실시간으로 출력하기
//
