#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
#define ERROR -1
#define OK 1;
//顺序栈的相关操作的实现
//栈的本质是线性表，只能在尾部插入和删除
#define MAX_SIZE 100//定义最大容量
typedef char SElemType;//这里的数据类型定义为char类型，具体情况看实际情况
typedef struct SqStack
{
	SElemType* base;//栈底指针
	SElemType* top;//栈顶指针
	int stacksize;//栈的最大容量
}SqStack,*SList;
//栈的初始化
void InitStack(SList S)
{
	//这里的S内存一般会先在主函数中分配好
	S->base = (SElemType*)malloc(MAX_SIZE * sizeof(SElemType));
	S->top = S->base;
	S->stacksize = MAX_SIZE;
}
//判断栈是否为空
int IsEmpty(SList S)
{
	return S->base == S->top;
}
//返回栈的长度
int GetLength(SList S)
{
	return S->top - S->base;
}
//清空栈
void ClearStack(SList S)
{
	S->top = S->base;
}
//销毁栈
void DestoryStack(SList S)
{
	free(S->base);
	S->stacksize = 0;
	S->base = NULL;
	S->top = NULL;
}
//入栈操作
Status Pust(SList S,SElemType e)
{
	if ((S->top - S->base) == S->stacksize)
	{
		return ERROR;
	}
	*S->top++ = e;
}
//出栈操作,并获得返回值保存起来
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