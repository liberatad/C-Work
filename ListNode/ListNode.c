#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode* PtrToLNode;
struct LNode
{
	int Data;
	PtrToLNode next;//ָ����һ���ڵ�
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
//����
Position Find(List L, int index)
{
	Position p = L;//ָ���һ���ڵ㣻
	while (p && p->Data != index)
	{
		p = p->next;
	}
	if (p)
	{
		return p;
	}
	else
	{
		return NULL;
	}
}
//����ڵ�
//����Lָͷ�ڵ㣬Pָ������Ҫ�����λ��
int Insert(List L, int X, Position P)
{
	Position pre = L;
	Position tmp;
	while (pre && pre->next != P)
	{
		pre = pre->next;
	}
	if (pre == NULL)
	{
		printf("����Ĳ�������\n");
		return 0;
	}
	else
	{
		tmp = (List)malloc(sizeof(struct LNode));
		tmp->Data = X;
		tmp->next = pre->next;//P
		pre->next = tmp;
		return 1;
	}
}
//ɾ���ڵ�
int Delete(List L, Position P)
{
	Position pre;
	while (pre && pre->next!=P)
	{
		pre = pre->next;
	}
	if (pre == NULL)
	{
		printf("ɾ���Ĳ�������\n");
		return 0;
	}
	else
	{
		pre->next = P->next;
		free(P);
		return 1;
	}
}



int main()
{
	return 0;
}

