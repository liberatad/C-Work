#define _CRT_SECURE_NO_WARNINGS
//�������������Ľڵ�,����ʹ��˳��洢
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct HuNode
{
	int weight;
	int parent;
	int lch;
	int rch;
}HuNode,*HuffmanTree;
//��ʼ����������
//����n�����м����ڵ�
//#define MAX = 1000
void Select(HuffmanTree HT, int n, int* s1, int* s2)
{
	int weight1 = 1000;
	int i = 0;
	for (i = 1; i <= n - 1; i++)
	{
		if (HT[i].parent == 0 && weight1 >= HT[i].weight)
		{
			*s1 = i;
			weight1 = HT[i].weight;
		}
	}
	int weight2 = 1000;
	for (i = 1; i <= n - 1; i++)
	{
		if (HT[i].parent == 0 && HT[i].weight <= weight2 && weight2 >= HT[*s1].weight && i != *s1)
		{
			weight2 = HT[i].weight;
			*s2 = i;
		}
	}

}
void CreateHuffmanTree(HuffmanTree HT, int n, int arr[])
{
	int m = 2 * n - 1;
	//HT = (HuffmanTree)malloc(sizeof(HuNode) * (m + 1));//��ʼ����СΪ2n
	int i = 0;
	for (i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].lch = 0;
		HT[i].rch = 0;
	}
	for (i = 1; i <= n; i++)
	{
		HT[i].weight = arr[i - 1];
	}
	//�ڽ���������㷨֮ǰ����дһ��Select����ʵ��ѡ��parent = 0��weightǰ���������ݣ�����
	for (i = n + 1; i <= m; i++)
	{
		int* s1 = malloc(sizeof(int));
		int* s2 = malloc(sizeof(int));
		Select(HT, i , s1, s2);
		/*printf("%d\n", *s1);
		printf("%d\n", *s2);
		printf("******************\n");*/
		HT[*s1].parent = i;
		HT[*s2].parent = i;
		HT[i].lch = *s1;
		HT[i].rch = *s2;
		HT[i].weight = HT[*s1].weight + HT[*s2].weight;
	}
}
//��ӡ���������ĸ��е�ֵ
void ShowHuffmanTree(HuffmanTree HT, int n)
{
	int m = 2 * n - 1;
	int i = 1;
	for (i = 1; i <= m; i++)
	{
		printf("%d  %d  %d  %d  \n", HT[i].parent, HT[i].weight, HT[i].lch, HT[i].rch);
	}
}
//����ʵ�ֹ�����������㷨
typedef char* CodeType;
void CreateHuffmanCode(HuffmanTree HT, CodeType* HC, int n)
{
	char* cd = (char*)malloc(sizeof(char) * n);//������ʱ��ű���Ķ�̬���飻
	cd[n - 1] = '\0';//�ַ����Ľ�����־
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		//һ��ѭ���Ϳ����ҵ�һ�����Ĺ��������룻
		while (f)
		{
			start--;
			if (HT[f].lch == c)
			{
				cd[start] = '0';
			}
			else if (HT[f].rch == c)
			{
				cd[start] = '1';
			}
			c = f;
			f = HT[f].parent;//���ݵĹ��̣�
		}
		HC[i] = (char*)malloc(sizeof(char) * (n - start));//��̬����ÿһ��������������ڴ棻
		strcpy(HC[i], &cd[start]);
	}
	free(cd);//�ͷ���ʱ�������ڴ棻
}
void ShowHuffmanCode(CodeType* HC, int n)
{
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		printf("%s\n", HC[i]);
	}
}
int main()
{
	HuffmanTree HT = (HuffmanTree)malloc(sizeof(HuNode) * 16);
	int arr[] = { 5,29,7,8,14,23,3,11 };
	CreateHuffmanTree(HT, 8, arr);
	ShowHuffmanTree(HT, 8);
	printf("**************\n");
	CodeType* HC = malloc(sizeof(CodeType) * 9);//���ڴ���ַ������׵�ֵַ�����飻���е�0��λ�ò�ʹ�ã�
	CreateHuffmanCode(HT, HC, 8);
	ShowHuffmanCode(HC, 8);
	//printf("%d\n", HT[11].weight);
	return 0;
}