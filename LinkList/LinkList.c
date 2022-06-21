#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
#define OK 1
#define ERROR -1
typedef char ElemType;//这里以char为数据类型，具体数据类型是实际情况而定
//定义链表的节点
typedef struct Lnode
{
	ElemType data;//存储数据
	struct Lnode* next;//指向下一个节点的指针域
}Lnode,*LinkList;//将struct Lnode重命名为Lnode,它的指针类型重命名为LinkList;
//初始化链表：即创建头节点以及头指针，并将头指针的指针域置为空
Status InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(Lnode));//开辟头结点的空间并返回地址；
	L->next = NULL;//将头结点的指针域置为空；
	return OK;
}
//判断链表是否为空：即当头节点的指针域为null时，链表为空
int IsEmpty(LinkList L)
{
	if (L->next)//说明有节点
	{
		return 0;
	}
	return 1;
}
//销毁单链表，即从头节点开始将单链表中的每一个节点的内存空间释放
//思想：L节点先往后移动，在释放前一个结点的内存空间
Status DestoryList(LinkList L)
{
	Lnode* p;//创建辅助指针
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
	return OK;
}
//清空单链表，即将除了头节点外的所有节点释放内存，同时将头节点的指针域置为空
Status ClearList(LinkList L)
{
	Lnode* p;
	Lnode* q;
	p = L->next;
	while (p)
	{
		q = p->next;//q指向p的下一个节点
		free(p);
		p = q;
	}
	L->next = NULL;//将头节点指针域置为空；
	return OK;
}
//求单链表的表长:从第一个结点开始往后数
int GetLength(LinkList L)
{
	Lnode* p;
	p = L->next;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}
//查找第i个位置节点的data的值
ElemType GetElem(LinkList L, int i)
{
	Lnode* p = L->next;//指向第一个元素
	int j = 1;//表示遍历了一个节点
	while (p && j < i)
	{
		p = p->next;
	}
	if (!p || j > i)
	{
		printf("查找的元素不存在\n");
		return NULL;
	}
	return p->data;
}
//按值查找并返回地址即逐个比较
Lnode* LocateElem1(LinkList L, ElemType e)
{
	Lnode* p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;//这里包含了未找到的情况，即p = null也可以直接返回；
}
//按值查找并返回第几个位置
int LocateElem2(LinkList L, ElemType e)
{
	Lnode* p = L->next;
	int j = 1;
	while (p && p->data != e)
	{
		j++;
		p = p->next;
	}
	if (p)
	{
		return j;
	}
	return 0;
}
//在第i个位置插入值为e的元素
Status InsertList(LinkList L, int i, ElemType e)
{
	//首先找到第i-1的位置
	int j = 0;
	Lnode* p = L;//这里从头结点开始，因为有可能是插入的第一个元素
	while (p && j < i - 1)
	{
		p = p->next;
	}
	if (!p || j > i - 1)
	{
		printf("插入位置非法\n");
		return ERROR;
	}
	Lnode* s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//删除第i个位置处的节点
Status DeleteList(LinkList L, int i, ElemType* e)
{
	int j = 0;
	Lnode* p = L;//从头结点开始
	Lnode* q;//保存需要删除的节点
	while ((p->next) && j < i - 1)
	{
		p = p->next;//找到需要删除的节点的前驱
	}
	if (!(p->next) || j > i - 1)
	{
		printf("删除的位置不存在\n");
		return ERROR;
	}
	q = p->next;
	*e = q->data;//将需要删除的节点的数据保存起来
	p->next = q->next;
	free(q);//释放需要删除结点的内存；
	return OK;
}
//用头插法创建链表
void CreateList_L(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	int i = 0;
	for (i = n; i > 0; i--)
	{
		Lnode* p = (Lnode*)malloc(sizeof(Lnode));
		scanf(p->data);
		//从最后一个开始取出放到第一个；
		p->next = L->next;
		L->next = p;
	}
}
//用尾插法创建链表（正序法）
void CreateList_R(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	Lnode* r = L;//尾指针，始终指向链表的尾部
	int i = 0;
	for (i = 0; i < n; i++)
	{
		Lnode* p = (Lnode*)malloc(sizeof(Lnode));
		p->next = NULL;//新的节点的指针域都为null;
		scanf(p->data);
		r->next = p;
		r = p;//r再次指向尾指针；
	}
}
//循环链表中的两个循环链表的合并
//这里的Ta和Tb都是表示链表的尾指针；
LinkList ConnectList(LinkList Ta, LinkList Tb)
{
	Lnode* p = Ta->next;//得到Ta头节点的地址
	Ta->next = Tb->next->next;//Ta指向Tb的第一个节点
	free(Tb->next);//释放Tb头节点的内存
	Tb->next = p;//Tb的尾指针指向Ta的头节点；
	return Tb;//返回Tb的尾指针；
}













int main()
{
	return 0;
}
