#define _CRT_SECURE_NO_WARNINGS
//��˳���ʵ��ѭ������
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
typedef int QElemType;//����Ԫ����������Ϊint��
#define ERROR -1
#define OK 1
#define MAXQSIZE 10
//��������
typedef struct SqQueue
{
	QElemType* base;//����
	int front;//����ͷ��
	int rear;//����β��
}SqQueue,*QList;
//��ʼ������
Status InitQueue(QList Q)
{
	Q->base = (QElemType*)malloc(sizeof(QElemType) * MAXQSIZE);
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
//����еĳ���
int GetLength(QList Q)
{
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}
//�ж϶����Ƿ��
int IsEmpty(QList Q)
{
	return Q->front == Q->rear;
}
//�ж϶����Ƿ���
int IsFull(QList Q)
{
	return (Q->rear + 1) % MAXQSIZE == Q->front;
}
//���Ԫ�ص�����
Status EnQueue(QList Q, QElemType e)
{
	if (IsFull(Q))
	{
		return ERROR;
	}
	(Q->base)[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}
//�Ӷ�����ȡ��Ԫ��
Status DeQueue(QList Q, QElemType* e)
{
	if (IsEmpty(Q))
	{
		return ERROR;
	}
	*e = (Q->base)[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}
//���ض���ͷԪ��
QElemType GetHead(QList Q)
{
	return Q->front;
}
int main()
{

	return 0;
}