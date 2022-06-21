#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//创建图的数据结构
#define MVNUM 100//代表最大的顶点数
#define MaxInt 32767//代表无穷大；
typedef char VerTexType;//代表顶点的数据类型
typedef int ArcType;//代表边的数据类型

//图的顺序存储结构
typedef struct
{
	VerTexType vexs[MVNUM];//顶点表
	ArcType arc[MVNUM][MVNUM];//邻接矩阵
	int vexnum;//代表当前顶点数
	int arcnum;//代表当前边的数目
}AMGraph;
int GetLocate(AMGraph* G, VerTexType v)
{
	int i = 0;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->vexs[i] == v)
		{
			return i;
		}
	}
	return -1;
}
//创建图
void CreateUDN(AMGraph* G)
{
	//输入总的顶点数和边数
	int vexnum = 0;
	int arcnum = 0;
	printf("请输入顶点数\n");
	scanf("%d", &vexnum);
	printf("请输入边数\n");
	scanf("%d", &arcnum);
	G->vexnum = vexnum;
	G->arcnum = arcnum;
	//初始化邻接矩阵
	int i = 0;
	for (i = 0; i < G->vexnum; i++)
	{
		VerTexType vex;
		printf("请输入顶点值\n");
		scanf(" %c", &vex);
		G->vexs[i] = vex;
		//printf("%c\n",G->vexs[i]);
	}
	//初始化边，都设置为最大值
	int j = 0;
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arc[i][j] = MaxInt;
		}
	}
	//接下来在两个顶点之间插入边
	int k = 0;
	for (k = 0; k < G->arcnum; k++)
	{
		VerTexType v1;
		VerTexType v2;
		ArcType w;
		printf("请输入插入边的顶点1\n");
		scanf("%c%*c", &v1);
		printf("请输入插入边的顶点2\n");
		scanf("%c%*c", &v2);
		printf("请输入插入边的权重\n");
		scanf("%d", &w);
		//下面需要得到顶点的下标
		i = GetLocate(G, v1);
		j = GetLocate(G, v2);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
int main()
{
	AMGraph* G = (AMGraph*)malloc(sizeof(AMGraph));
	CreateUDN(G);
	return 0;
}