#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//使用双亲表示法存放树
typedef struct PTNode
{
	ElemType data;
	int parent;//双亲的位置域
}PTNode;
#define MAX_TREESIZE 100
//使用顺序表进行存储
typedef struct
{
	PTNode nodes[MAX_TREESIZE];
	int r;//根节点的位置
	int n;//节点的个数
};
//使用单链表存放树，每个链表代表兄弟
//孩子节点的结构
typedef struct CTNode
{
	int child;//存放双亲的位置
	struct CTNode* next;//存放下个节点的指针；
}*ChildPtr;
//双亲结点结构
typedef char TElemType;
typedef struct
{
	TElemType data;
	ChildPtr firstchild;//孩子链表的头指针
}CTBox;
//树结构
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