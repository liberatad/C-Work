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
//���Ա��˳��洢�ṹ�ı�ʾ
//1.����ʽ
//#define MAX_SIZE 100
//typedef struct
//{
//	float p;//ϵ��
//	int e;//ָ����
//}Polynomia;
//typedef struct
//{
//	Polynomia* elem;//�׵�ַ��
//	int length;//����ʽ�����ݸ�����
//}SqList;//˳��洢����������
//������������
typedef struct
{
	ElemType* elem;//��̬�������飬�����׵�ַ
	int length;//�������鳤��
}SqList;
typedef SqList* List;//��SqList���͵�˳����ָ���������������������
//��ʼ��˳���
Status InitList(List L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);//��ʼ�����飬�������׵�ַ
	if (!L->elem)
	{
		exit(OVERFLOW);//�쳣��������-2;
	}
	L->length = 0;//��ʼ������Ϊ�㣻
	return OK;
}
//ɾ����
void DestroyList(List L)
{
	if (L->elem)
	{
		free(L->elem);//�ͷ��ڴ�ռ䣻
	}
}
//��ձ�
void ClearList(List L)
{
	L->length = 0;
}
//���س���
int GetLength(List L)
{
	return L->length;
}
//�ж�˳����Ƿ�Ϊ��
int IsEmty(List L)
{
	if (L->length == 0)
	{
		return 1;//����Ϊ�㣬˵��˳�����Ϊ�գ�
	}
	return 0;
}
//���ص�i��Ԫ�ص�ֵ
int GetElem(List L, int i)
{
	if (i < 1 || i > L->length)
	{
		return ERROR;
	}
	return L->elem[i - 1];
}
//��ֵ����
int LocateElem(List L, ElemType e)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		if (L->elem[i] == e)
		{
			return i + 1;//���ﷵ�ص��Ǿ����λ�ã�
		}
	}
	//�����������㷨��
	//while (i < L->length && L->elem[i] != e)
	//{
	//	i++;
	//}
	//if (i < L->length)
	//{
	//	return i + 1;
	//}
	//return 0;
	return 0;//����ʧ�ܣ�����0;
}
//�ڵ�i��λ�ò���Ԫ��e
Status InsertList(List L, int i, ElemType e)
{
	if (i < 1 || i > L->length + 1)
	{
		printf("����λ�÷Ƿ�\n");
		return ERROR;
	}
	if (L->length == MAX_SIZE)
	{
		printf("�������޷�����\n");
		return ERROR;
	}
	int j = 0;
	for (j = L->length - 1; j >= i - 1; j++)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	L->length++;//��ĳ�������1;
	return OK;
}
//ɾ��ָ��λ��i��Ԫ��
Status DeleteList(List L, int i)
{
	if (i < 1 || i > L->length)
	{
		printf("ɾ��λ�ò��Ϸ�\n");
		return ERROR;
	}
	int j = 0;
	for (j = i; j <= L->length - 1; j++)
	{
		L->elem[j - 1] = L->elem[j];//�ӵ�i����ʼÿ��Ԫ����ǰ�ƣ�
	}
	L->length--;
	return OK;
}




int main()
{
	return 0;
}