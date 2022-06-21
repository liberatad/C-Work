#define _CRT_SECURE_NO_WARNINGS
//用顺序表实现循环队列
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
typedef int QElemType;//数据元素类型设置为int型
#define ERROR -1
#define OK 1
#define MAXQSIZE 10
//创建队列
typedef struct SqQueue
{
	QElemType* base;//数组
	int front;//队列头部
	int rear;//队列尾部
}SqQueue,*QList;
//初始化队列
Status InitQueue(QList Q)
{
	Q->base = (QElemType*)malloc(sizeof(QElemType) * MAXQSIZE);
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
//求队列的长度
int GetLength(QList Q)
{
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}
//判断队列是否空
int IsEmpty(QList Q)
{
	return Q->front == Q->rear;
}
//判断队列是否满
int IsFull(QList Q)
{
	return (Q->rear + 1) % MAXQSIZE == Q->front;
}
//添加元素到队列
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
//从队列中取出元素
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
//返回队列头元素
QElemType GetHead(QList Q)
{
	return Q->front;
}
int main()
{

	return 0;
}