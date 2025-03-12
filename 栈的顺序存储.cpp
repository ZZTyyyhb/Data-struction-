#include<stdio.h>
#include<stdlib>

#define MAXSIZE 100

typedef int ElementType;
typedef struct SNode* Stack;

struct SNode
{
	int top;
	ElementType Data;
};

Stack S;

Stack CreateStack();
int Isfull(Stack S);
int IsEmpty(Stack S);
void push(Stack S, ElementType item);
ElementType pop(Stack S);

Stack CreateStack()
{
	S = (Stack)malloc(sizeof(struct SNode));
	S->top = -1;
	return S;
}

int Isfull(Stack S)
{
	return (top - 1 == MAXSIZE);
}

int IsEmpty(Stack S)
{
	return (top == -1);
}

void push(Stack S, ElementType item)
{
	if (ISfull(S))
	{
		std::cout << "ջ����" << std::endl;
	}
	else
	{
		S->top++;
		S->Data[S->top] = item;
	}
}

ElementType pop(Stack S)
{
	if (IsEmpty(S))
	{
		std::cout << "ջΪ��" << std::endl;
	}
	else
	{
		ElementType val = S->Data[S->top];
		S->top--;
		return val;
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

}
















