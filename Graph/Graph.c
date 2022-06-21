#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//创建图的数据结构
#define MVNUM 100//代表最大的顶点数
#define MaxInt 32767//代表无穷大；
typedef char VerTexType;//代表顶点的数据类型
typedef int ArcType;//代表边的数据类型
typedef int OtherInfo;
//图的链式存储结构
//边的节点
typedef struct ArcNode
{
	int adjvex;//该边指向顶点的位置
	struct ArcNode* nextarc;//指向下一条边的位置
	OtherInfo info;//和边的相关信息，一般指边的权重
}ArcNode;
//顶点的节点结构
typedef struct VNode
{
	VerTexType data;//顶点信息
	ArcNode* firstarc;//指向第一条依附于该顶点的边的指针；
}VNode,AdjList[MVNUM];//AdjList v 则相当于 VNode v[MVNUM];
//图的数据结构
typedef struct
{
	AdjList vertices;//顶点数组
	int vexnum;//顶点数
	int arcnum;//边的条数
}ALGraph;
//创建队列
typedef struct Queue
{
	int* data;
	int rear;
	int front;
}GQueue,*Queue;
//入队列
void EnQueue(Queue Q, int v)
{
	Q->data[Q->rear] = v;
	Q->rear++;
}
//出队列
int DeQueue(Queue Q)
{
	int v = Q->data[Q->front];
	Q->front++;
	return v;
}
//判断队列是否空
int IsEmpty(Queue Q)
{
	return Q->front == Q->rear;
}
//广度优先算法
void BFS(ALGraph* G, Queue Q, int v, int visited[])
{
	printf("%c->", G->vertices[v].data);
	visited[v] = 1;
	EnQueue(Q, v);
	while (!IsEmpty(Q))
	{
		int u = DeQueue(Q);
		ArcNode* p = G->vertices[u].firstarc;
		while (p != NULL)
		{
			if (!visited[p->adjvex])
			{
				printf("%c->", G->vertices[p->adjvex].data);
				visited[p->adjvex] = 1;
				EnQueue(Q, p->adjvex);
			}
			p = p->nextarc;
		}
	}
}
//创建图
int LocateVex(ALGraph* G, VerTexType v)
{
	int i = 0;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->vertices[i].data == v)
		{
			return i;
		}
	}
	return -1;
}
void CreateUDG(ALGraph* G)
{
	int vexnum = 0;
	int arcnum = 0;
	printf("请输入顶点个数\n");
	scanf("%d", &vexnum);
	printf("请输入边的数目\n");
	scanf("%d", &arcnum);
	G->vexnum = vexnum;
	G->arcnum = arcnum;
	int i = 0;
	//初始化顶点表
	for (i = 0; i < G->vexnum; i++)
	{
		VerTexType data;
		printf("请输入顶点信息\n");
		scanf(" %c", &data);
		G->vertices[i].data = data;
		G->vertices[i].firstarc = NULL;
	}
	int j = 0;
	int k = 0;
	for (k = 0; k < G->arcnum; k++)
	{
		VerTexType v1;
		VerTexType v2;
		//OtherInfo info;
		printf("请输入与边关联的第一个顶点\n");
		scanf(" %c", &v1);
		printf("请输入与边关联的第二个顶点\n");
		scanf(" %c", &v2);
		//scanf("请输入边的权重：%d", &info);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		ArcNode* p1 = malloc(sizeof(ArcNode));
		//p1->info = info;
		p1->adjvex = j;
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;
		ArcNode* p2 = malloc(sizeof(ArcNode));
		//p2->info = info;
		p2->adjvex = i;
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2;
	}
}



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
		scanf(" %c", &v1);
		printf("请输入插入边的顶点2\n");
		scanf(" %c", &v2);
		printf("请输入插入边的权重\n");
		scanf("%d", &w);
		//下面需要得到顶点的下标
		i = GetLocate(G, v1);
		j = GetLocate(G, v2);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
//深度优先遍历算法
//其中v代表起始位置
void DFS(AMGraph* G, int v, int visited[])
{
	printf("%c->", G->vexs[v]);
	visited[v] = 1;
	int w = 0;
	for (w = 0; w < G->vexnum; w++)
	{
		if ((G->arc[v][w] != MaxInt) && !visited[w])
		{
			DFS(G, w, visited);
		}
	}
}


int main()
{
	//AMGraph* MG = (AMGraph*)malloc(sizeof(AMGraph));
	ALGraph* LG = (ALGraph*)malloc(sizeof(ALGraph));
	//CreateUDN(MG);
	//int visited[6] = { 0 };
	//printf("**********************\n");
	//DFS(MG, 1, visited);
	CreateUDG(LG);
	Queue Q = (Queue)malloc(sizeof(GQueue));
	Q->data = (int*)malloc(sizeof(int) * 10);
	Q->front = 0;
	Q->rear = 0;
	int visited[8] = { 0 };
	BFS(LG, Q, 0, visited);
	return 0;
}