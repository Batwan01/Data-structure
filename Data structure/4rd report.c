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

void init(Tnode** root) { //��Ʈ �ʱ�ȭ
    *root = NULL;
}

void add(Tnode** root, char* word, int lines) { //��� �߰�
    Tnode* search = *root;
    Tnode* parent = NULL;
    while (search) {
        if (strcmp(word, search->data) == 0) { //���� ���� ��
            if (search->line[search->try - 1] == lines) search->try++; //�������� ������ Ƚ���� ����
            else search->line[search->try++] = lines;
            return;
        }
        parent = search;
        if (0 > strcmp(word, search->data)) search = search->left; //������ ����
        else search = search->right;
    }

    Tnode* new = (Tnode*)malloc(sizeof(Tnode));
    if (!new) {
        printf("�Ҵ� ����");
        exit(1);
    }
    strcpy(new->data, word);
    new->try = 0; //Ƚ�� �ʱ�ȭ
    new->line[new->try++] = lines; //�� ����
    new->left = new->right = NULL; //��ũ �ʱ�ȭ
    if (!parent) *root = new; //�� Ʈ��
    else if (0 > strcmp(new->data, parent->data)) parent->left = new; //data�� ������ left 
    else parent->right = new;
}

int sum = 0; //���� ����

void inorder(Tnode* root) { //���� ��ȸ
    if (root) {
        inorder(root->left);
        printf("%s\t", root->data);
        printf("%d\t", root->try);
        sum += root->try; //�� ����
        for (int i = 0; i < root->try; i++) { //try��ŭ �ݺ� ���
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
    file = fopen("txt.txt", "r"); // �ؽ�Ʈ ���� ����
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.");
        return 1;
    }

    // ���Ͽ��� �� �پ� �о����
    while (fgets(line, sizeof(line), file)) { //�� �� ����
        lines++;

        for (int h = 0; h < strlen(line); h++) { //�ҹ��ڷ� �ٲٱ�
            line[h] = tolower(line[h]);
        }

        word = strtok(line, " \t\n"); // ����, ��, ���� ���ڸ� �����ڷ� ����Ͽ� �ܾ� �и�

        while (word != NULL) { // �ٿ��� �� �ܾ �����ϱ�
            add(&(root.root), word, lines);
            word = strtok(NULL, " \t\n,.'?");
        }
    }
    printf("�ܾ�\tȽ��\t��\n");

    inorder(root.root); //���� ��ȸ
    printf("��\t%d", sum);

    fclose(file); // ���� �ݱ�
    return 0;
}
