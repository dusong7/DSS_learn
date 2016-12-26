// ConsGraphYale.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "graph.h"

int main()
{
	Graph graph;
	graph = graph_create(4);
	show(graph);
    return 0;
}

