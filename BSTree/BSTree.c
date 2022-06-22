#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//typedef char OtherType;//
//�ڵ�����
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode,*BSTree;
//�����������Ĺ���
void CreateBSTree(int data, BSTree T)
{
	if (T == NULL)
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = data;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else if (data > T->data)
	{
		CreateBSTree(data, T->rchild);
	}
	else
	{
		CreateBSTree(data, T->lchild);
	}
}
//�����������Ĳ����㷨
BSTree SearchBST(BSTree T, ElemType data)
{
	if (!T || T->data == data)
	{
		return T;
	}
	else if (data < T->data)
	{
		return SearchBST(T->lchild ,data);
	}
	else
	{
		return SearchBST(T->rchild, data);
	}
}
//�����������Ĳ������
void Insert(BSTree T, int data)
{
	//���жϸýڵ��Ƿ����
	BSTNode* K = T;//ָ��ǰ�ڵ�
	BSTNode* Pre;//ָ��ǰ�ڵ��ǰ���ڵ�
	while (K != NULL && K->data != data)
	{
		if (data > K->data)
		{
			Pre = K;
			K = K->rchild;
		}
		else
		{
			Pre = K;
			K = K->lchild;
		}
	}
	if (K == NULL)
	{
		printf("�ýڵ��Ѿ�����\n");
		return;
	}
	else
	{
		BSTNode* P = (BSTNode*)malloc(sizeof(BSTNode));
		P->data = data;
		if (P->data > Pre->data)
		{
			Pre->rchild = P;
			P->lchild = NULL;
			P->rchild = NULL;
		}
		else
		{
			Pre->lchild = P;
			P->lchild = NULL;
			P->rchild = NULL;
		}
	}
}

int main()
{
	return 0;
}