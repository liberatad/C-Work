#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char VerTexType;
typedef int EdgeType;
//创建边的类型
typedef struct Edge
{
	int begin;
	int end;
	EdgeType weight;
}Edge;
//对边进行插入排序
void sort(Edge* edge, int maxedge)
{
	int i = 0;
	int j = 0;
	int min = 0;
	for (i = 0; i < maxedge - 1; i++)
	{
		min = i;
		Edge temp;
		for (j = i + 1; j < maxedge; j++)
		{
			if (edge[min].weight > edge[j].weight)
			{
				min = j;
			}
		}
		if (min != i)//下面进行交换
		{
			temp.begin = edge[i].begin;
			temp.end = edge[i].end;
			temp.weight = edge[i].weight;
			edge[i].begin = edge[min].begin;
			edge[i].end = edge[min].end;
			edge[i].weight = edge[min].weight;
			edge[min].begin = temp.begin;
			edge[min].end = temp.end;
			edge[min].weight = temp.weight;
		}
	}
}
int Find(int* parent, int i)
{
	while (parent[i] != 0)
	{
		i = parent[i];
	}
	return i;
}
//kruskal算法计算最小生成树
void MinSpanTree(int maxvex, int maxedge)
{
	int i = 0;
	int n = 0;
	int m = 0;
	Edge* edge = (Edge*)malloc(sizeof(Edge) * maxedge);//边集数组；
	int* parent = (int*)malloc(sizeof(int) * maxvex);//判断是否形成回路
	printf("输入边和权值：\n");
	for (i = 0; i < maxedge; i++)
	{
		scanf("%d,%d,%d", &edge[i].begin, &edge[i].end, &edge[i].weight);
	}
	sort(edge, maxedge);
	for (i = 0; i < maxvex; i++)
	{
		parent[i] = 0;
	}
	for (i = 0; i < maxedge; i++)
	{
		n = Find(parent, edge[i].begin);
		m = Find(parent, edge[i].end);
		if (n != m)
		{
			parent[n] = m;
			printf("(%d,%d)%d\n", edge[i].begin, edge[i].end, edge[i].weight);
		}

	}
}

int main()
{
	int maxedge;
	int maxvex;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d", &maxvex, &maxedge);
	MinSpanTree(maxvex, maxedge);
	return 0;
}