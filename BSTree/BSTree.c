#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//typedef char OtherType;//
//节点类型
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode,*BSTree;
//二叉排序树的构建
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
//二叉排序树的查找算法
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
//二叉排序树的插入操作
void Insert(BSTree T, int data)
{
	//先判断该节点是否存在
	BSTNode* K = T;//指向当前节点
	BSTNode* Pre;//指向当前节点的前驱节点
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
		printf("该节点已经存在\n");
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