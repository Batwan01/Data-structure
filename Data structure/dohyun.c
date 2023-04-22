#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//���߿��Ḯ��Ʈ ����ü
typedef struct NODE {
    char data[20];
    struct NODE* rlink;
    struct NODE* llink;
}NODE;
//��� �߰��ϴ� �Լ�
NODE* add_newNode(NODE* head) {
    char data[20];
    printf("�߰��� ����� �����͸� �Է��ϼ���: (�׸��Է��Ͻ÷��� 0�� �Է��Ͻʽÿ�.)");
    while (1) {
        scanf("%s", data);
        if (strcmp(data, "0") == 0) {
            break;
        }
        NODE* newNode = (NODE*)malloc(sizeof(NODE));
        newNode->rlink = head->rlink;
        newNode->llink = head;
        head->rlink->llink = newNode;
        head->rlink = newNode;
        printf("�л��� �̸� : %s \n", strcpy(newNode->data, data));
    }
    return head;
}

//��� �����ϴ� �Լ�
NODE* delete_node(NODE* head) {
    NODE* temp = head->rlink;
    temp->llink->rlink = temp->rlink;
    temp->rlink->llink = temp->rlink;
    free(temp);;
}
//��带 �Է¹��� ����ŭ ���������� ã�� �����ϴ� �Լ�
NODE* right_delete(NODE** head, int n) {
    NODE* temp = (*head)->rlink;
    for (int i = 0; i < n; i++) {
        temp = temp->rlink;
    }
    NODE* right_node = temp;
    delete_node(temp);
    //������ ��� ���������� �̵�
    right_node = right_node->rlink;
    //������ ��� ���
    printf("������ ���: %s\n", temp->data);
    return temp;
}
//��带 �Է¹��� ����ŭ �������� ã�� �����ϴ� �Լ�
NODE* left_delete(NODE** head, int n) {
    NODE* temp = (*head)->llink;
    for (int i = 0; i < n; i++) {
        temp = temp->llink;
    }
    NODE* left_node = temp;
    delete_node(temp);
    //������ ��� �������� �̵�
    left_node = left_node->llink;
    //������ ��� ���
    printf("������ ���: %s\n", temp->data);
    return temp;
}
//�������� ��� �̱�0
NODE* random_student(NODE* head, int count) {
    NODE* temp = head->rlink;

    srand(time(NULL));
    int random = rand() % count;
    for (int i = 0; i < random - 1; i++) {
        temp = temp->rlink;
    }
    printf("�������� ���� ��� : %s\n", temp->data);
    return temp;
}
//��� ���� ���� �Լ�
int count_node(NODE* head) {
    NODE* temp = head->rlink;
    int count = 0;
    while (temp != head) {
        count++;
        temp = temp->rlink;
    }
    return count;
}

int main() {
    int n = 0; int i = 0;
    NODE* head = (NODE*)malloc(sizeof(NODE)); //����� �����Ҵ�
    head->rlink = head;
    head->llink = head;
    NODE* rlink = NULL;
    NODE* llink = NULL;
    char data[20] = "";
    add_newNode(head, data);
    printf("n�� �Է��Ͻʽÿ� : ");
    scanf("%d", &n);
    int count = count_node(head);
    random_student(head, count);
    right_delete(&head, n);
    left_delete(&head, n);
    return 0;

}