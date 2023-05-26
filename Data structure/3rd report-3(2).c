#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
	char name[100];
	int *link;
} Person;

typedef struct linkperson {
	Person* front;
	Person* rear;
} linkperson;

void init(linkperson* p) { //ť �ʱ�ȭ
	p->front = p->rear = NULL;
}

int full(Person* p) { //�ʰ��ƴ��� Ȯ��
	return p == NULL;
}

int empty(linkperson* p) { //����ִ��� Ȯ��
	return p->front == NULL;
}

int add(linkperson* p, char* nick) { //������ �߰�
	Person* new = (Person*)malloc(sizeof(Person));
	if (full(new)) {
		return -1;
	}
	else {
		strcpy(new->name, nick);
		new->link = NULL;
		if (empty(p)) p->front = new;
		else p->rear->link = new;
		p->rear = new;
		return 0;
	}
}

void delete(linkperson* M, linkperson* F) { //������ ���
	
}

void meeting(linkperson* M, linkperson* F) { //¦�� �´��� Ȯ��
	if (empty(M) == 0 && empty(F) == 0) delete(M, F);
	else printf("���� ����ڰ� �����ϴ�. ��ٷ� �ֽʽÿ�.\n\n");
}

int main(void) {
	linkperson M, F;
	char nick[100];
	char gen = ' ';
	init(&M); //�ʱ�ȭA
	init(&F);
	int a;
	printf("���� �ּ� ���α׷��Դϴ�.(�����Ϸ��� 0�� �Է����ּ���.)\n\n");
	while (1) {
		printf("���̸� : "); //�̸� �Է�
		scanf("%s", nick);
		if (nick[0] == '0') return 0; //�̸��� 0�̸� ����

		printf("������ �Է��ϼ���(f or m) "); //���� �Է�
		scanf(" %c", &gen);
		if (gen == 'm') { //m�� �� ���� ������ �߰�
			a = add(&M, nick);
			if (a == 0) meeting(&M, &F);
			else printf("�ο��� �ʰ��Ǿ����ϴ�.\n\n");
		}
		else if (gen == 'f') { //f�� �� ���� ������ �߰�
			a = add(&F, nick);
			if (a == 0) meeting(&M, &F);
			else printf("�ο��� �ʰ��Ǿ����ϴ�.\n\n");
		}
		else printf("�ùٸ� ������ �Է��� �ּ���.\n\n");
	}
	return 0;
}