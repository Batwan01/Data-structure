#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct ArrayStack {
    int top;
    char stack[MAX_SIZE];
} ArrayStack;

void init_stack(ArrayStack *AS) { 
    AS->top = -1;
}

int is_stack_full(ArrayStack *AS) {
    return AS->top == MAX_SIZE - 1;
}
int is_stack_empty(ArrayStack *AS) {
    return AS->top == -1;
}

void push(ArrayStack* AS, char data) {
    if (is_stack_full(AS)) {
        printf("더 이상 입력 할 수 없습니다.");
        exit(1);
    }
    else return AS->stack[++AS->top] =data;
}

char pop(ArrayStack* AS) { //-----------------------------수정 필요
    return AS->stack[AS->top--];
}

int matching(ArrayStack *AS, char temp[MAX_SIZE]) {
    
    int len, i;
    init_stack(AS);
    len = strlen(temp);
    for (i = 0; i < len; i++) {
        if (temp[i] != '(' && temp[i] != ')' && temp[i] != '{' && temp[i] != '}' && temp[i] != '[' && temp[i] != ']') {
            exit(1);
        }
        if (temp[i] == '(' || temp[i] == '{' || temp[i] == '[') {
            push(AS, temp[i]);
        }
        else if (temp[i] == ')' || temp[i] == '}' || temp[i] == ']') {
            if (is_stack_empty(AS)) {
                //printf("괄호의 짝이 맞지 않습니다."); 
                return -1;
            }
            else {
                switch (temp[i]) //----------------------------이런식으로 해본던가
                {
                    case ')':
                        if (temp[i] - 1 == pop(AS)) printf(")짝 맞음\n");
                        break;
                    case '}':
                        if (temp[i] - 2 == pop(AS)) printf("}짝 맞음\n");
                        break;
                    case ']':
                        if (temp[i] - 2 == pop(AS)) printf("]짝 맞음\n");
                        break;
                }
            }
        }
    }
    if (!is_stack_empty(AS)) {
        return -1;
    }
}

int main() {
    char temp[MAX_SIZE] = "";
    ArrayStack astack;
    printf("소괄호, 중괄호, 대괄호를 입력하세요 : ");
    scanf("%s", temp);
    if (matching(&astack, temp) == 0) {
        printf("괄호의 짝이 맞습니다.");
    }
    else {
        printf("괄호의 짝이 맞지 않습니다.");
    }


}