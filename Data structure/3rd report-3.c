#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 3

typedef struct Person {
	char name[max][100];
	int front;
	int rear;
} Person;

void init(Person* p) { //큐 초기화
	p->front = p->rear = 0;
}

int full(Person* p) { //초과됐는지 확인
	return (p->rear + 1) % max == p->front;
}

int add(Person* p, char* nick) { //데이터 추가
	if (full(p)) {
		return -1;
	}
	else {
		p->rear = (p->rear + 1) % max;
		strcpy(p->name[p->rear], nick);
		return 0;
	}
}

void delete(Person* M, Person* F) { //데이터 출력
	M->front = (M->front + 1) % max;
	F->front = (F->front + 1) % max;
	printf("커플이 탄생했습니다! %s과 %s\n\n", M->name[M->front], F->name[F->front]);
}

int empty(Person* p) { //비어있는지 확인
	return p->front == p->rear;
}

void meeting(Person* M, Person* F) { //짝이 맞는지 확인
	if (empty(M) == 0 && empty(F) == 0) delete(M, F);
	else printf("아직 대상자가 없습니다. 기다려 주십시오.\n\n");
}

int main(void) {
	Person M,F;
	char nick[100];
	char gen=' ';
	init(&M);
	init(&F);
	int a;
	printf("미팅 주선 프로그램입니다.(종료하려면 0을 입력해주세요.)\n");
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