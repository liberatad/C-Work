#define _CRT_SECURE_NO_WARNINGS
//�����е�ʵ��
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
typedef int QElemType;
#define ERROR -1
#define OK 1
//�����ڵ�
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
//������ָ��������
typedef struct QList
{
	QueuePtr front;
	QueuePtr rear;
}*QList;
//��ʼ������
Status InitQueue(QList Q)
{
	Q->front = (QueuePtr)malloc(sizeof(QNode));
	Q->front->next = NULL;
	Q->rear = Q->front;
	return OK;
}
//�����������٣����ͷ����еĿռ�
Status DestoryQurur(QList Q)
{
	QNode* p;
	while (Q->front)
	{
		p = Q->front->next;
		free(Q->front);
		Q->front = p;
	}
	return OK;
}
//��Ԫ����������
Status EnQueue(QList Q, QElemType e)
{
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}
//��������
Status DeQueue(QList Q, QElemType* e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	if (Q->front->next == Q->rear)
	{
		QNode* p = Q->front->next;
		Q->rear = Q->front;
		free(p);
		return OK;
	}
	QNode* p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	free(p);
	return OK;
}
//����ͷָ���ֵ
QElemType GetHead(QList Q)
{
	return Q->front->next->data;
}
int main()
{
	return 0;
}