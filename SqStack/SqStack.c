#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
#define ERROR -1
#define OK 1;
//˳��ջ����ز�����ʵ��
//ջ�ı��������Ա�ֻ����β�������ɾ��
#define MAX_SIZE 100//�����������
typedef char SElemType;//������������Ͷ���Ϊchar���ͣ����������ʵ�����
typedef struct SqStack
{
	SElemType* base;//ջ��ָ��
	SElemType* top;//ջ��ָ��
	int stacksize;//ջ���������
}SqStack,*SList;
//ջ�ĳ�ʼ��
void InitStack(SList S)
{
	//�����S�ڴ�һ��������������з����
	S->base = (SElemType*)malloc(MAX_SIZE * sizeof(SElemType));
	S->top = S->base;
	S->stacksize = MAX_SIZE;
}
//�ж�ջ�Ƿ�Ϊ��
int IsEmpty(SList S)
{
	return S->base == S->top;
}
//����ջ�ĳ���
int GetLength(SList S)
{
	return S->top - S->base;
}
//���ջ
void ClearStack(SList S)
{
	S->top = S->base;
}
//����ջ
void DestoryStack(SList S)
{
	free(S->base);
	S->stacksize = 0;
	S->base = NULL;
	S->top = NULL;
}
//��ջ����
Status Pust(SList S,SElemType e)
{
	if ((S->top - S->base) == S->stacksize)
	{
		return ERROR;
	}
	*S->top++ = e;
}
//��ջ����,����÷���ֵ��������
Status Pop(SList S,SElemType* e)
{
	if (IsEmpty(S))
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}


int main()
{
	return 0;
}