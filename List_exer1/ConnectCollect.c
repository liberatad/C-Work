#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//ʵ���������Ա�ĺϲ���ʹ������ʵ��
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*List;
//��������ʹ��β�巨
void CreateList(List L, int n)
{
	//L = (List)malloc(sizeof(LNode));
	L->next = NULL;
	int i = 0;
	for (i = n; i > 0; i--)
	{
		LNode* p = (List)malloc(sizeof(LNode));
		int input = 0;
		printf("����������\n");
		scanf("%d", &input);
		p->data = input;
		p->next = L->next;
		L->next = p;
	}
}
//����β����������
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
//ʵ�ּ�������ĳ���
// 
//ʵ�ּ��Ϻϲ����㷨
List ConnectList(List L1, List L2)
{
	LNode* p = L1->next;
	LNode* q = L2->next;
	while (q)
	{
		while (p)
		{
			if (p->data == q->data)
			{
				break;
			}
			p = p->next;
		}
		if (!p)
		{
			InsertList(L1, q->data);
		}
		q = q->data;
		p = L1->next;
	}
	return L1;
}
int main()
{
	List L1 = (List)malloc(sizeof(LNode));
	printf("%p\n", L1);
	//List L2;
	CreateList(L1,4);
	List L2 = (List)malloc(sizeof(LNode));
	CreateList(L2, 3);
	List L = ConnectList(L1, L2);
	printf("%p\n", L);
	LNode* p = L->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	//printf("%d\n", L1->next->data);
	return 0;
}