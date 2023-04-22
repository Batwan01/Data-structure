#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//이중연결리스트 구조체
typedef struct NODE {
    char data[20];
    struct NODE* rlink;
    struct NODE* llink;
}NODE;
//노드 추가하는 함수
NODE* add_newNode(NODE* head) {
    char data[20];
    printf("추가할 노드의 데이터를 입력하세요: (그만입력하시려면 0을 입력하십시오.)");
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
        printf("학생의 이름 : %s \n", strcpy(newNode->data, data));
    }
    return head;
}

//노드 삭제하는 함수
NODE* delete_node(NODE* head) {
    NODE* temp = head->rlink;
    temp->llink->rlink = temp->rlink;
    temp->rlink->llink = temp->rlink;
    free(temp);;
}
//노드를 입력받은 수만큼 오른쪽으로 찾고 삭제하는 함수
NODE* right_delete(NODE** head, int n) {
    NODE* temp = (*head)->rlink;
    for (int i = 0; i < n; i++) {
        temp = temp->rlink;
    }
    NODE* right_node = temp;
    delete_node(temp);
    //삭제한 노드 오른쪽으로 이동
    right_node = right_node->rlink;
    //삭제된 노드 출력
    printf("삭제된 노드: %s\n", temp->data);
    return temp;
}
//노드를 입력받은 수만큼 왼쪽으로 찾고 삭제하는 함수
NODE* left_delete(NODE** head, int n) {
    NODE* temp = (*head)->llink;
    for (int i = 0; i < n; i++) {
        temp = temp->llink;
    }
    NODE* left_node = temp;
    delete_node(temp);
    //삭제한 노드 왼쪽으로 이동
    left_node = left_node->llink;
    //삭제된 노드 출력
    printf("삭제된 노드: %s\n", temp->data);
    return temp;
}
//랜덤으로 사람 뽑기0
NODE* random_student(NODE* head, int count) {
    NODE* temp = head->rlink;

    srand(time(NULL));
    int random = rand() % count;
    for (int i = 0; i < random - 1; i++) {
        temp = temp->rlink;
    }
    printf("랜덤으로 뽑힌 사람 : %s\n", temp->data);
    return temp;
}
//노드 갯수 세는 함수
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
    NODE* head = (NODE*)malloc(sizeof(NODE)); //헤드노드 동적할당
    head->rlink = head;
    head->llink = head;
    NODE* rlink = NULL;
    NODE* llink = NULL;
    char data[20] = "";
    add_newNode(head, data);
    printf("n을 입력하십시오 : ");
    scanf("%d", &n);
    int count = count_node(head);
    random_student(head, count);
    right_delete(&head, n);
    left_delete(&head, n);
    return 0;

}