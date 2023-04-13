#include <stdio.h>
#include <stdlib.h> //malloc�Լ��� ����ϱ� ���� ��� ����
#include <string.h>

typedef struct Node { //��� ����
	char *name;
	struct Node* next; //���� ���Ḯ��Ʈ ����
	struct Node* prev;
} Node;

typedef struct List { //head�� tail ����
	Node* head;
	Node* tail;
	Node* first;
	int count;
}List;

Node* Newnode(char *names) //��� ���� �����
{
	Node* new = (Node*)malloc(sizeof(Node)); //����ü 1�� ���� �Ҵ�
	new->name = (char*)malloc(strlen(names) + 1);
	strcpy(new->name, names);
	new->next = new->prev = NULL;
	return new;	
}

void Setnode(List* list) { //��� �ʱ⼳��
	list->head = Newnode(" ");
	list->tail = Newnode(" ");
	list->head->next = list->tail; //head�� ������ tail
	list->head->prev = list->tail; //head�� �ڴ� tail
	list->tail->next = list->head; //tail�� ������ head
	list->tail->prev = list->head; //tail�� �ڴ� head
	list->count = 0;
}

void Adddata(List* list, char* names) {
	Node *add = Newnode(names);
	if (list->count == 0) { //ù��° tail ����
		add->next = list->head->next;
		add->prev = list->head;
		list->head->next = add;
		list->tail->prev = add;
	}
	else {
		add->next = list->head->next;
		add->prev = list->head;
		list->head->next = add;
		list->first = add; //ù��° ��
	}
	list->count++;
}
void Freelist(List* list) { //head�� tail�� free�ϱ�
	Node* heads = list->head;
	Node* tails = list->tail;
	list->head->next->prev = list->tail->prev; //head���� ù ���� ���� prev�� tail�� prev��
	list->tail->prev->next = list->head->next;//tail���� ���� next���� tail�� next��
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
	printf("�л��� �̸��� �Է��ϼ���.(���Ḧ ���ϸ� 0�� �Է��ϼ���.)\n");
	while (1) {
 		scanf("%s", names);
		if (names[0] == '0') break;
		Adddata(&list, names);
	}
	Freelist(&list);
	Viewall(&list);
}	
//���� �� �� rand�Լ��� ���� ��� �̱�, n�� �Է¹޾Ƽ� ��� ���ֱ�, ������� �ǽð����� ����ϱ�
//
