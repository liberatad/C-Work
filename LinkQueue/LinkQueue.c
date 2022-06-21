#define _CRT_SECURE_NO_WARNINGS
//链队列的实现
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
typedef int QElemType;
#define ERROR -1
#define OK 1
//创建节点
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
//用两个指针代表队列
typedef struct QList
{
	QueuePtr front;
	QueuePtr rear;
}*QList;
//初始化队列
Status InitQueue(QList Q)
{
	Q->front = (QueuePtr)malloc(sizeof(QNode));
	Q->front->next = NULL;
	Q->rear = Q->front;
	return OK;
}
//将链队列销毁，即释放所有的空间
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
//将元素入链队列
Status EnQueue(QList Q, QElemType e)
{
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}
//出链队列
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
//返回头指针的值
QElemType GetHead(QList Q)
{
	return Q->front->next->data;
}
int main()
{
	return 0;
}