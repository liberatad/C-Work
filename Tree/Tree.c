#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//ʹ��˫�ױ�ʾ�������
typedef struct PTNode
{
	ElemType data;
	int parent;//˫�׵�λ����
}PTNode;
#define MAX_TREESIZE 100
//ʹ��˳�����д洢
typedef struct
{
	PTNode nodes[MAX_TREESIZE];
	int r;//���ڵ��λ��
	int n;//�ڵ�ĸ���
};
//ʹ�õ�����������ÿ����������ֵ�
//���ӽڵ�Ľṹ
typedef struct CTNode
{
	int child;//���˫�׵�λ��
	struct CTNode* next;//����¸��ڵ��ָ�룻
}*ChildPtr;
//˫�׽��ṹ
typedef char TElemType;
typedef struct
{
	TElemType data;
	ChildPtr firstchild;//���������ͷָ��
}CTBox;
//���ṹ
typedef struct
{
	CTBox nodes[MAX_TREESIZE];
	int r;
	int n;
}CTree;
int main()
{
	return 0;
}