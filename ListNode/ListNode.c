#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode* PtrToLNode;
struct LNode
{
	int Data;
	PtrToLNode next;//指向下一个节点
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
//查找
Position Find(List L, int index)
{
	Position p = L;//指向第一个节点；
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
//插入节点
//这里L指头节点，P指的是需要插入的位置
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
		printf("插入的参数错误\n");
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
//删除节点
int Delete(List L, Position P)
{
	Position pre;
	while (pre && pre->next!=P)
	{
		pre = pre->next;
	}
	if (pre == NULL)
	{
		printf("删除的参数错误\n");
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

