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

int check(Stack* s) {
	int count = 0,check = 0;
	char ch;
	char word[100];
	s->top = -1;
	int len = strlen(s->word);
	for (int i = 0; i < len; i++) {
		ch = s->word[i];
		if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']') { //괄호면 저장
			s->word[++s->top] = ch; //top +1하고 저장
		}
	}
	if (s->top % 2 == 0) return -1; //짝수면 틀림
	while (s->top!=-1) {
		ch = s->word[s->top--]; //ch에 저장
		check = 0;
		count = 1;
		if (ch == '(') {
			check = s->top+2;
			while (s->word[check] != " ") {
				check++;
				count++;
			}
			if (s->word[s->top + count] == ch + 1) {
				printf("() 맞음");
			}
			else return - 1;
		}
		else if (ch == '{' || ch == '[') {
			if (s->word[count] == ch + 2) printf("%c %c맞음", ch, ch + 2);
			else return - 1;
		}
	}
	return 0;
}

int main(void) {
	Stack s;
	scanf("%[^\n]s", s.word);
	int a = check(&s);
	if (a == -1) printf("올바르지 않습니다.");
	else printf("올바릅니다.");
}