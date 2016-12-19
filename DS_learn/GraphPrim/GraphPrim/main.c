// ConsoleAPrim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//
//  main.c
//  GraphPrim
//
//  Created by apple on 16/12/18.
//  Copyright ? 2016年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define USED 0
#define NOADJ -1

// ConsoleGraph.cpp : Defines the entry point for the console application.
//

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
		scanf("%d,%d,%d", &start, &end, &weight);
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
		scanf("%c", &(g->Vertex[i]));
		//
	}
	//
	printf("Input 2 vertexs and weight\n");
	for (k = 0; k < g->EdgeNum; k++)
	{
		getchar();
		printf("%dth edge:\n ", k + 1);
		scanf("%c,%c,%d", &start, &end, &weight);
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
	for (i = 0; i < g->VertexNum; i++)
	{
		printf("%c", g->Vertex[i]);
		for (j = 0; j < g->VertexNum; j++)
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
	for (j = 0; j < g->VertexNum; j++)
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
	for (i = 0; i < g->VertexNum; i++)
	{
		g->isTrave[i] = 0;
	}

	printf("DFS Travese Nodes\n");
	for (i = 0; i < g->VertexNum; i++)
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


void Prim(MatrixGraph g)
{
	int i;
	int j;
	int k;
	int min;
	int sum = 0;
	int weight[VERTEX_MAX];
	char tmpvertex[VERTEX_MAX];

	for (i = 1; i<g.VertexNum; i++)
	{
		weight[i] = g.Edges[0][i];
		if (weight[i] == MAXVALUE)
		{
			tmpvertex[i] = NOADJ; //Non-Adj
		}
		else
		{
			tmpvertex[i] = g.Vertex[0]; //Adj-Points
		}
	}

	tmpvertex[0] = USED;
	weight[0] = MAXVALUE;
	for (i = 1; i<g.VertexNum; i++) {
		min = weight[0];
		k = i;
		for (j = 1; j<g.VertexNum; j++) {
			if (weight[j]<min && tmpvertex[j] != 0) {
				min = weight[j];
				k = j;
			}
		}
		sum += min;
		printf("(%c, %c)", tmpvertex[k], g.Vertex[k]);
		tmpvertex[k] = USED;
		weight[k] = MAXVALUE;
		for (j = 0; j<g.VertexNum; j++) {
			if (g.Edges[k][j] < weight[j] && tmpvertex[j] != 0) {
				weight[j] = g.Edges[k][j];
				tmpvertex[j] = g.Vertex[k];
			}
		}
		printf("temp generate Tree totla weight is %d\n", sum);
	}
	printf("Min generate Tree totla weight is %d\n", sum);
}

void Dijkstra(MatrixGraph g)
{
	//
	int tmpvertex[VERTEX_MAX];
	int weight[VERTEX_MAX];
	int path[VERTEX_MAX];
	int i;
	int j;
	int k;
	int v0; //Orig point
	int min;

	scanf_s("%d", &v0); //Tag 
	v0--; //start from 0

	for (i = 0; i<g.VertexNum; i++) //1 can make n->0 is NO Path
	{
		weight[i] = g.Edges[v0][i];
		if (weight[i] < MAXVALUE && weight[i]>0)
		{
			path[i] = v0;
		}
		tmpvertex[i] = 0;
	}
	tmpvertex[v0] = 1;
	weight[v0] = 0;
	for (i = 0; i < g.VertexNum ; i++)
	{
		min = MAXVALUE;
		k = v0;
		for (j = 0;j<g.VertexNum;j++)
		{
			if (tmpvertex[j] == 0 && weight[j]<min)
			{
				min = weight[j];
				k = j;
			}
		}
		tmpvertex[k] = 1;
		for ( j = 0; j < g.VertexNum; j++)
		{
			if (tmpvertex[j] ==0 && weight[k] + g.Edges[k][j]<weight[j])
			{
				weight[j] = weight[k] + g.Edges[k][j];
				path[j] = k;
			}
		}
	}
	printf("Vertex %c to each point: __\n", g.Vertex[v0]);
	for (i = 0; i < g.VertexNum; i++)
	{
		if (tmpvertex[i] == 1)
		{
			k = i;
			while (k != v0)
			{
				j = k;
				printf("%c < ", g.Vertex[k]);
				k = path[k];
			}
			printf("%c\n", g.Vertex[k]);
		}
		else
		{
			printf("%c <- %c: No path\n", g.Vertex[i], g.Vertex[v0]);
		}
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
	//DFSTravese(&G);
	Prim(G);
	Dijkstra(G);
	getchar();

	//    ListGraph glist;
	//    glist.VertexNum = 5;
	//    glist.EdgeNum = 6;
	//    glist.GraphType = 0;
	//    
	//    CreateListGraph(&glist);
	//    OutListGraph(&glist);
	return 0;
}
