#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElementType;
typedef struct LNode* List;
struct LNode
{
    ElementType data[MAXSIZE];
    int last;
};

List MakeEmpty();
int Find(ElementType X, List L);            // ���� X ��һ�γ��ֵ��±�
void Insert(ElementType X, int i, List L);
void Delete(int i, List L);
ElementType FindKth(int K, List L);
int Length(List L);

List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->last = -1;
    return L;
}

int Find(ElementType X, List L)
{
    int i = 0;
    while (i <= L->last && L->data[i] != X)
        i++;
    if (i > L->last)
        return -1;
    else
        return i;
}

void Insert(ElementType X, int i, List L)
{
    int j;
    if (L->last == MAXSIZE - 1)
    {
        printf("����\n");
        return;
    }
    if (i < 0 || i > L->last + 1)
    {
        printf("����λ�ò��Ϸ�\n");
        return;
    }
    for (j = L->last; j >= i; j--)
    {
        L->data[j + 1] = L->data[j];
    }
    L->data[i] = X;
    L->last++;
}

void Delete(int i, List L)
{
    int j;
    if (i < 0 || i > L->last)
    {
        printf("ɾ��λ�ò��Ϸ�\n");
        return;
    }
    for (j = i; j < L->last; j++)
    {
        L->data[j] = L->data[j + 1];
    }
    L->last--;
}

ElementType FindKth(int K, List L)
{
    if (K < 0 || K > L->last)
    {
        printf("L->data[%d]������Ԫ��\n", K);
        return (ElementType)NULL; // ������Чֵ
    }
    return L->data[K];
}

int Length(List L)
{
    return L->last + 1;
}

int main()
{
    int i = 0;
    List L;
    L = MakeEmpty();
    Insert(23, 0, L);
    printf("�����Ա� L->data[0] ���� 23\n");
    Insert(77, 1, L);
    printf("�����Ա� L->data[1] ���� 77\n");
    Insert(24, 2, L);
    printf("�����Ա� L->data[2] ���� 24\n");
    Insert(8, 3, L);
    printf("�����Ա� L->data[3] ���� 8\n");
    Insert(30, 4, L);
    printf("�����Ա� L->data[4] ���� 30\n");

    printf("���Ա����±�Ϊ 3 ��Ԫ���ǣ�%d\n", FindKth(3, L));

    Delete(0, L);
    printf("ɾ�����Ա����±�Ϊ 0 ��Ԫ��\n");
    Delete(2, L);
    printf("ɾ�����Ա����±�Ϊ 2 ��Ԫ��\n");
    Delete(4, L); // ���ɾ�����ܻ�ʧ�ܣ���Ϊ Length �� 3���±����Ϊ 2

    printf("��ʱ���Ա�Ϊ��");
    for (i = 0; i < Length(L); i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n�䳤��Ϊ��%d\n", Length(L));

    return 0;
}

