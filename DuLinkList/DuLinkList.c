#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ERROR -1;
#define OK 1;
typedef int Status;
typedef char ElemType;//�����������������Ϊchar�����������ʵ�������
typedef struct LNode
{
	ElemType data;
	LNode* next;//�����һ���ڵ�ĵ�ַ
	LNode* prior;//���ǰһ���ڵ�ĵ�ַ
}LNode,*DuLinkList;
//��˫�������е�i��λ�ò���Ԫ��
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
		printf("����λ�÷Ƿ�\n");
			return ERROR;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
 //ɾ��˫�������еĵ�i��λ�õ�Ԫ��
 Status DeleteList(DuLinkList L, int i, ElemType* e)
 {
	 int j = 0;
	 LNode* p = L;
	 while (p && j < i)
	 {
		 p = p->next;//ʹpָ����Ҫɾ���Ľڵ�
	 }
	 if (!p)
	 {
		 return ERROR;
	 }
	 if (p->next)
	 {
		 p->prior->next = p->next;
		 p->next->prior = p->prior;
		 free(p);//��pλ�õ��ڴ��ͷţ�
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