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
		if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']') { //��ȣ�� ����
			s->word[++s->top] = ch; //top +1�ϰ� ����
		}
	}
	if (s->top % 2 == 0) return -1; //¦���� Ʋ��
	while (s->top!=-1) {
		ch = s->word[s->top--]; //ch�� ����
		check = 0;
		count = 1;
		if (ch == '(') {
			check = s->top+2;
			while (s->word[check] != " ") {
				check++;
				count++;
			}
			if (s->word[s->top + count] == ch + 1) {
				printf("() ����");
			}
			else return - 1;
		}
		else if (ch == '{' || ch == '[') {
			if (s->word[count] == ch + 2) printf("%c %c����", ch, ch + 2);
			else return - 1;
		}
	}
	return 0;
}

int main(void) {
	Stack s;
	scanf("%[^\n]s", s.word);
	int a = check(&s);
	if (a == -1) printf("�ùٸ��� �ʽ��ϴ�.");
	else printf("�ùٸ��ϴ�.");
}