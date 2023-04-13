//���� ���Ḯ��Ʈ - ���� ������ ������ ����
//���Ḯ��Ʈ ����, ��� ����, �ʱ�ȭ, �߰�, ����, �˻�, ��ü ���, ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void* Element;

typedef struct Node//��� ����
{
    Element data;//������
    struct Node* next;//��ũ(���� ����� ��ġ ����)
    struct Node* prev;//��ũ(���� ����� ��ġ ����)
}Node;

Node* NewNode(Element data)//��� ����
{
    Node* now = (Node*)malloc(sizeof(Node));
    now->data = data;
    now->prev = now->next = NULL;
    return now;
}

typedef struct List//���Ḯ��Ʈ ����
{
    Node* head;
    Node* tail;
    int count;
}List;


typedef struct Data//�׽�Ʈ���� ����Ʈ�� ������ ������ ����
{
    int num;
    char* name;
}Data;

Data* NewData(int num, const char* name)//������ ���� ����
{
    Data* data = (Data*)malloc(sizeof(Data));
    data->num = num;
    data->name = (char*)malloc(strlen(name) + 1);
    strcpy_s(data->name, strlen(name) + 1, name);
    return data;
}
void DeleteData(Data* data)//������ ���� �Ҹ�
{
    free(data->name);
    free(data);
}
void ViewData(Data* data)//������ ���� ���
{
    printf("%-5d %-10s\n", data->num, data->name);
}

typedef int(*IsEqual)(Element e1);//�� �˰���
typedef void(*View)(Element e1);//��� �˰���
typedef void(*Dispose)(Element e1);//�Ҹ� �˰���

List* NewList();//����Ʈ ���� ����
void DeleteList(List* list, Dispose dispose);//����Ʈ �Ҹ�
void AddData(List* list, Element data);//������ �߰�
void Remove(List* list, Node* now, Dispose dispose);//��� ����
Node* Find(List* list, IsEqual isequal);//��� �˻�
void ViewAll(List* list, View view);//��ü ���
void Clear(List* list, Dispose dispose);//����


void AlgoDeleteData(Element elem)//������ ���� �Ҹ� ����
{
    DeleteData((Data*)elem);
}
void AlgoViewData(Element elem)//������ ���� ��� ����
{
    ViewData((Data*)elem);
}

int find_num; //�˻��� ��ȣ
int AlgoEqual(Element e1)//�˻� �˰���
{
    Data* data = (Data*)e1;
    return find_num == data->num;

}
int main(void)
{
    List* list = NewList();
    {//�߰�  �׽�Ʈ�� ���� ���
        AddData(list, NewData(3, "ȫ�浿")); //3
        AddData(list, NewData(6, "������")); //3, 6
        AddData(list, NewData(4, "��������")); //3, 6, 4
        AddData(list, NewData(9, "�̼���")); //3, 6, 4, 9
        ViewAll(list, AlgoViewData);// 3 4 6 9 ���
    }

    {//���� �׽�Ʈ�� ���� ��

        Node* seek;
        find_num = 4;
        seek = Find(list, AlgoEqual);
        if (seek)
        {
            printf("4�� ������ ��带 ã����\n");
            Remove(list, seek, AlgoDeleteData); //3 6 9
            printf("4�� ������ ��� ���� ��\n");
            ViewAll(list, AlgoViewData);// 3 6 9 ���
        }
    }
    Clear(list, AlgoDeleteData);//��ü ����
    printf("��ü ���� ��\n");
    ViewAll(list, AlgoViewData);// �ƹ��͵� ������� ����
    DeleteList(list, AlgoDeleteData);//����Ʈ ����
    return 0;
}
void InitList(List* list);//�ʱ�ȭ
List* NewList()
{
    List* list = (List*)malloc(sizeof(List));//����Ʈ ���� �޸� �Ҵ�
    InitList(list);//����Ʈ �ʱ�ȭ
    return list;
}
void DeleteList(List* list, Dispose dispose)
{
    Clear(list, dispose);//�ڷḦ ������ ��� ��带 ����
    free(list->head);//�� ���� ���� ��� ����
    free(list->tail);//�� ���� ���� ��� ����
    free(list);//����Ʈ ����
}
void InitList(List* list)
{
    list->head = NewNode(NULL);//���� ����Ʈ�� �� �տ� ���� ��� ����
    list->tail = NewNode(NULL);//���� ����Ʈ�� �� �ڿ� ���� ��� ����
    list->head->next = list->tail;//head�� ������ tail�� ����
    list->tail->prev = list->head;//tail�� ������ head�� ����
    list->count = 0;//������ ������ ������ 0���� ����    
}
void AddData(List* list, Element data)
{
    //���� ������ ��带 tail�տ� �Ŵ�ϴ�.
    Node* now = NewNode(data);//���ο� ��� ����
    now->prev = list->tail->prev;//now�� prev�� tail �� ���� ����
    now->next = list->tail;//now�� next�� tail�� ����
    list->tail->prev->next = now;//tail�� ���� ����� next�� now�� ����
    list->tail->prev = now;//tail�� prev�� now�� ����
    list->count++;//������ ������ ������ 1 ����
}

void Remove(List* list, Node* now, Dispose dispose)
{
    now->prev->next = now->next;//���� ����� next�� now�� ���� ���� ����
    now->next->prev = now->prev;//���� ����� prev�� now�� ���� ���� ����
    dispose(now->data);
    free(now);
    list->count--;//������ ��� ������ 1 ����
}

Node* Find(List* list, IsEqual isequal)
{
    //head�� tail�� ���� ����Դϴ�.
    Node* seek = list->head->next;//head�� next���� �˻��մϴ�.
    while (seek != list->tail) //seek�� tail�� �ƴϸ�
    {
        if (isequal(seek->data))//ã���� ��
        {
            return seek;
        }
        seek = seek->next;//seek�� �������� �̵�
    }
    return NULL;//�� ã���� ��
}

void ViewAll(List* list, View view)
{
    //head�� tail�� ���� ����Դϴ�.
    Node* seek = list->head->next;//head->next ���� ����մϴ�.
    int i = 0;
    printf("������ ������ ����: %d\n", list->count);

    while (seek != list->tail) //seek�� ���̸�(NULL �� �ƴϸ�)
    {
        i++;
        view(seek->data);

        if (i % 5 == 0)//5�� ����� ��
        {
            printf("\n");//����
        }
        seek = seek->next;//seek�� �������� �̵�
    }
    printf("\n");
}

void Clear(List* list, Dispose dispose)
{
    //head ���� ��尡 tail�� �ƴ� ������ ����Ʈ���� ����
    Node* seek = list->head->next;
    while (seek != list->tail) //seek�� ���̸�(NULL �� �ƴϸ�)
    {
        Remove(list, seek, dispose);
        seek = list->head->next;
    }
}