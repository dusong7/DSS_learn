#include "stdafx.h"
#include "graph.h"
#include <stdlib.h>
#include <assert.h>


struct graph {
	int n;                                             /* number of vertices */
	int m;                                             /* number of edges */
	struct successors {
		int d;                                         /* number of successors */
		int len;                                       /* number of slots in array */
		char is_sorted;                                /* true if list is already sorted */
		int list[1];
		/* actual list of successors */
	} *alist[1];
};


Graph graph_create(int n)
{
	Graph g;
	int i;

	g = (Graph)malloc(sizeof(struct graph) + sizeof(struct successors *) * (n - 1));
	assert(g);

	g->n = n;
	g->m = 0;
	
	for (i = 0; i < n; i++) {
		g->alist[i] = (graph::successors *)malloc(sizeof(graph::successors));
		assert(g->alist[i]);

		g->alist[i]->d = 0;
		g->alist[i]->len = 1;
		g->alist[i]->is_sorted = 1;
	}

	/*for (size_t i = 0; i < 4; i++)
	{
		printf("%d_,%d,%d,%d\n", i,g->alist[i]->d, g->alist[i]->len, g->alist[i]->is_sorted);
	}*/
	return g;
}

void show(Graph g)
{
	for (size_t i = 0; i < 4; i++)
	{
		printf("%d_,%d,%d,%d\n", i, g->alist[i]->d, g->alist[i]->len, g->alist[i]->is_sorted);
	}
}

void graph_add_edge(Graph, int source, int sink)
{
	//
}

int graph_out_degree(Graph, int source)
{
	return 0;
}

int graph_has_edge(Graph, int source, int sink)
{
	return 0;
}

void graph_foreach(Graph g, int source, void(*f)(Graph g, int source, int sink, void *data), void * data)
{

}
