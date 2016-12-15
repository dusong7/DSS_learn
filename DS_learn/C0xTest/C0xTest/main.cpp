// Consoleself.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iterator>
#include <queue>
#include <limits>
#include <vector>

#include "BFS_.hpp"

using namespace std;

struct nodeInfo
{
public:
	nodeInfo(int i, int w)
		:index(i), weight(w){}
	nodeInfo() :index(0), weight(0) {}
	nodeInfo(const nodeInfo &ni)
		:index(ni.index), weight(ni.weight){}
	friend
		bool operator < (const nodeInfo& lth, const nodeInfo& rth) {
		return lth.weight > rth.weight;//
	}
public:
	int index;
	int weight;
};

struct pathInfo
{
	pathInfo()
		: front_index(0), weight(numeric_limits<int>::max()) {} //numeric_limits<int>::max()  maximum number
public:
	int front_index;
	int weight;
};

class ss_sort_path
{
public:
	ss_sort_path(const vector<vector<int>> &g, int end_location)
		:no_edge(-1), end_node(end_location), node_count((int)g.size()), graph(g){}

	void print_paths()
	{
		//
		cout << "min weight :" << shortest_path << endl;
		cout << "path: ";
		copy(s_path_index.rbegin(), s_path_index.rend(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	void shortest_paths()
	{
		vector<pathInfo> path(node_count);
		priority_queue<nodeInfo, vector<nodeInfo>> min_heap;
		min_heap.push(nodeInfo(0, 0));

		while (true)
		{
			nodeInfo top = min_heap.top();
			min_heap.pop();

			if (min_heap.empty())
			{
				printf("Empty\n");
			}

			if (top.index == end_node)
			{
				break;
			}
			for (size_t i = 0; i < node_count; i++)
			{
				//
				if (graph[top.index][i] != no_edge && (top.weight + graph[top.index][i])< path[i].weight)
				{
					min_heap.push(nodeInfo(i, top.weight + graph[top.index][i]));
					path[i].front_index = top.index;
					path[i].weight = top.weight + graph[top.index][i];
				}
			}
			if (min_heap.empty())
			{
				break;
			}
		}

		shortest_path = path[end_node].weight;
		int index = end_node;
		s_path_index.push_back(index);
		while (true)
		{
			index = path[index].front_index;
			s_path_index.push_back(index);
			if (index == 0)
			{
				break;
			}
		}
	}

private:
	vector<vector<int>> graph; //
	int node_count;
	const  int   no_edge;
	const int end_node;
	vector<int>  s_path_index;
	int  shortest_path;

};

int main()
{
	nodeInfo info(10,30);
	nodeInfo info2(20, 40);
	nodeInfo ni(info);

	//printf("%d", info<info2);
	vector<pathInfo> p(10);
	const int size = 11;
	vector<vector<int> > graph(size);
	for (int i = 0; i < size; ++i)
	{
		graph[i].resize(size);
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			graph[i][j] = -1;
		}
	}
	graph[0][1] = 2;
	graph[0][2] = 3;
	graph[0][3] = 4;
	graph[1][2] = 3;
	graph[1][5] = 2;
	graph[1][4] = 7;
	graph[2][5] = 9;
	graph[2][6] = 2;
	graph[3][6] = 2;
	graph[4][7] = 3;
	graph[4][8] = 3;
	graph[5][6] = 1;
	graph[5][8] = 3;
	graph[6][9] = 1;
	graph[6][8] = 5;
	graph[7][10] = 3;
	graph[8][10] = 2;
	graph[9][8] = 2;
	graph[9][10] = 2;

	ss_sort_path ssp(graph, 10);
	ssp.shortest_paths();
	ssp.print_paths();
	getchar();
    return 0;
}
