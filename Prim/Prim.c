#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char VerTexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 33673//代表无穷大
int visited[MAXVEX];//代表是否被访问过
typedef struct MGraph
{
	VerTexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes;
	int numEdges;
}MGraph;
//建立无向图的邻接矩阵
void CreateMGraph(MGraph* G) {
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	printf("输入顶点值（字符）：\n");
	for (i = 0; i < G->numVertexes; i++) {//读取顶点信息，建立顶点表 
		getchar();	//吃掉回车 
		scanf("%c", &G->vexs[i]);
	}
	for (i = 0; i < G->numVertexes; i++)
		for (j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = INFINITY;	//邻接矩阵初始化
	for (k = 0; k < G->numEdges; k++) {	//读取numEdges条边，建立邻接矩阵 
		printf("输入边（vi,vj）上的下标i，下标j和权w：\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];	//无向图的邻接矩阵关于主对角线对称 
	}
}
//Prim算法计算最小生成树
void Prim(MGraph* G)
{
	int i = 0;
	int j = 0;
	int min;
	int k;
	int adjvex[MAXVEX];//保存相关顶点下标
	int lowcost[MAXVEX];//保留相关顶点之间的权值
	lowcost[0] = 0;//表示v0已经加入生成树，
	adjvex[0] = 0;//初始化第一个下标为零
	for (i = 1; i < G->numVertexes; i++)
	{
		lowcost[i] = G->arc[0][i];//将与v0相关边的权值加入到数组当中
		adjvex[i] = 0;//初始化全为v0的下标
	}
	for (i = 1; i < G->numVertexes; i++)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		while (j < G->numVertexes)//循环全部的顶点
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];//找到最小的权值
				k = j;//找到最小权值对应的下标
			}
			j++;
		}
		printf("(%d,%d)%d\n", adjvex[k], k, lowcost[k]);
		lowcost[k] = 0;//将此顶点权值设置为零，表示已经访问过
		for (j = 1; j < G->numVertexes; j++)
		{
			if (lowcost[j] != 0 && G->arc[k][j] < lowcost[j])
			{
				//每加入一个顶点，需要更新lowcost数组，使其最小
				lowcost[j] = G->arc[k][j];
				adjvex[j] = k;//每次加入完毕后均需要更新adjvex数组；
			}
		}
	}
}




int main()
{
	MGraph* G = (MGraph*)malloc(sizeof(MGraph));
	CreateMGraph(G);
	Prim(G);
	return 0;
}