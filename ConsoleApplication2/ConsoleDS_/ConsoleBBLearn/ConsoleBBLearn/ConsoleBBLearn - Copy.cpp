#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct node_info
{
public:
	node_info(int i, int w)
		: index(i), weight(w) {}
	node_info()
		: index(0), weight(0) {}
	node_info(const node_info & ni)
		: index(ni.index), weight(ni.weight) {}

	friend
		bool operator < (const node_info& lth, const node_info& rth) {
		return lth.weight > rth.weight; // Ϊ��ʵ�ִ�С�����˳��
	}

public:
	int index; // ���λ��
	int weight; // Ȩֵ
};

struct path_info
{
public:
	path_info()
		: front_index(0), weight(numeric_limits<int>::max()) {}

public:
	int front_index;
	int weight;
};

// single source shortest paths
class ss_shortest_paths
{

public:
	ss_shortest_paths(const vector<vector<int> >& g, int end_location)
		:no_edge(-1), end_node(end_location), node_count(g.size()), graph(g)
	{}

	// ��ӡ���·��
	void print_spaths() const {
		cout << "min weight : " << shortest_path << endl;
		cout << "path: ";
		copy(s_path_index.rbegin(), s_path_index.rend(),ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	// �����·��
	void shortest_paths() {
		vector<path_info> path(node_count);
		priority_queue<node_info, vector<node_info> > min_heap;
		min_heap.push(node_info(0, 0));    // ����ʼ������

		while (true) {
			node_info top = min_heap.top();    // ȡ�����ֵ
			min_heap.pop();

			// �ѵ���Ŀ�Ľ��
			if (top.index == end_node) {
				break;
			}
			// δ���������
			for (int i = 0; i < node_count; ++i) {
				// ����top.index��i���бߣ��Ҵ�·����С��ԭ�ȴ�ԭ�㵽i��·���� 
				if (graph[top.index][i] != no_edge &&
					(top.weight + graph[top.index][i]) < path[i].weight) {
					min_heap.push(node_info(i, top.weight + graph[top.index][i]));
					path[i].front_index = top.index;
					path[i].weight = top.weight + graph[top.index][i];
				}
			}
			if (min_heap.empty()) {
				break;
			}
		}

		shortest_path = path[end_node].weight;
		int index = end_node;
		s_path_index.push_back(index);
		while (true) {
			index = path[index].front_index;
			s_path_index.push_back(index);
			if (index == 0) {
				break;
			}
		}
	}

private:
	vector<vector<int> >    graph;            // ͼ�������ʾ
	int                        node_count;        // ������
	const int                no_edge;        // ��ͨ·
	const int                end_node;        // Ŀ�Ľ��
	vector<int>                s_path_index;    // ���·��
	int                        shortest_path;    // ���·��
};

int main()
{
	const int size = 11;
	vector<vector<int> > graph(size);
	for (int i = 0; i < size; ++i) {
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

	ss_shortest_paths ssp(graph, 10);
	ssp.shortest_paths();
	ssp.print_spaths();
	return 0;
}