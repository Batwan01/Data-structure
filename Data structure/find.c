//이중 연결리스트 - 더미 노드 사용, 순차 보관(가장 최근에 보관한 데이터가 맨 뒤)
//연결리스트 정의, 노드 정의, 초기화, 추가, 삭제, 검색, 전체 출력, 해제
#include <stdio.h>
#include <stdlib.h>

typedef struct Node//노드 정의
{
    int data;//데이터
    struct Node* next;//링크(다음 노드의 위치 정보)
    struct Node* prev;//링크(이전 노드의 위치 정보)
}Node;

Node* NewNode(int data)
{
    Node* now = (Node*)malloc(sizeof(Node));
    now->data = data;
    now->prev = now->next = NULL;
    return now;
}

typedef struct List//연결리스트 정의
{
    Node* head;
    Node* tail;
    int count;
}List;
void InitList(List* list);//초기화
void AddData(List* list, int data);//데이터 추가
void Remove(List* list, Node* now);//노드 삭제
Node* Find(List* list, int data);//노드 검색(리스트에서 맨 처음 발견한 노드 반환)
Node* Find2(List* list, Node* seek, int data);//노드 검색(pos 다음 노드에서부터 처음 발견한 노드 반환)
void ViewAll(List* list);//전체 출력
void Clear(List* list);//해제

int main(void)
{
    List list;
    {//초기화 및 추가 테스트를 위한 블록
        InitList(&list);
        AddData(&list, 3); //3
        AddData(&list, 4); //3 4
        AddData(&list, 6); //3 4 6
        AddData(&list, 9); //3 4 6 9
        ViewAll(&list);// 3 4 6 9 출력
    }

    {//검색과 삭제 테스트를 위한 블록
        Node* seek = Find(&list, 4);
        if (seek)
        {
            printf("4를 보관한 노드를 찾았음\n");
            Remove(&list, seek); //3 6 9
            printf("4를 보관한 노드 제거 후\n");
            ViewAll(&list);// 3 6 9 출력
        }
    }
    Clear(&list);//전체 해제
    printf("전체 해제 후\n");
    ViewAll(&list);// 아무것도 출력하지 않음

    return 0;
}

void InitList(List* list)
{
    list->head = NewNode(0);//연결 리스트의 맨 앞에 더미 노드 생성
    list->tail = NewNode(0);//연결 리스트의 맨 뒤에 더미 노드 생성
    list->head->next = list->tail;//head의 다음은 tail로 설정
    list->tail->prev = list->head;//tail의 다음은 head로 설정
    list->count = 0;//보관한 데이터 개수를 0으로 설정    
}
void AddData(List* list, int data)
{
    //새로 생성한 노드를 tail앞에 매답니다.
    Node* now = NewNode(data);//새로운 노드 생성
    now->prev = list->tail->prev;//now의 prev를 tail 앞 노드로 설정
    now->next = list->tail;//now의 next를 tail로 설정

    list->tail->prev->next = now;//tail의 이전 노드의 next를 now로 설정
    list->tail->prev = now;//tail의 prev를 now로 설정
    list->count++;//보관한 데이터 개수를 1 증가
}

void Remove(List* list, Node* now)
{
    now->prev->next = now->next;//이전 노드의 next를 now의 다음 노드로 설정
    now->next->prev = now->prev;//다음 노드의 prev를 now의 이전 노드로 설정
    free(now);//노드 소멸
    list->count--;//보관한 노드 개수를 1 감소
}

Node* Find(List* list, int data)
{
    //head와 tail은 더미 노드입니다.
    Node* seek = list->head->next;//head의 next부터 검색합니다.
    while (seek != list->tail) //seek가 tail이 아니면
    {
        if (seek->data == data)//찾았을 때
        {
            return seek;
        }
        seek = seek->next;//seek를 다음으로 이동
    }
    return NULL;//못 찾았을 때
}

Node* Find2(List* list, Node* seek, int data)
{
    seek = seek->next;//seek 다음 노드부터 검색합니다.
    while (seek != list->tail) //seek가 tail이 아니면
    {
        if (seek->data == data)//찾았을 때
        {
            return seek;
        }
        seek = seek->next;//seek를 다음으로 이동
    }
    return NULL;//못 찾았을 때
}
void ViewAll(List* list)
{
    //head와 tail은 더미 노드입니다.
    Node* seek = list->head->next;//head->next 부터 출력합니다.
    int i = 0;
    printf("보관한 데이터 개수: %d\n", list->count);

    while (seek != list->tail) //seek가 참이면(NULL 이 아니면)
    {
        i++;
        printf("[%2d]:%-05d ", i, seek->data);

        if (i % 5 == 0)//5의 배수일 때
        {
            printf("\n");//개행
        }
        seek = seek->next;//seek를 다음으로 이동
    }
    printf("\n");
}

void Clear(List* list)
{
    //head 다음 노드가 tail이 아닐 때까지 리스트에서 제거
    Node* seek = list->head->next;
    while (seek != list->tail) //seek가 참이면(NULL 이 아니면)
    {
        Remove(list, seek);
        seek = list->head->next;
    }
}