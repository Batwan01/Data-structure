#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tnode {
    int try;
    char data[100];
    int line[100];
    struct Tnode* left;
    struct Tnode* right;
} Tnode;

typedef struct Linkroot {
    Tnode* root;
} Linkroot;

void init(Tnode** root) { //루트 초기화
    *root = NULL;
}

void add(Tnode** root, char* word, int lines) { //노드 추가
    Tnode* search = *root;
    Tnode* parent = NULL;
    while (search) {
        if (strcmp(word, search->data) == 0) { //같은 값일 때
            if (search->line[search->try - 1] == lines) search->try++; //이전값과 같으면 횟수만 누적
            else search->line[search->try++] = lines;
            return;
        }
        parent = search;
        if (0 > strcmp(word, search->data)) search = search->left; //빠르면 왼쪽
        else search = search->right;
    }

    Tnode* new = (Tnode*)malloc(sizeof(Tnode));
    if (!new) {
        printf("할당 실패");
        exit(1);
    }
    strcpy(new->data, word);
    new->try = 0; //횟수 초기화
    new->line[new->try++] = lines; //줄 저장
    new->left = new->right = NULL; //링크 초기화
    if (!parent) *root = new; //빈 트리
    else if (0 > strcmp(new->data, parent->data)) parent->left = new; //data가 빠르면 left 
    else parent->right = new;
}

int sum = 0; //전역 변수

void inorder(Tnode* root) { //중위 순회
    if (root) {
        inorder(root->left);
        printf("%s\t", root->data);
        printf("%d\t", root->try);
        sum += root->try; //계 저장
        for (int i = 0; i < root->try; i++) { //try만큼 반복 출력
            if (i != 0 && root->line[i] > 0) printf(",");
            if (root->line[i] > 0) printf("%d", root->line[i]);
        }
        printf("\n");
        inorder(root->right);
    }
}

int main(void) {
    FILE* file;
    Linkroot root;
    char line[100];
    char* word;
    int lines = 0;

    init(&(root.root));
    file = fopen("txt.txt", "r"); // 텍스트 파일 열기
    if (file == NULL) {
        printf("파일을 열 수 없습니다.");
        return 1;
    }

    // 파일에서 한 줄씩 읽어오기
    while (fgets(line, sizeof(line), file)) { //한 줄 추출
        lines++;

        for (int h = 0; h < strlen(line); h++) { //소문자로 바꾸기
            line[h] = tolower(line[h]);
        }

        word = strtok(line, " \t\n"); // 공백, 탭, 개행 문자를 구분자로 사용하여 단어 분리

        while (word != NULL) { // 줄에서 한 단어씩 추출하기
            add(&(root.root), word, lines);
            word = strtok(NULL, " \t\n,.'?");
        }
    }
    printf("단어\t횟수\t줄\n");

    inorder(root.root); //중위 순회
    printf("계\t%d", sum);

    fclose(file); // 파일 닫기
    return 0;
}
