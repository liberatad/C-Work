#define _CRT_SECURE_NO_WARNINGS
//������ʵ��ջ
#include<stdio.h>
#include<stdlib.h>
typedef int SElemType;
typedef int Status;
#define ERROR -1
#define OK 1
//�����ڵ�
typedef struct LNode
{
	SElemType data;
	struct LNode* next;
}LNode,*SList;
//��ʼ��ջ
void InitStack(SList S)
{
	//��ʼ��һ����main�����н���
	S = (LNode*)malloc(sizeof(LNode));
	S = NULL;
}
//��ջ�д�����
Status Push(SList S, SElemType e)
{
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->data = e;
	L->next = S;
	S = L;
	return OK;
}
//��ջ��ȡ������
Status Pop(SList S, SElemType* e)
{
	if (S == NULL)
	{
		return ERROR;
	}
	*e = S->data;
	LNode* p = S;
	S = S->next;
	free(p);
	return OK;
}
int main()
{
	return 0;
}