#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode* List;//�����ڵ��ָ��
struct LNode
{
	int Data[100];//��ʾ���Ա���������
	int Last;//ָ���������һ��Ԫ�أ�
};
//��ʼ�����Ա�
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}
//�����Ա��в���Ԫ�أ�
int Find(List L, int x)
{
	int i = 0;
	while (i <= L->Last && x != L->Data[i])
	{
		i++;
	}
	if (i > L->Last)
	{
		return -1;//��ʾδ�ҵ�
	}
	else
	{
		return i;//�����ҵ���λ�ã�
	}
}
//�����Ա��в���Ԫ��
//x��ʾҪ�����Ԫ�أ�index��ʾ��Ҫ�����λ��
int Insert(List L, int x, int index)
{
	int i = 0;
	if (L->Last == 99)
	{
		printf("��ռ��Ѿ������޷�����\n");
		return 0;
	}
	if (index < 0 || index > L->Last + 1)
	{
		printf("����λ�ò��Ϸ�\n");
		return 0;
	}
	for (i = L->Last; i >= index; i--)
	{
		L->Data[i + 1] = L->Data[i];//��index��ʼ��Ԫ���������ƶ���ע���ǴӺ���ǰ��
	}
	L->Data[index] = x;//��indexλ��Ԫ�ظ�ֵΪx;
	L->Last++;//ָ������һ��Ԫ�����ӣ�
	return 1;
}
//�����Ա���ɾ��Ԫ��
int Delete(List L, int index)//index��ʾҪɾ��Ԫ�ص�λ��
{
	int i = 0;
	if (index < 0 || index > L->Last)
	{
		printf("ɾ��%d��λ�ò�����\n", index);
		return 0;
	}
	for (i = index + 1; i <= L->Last; i++)
	{
		L->Data[i - 1] = L->Data[i];
	}
	L->Last--;//ָ������һ��Ԫ�ؼ���1��
	return 1;
}
int main()
{
	return 0;
}







