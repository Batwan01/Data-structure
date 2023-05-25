#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// ( : 40, ) : 41
//[ : 91, ] : 93
//{ : 123, } : 125
typedef struct Stack {
	int top;
	char word[100];
} Stack;

void init(Stack* s) {
	s->top = -1;
}

void push(Stack* s, char data) {
	if (s->top == 100) { //포화상태 확인
		printf("포화상태입니다.");
		exit(1);
	}
	else s->word[++s->top] = data; //top을 +1하고 data저장
}

char pop(Stack* s) {
	if (s->top == -1) { //공백인지 확인(만약 공백이면 비교값이 없는 것이기 때문에 오류)
		printf("올바르지 않습니다.");
		exit(1);
	}
	else return s->word[s->top--]; //값을 반환하고 top -1
}

int check(Stack* s) {
	int answer = 0;
	char ch;
	int len = strlen(s->word); //길이 저장
	for (int i = 0; i <=len; i++) {
		ch = s->word[i]; //비교 문자열 저장

		switch (ch) //괄호가 아니면 저장X
		{
			case '(': //열린 괄호면 push
				push(s, ch);
				break;
			case '{':
				push(s, ch);
				break;
			case '[':
				push(s, ch);
				break;
			case ')': //닫힌 괄호면 pop
				if (ch - 1 == pop(s)) { answer++; continue; } //횟수 적립(만약 0이면 작동을 하지 않았다는 의미)
				else return -1;
			case '}':
				if (ch - 2 == pop(s)) { answer++; continue; }
				else return -1;
			case ']':
				if (ch - 2 == pop(s)) { answer++; continue; }
				else return -1;
		}
	}
	if (s->top != -1) return -1; //스택이 남아있으면 오류
	if (answer > 0) return 0; //case가 작동했으면 정답
	else return -1;//0이면 오류
}

int main(void) {
	Stack s;
	init(&s); //top 초기화
	printf("괄호를 입력하세요. : ");
	scanf("%[^\n]s", s.word); //공백도 포함하여 입력받음
	int a = check(&s);
	if (a == -1) printf("올바르지 않습니다.");
	else printf("올바릅니다.");
}