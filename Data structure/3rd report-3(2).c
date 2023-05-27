#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
	char name[100];
	int *link;
} Person;

typedef struct linkperson { //front, rear������
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
		if (empty(p)) p->front = new; //��������� front����
		else p->rear->link = new; //rear����
		p->rear = new;
		return 0;
	}
}

void delete(linkperson* M, linkperson* F) { //������ ���
	Person* del_M = M->front; //���� ���
	Person* del_F = F->front; 
	printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", del_M, del_F);
	M->front = del_M->link; //front ����
	F->front = del_F->link;
	if (empty(M)) M->rear = NULL; //��������� rear=NULL
	if (empty(F)) F->rear = NULL;
	free(del_M);
	free(del_F);
}

void meeting(linkperson* M, linkperson* F) { //¦�� �´��� Ȯ��
	if (empty(M) == 0 && empty(F) == 0) delete(M, F); //�� �� ������� ������ ����
	else printf("���� ����ڰ� �����ϴ�. ��ٷ� �ֽʽÿ�.\n\n");
}

int main(void) {
	linkperson M, F;
	char nick[100];
	char gen = ' ';
	init(&M); //�ʱ�ȭ
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
			a = add(&M, nick); //������ �߰�
			if (a == 0) meeting(&M, &F); //¦ Ȯ��
			else printf("�ο��� �ʰ��Ǿ����ϴ�.\n\n"); //ť�� �ʰ��Ǿ��� ��
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