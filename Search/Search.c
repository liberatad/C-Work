#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int KeyType;//关键字的类型
typedef char OtherType;//其他类型的域
typedef struct
{
	KeyType key;
	OtherType other;
}ElemType;
//定义顺序表
typedef struct
{
	ElemType* R;
	int length;
}SSTable;
int Search_Seq(SSTable ST, KeyType key)
{
	ST.R[0].key = key;
	int i = 0;
	for (i = ST.length; ST.R[i].key != key; i--);
	return i;
}
int Search_Bin1(SSTable ST, KeyType key)
{
	int low = 1;
	int high = ST.length;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key > ST.R[mid].key)
		{
			low = mid + 1;
		}
		else if (key < ST.R[mid].key)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return 0;
}
int Search_Bin2(SSTable ST, KeyType key, int low, int high)
{
	if (low > high)
	{
		return 0;
	}
	int mid = (low + high) / 2;
	if (key == ST.R[mid].key)
	{
		return mid;
	}
	if (key > ST.R[mid].key)
	{
		return Search_Bin2(ST, key, mid + 1, high);
	}
	if (key < ST.R[mid].key)
	{
		return Search_Bin2(ST, key, low, high - 1);
	}
}


int main()
{
	SSTable ST;
	ST.length = 10;
	ST.R = (ElemType*)malloc(sizeof(ElemType) * (ST.length + 1));
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		ST.R[i].key = i;
	}
	printf("顺序查找：%d\n", Search_Seq(ST, 5));
	printf("使用循环的二分查找：%d\n", Search_Bin1(ST, 5));
	printf("使用递归的二分查找：%d\n", Search_Bin2(ST, 5, 1, ST.length));
	return 0;
}