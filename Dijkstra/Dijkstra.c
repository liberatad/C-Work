#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char VerTexType;
typedef int EdgeType;
#define MAXSIZE 100
#define INFINITY 35565
typedef struct
{
	VerTexType vers[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int numVertexes;
	int numEdges;
}MGraph;
void CreateMGraph(MGraph* G)
{
	int i = 0;
	int j = 0;
	int w = 0;
	int k = 0;
	printf("�����붥�����ͱ�����\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; i++)
	{
		printf("�����붥����Ϣ��\n");
		scanf(" %c", &G->vers[i]);
	}
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	for (k = 0; k < G->numEdges; k++)
	{
		printf("�������(vi, vj)���ϱ�vi���±�vj��Ȩw��\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
//Dijkstra�㷨
#define MAXVEX 20
typedef int Patharc[MAXVEX];//�洢���·���±�
typedef int ShortPathTable[MAXVEX];//�洢���·��֮��
void Dijkstra(MGraph* G, int v0, Patharc P, ShortPathTable D)
{
	int v, w, k, min;
	int final[MAXVEX];//final[k] = 1��ʾ�Ѿ�������·��
	for (v = 0; v < G->numVertexes; v++)
	{
		final[v] = 0;
		P[v] = 0;
		D[v] = G->arc[v0][v];
	}
	D[v0] = 0;
	final[v0] = 1;
	//���v0��ĳ���������·��
	for (v = 1; v < G->numVertexes; v++)
	{
		min = INFINITY;
		for (w = 0; w < G->numVertexes; w++)
		{
			if (!final[w] && D[w] < min)
			{
				k = w;//�ҵ���С�߶�Ӧ���±�
				min = D[w];
			}
		}
		final[k] = 1;
		//�޸����·��������
		for (w = 0; w < G->numVertexes; w++)
		{
			if (!final[w] && (min + G->arc[k][w]) < D[w])
			{
				D[w] = min + G->arc[k][w];
				P[w] = k;
			}
		}
	}
}



int main()
{
	MGraph* G = (MGraph*)malloc(sizeof(MGraph));
	CreateMGraph(G);
	Patharc P;
	ShortPathTable D;
	Dijkstra(G, 0, P, D);
	int i = 0;
	for (i = 0; i < G->numVertexes; i++)
	{
		printf("%d\n", D[i]);
	}
	return 0;
}