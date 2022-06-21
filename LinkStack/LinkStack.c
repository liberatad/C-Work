#define _CRT_SECURE_NO_WARNINGS
//用链表实现栈
#include<stdio.h>
#include<stdlib.h>
typedef int SElemType;
typedef int Status;
#define ERROR -1
#define OK 1
//创建节点
typedef struct LNode
{
	SElemType data;
	struct LNode* next;
}LNode,*SList;
//初始化栈
void InitStack(SList S)
{
	//初始化一般在main函数中进行
	S = (LNode*)malloc(sizeof(LNode));
	S = NULL;
}
//向栈中存数据
Status Push(SList S, SElemType e)
{
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->data = e;
	L->next = S;
	S = L;
	return OK;
}
//从栈中取出数据
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