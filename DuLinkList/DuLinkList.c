#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ERROR -1;
#define OK 1;
typedef int Status;
typedef char ElemType;//这里的数据类型设置为char，具体情况看实际情况；
typedef struct LNode
{
	ElemType data;
	LNode* next;//存放下一个节点的地址
	LNode* prior;//存放前一个节点的地址
}LNode,*DuLinkList;
//在双向链表中第i个位置插入元素
 Status InsertDuList(DuLinkList L, int i, ElemType e)
{
	LNode* p = L;
	int j = 0;
	while (p && j < i)
	{
		p = p->next;
	}
	if (!p)
	{
		printf("插入位置非法\n");
			return ERROR;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
 //删除双向链表中的第i个位置的元素
 Status DeleteList(DuLinkList L, int i, ElemType* e)
 {
	 int j = 0;
	 LNode* p = L;
	 while (p && j < i)
	 {
		 p = p->next;//使p指向需要删除的节点
	 }
	 if (!p)
	 {
		 return ERROR;
	 }
	 if (p->next)
	 {
		 p->prior->next = p->next;
		 p->next->prior = p->prior;
		 free(p);//将p位置的内存释放；
	 }
	 else
	 {
		 p->prior->next = NULL;
		 free(p);
	 }
 }
int main()
{
	return 0;
}