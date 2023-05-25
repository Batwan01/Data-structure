#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 3

typedef struct Person {
	char name[max][100];
	int front;
	int rear;
} Person;

void init(Person* p) { //ť �ʱ�ȭ
	p->front = p->rear = 0;
}

int full(Person* p) { //�ʰ��ƴ��� Ȯ��
	return (p->rear + 1) % max == p->front;
}

int add(Person* p, char* nick) { //������ �߰�
	if (full(p)) {
		return -1;
	}
	else {
		p->rear = (p->rear + 1) % max;
		strcpy(p->name[p->rear], nick);
		return 0;
	}
}

void delete(Person* M, Person* F) { //������ ���
	M->front = (M->front + 1) % max;
	F->front = (F->front + 1) % max;
	printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", M->name[M->front], F->name[F->front]);
}

int empty(Person* p) { //����ִ��� Ȯ��
	return p->front == p->rear;
}

void meeting(Person* M, Person* F) { //¦�� �´��� Ȯ��
	if (empty(M) == 0 && empty(F) == 0) delete(M, F);
	else printf("���� ����ڰ� �����ϴ�. ��ٷ� �ֽʽÿ�.\n\n");
}

int main(void) {
	Person M,F;
	char nick[100];
	char gen=' ';
	init(&M);
	init(&F);
	int a;
	printf("���� �ּ� ���α׷��Դϴ�.(�����Ϸ��� 0�� �Է����ּ���.)\n");
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