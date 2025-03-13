#include<stdio.h>
#include<stdlib>

#define MAXSIZE 100

typedef int ElementType;
typedef struct SNode* Stack;

struct SNode
{
	ElementType Data;
	Stack Next;
};


Stack CreateStack();
//int Isfull(Stack S);
int IsEmpty(Stack S);
void push(Stack S, ElementType item);
ElementType pop(Stack S);

Stack CreateStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

/*int Isfull(Stack S)
{
	return (top - 1 == MAXSIZE);
}*/
int IsEmpty(Stack S)
{
	return (S->Next == NULL);
}

void push(Stack S, ElementType item)
{
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct SNode));
	tmp->Next = S->Next;
	S->Next = tmp;
}

ElementType pop(Stack S)
{
	Stack First;
	ElementType Topval;
	if (IsEmpty(S))
	{
		std::cout << "ջΪ��" << std::endl;
	}
	else
	{
		First = S->Next;
		S->Next = First->Next;
		Topval = First->Data;
		free(First);
		return Topval;
	}
}

int main()
{
	S = CreateStack();
	std::cout << "1��ջ" << std::endl;
	push(S, 1);
	std::cout << "2��ջ" << std::endl;
	push(S, 2);
	std::cout << "3��ջ" << std::endl;
	push(S, 3);
	std::cout << "2��ջ" << std::endl;
	pop(S, 2);
}
















