#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int KeyType;
typedef char OtherType;
typedef struct
{
	KeyType key;
	OtherType info;
}RedType;//RecordType
typedef struct
{
	RedType r[MAXSIZE + 1];
	int length;
}SqList;
//插入排序
void InsertSort(SqList L)
{
	int i;
	int j;
	for (i = 2; i <= L.length; i++)
	{
		if (L.r[i].key < L.r[i - 1].key)
		{
			L.r[0].key = L.r[i].key;
			for (j = i - 1; L.r[j].key > L.r[0].key; j--)
			{
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];
		}
	}
}
//折半插入排序
void BinsertSort(SqList L)
{
	int i;
	int j;
	for (i = 2; i <= L.length; i++)
	{
		L.r[0] = L.r[i];
		int low = 1;
		int high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (j = i - 1; j >= high + 1; j--)
		{
			L.r[j + 1] = L.r[j];
		}
		L.r[high + 1] = L.r[0];
	}
}
//希尔排序
//dk中存储了每次插入排序的步长，并且最后一次应该为1
void ShellinSort(SqList L, int dk)
{
	int i;
	int j;
	for (i = dk + 1; i <= L.length; i++)
	{
		if (L.r[i].key < L.r[i - dk].key)
		{
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && L.r[j].key > L.r[0].key; j -= dk)
			{
				L.r[j + dk].key = L.r[j].key;
			}
			L.r[j + dk] = L.r[0];
		}
		
	}
}
void ShellSort(SqList L, int dk[], int t)
{
	int k = 0;
	for (k = 0; k < t; k++)
	{
		ShellinSort(L, dk[k]);
	}
}
//冒泡排序
void BubbleSort(SqList L)
{
	int n = L.length;
	int i;
	int j;
	int flag = 1;
	for (i = 1; i <= n - 1 && flag == 1; i++)
	{
		flag = 0;
		for (j = 1; j <= n - i; j++)
		{
			if (L.r[j].key > L.r[j + 1].key)
			{
				flag = 1;
				RedType x = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = x;
			}
		}
	}
}
//快速排序，采用递归，而且第一次应该从low=1,high=length开始
int Partition(SqList L, int low, int high)
{
	L.r[0] = L.r[low];
	int piokey = L.r[low].key;//这是每一次排序的基准
	while (low < high)
	{
		while (low < high && L.r[high].key >= piokey)
		{
			high--;
		}
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= piokey)
		{
			low++;
		}
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}
void QuickSort(SqList L, int low, int high)
{
	if (low < high)//说明子表的元素个数仍然大于1
	{
		int pivotloc = Partition(L, low, high);
		QuickSort(L, low, pivotloc - 1);//对低子表进行排序
		QuickSort(L, pivotloc + 1, high);//对高子表进行排序；
	}
}
//选择排序
void SelectSort(SqList L)
{
	int k;
	int i;
	int j;
	for (i = 1; i < L.length; i++)
	{
		k = i;
		for (j = i + 1; j <= L.length; j++)
		{
			if (L.r[j].key < L.r[k].key)
			{
				k = j;
			}
		}
		if (k != i)
		{
			RedType temp = L.r[i];
			L.r[i] = L.r[k];
			L.r[k] = temp;
		}
	}
}
//堆排序
//堆的调整，调整成为大顶堆
void HeapAdjust1(int elem[], int s, int m)
{
	int rc = elem[s];
	int j;
	for (j = 2 * s; j <= m; j++)
	{
		if (j < m && elem[j] < elem[j + 1])
		{
			j++;
		}
		if (rc >= elem[j])
		{
			break;
		}
		elem[s] = elem[j];
		s = j;
	}
	elem[s] = rc;
}
//调整成小顶堆
void HeapAdjust2(int elem[], int s, int m)
{
	int rc = elem[s];
	int j;
	for (j = 2 * s; j <= m; j++)
	{
		if (j < m && elem[j] > elem[j + 1])
		{
			j++;
		}
		if (rc <= elem[j])
		{
			break;
		}
		elem[s] = elem[j];
		s = j;
	}
	elem[s] = rc;
}

int main()
{
	int arr[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int i;
	int n = sizeof(arr) / sizeof(arr[0]) - 1;
	for (i = n / 2; i >= 1; i-- )
	{
		HeapAdjust1(arr, i, n);
	}
	for (i = 1; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}