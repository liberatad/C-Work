#define _CRT_SECURE_NO_WARNINGS
//使用单链表实现有序表的合并
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*List;
//向链表中插入元素，直插入在尾部
void InsertList(List L, int x)
{
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
}
//实现有序表的合并
void MergeList(List La, List Lb, List Lc)
{
	LNode* pa = La->next;
	LNode* pb = Lb->next;
	LNode* pc = Lc;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	while (pa)
	{
		pc->next = pa;
		pc = pa;
		pa = pa->next;
	}
	while (pb)
	{
		pc->next = pb;
		pc = pb;
		pb = pb->next;
	}
}
int main()
{
	int arr1[] = { 1,3,5,7,9 };
	int arr2[] = { 2,4,6,8,10 };
	int i = 0;
	List L1 = (List)malloc(sizeof(LNode));
	List L2 = (List)malloc(sizeof(LNode));
	L1->next = NULL;
	L2->next = NULL;
	for (i = 0; i < 5; i++)
	{
		InsertList(L1, arr1[i]);
		InsertList(L2, arr2[i]);
	}
	List L = L1;
	MergeList(L1, L2, L);
	LNode* p = L->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	return 0;
}