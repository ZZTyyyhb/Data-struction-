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
int Find(ElementType X, List L);            // 查找 X 第一次出现的下标
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
        printf("表满\n");
        return;
    }
    if (i < 0 || i > L->last + 1)
    {
        printf("插入位置不合法\n");
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
        printf("删除位置不合法\n");
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
        printf("L->data[%d]不存在元素\n", K);
        return (ElementType)NULL; // 返回无效值
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
    printf("在线性表 L->data[0] 插入 23\n");
    Insert(77, 1, L);
    printf("在线性表 L->data[1] 插入 77\n");
    Insert(24, 2, L);
    printf("在线性表 L->data[2] 插入 24\n");
    Insert(8, 3, L);
    printf("在线性表 L->data[3] 插入 8\n");
    Insert(30, 4, L);
    printf("在线性表 L->data[4] 插入 30\n");

    printf("线性表中下标为 3 的元素是：%d\n", FindKth(3, L));

    Delete(0, L);
    printf("删除线性表中下标为 0 的元素\n");
    Delete(2, L);
    printf("删除线性表中下标为 2 的元素\n");
    Delete(4, L); // 这个删除可能会失败，因为 Length 是 3，下标最大为 2

    printf("此时线性表为：");
    for (i = 0; i < Length(L); i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n其长度为：%d\n", Length(L));

    return 0;
}

