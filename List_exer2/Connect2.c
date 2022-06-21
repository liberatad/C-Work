#define _CRT_SECURE_NO_WARNINGS
//ʹ��˳���ʵ�������������������������ӣ����Ӻ���Ȼ�ǵ���������
#include<stdio.h>
#include<stdlib.h>

typedef struct SqList
{
	int* elem;
	int length;
}SqList,*List;
//��˳����β�в���Ԫ��
void InsertSqList(List L, int x)
{
	L->length++;
	L->elem[L->length - 1] = x;
}
//ʵ�������ĺϲ�
void MergeList(List La, List Lb, List Lc)
{
	//����Lc���µ�˳���
	int* pa = La->elem;
	int* pb = Lb->elem;
	/*Lc->elem = (int*)malloc(sizeof(int) * ((La->length) + (Lb->length)));
	Lc->length = La->*//*length + Lb->length;*/
	//���ϵĴ���Ӧ������������ִ��
	int* pc = Lc->elem;
	int* pa_last = pa + La->length - 1;
	int* pb_last = pb + Lb->length - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}
}

int main()
{
	//����˳���
	List L1 = (List)malloc(sizeof(SqList));
	L1->elem = (int*)malloc(sizeof(int) * 5);
	L1->length = 0;
	List L2 = (List)malloc(sizeof(SqList));
	L2->elem = (int*)malloc(sizeof(int) * 5);
	L2->length = 0;
	int arr1[5] = { 1,3,5,7,9 };
	int arr2[5] = { 2,4,6,8,10 };
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		InsertSqList(L1, arr1[i]);
	}
	for (i = 0; i < 5; i++)
	{
		InsertSqList(L2, arr2[i]);
	}
	List L = (List)malloc(sizeof(SqList));
	L->elem = (int*)malloc(sizeof(int) * ((L1->length) + (L2->length)));
	L->length = L1->length + L2->length;
	MergeList(L1, L2, L);
	for (i = 0; i < L->length; i++)
	{
		printf("%d\n", L->elem[i]);
	}
	/*InsertSqList(L1, 1);
	printf("%d\n", L1->elem[L1->length - 1]);*/
	return 0;
}
