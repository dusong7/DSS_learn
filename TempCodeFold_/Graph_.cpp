#define VERTUX_MAX 26
#define MAXVALUE 32767
typedef struct
{
  char VERTEX[VERTUX_MAX];   //Weight value
  int  Edges[VERTUX_MAX][VERTUX_MAX]; //
  int  isTravel[VERTUX_MAX];  // 
  int  VertexNum;
  int  EdgeNum;  
  int  GraphType;   //0 is undirected, 1 is directed
}MatrixGraph;

void CreateMatrix(MatrixGraph *G);  //Generate adjacancy matrix
void OutMatrix(MatrixGraph *G);     //Out adjacency matrixint

int number[][]={1,2,3,4}
int (*num)[2]=(int(*)[2])malloc(sizeof(int)*2*2);
for(int i=0;i<2;i++)
{
  for(int j=0;j<2;j++)
  {
    num[i][j] = number[i][j];
  }
}


struct Table
	{
		int num;
		bool isTre;
	};

	int TNumber = 0;
	int randTable[] = { 10, 4, 8, 9, 9, 4, 7, 6, 1, 9, 1, 1, 8, 10, 10, 3, 2, 5, 4, 6, 6, 5, 7, 7, 4, 3, 10, 9, 4, 5, 2, 3, 8, 4, 3, 3, 3, 6, 5, 1, 10, 9, 6, 7, 5, 3, 2};
	Table tb[10];

	for (size_t i = 0; i < 10; i++)
	{
		tb[i].isTre = false;
	}
	for (size_t i = 0; i < 47; i++)
	{
		//printf("% d#", i);
		if (!tb[randTable[i]-1].isTre)
		{
			tb[randTable[i]-1].isTre = true;
			TNumber++;
			printf("%d_hit\t", randTable[i]);
		}
		if (TNumber == 10)
		{
			printf("%dth_Val %d\n", i+1, randTable[i]);
			//break;
		}
	}


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
		if (g->Edges[i][j] != MAXVALUE)
		{
			printf("g(%d,%d)", i, j);
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
	MatrixGraph G;
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
	getchar();

	return 0;
}
