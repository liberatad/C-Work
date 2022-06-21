#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//����ͼ�����ݽṹ
#define MVNUM 100//�������Ķ�����
#define MaxInt 32767//���������
typedef char VerTexType;//���������������
typedef int ArcType;//����ߵ���������

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
		//printf("%c\n",G->vexs[i]);
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
		scanf("%c%*c", &v1);
		printf("���������ߵĶ���2\n");
		scanf("%c%*c", &v2);
		printf("���������ߵ�Ȩ��\n");
		scanf("%d", &w);
		//������Ҫ�õ�������±�
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