// ConsoleGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define VERTEX_MAX 26
#define MAXVALUE 32767
typedef struct {
	char Vertex[VERTEX_MAX];
	int Edges[VERTEX_MAX][VERTEX_MAX];
	int isTrave[VERTEX_MAX];
	int VertexNum;
	int EdgeNum;
	int Graphtype;
}MatrixGraph;

void CreateMatrixGraph(MatrixGraph *g)
{
	//
	int i, j, k, weight;
	char start;
	char end;
	printf("Input peak info\n");
	//Input vertex info
	for (i = 0; i < g->VertexNum; i++)
	{
		getchar();
		printf("Input %d\n", i + 1);
		scanf_s("%c", &(g->Vertex[i]));
		//
	}
	//
	printf("Input 2 vertexs and weight\n");
	for (k = 0; k < g->EdgeNum; k++)
	{
		getchar();
		printf("%dth edge:\n ", k + 1);
		scanf_s("%c,%c,%d",&start,1, &end,1,&weight);
		for (i = 0; start != g->Vertex[i]; i++);
		for (j = 0; end != g->Vertex[j]; j++);
		g->Edges[i][j] = weight;
		if (g->Graphtype == 0)
		{
			g->Edges[j][i] = weight;
		}
	}
}

void OutGraph(MatrixGraph *g)
{
	//
	int i, j;
	for (j = 0; j < g->VertexNum; j++)
		printf("\t%c", g->Vertex[j]);
	printf("\n");
	for ( i = 0; i < g->VertexNum; i++)
	{
		printf("%c", g->Vertex[i]);
		for ( j = 0; j < g->VertexNum; j++)
		{
			if (g->Edges[i][j] == MAXVALUE)
			{
				printf("\t#");
			}
			else
			{
				printf("\t%d", g->Edges[i][j]);
			}
		}
		printf("\n");
	}
}

int main()
{
	MatrixGraph G;
	G.Graphtype = 0;
	G.VertexNum = 5;
	G.EdgeNum = 6;

	for (size_t i = 0; i < G.VertexNum; i++)
	{
		for (size_t j = 0; j < G.VertexNum; j++)
		{
			G.Edges[i][j] = MAXVALUE;
		}
	}

	CreateMatrixGraph(&G);
	OutGraph(&G);
	getchar();

	return 0;
}

