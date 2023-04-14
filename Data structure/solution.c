#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {   // ����ü ���� ���Ḯ��Ʈ�� ���� Node
    struct Node* next;
    struct Node* prev;
    char name[10];
}Node;

Node* creat_node() { // ��� ���� �Լ�
    Node* NEW = (Node*)malloc(sizeof(Node));
    NEW->next = NULL;
    NEW->prev = NULL;
    return NEW;
}

void make_circular_doubly_linked_list(Node* head, Node* tail) {   // ���� ���� ���� ����Ʈ ����
    head->next = tail;
    tail->next = head;
    head->prev = tail;
    tail->prev = head;
}

/*���� ���� ����Ʈ�� ��� �߰�(�������� �߰��� ��� ����)*/
Node* Add_Node(Node* Before, Node* tail, char* Student_name) {
    Node* NEW = (Node*)malloc(sizeof(Node));
    NEW->prev = Before;
    Before->next = NEW;
    strcpy(NEW->name, Student_name);
    return NEW;
}

/* head���� tail��带 ���ܽ�Ų ���� ���� ���� ����Ʈ�� �����
ó������ �Էµ� �̸��� ����� ��带 ����Ű�� ������ First ��ȯ */
Node* head_tail_Remove_ReturnFirst(Node* head, Node* tail) {
    head->next->prev = tail->prev;
    tail->prev->next = head->next;
    Node* First = head->next;
    return First;
}

/*������ �̿��� ���� ��� ����
���� �Էµ� ������� 1, 2, 3 ... ������ ���� */
Node* Random_Choice_Student(Node* First, int Number_Of_Student) {
    srand((int)time(NULL)); // ���� ����
    // ���� �Էµ� �̸� ���� �� ���� �̸� ������ 1, 2, 3, ... ��Ī �����Ѵٰ� ����
    int choice = 2;
    Node* target = First;
    for (int i = 1; i < choice; i++) {
        target = target->next;
    }
    printf("���� �л� : %s\n", target->name);
    return target;
}

/* ��� ���� �Լ� */
void Remove_Node(Node* target) {
    target->next->prev = target->prev;
    target->prev->next = target->next;
    free(target);
}
/* �ð� �������� N��° ��� ����(���� �� �� �ڽ��� �� ����)
   ���� ��� ���*/
Node* Clockwise_Remove_Linked_List(Node* target, int N, int Number_Of_Student) {
    for (int i = 0; i < N; i++) {
        target = target->next;
    }
    printf("���� �� ��� %s\n", target->name);
    Node* Next_target = target->next;
    Remove_Node(target);
    for (int i = 0; i < Number_Of_Student - 1; i++) {
        printf("%s- ", Next_target->name);
        Next_target = Next_target->next;
    }
    printf("\n");
    return Next_target;
}

/* �ݽð� �������� N��° ��� ����(���� �� �� �ڽ��� �� ����)
   ���� ��� ���*/
Node* CounterClockwise_Remove_Linked_List(Node* target, int N, int Number_Of_Student) {
    for (int i = 0; i < N; i++) {
        target = target->prev;
    }
    printf("���� �� ��� %s\n", target->name);
    Node* Next_target = target->prev;
    Remove_Node(target);
    for (int i = 0; i < Number_Of_Student - 1; i++) {
        printf("%s- ", Next_target->name);
        Next_target = Next_target->next;
    }
    printf("\n");
    return Next_target;
}
int main(void) {
    Node* head = creat_node();
    Node* tail = creat_node();
    make_circular_doubly_linked_list(head, tail);
    printf("������ �л� �� �Է� : ");
    int Number_Of_Student = 0;                  // �л� ��
    int fit1 = scanf("%d", &Number_Of_Student);      // �Է��� �ùٸ��� ������ 0������ ���� ��ȯ
    if (fit1 <= 0) {
        printf("�ùٸ� ���� �ƴմϴ�.");
        return -1;                            // �Է��� �ùٸ��� ������ ����
    }
    Node* Before = head;
    for (int i = 0; i < Number_Of_Student; i++) {   // �л� �� ��ŭ �ݺ�
        printf("�̸��� �Է��ϼ��� : ");
        char Student_Name[10];
        scanf("%s", Student_Name);
        Before = Add_Node(Before, tail, Student_Name);
    }
    /*�������� ������ ��嵵 �������ֱ�*/
    Before->next = tail;
    tail->prev = Before;
    /* head�� tail�� ������ ������ ����� ���Ḯ��Ʈ�� ������ְ�
    head���� tail��� �޸� ��ȯ*/
    Node* First = head_tail_Remove_ReturnFirst(head, tail);
    free(head);
    free(tail);
    int N;
    printf("���� �ϳ�(N) �Է�: ");
    int fit2 = scanf("%d", &N);      // �Է��� �ùٸ��� ������ 0������ ���� ��ȯ
    if (fit2 <= 0) {
        printf("�ùٸ� ���� �ƴմϴ�.");
        return -1; // �Է��� �ùٸ��� ������ ����
    }
    /* ������ ������ ���ڸ� �������� �̸��� ���� ����� ���� */
    Node* target = Random_Choice_Student(First, Number_Of_Student);
    while (Number_Of_Student != 1) { // �� ����� ������ ����
        target = Clockwise_Remove_Linked_List(target, N, Number_Of_Student); // �ð�������� N��° ����
        Number_Of_Student--;
        if (Number_Of_Student == 1) // �� ����� ������ ����
            break;
        target = CounterClockwise_Remove_Linked_List(target, N, Number_Of_Student); // �ݽð�������� N��° ����
        Number_Of_Student--;
    }
    printf("���������� ���� ��� %s", target->name);
    free(target);
    return 0;
}