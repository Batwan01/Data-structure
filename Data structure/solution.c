#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {   // 구조체 이중 연결리스트에 사용될 Node
    struct Node* next;
    struct Node* prev;
    char name[10];
}Node;

Node* creat_node() { // 노드 생성 함수
    Node* NEW = (Node*)malloc(sizeof(Node));
    NEW->next = NULL;
    NEW->prev = NULL;
    return NEW;
}

void make_circular_doubly_linked_list(Node* head, Node* tail) {   // 원형 이중 연결 리스트 생성
    head->next = tail;
    tail->next = head;
    head->prev = tail;
    tail->prev = head;
}

/*원형 연결 리스트에 노드 추가(마지막에 추가된 노드 제외)*/
Node* Add_Node(Node* Before, Node* tail, char* Student_name) {
    Node* NEW = (Node*)malloc(sizeof(Node));
    NEW->prev = Before;
    Before->next = NEW;
    strcpy(NEW->name, Student_name);
    return NEW;
}

/* head노드와 tail노드를 제외시킨 원형 이중 연결 리스트를 만들고
처음으로 입력된 이름이 저장된 노드를 가리키는 포인터 First 반환 */
Node* head_tail_Remove_ReturnFirst(Node* head, Node* tail) {
    head->next->prev = tail->prev;
    tail->prev->next = head->next;
    Node* First = head->next;
    return First;
}

/*난수를 이용해 뽑힐 사람 결정
먼저 입력된 사람부터 1, 2, 3 ... 순으로 증가 */
Node* Random_Choice_Student(Node* First, int Number_Of_Student) {
    srand((int)time(NULL)); // 난수 생성
    // 먼저 입력된 이름 부터 그 다음 이름 순으로 1, 2, 3, ... 별칭 지정한다고 가정
    int choice = 2;
    Node* target = First;
    for (int i = 1; i < choice; i++) {
        target = target->next;
    }
    printf("뽑힌 학생 : %s\n", target->name);
    return target;
}

/* 노드 삭제 함수 */
void Remove_Node(Node* target) {
    target->next->prev = target->prev;
    target->prev->next = target->next;
    free(target);
}
/* 시계 방향으로 N번째 사람 제거(숫자 셀 때 자신은 미 포함)
   남은 사람 출력*/
Node* Clockwise_Remove_Linked_List(Node* target, int N, int Number_Of_Student) {
    for (int i = 0; i < N; i++) {
        target = target->next;
    }
    printf("제거 될 사람 %s\n", target->name);
    Node* Next_target = target->next;
    Remove_Node(target);
    for (int i = 0; i < Number_Of_Student - 1; i++) {
        printf("%s- ", Next_target->name);
        Next_target = Next_target->next;
    }
    printf("\n");
    return Next_target;
}

/* 반시계 방향으로 N번째 사람 제거(숫자 셀 때 자신은 미 포함)
   남은 사람 출력*/
Node* CounterClockwise_Remove_Linked_List(Node* target, int N, int Number_Of_Student) {
    for (int i = 0; i < N; i++) {
        target = target->prev;
    }
    printf("제거 될 사람 %s\n", target->name);
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
    printf("참가할 학생 수 입력 : ");
    int Number_Of_Student = 0;                  // 학생 수
    int fit1 = scanf("%d", &Number_Of_Student);      // 입력이 올바르지 않으면 0이하의 값을 반환
    if (fit1 <= 0) {
        printf("올바른 값이 아닙니다.");
        return -1;                            // 입력이 올바르지 않으면 종료
    }
    Node* Before = head;
    for (int i = 0; i < Number_Of_Student; i++) {   // 학생 수 만큼 반복
        printf("이름을 입력하세요 : ");
        char Student_Name[10];
        scanf("%s", Student_Name);
        Before = Add_Node(Before, tail, Student_Name);
    }
    /*마지막에 생성된 노드도 연결해주기*/
    Before->next = tail;
    tail->prev = Before;
    /* head와 tail을 제외한 나머지 노드들로 연결리스트를 만들어주고
    head노드와 tail노드 메모리 반환*/
    Node* First = head_tail_Remove_ReturnFirst(head, tail);
    free(head);
    free(tail);
    int N;
    printf("숫자 하나(N) 입력: ");
    int fit2 = scanf("%d", &N);      // 입력이 올바르지 않으면 0이하의 값을 반환
    if (fit2 <= 0) {
        printf("올바른 값이 아닙니다.");
        return -1; // 입력이 올바르지 않으면 종료
    }
    /* 난수로 선정된 숫자를 기준으로 이름을 뽑힌 사람을 정함 */
    Node* target = Random_Choice_Student(First, Number_Of_Student);
    while (Number_Of_Student != 1) { // 한 사람만 남으면 종료
        target = Clockwise_Remove_Linked_List(target, N, Number_Of_Student); // 시계방향으로 N번째 제거
        Number_Of_Student--;
        if (Number_Of_Student == 1) // 한 사람만 남으면 종료
            break;
        target = CounterClockwise_Remove_Linked_List(target, N, Number_Of_Student); // 반시계방향으로 N번째 제거
        Number_Of_Student--;
    }
    printf("마지막으로 남은 사람 %s", target->name);
    free(target);
    return 0;
}