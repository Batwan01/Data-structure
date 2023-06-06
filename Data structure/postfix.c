#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Stack implementation
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

// Operator precedence
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/' || operator == '%')
        return 2;
    else if (operator == '^')
        return 3;
    return -1;
}

// Infix to postfix conversion
char* infixToPostfix(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i, j;
    char* postfix = (char*)malloc((strlen(expression) + 1) * sizeof(char));

    if (!stack || !postfix)
        return NULL;

    for (i = 0, j = -1; expression[i]; i++) {
        if ((expression[i] >= 'a' && expression[i] <= 'z') ||
            (expression[i] >= 'A' && expression[i] <= 'Z')) {
            postfix[++j] = expression[i];
        }
        else if (expression[i] == '(') {
            push(stack, expression[i]);
        }
        else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[++j] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
                return NULL; // Invalid expression
            else
                pop(stack); // Discard the matching '('
        }
        else {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) {
                postfix[++j] = pop(stack);
            }
            push(stack, expression[i]);
        }
    }

    while (!isEmpty(stack)) {
        if (peek(stack) == '(')
            return NULL; // Invalid expression
        postfix[++j] = pop(stack);
    }

    postfix[++j] = '\0';
    return postfix;
}

// Example usage
int main() {
    char infix_expression[] = "(a+b)*d+e/(f+a*d)+c";
    char* postfix_expression = infixToPostfix(infix_expression);

    if (postfix_expression == NULL) {
        printf("Invalid expression\n");
    }
    else {
        printf("Postfix expression: %s\n", postfix_expression);
        free(postfix_expression);
    }

    return 0;
}
