#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Stack {
	int top;
	char word[100];
} Stack;

int check(Stack* s) {
	char ch;
	s->top = -1;
	int len = strlen(s->word);
	for (int i = 0; i < len; i++) {
		ch = s->word[i];
		if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']') {
			s->word[++s->top] = ch;
		}
		else continue;
	}
	for (int i = 0; i < len; i++) {
		printf("%c", s->word[i]);
		/*if (s->word[i] == s->word[s->top--]) continue;
		else return -1;
		if (i > s->top) break;*/
	}
	return 0;
}

int main(void) {
	Stack s;
	scanf("%[^\n]s", s.word);
	int a = check(&s);
	printf("%d", a);
}