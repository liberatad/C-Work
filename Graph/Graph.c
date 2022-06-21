#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//����ͼ�����ݽṹ
#define MVNUM 100//�������Ķ�����
#define MaxInt 32767//���������
typedef char VerTexType;//���������������
typedef int ArcType;//����ߵ���������
typedef int OtherInfo;
//ͼ����ʽ�洢�ṹ
//�ߵĽڵ�
typedef struct ArcNode
{
	int adjvex;//�ñ�ָ�򶥵��λ��
	struct ArcNode* nextarc;//ָ����һ���ߵ�λ��
	OtherInfo info;//�ͱߵ������Ϣ��һ��ָ�ߵ�Ȩ��
}ArcNode;
//����Ľڵ�ṹ
typedef struct VNode
{
	VerTexType data;//������Ϣ
	ArcNode* firstarc;//ָ���һ�������ڸö���ıߵ�ָ�룻
}VNode,AdjList[MVNUM];//AdjList v ���൱�� VNode v[MVNUM];
//ͼ�����ݽṹ
typedef struct
{
	AdjList vertices;//��������
	int vexnum;//������
	int arcnum;//�ߵ�����
}ALGraph;
//��������
typedef struct Queue
{
	int* data;
	int rear;
	int front;
}GQueue,*Queue;
//�����
void EnQueue(Queue Q, int v)
{
	Q->data[Q->rear] = v;
	Q->rear++;
}
//������
int DeQueue(Queue Q)
{
	int v = Q->data[Q->front];
	Q->front++;
	return v;
}
//�ж϶����Ƿ��
int IsEmpty(Queue Q)
{
	return Q->front == Q->rear;
}
//��������㷨
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
//����ͼ
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
	printf("�����붥�����\n");
	scanf("%d", &vexnum);
	printf("������ߵ���Ŀ\n");
	scanf("%d", &arcnum);
	G->vexnum = vexnum;
	G->arcnum = arcnum;
	int i = 0;
	//��ʼ�������
	for (i = 0; i < G->vexnum; i++)
	{
		VerTexType data;
		printf("�����붥����Ϣ\n");
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
		printf("��������߹����ĵ�һ������\n");
		scanf(" %c", &v1);
		printf("��������߹����ĵڶ�������\n");
		scanf(" %c", &v2);
		//scanf("������ߵ�Ȩ�أ�%d", &info);
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



//ͼ��˳��洢�ṹ
typedef struct
{
	VerTexType vexs[MVNUM];//�����
	ArcType arc[MVNUM][MVNUM];//�ڽӾ���
	int vexnum;//����ǰ������
	int arcnum;//����ǰ�ߵ���Ŀ
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
//����ͼ
void CreateUDN(AMGraph* G)
{
	//�����ܵĶ������ͱ���
	int vexnum = 0;
	int arcnum = 0;
	printf("�����붥����\n");
	scanf("%d", &vexnum);
	printf("���������\n");
	scanf("%d", &arcnum);
	G->vexnum = vexnum;
	G->arcnum = arcnum;
	//��ʼ���ڽӾ���
	int i = 0;
	for (i = 0; i < G->vexnum; i++)
	{
		VerTexType vex;
		printf("�����붥��ֵ\n");
		scanf(" %c", &vex);
		G->vexs[i] = vex;
	}
	//��ʼ���ߣ�������Ϊ���ֵ
	int j = 0;
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arc[i][j] = MaxInt;
		}
	}
	//����������������֮������
	int k = 0;
	for (k = 0; k < G->arcnum; k++)
	{
		VerTexType v1;
		VerTexType v2;
		ArcType w;
		printf("���������ߵĶ���1\n");
		scanf(" %c", &v1);
		printf("���������ߵĶ���2\n");
		scanf(" %c", &v2);
		printf("���������ߵ�Ȩ��\n");
		scanf("%d", &w);
		//������Ҫ�õ�������±�
		i = GetLocate(G, v1);
		j = GetLocate(G, v2);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
//������ȱ����㷨
//����v������ʼλ��
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