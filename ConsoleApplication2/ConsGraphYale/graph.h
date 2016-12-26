
#pragma once
#ifndef __GRAPH__H__
#define __GRAPH__H__
typedef struct graph *Graph;

Graph graph_create(int n);
void graph_destroy(Graph);
void show(Graph g);
void graph_add_edge(Graph, int source, int sink);
int graph_vertex_count(Graph);
int graph_edge_count(Graph);
int graph_out_degree(Graph, int source);
int graph_has_edge(Graph, int source, int sink);
void graph_foreach(Graph g, int source,
	void(*f)(Graph g, int source, int sink, void *data),
	void *data);

#endif // !__GRAPH__H__
