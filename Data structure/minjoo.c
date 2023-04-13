#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
    DataType data;
    struct Node* link;
} Node;

void insert_node(Node** p2head, Node* before, Node* new) {
    if (*p2head == NULL) {
        new->link = NULL;
        *p2head = new;
    }
    else if (before == NULL) {
        new->link = *p2head;
        *p2head = new;
    }
    else {
        new->link = before->link;
        before->link = new;
    }
}

int main() {

    Node* head, * before, * new;

    head = (Node*)malloc(sizeof(Node));
    if (!head) exit(1);
    head->data = 10;
    head->link = NULL;

    before = (Node*)malloc(sizeof(Node));
    if (!before) exit(1);
    before->data = 20;
    before->link = NULL;

    new = (Node*)malloc(sizeof(Node));
    if (!new) exit(1);
    new->data = 15;
    new->link = NULL;

    insert_node(&head, before, new);

    printf("%d %d %d", head->data, head->link->data, head->link->link->data);

    free(head);
    free(before);
    free(new);
}