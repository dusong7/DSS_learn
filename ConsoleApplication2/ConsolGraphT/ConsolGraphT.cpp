// ConsolGraphT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

# define maxlen 10
# define large 999


typedef struct
{
	int a[maxlen], b[maxlen], h[maxlen];/*第K边的起点,终点,权值*/
	char vexs[maxlen];/*顶点信息集合*/
	int vexnum, arcnum;/*顶点数和边数*/
	int kind;/*图的类型*/
	int arcs[maxlen][maxlen];/*邻接矩阵*/
}graph;

graph printf_adjmatrix(graph g)/*输出邻接矩阵*/
{
	int i, j;
	printf("邻接矩阵:\n");
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

