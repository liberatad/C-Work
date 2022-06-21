#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define MAX_SIZE 100
#define OK 1
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;
//线性表的顺序存储结构的表示
//1.多项式
//#define MAX_SIZE 100
//typedef struct
//{
//	float p;//系数
//	int e;//指数；
//}Polynomia;
//typedef struct
//{
//	Polynomia* elem;//首地址；
//	int length;//多项式的数据个数；
//}SqList;//顺序存储的数据类型
//创建数据类型
typedef struct
{
	ElemType* elem;//动态分配数组，代表首地址
	int length;//代表数组长度
}SqList;
typedef SqList* List;//给SqList类型的顺序表的指针类型重命名，方便操作
//初始化顺序表
Status InitList(List L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);//初始化数组，并返回首地址
	if (!L->elem)
	{
		exit(OVERFLOW);//异常处理；返回-2;
	}
	L->length = 0;//初始化长度为零；
	return OK;
}
//删除表
void DestroyList(List L)
{
	if (L->elem)
	{
		free(L->elem);//释放内存空间；
	}
}
//清空表
void ClearList(List L)
{
	L->length = 0;
}
//返回长度
int GetLength(List L)
{
	return L->length;
}
//判断顺序表是否为空
int IsEmty(List L)
{
	if (L->length == 0)
	{
		return 1;//长度为零，说明顺序表长度为空；
	}
	return 0;
}
//返回第i个元素的值
int GetElem(List L, int i)
{
	if (i < 1 || i > L->length)
	{
		return ERROR;
	}
	return L->elem[i - 1];
}
//按值查找
int LocateElem(List L, ElemType e)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		if (L->elem[i] == e)
		{
			return i + 1;//这里返回的是具体的位置；
		}
	}
	//或者用以下算法；
	//while (i < L->length && L->elem[i] != e)
	//{
	//	i++;
	//}
	//if (i < L->length)
	//{
	//	return i + 1;
	//}
	//return 0;
	return 0;//查找失败，返回0;
}
//在第i个位置插入元素e
Status InsertList(List L, int i, ElemType e)
{
	if (i < 1 || i > L->length + 1)
	{
		printf("插入位置非法\n");
		return ERROR;
	}
	if (L->length == MAX_SIZE)
	{
		printf("表满，无法插入\n");
		return ERROR;
	}
	int j = 0;
	for (j = L->length - 1; j >= i - 1; j++)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	L->length++;//表的长度增加1;
	return OK;
}
//删除指定位置i的元素
Status DeleteList(List L, int i)
{
	if (i < 1 || i > L->length)
	{
		printf("删除位置不合法\n");
		return ERROR;
	}
	int j = 0;
	for (j = i; j <= L->length - 1; j++)
	{
		L->elem[j - 1] = L->elem[j];//从第i个开始每个元素往前移；
	}
	L->length--;
	return OK;
}




int main()
{
	return 0;
}