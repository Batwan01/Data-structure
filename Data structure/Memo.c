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
	Node* head;
	Node* tail;
	Node* first;
	int count;
}List;

Node* Newnode(char* names) //��� ����
{
	Node* new = (Node*)malloc(sizeof(Node)); //����ü 1�� ���� �Ҵ�
	new->name = (char*)malloc(strlen(names) + 1); //�̸��� ��ŭ ���� �Ҵ�
	strcpy(new->name, names); //new->name�� �̸� ����
	new->next = new->prev = NULL; //new ��ũ �ʱ�ȭ
	return new;
}

void Setnode(List* list) { //��� �ʱ⼳��
	list->head = Newnode(" ");
	list->tail = Newnode(" ");
	list->head->next = list->tail; //head�� ������ tail
	list->head->prev = list->tail; //head�� �ڴ� tail
	list->tail->next = list->head; //tail�� ������ head
	list->tail->prev = list->head; //tail�� �ڴ� head
	list->count = 0; //���� 0
}

void Adddata(List* list, char* names) {
	Node* add = Newnode(names);
	if (list->count == 0) { //ù��° Add
		add->next = list->head->next; //add�� ������ head�� next
		add->prev = list->head; //add�� prev�� head
		list->head->next = add; //head�� next�� add
		list->tail->prev = add; //tail�� prev�� add
	}
	else { //2�� �̻� Add
		add->next = list->head->next; //add�� next�� head�� next
		list->head->next->prev = add; //head�� ����Ű�� ���� prev�� add�� ����Ű����
		add->prev = list->head; //add�� prev�� head
		list->head->next = add; //head�� next�� add
		list->first = add; //ù ��°�� ����(Freelist ����� ����)
	}
	list->count++; //���� ����
}
void Freelist(List* list) { //head�� tail�� free�ϱ�
	Node* heads = list->head;
	Node* tails = list->tail;
	list->head->next->prev = list->tail->prev; //head���� ù ��° ���� prev�� tail�� prev��
	list->tail->prev->next = list->head->next;//tail���� ���� next���� tail�� next��
	free(heads);
	free(tails);
}

void Randperson(List* list) {
	Node* person = list->first;
	int n = 2;
	for (int i = 0; i < n; i++)
	{
		person = person->next; //���� ��� ����
	}
	list->first = person; //���� ����� ù ��°�� ����
	printf("���� ��� : %s\n", person->name);
}

void Viewall(List* list) {
	Node* check = list->first; //ù ��° ���
	int i = 0;
	printf("�л��� �̸� : ");
	while (i != list->count)
	{
		printf("%s ", check->name); //�̸� ���
		check = check->next; //���� ���
		i++;
	}
	printf("\n");
}

void Remove(List* list) { //n��° ��� ����
	Node* person = list->first;
	Node* explain = person;
	int n, j, i = 0, t = 0;
	printf("n�� �Է��ϼ���.(n��° ��� ����) : ");
	scanf("%d", &n);
	while (list->count != 1) { //���� �ʿ���
		explain = list->first;
		if (i == 0) { //�ð����
			for (j = 0; j < n; j++)
			{
				person = person->next;
			}
			if (person == list->first)
			{
				list->first = person->next;
				list->first->prev = person->prev;
			}
			list->count--;
			printf("���� �� ��� : %s\n", person->name);
			person->next->prev = person->prev;
			person->prev->next = person->next;
			person = person->next;
			i = -1;
		}
		else { //�ݽð����
			for (j = 0; j < n; j++)
			{
				person = person->prev;
			}
			if (person == list->first)
			{
				list->first = person->next;
				list->first->prev = person->prev;
			}
			list->count--;
			printf("���� �� ��� : %s\n", person->name);
			person->next->prev = person->prev;
			person->prev->next = person->next;
			person = person->prev;
			i = 0;
		}

		printf("���� ��� : ");
		while (t != list->count) {
			printf("%s ", explain->name);
			explain = explain->next;
			t++;
		}
		t = 0;
		printf("\n");
	}
	printf("���� ���� �л� : %s", person->name);
}

void main() {
	char names[10];
	List list;
	int n;
	srand((int)time(NULL)); //�����Լ� �ʱ�ȭ
	Setnode(&list); //�ʱ� ����
	printf("�л��� �̸��� �Է��ϼ���.(���Ḧ ���ϸ� 0�� �Է��ϼ���.)\n");
	while (1) {
		scanf("%s", names);
		if (names[0] == '0') break; //0 �Է��ϸ� ����
		Adddata(&list, names); //��� ���� �� �̸� �Է�
	}
	Freelist(&list); //head, tail�� free
	Randperson(&list); //������ ��� �̱�
	Viewall(&list); //��� �� ����
	Remove(&list); //��� ����
}