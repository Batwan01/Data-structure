#include <stdio.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일
#include <string.h>
#include <time.h>

typedef struct Node { //노드 생성
	char *name;
	struct Node* next; //다음값
	struct Node* prev; //이전값
} Node;

typedef struct List { //head와 tail 정의
	Node* head; //첫 번째 값 가르킴
	Node* tail; //마지막 값 가르킴
	Node* first; //head, tail free되면 첫번째 위치가르킴
	int count;
}List;

Node* Newnode(char *names) //노드 생성
{
	Node* new = (Node*)malloc(sizeof(Node)); //구조체 1개 공간 할당
	new->name = (char*)malloc(strlen(names) + 1); //이름수 만큼 공간 할당
	strcpy(new->name, names); //new->name에 이름 저장
	new->next = new->prev = NULL; //new 링크 초기화
	return new;	
}

void Setnode(List* list) { //노드 초기설정
	list->head = Newnode(" ");
	list->tail = Newnode(" ");
	list->head->next = list->tail; //head의 다음은 tail
	list->head->prev = list->tail; //head의 뒤는 tail
	list->tail->next = list->head; //tail의 다음은 head
	list->tail->prev = list->head; //tail의 뒤는 head
	list->count = 0; //노드수 0
}

void Adddata(List* list, char* names) {
	Node *add = Newnode(names);
	if (list->count == 0) { //첫번째 Add
		add->next = list->head->next; //add의 다음은 head의 next
		add->prev = list->head; //add의 prev은 head
		list->head->next = add; //head의 next는 add
		list->tail->prev = add; //tail의 prev은 add
		list->first = add; //첫 번째값 정함(Freelist 사용을 위함)
	}
	else { //2번 이상 Add
		add->next = list->head->next; //add의 next는 head의 next
		list->head->next->prev = add; //head가 가르키던 값의 prev을 add를 가르키게함
		add->prev = list->head; //add의 prev은 head
		list->head->next = add; //head의 next는 add
		list->first = add; //첫 번째값 정함(Freelist 사용을 위함)
	}
	list->count++; //노드수 저장
}
void Freelist(List* list) { //head와 tail값 free하기
	Node* heads = list->head; //head설정
	Node* tails = list->tail; //tial설정
	list->head->next->prev = list->tail->prev; //head다음 첫 번째 값의 prev는 tail의 prev값
	list->tail->prev->next = list->head->next;//tail뒤의 값의 next값은 tail의 next값
	free(heads);
	free(tails);
}

void Randperson(List* list) {
	Node* person = list->first;
	int n = rand() % list->count+1; //랜덤함수의 값을 사람수(count)로 범위를 정함
	for (int i = 0; i < n; i++)
	{
		person = person->next; //뽑힌 사람 선발
	}
	list->first = person; //뽑힌 사람을 첫 번째로 설정
	printf("뽑힌 사람 : %s\n", person->name);
}

void Viewall(List* list) {
	Node* check = list->first; //첫 번째 사람
	int i = 0;
	printf("학생들 이름 : ");
	while (i!=list->count) //학생수만큼 돌면 정지
	{
		printf("%s ",check->name); //이름 출력
		check = check->next; //다음 사람
		i++;
	}
	printf("\n");
}

void Remove(List* list) { //n번째 사람 제거
	Node* person = list->first; //첫번째 값
	Node* explain = person; //남은 사람 출력용
	Node* frees = person; //free 용도
	int n, j, i=0, t=0;
	printf("n을 입력하세요.(n번째 사람 제거) : ");
	scanf("%d", &n);
	while (list->count != 1) { //정렬 필요함
		if (i == 0) { //시계방향
			for (j = 0; j < n; j++)
			{
				person = person->next; //제거할 값 n번만큼 앞으로
			}
			if (person == list->first) //first값이 제거 될 때
			{
				list->first = person->next; //first값 next값 설정
				list->first->prev = person->prev; //first의 prev값 설정
				explain = list->first; //출력용도 first값 적용
			}
			list->count--; //사람 수 제거
			printf("제거 될 사람 : %s\n", person->name);
			person->next->prev = person->prev; //제거대상의 앞 뒤 연결
			person->prev->next = person->next;
			frees = person; //제거 대상을 frees에 저장
			person = person->next; //제거대상의 다음사람이 기준
			free(frees); //제거 대상을 free
			i = -1;
		}
		else { //반시계방향
			for (j = 0; j < n; j++)
			{
				person = person->prev; //반시계 방향으로 n번 뒤로
			}
			if (person == list->first) //first값이 제거될 때
			{
				list->first = person->next; //first의 next설정
				list->first->prev = person->prev; //first의 prev값 설정
				explain = list->first; //출력용도 설정
			}
			list->count--; //사람 수 감소
			printf("제거 될 사람 : %s\n", person->name);
			person->next->prev = person->prev; //제거대상의 앞 뒤 연결
			person->prev->next = person->next;
			frees = person; //제거 대상을 frees에 저장
			person = person->prev; //제거대상의 다음사람이 기준
			free(frees); //제거 대상을 free
			i = 0;
		}
		printf("남은 사람 : ");
		while (t != list->count) { //남은 사람 이름 출력
			printf("%s ", explain->name);
			explain = explain->next;
			t++;
		}
		t = 0;
		printf("\n");
	}
	printf("최종 남은 학생 : %s", person->name);
	free(person);
}

void main() {
	char names[10];
	List list;
	int n;
	srand((int)time(NULL)); //랜덤함수 초기화
	Setnode(&list); //초기 설정
	printf("학생의 이름을 입력하세요.(종료를 원하면 0을 입력하세요.)\n");
	while (1) {
 		scanf("%s", names);
		if (names[0] == '0') break; //0 입력하면 종료
		Adddata(&list, names); //노드 생성 및 이름 입력
	}
	Freelist(&list); //head, tail값 free
	Randperson(&list); //무작위 사람 뽑기
	Viewall(&list); //모든 값 보기
	Remove(&list); //사람 제거
}	