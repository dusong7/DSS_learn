// ConsolGraphT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

# define maxlen 10
# define large 999


typedef struct
{
	int a[maxlen], b[maxlen], h[maxlen];/*��K�ߵ����,�յ�,Ȩֵ*/
	char vexs[maxlen];/*������Ϣ����*/
	int vexnum, arcnum;/*�������ͱ���*/
	int kind;/*ͼ������*/
	int arcs[maxlen][maxlen];/*�ڽӾ���*/
}graph;

graph printf_adjmatrix(graph g)/*����ڽӾ���*/
{
	int i, j;
	printf("�ڽӾ���:\n");
	printf("vertex\t");
	for (i = 0; i<g.vexnum; i++) printf("%4c", g.vexs[i]);
	printf("\n");
	for (i = 0; i<g.vexnum; i++)
	{
		printf("% 4c \t", g.vexs[i]);
		for (j = 0; j<g.vexnum; j++) printf("%4d", g.arcs[i][j]);
		printf("\n");
	}
	return g;
}

void create_2(graph g)
{
	int i, j, k, c = 0;
	for (i = 0; i<g.vexnum; i++)
		for (j = 0; j<g.vexnum; j++)
			g.arcs[i][j] = c;
	for (k = 0; k<g.arcnum; k++)
	{
		g.arcs[g.a[k] - 1][g.b[k] - 1] = 1;
		g.arcs[g.b[k] - 1][g.a[k] - 1] = 1;
	}
	//printf_adjmatrix(g);

}

int main()
{
	//
    return 0;
}

