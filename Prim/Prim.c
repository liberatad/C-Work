#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char VerTexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 33673//���������
int visited[MAXVEX];//�����Ƿ񱻷��ʹ�
typedef struct MGraph
{
	VerTexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes;
	int numEdges;
}MGraph;
//��������ͼ���ڽӾ���
void CreateMGraph(MGraph* G) {
	int i, j, k, w;
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	printf("���붥��ֵ���ַ�����\n");
	for (i = 0; i < G->numVertexes; i++) {//��ȡ������Ϣ����������� 
		getchar();	//�Ե��س� 
		scanf("%c", &G->vexs[i]);
	}
	for (i = 0; i < G->numVertexes; i++)
		for (j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = INFINITY;	//�ڽӾ����ʼ��
	for (k = 0; k < G->numEdges; k++) {	//��ȡnumEdges���ߣ������ڽӾ��� 
		printf("����ߣ�vi,vj���ϵ��±�i���±�j��Ȩw��\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];	//����ͼ���ڽӾ���������Խ��߶Գ� 
	}
}
//Prim�㷨������С������
void Prim(MGraph* G)
{
	int i = 0;
	int j = 0;
	int min;
	int k;
	int adjvex[MAXVEX];//������ض����±�
	int lowcost[MAXVEX];//������ض���֮���Ȩֵ
	lowcost[0] = 0;//��ʾv0�Ѿ�������������
	adjvex[0] = 0;//��ʼ����һ���±�Ϊ��
	for (i = 1; i < G->numVertexes; i++)
	{
		lowcost[i] = G->arc[0][i];//����v0��رߵ�Ȩֵ���뵽���鵱��
		adjvex[i] = 0;//��ʼ��ȫΪv0���±�
	}
	for (i = 1; i < G->numVertexes; i++)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		while (j < G->numVertexes)//ѭ��ȫ���Ķ���
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];//�ҵ���С��Ȩֵ
				k = j;//�ҵ���СȨֵ��Ӧ���±�
			}
			j++;
		}
		printf("(%d,%d)%d\n", adjvex[k], k, lowcost[k]);
		lowcost[k] = 0;//���˶���Ȩֵ����Ϊ�㣬��ʾ�Ѿ����ʹ�
		for (j = 1; j < G->numVertexes; j++)
		{
			if (lowcost[j] != 0 && G->arc[k][j] < lowcost[j])
			{
				//ÿ����һ�����㣬��Ҫ����lowcost���飬ʹ����С
				lowcost[j] = G->arc[k][j];
				adjvex[j] = k;//ÿ�μ�����Ϻ����Ҫ����adjvex���飻
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