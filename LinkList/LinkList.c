#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
#define OK 1
#define ERROR -1
typedef char ElemType;//������charΪ�������ͣ���������������ʵ���������
//��������Ľڵ�
typedef struct Lnode
{
	ElemType data;//�洢����
	struct Lnode* next;//ָ����һ���ڵ��ָ����
}Lnode,*LinkList;//��struct Lnode������ΪLnode,����ָ������������ΪLinkList;
//��ʼ������������ͷ�ڵ��Լ�ͷָ�룬����ͷָ���ָ������Ϊ��
Status InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(Lnode));//����ͷ���Ŀռ䲢���ص�ַ��
	L->next = NULL;//��ͷ����ָ������Ϊ�գ�
	return OK;
}
//�ж������Ƿ�Ϊ�գ�����ͷ�ڵ��ָ����Ϊnullʱ������Ϊ��
int IsEmpty(LinkList L)
{
	if (L->next)//˵���нڵ�
	{
		return 0;
	}
	return 1;
}
//���ٵ���������ͷ�ڵ㿪ʼ���������е�ÿһ���ڵ���ڴ�ռ��ͷ�
//˼�룺L�ڵ��������ƶ������ͷ�ǰһ�������ڴ�ռ�
Status DestoryList(LinkList L)
{
	Lnode* p;//��������ָ��
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
	return OK;
}
//��յ�������������ͷ�ڵ�������нڵ��ͷ��ڴ棬ͬʱ��ͷ�ڵ��ָ������Ϊ��
Status ClearList(LinkList L)
{
	Lnode* p;
	Lnode* q;
	p = L->next;
	while (p)
	{
		q = p->next;//qָ��p����һ���ڵ�
		free(p);
		p = q;
	}
	L->next = NULL;//��ͷ�ڵ�ָ������Ϊ�գ�
	return OK;
}
//������ı�:�ӵ�һ����㿪ʼ������
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
//���ҵ�i��λ�ýڵ��data��ֵ
ElemType GetElem(LinkList L, int i)
{
	Lnode* p = L->next;//ָ���һ��Ԫ��
	int j = 1;//��ʾ������һ���ڵ�
	while (p && j < i)
	{
		p = p->next;
	}
	if (!p || j > i)
	{
		printf("���ҵ�Ԫ�ز�����\n");
		return NULL;
	}
	return p->data;
}
//��ֵ���Ҳ����ص�ַ������Ƚ�
Lnode* LocateElem1(LinkList L, ElemType e)
{
	Lnode* p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;//���������δ�ҵ����������p = nullҲ����ֱ�ӷ��أ�
}
//��ֵ���Ҳ����صڼ���λ��
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
//�ڵ�i��λ�ò���ֵΪe��Ԫ��
Status InsertList(LinkList L, int i, ElemType e)
{
	//�����ҵ���i-1��λ��
	int j = 0;
	Lnode* p = L;//�����ͷ��㿪ʼ����Ϊ�п����ǲ���ĵ�һ��Ԫ��
	while (p && j < i - 1)
	{
		p = p->next;
	}
	if (!p || j > i - 1)
	{
		printf("����λ�÷Ƿ�\n");
		return ERROR;
	}
	Lnode* s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//ɾ����i��λ�ô��Ľڵ�
Status DeleteList(LinkList L, int i, ElemType* e)
{
	int j = 0;
	Lnode* p = L;//��ͷ��㿪ʼ
	Lnode* q;//������Ҫɾ���Ľڵ�
	while ((p->next) && j < i - 1)
	{
		p = p->next;//�ҵ���Ҫɾ���Ľڵ��ǰ��
	}
	if (!(p->next) || j > i - 1)
	{
		printf("ɾ����λ�ò�����\n");
		return ERROR;
	}
	q = p->next;
	*e = q->data;//����Ҫɾ���Ľڵ�����ݱ�������
	p->next = q->next;
	free(q);//�ͷ���Ҫɾ�������ڴ棻
	return OK;
}
//��ͷ�巨��������
void CreateList_L(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	int i = 0;
	for (i = n; i > 0; i--)
	{
		Lnode* p = (Lnode*)malloc(sizeof(Lnode));
		scanf(p->data);
		//�����һ����ʼȡ���ŵ���һ����
		p->next = L->next;
		L->next = p;
	}
}
//��β�巨�����������򷨣�
void CreateList_R(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	Lnode* r = L;//βָ�룬ʼ��ָ�������β��
	int i = 0;
	for (i = 0; i < n; i++)
	{
		Lnode* p = (Lnode*)malloc(sizeof(Lnode));
		p->next = NULL;//�µĽڵ��ָ����Ϊnull;
		scanf(p->data);
		r->next = p;
		r = p;//r�ٴ�ָ��βָ�룻
	}
}
//ѭ�������е�����ѭ������ĺϲ�
//�����Ta��Tb���Ǳ�ʾ�����βָ�룻
LinkList ConnectList(LinkList Ta, LinkList Tb)
{
	Lnode* p = Ta->next;//�õ�Taͷ�ڵ�ĵ�ַ
	Ta->next = Tb->next->next;//Taָ��Tb�ĵ�һ���ڵ�
	free(Tb->next);//�ͷ�Tbͷ�ڵ���ڴ�
	Tb->next = p;//Tb��βָ��ָ��Ta��ͷ�ڵ㣻
	return Tb;//����Tb��βָ�룻
}













int main()
{
	return 0;
}
