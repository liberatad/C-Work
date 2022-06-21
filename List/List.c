#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode* List;//创建节点的指针
struct LNode
{
	int Data[100];//表示线性表的最大容量
	int Last;//指向数组最后一个元素；
};
//初始化线性表
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}
//在线性表中查找元素；
int Find(List L, int x)
{
	int i = 0;
	while (i <= L->Last && x != L->Data[i])
	{
		i++;
	}
	if (i > L->Last)
	{
		return -1;//表示未找到
	}
	else
	{
		return i;//返回找到的位置；
	}
}
//在线性表中插入元素
//x表示要插入的元素，index表示需要插入的位置
int Insert(List L, int x, int index)
{
	int i = 0;
	if (L->Last == 99)
	{
		printf("表空间已经满，无法插入\n");
		return 0;
	}
	if (index < 0 || index > L->Last + 1)
	{
		printf("插入位置不合法\n");
		return 0;
	}
	for (i = L->Last; i >= index; i--)
	{
		L->Data[i + 1] = L->Data[i];//从index开始将元素逐个向后移动，注意是从后往前；
	}
	L->Data[index] = x;//将index位置元素赋值为x;
	L->Last++;//指向最后的一个元素增加；
	return 1;
}
//从线性表中删除元素
int Delete(List L, int index)//index表示要删除元素的位置
{
	int i = 0;
	if (index < 0 || index > L->Last)
	{
		printf("删除%d的位置不存在\n", index);
		return 0;
	}
	for (i = index + 1; i <= L->Last; i++)
	{
		L->Data[i - 1] = L->Data[i];
	}
	L->Last--;//指向的最后一个元素减少1；
	return 1;
}
int main()
{
	return 0;
}







