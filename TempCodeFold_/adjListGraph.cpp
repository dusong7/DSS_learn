// ConsoleGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
#define VERTEX_MAX 26
#define MAXVALUE 32767
///Adjax matrix
typedef struct {
	char Vertex[VERTEX_MAX];
	int Edges[VERTEX_MAX][VERTEX_MAX];
	int isTrave[VERTEX_MAX];
	int VertexNum;
	int EdgeNum;
	int Graphtype;
}MatrixGraph;

//Adjax list
typedef struct edgeNode 
{
	int Vertex;
	int weigth;
	struct edgeNode *next;
}EdgeNode;

typedef struct 
{
	EdgeNode* AdjList[MAXVALUE];
	int VertexNum, EdgeNum;
	int GraphType;
}ListGraph;

void CreateListGraph(ListGraph *g)
{
	//
	int i;
	int weight;
	int start, end;
	EdgeNode *enode;
	for (size_t i = 1; i <= g->VertexNum; i++)
	{
		g->AdjList[i] = NULL;
	}
	for (size_t i = 1; i <= g->EdgeNum; i++)
	{
		printf("%dth edges", i);
		scanf_s("%d,%d,%d", &start, &end, &weight);
		enode = (EdgeNode*)malloc(sizeof(EdgeNode));
		enode->next = g->AdjList[start];
		enode->Vertex = end;
		enode->weigth = weight;
		g->AdjList[start] = enode;

		if (g->GraphType == 0)
		{
			enode = (EdgeNode*)malloc(sizeof(EdgeNode));
			enode->next = g->AdjList[end];
			enode->Vertex = start;
			enode->weigth = weight;
			g->AdjList[end] = enode;
		}

	}


}

void OutListGraph(ListGraph *g)
{
	//
	int i;
	EdgeNode *s;
	for (size_t i = 1; i <= g->VertexNum; i++)
	{
		printf("Vertex %d :", i);
		s = g->AdjList[i];
		while (s)
		{
			//printf("%x__", &s);
			printf("-->%d(%d) ", s->Vertex, s->weigth);
			s = s->next;
		}
		printf("\n");
	}
}


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
				printf("\t$");
			}
			else
			{
				printf("\t%d", g->Edges[i][j]);
			}
		}
		printf("\n");
	}
}

void DFSM(MatrixGraph *g, int i)
{
	int j;
	if (g->isTrave[i] == 1)
	{
		return;
	}
	printf("-->%d", i);
	g->isTrave[i] = 1;
	//printf("->%c", g->Vertex[i]);
	for ( j = 0; j < g->VertexNum; j++)
	{
		if (g->Edges[i][j] != MAXVALUE && g->isTrave[j] != 1)
		{
			//printf("g(%d,%d)", i, j);
			g->isTrave[j] = 1;
			DFSM(g, j);
		}
	}
}

void DFSTravese(MatrixGraph *g)
{
	int i;
	for ( i = 0; i < g->VertexNum; i++)
	{
		g->isTrave[i] = 0;
	}
	
	printf("DFS Travese Nodes\n");
	for ( i = 0; i < g->VertexNum; i++)
	{
		if (!g->isTrave[i])
		{
			DFSM(g, i);
		}
	}
	printf("\n");
}

void DFSSearch(MatrixGraph *g, int n)
{
	//
}

int main()
{
	/*MatrixGraph G;
	G.Graphtype = 1;
	G.VertexNum = 5;
	G.EdgeNum = 3;

	for (size_t i = 0; i < G.VertexNum; i++)
	{
		for (size_t j = 0; j < G.VertexNum; j++)
		{
			G.Edges[i][j] = MAXVALUE;
		}
	}

	CreateMatrixGraph(&G);
	OutGraph(&G);
	DFSTravese(&G);
	getchar();*/

	ListGraph glist;
	glist.VertexNum = 5;
	glist.EdgeNum = 6;
	glist.GraphType = 0;

	CreateListGraph(&glist);
	OutListGraph(&glist);
	return 0;
}
