#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int socre[3];
	struct Node *next;
}Node;

typedef struct Link {
	Node* head;
	int length;
}Link;

void start(Link *sum) {
	sum->head = NULL;
	sum->length = 0;
}

Node* newnode(int score1, int score2, int score3) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->socre[0] = score1;
	new->socre[1] = score2;
	new->socre[2] = score3;
	//("%d %d %d\n", new->socre[0], new->socre[1], new->socre[2]);
	return new;
}

void add(Link *sum, Node *new) {
	if (sum->head == NULL) {
		sum->head = new;
		sum->length++;
		//printf("sum->head 작동해떠염\n");
	}
	else {
		new->next = sum->head->next;
		sum->head->next = new;
		sum->length++;
		//printf("sum->head else 작동해떠염\n");
	}
}

void viewall(Link* sum) {
	Node* all = sum->head;
	//printf("vieall에 들어와떠염");
	while (all) {
		printf("성적 : %d %d %d\n", all->socre[0], all->socre[1], all->socre[2]);
		all = all->next;
	}
}

int main() {
	Link *sum;
	int i = 0, score1, score2, score3;
	start(&sum);
	printf("학생의 성적입력\n");
	while (i != 5) {
		scanf("%d %d %d", &score1, &score2, &score3);
		add(&sum,newnode(score1, score2, score3));
		i++;
	}
	viewall(&sum);
}