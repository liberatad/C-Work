#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int a;
	struct LNode* next;
}LNode,*List;
InitList(List L)
{
	L = (List)malloc(sizeof(List));
	L->next = NULL;
}
int main()
{
	List L;
	InitList(L);
	return 0;
}