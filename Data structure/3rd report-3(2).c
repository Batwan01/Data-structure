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

void init(linkperson* p) { //큐 초기화
	p->front = p->rear = NULL;
}

int full(Person* p) { //초과됐는지 확인
	return p == NULL;
}

int empty(linkperson* p) { //비어있는지 확인
	return p->front == NULL;
}

int add(linkperson* p, char* nick) { //데이터 추가
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

void delete(linkperson* M, linkperson* F) { //데이터 출력
	
}

void meeting(linkperson* M, linkperson* F) { //짝이 맞는지 확인
	if (empty(M) == 0 && empty(F) == 0) delete(M, F);
	else printf("아직 대상자가 없습니다. 기다려 주십시오.\n\n");
}

int main(void) {
	linkperson M, F;
	char nick[100];
	char gen = ' ';
	init(&M); //초기화A
	init(&F);
	int a;
	printf("미팅 주선 프로그램입니다.(종료하려면 0을 입력해주세요.)\n\n");
	while (1) {
		printf("고객이름 : "); //이름 입력
		scanf("%s", nick);
		if (nick[0] == '0') return 0; //이름이 0이면 종료

		printf("성별을 입력하세요(f or m) "); //성별 입력
		scanf(" %c", &gen);
		if (gen == 'm') { //m일 때 남자 데이터 추가
			a = add(&M, nick);
			if (a == 0) meeting(&M, &F);
			else printf("인원이 초과되었습니다.\n\n");
		}
		else if (gen == 'f') { //f일 때 여자 데이터 추가
			a = add(&F, nick);
			if (a == 0) meeting(&M, &F);
			else printf("인원이 초과되었습니다.\n\n");
		}
		else printf("올바른 성별을 입력해 주세요.\n\n");
	}
	return 0;
}