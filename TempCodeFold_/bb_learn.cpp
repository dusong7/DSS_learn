/
//  main.cpp
//  C0xTest
//
//  Created by apple on 16/12/9.
//  Copyright ? 2016年 apple. All rights reserved.
//
// ConsolBB.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>
#include <iterator>
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
		printf("isCall %d_%d\n", lth.weight, rth.weight);
		return lth.weight > rth.weight; // 为了实现从小到大的顺序
	}

public:
	int index; // 结点位置
	int weight; // 权值
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
		:no_edge(-1), end_node(end_location), node_count((int)g.size()), graph(g)
	{}

	// 打印最短路径
	void print_spaths() const {
		cout << "min weight : " << shortest_path << endl;
		cout << "path: ";
		copy(s_path_index.rbegin(), s_path_index.rend(),
			ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	// 求最短路径
	void shortest_paths() {
		vector<path_info> path(node_count);
		priority_queue<node_info, vector<node_info>> min_heap;
		min_heap.push(node_info(0, 0));    // 将起始结点入队
		printf("end node_%d\n", end_node);
		while (true) 
		{
			printf("Top Info %d_i,%d,size %d\n", min_heap.top().index, min_heap.top().weight, min_heap.size());
			node_info top = min_heap.top();    // 取出最大值
			
			min_heap.pop();
			if (!min_heap.empty())
			{
				printf("After_Top Info %d_i,%d,size %d\n", min_heap.top().index, min_heap.top().weight, min_heap.size());
			}
			else
			{
				printf("Empty\n");
			}

			// 已到达目的结点
			if (top.index == end_node) 
			{
				printf("end\n");
				break;
			}
			// 未到达则遍历
			for (int i = 0; i < node_count; ++i) 
			{
				// 顶点top.index和i间有边，且此路径长小于原先从原点到i的路径长
				printf("W%d_g%d,(%d%d)_before%d_is%d_\n", top.weight, graph[top.index][i], top.index, i, path[i].weight, (top.weight + graph[top.index][i]));
				if (graph[top.index][i] != no_edge && (top.weight + graph[top.index][i]) < path[i].weight)
				{
					printf("hit nodecount %d_index (%d,%d)_%d\n", i, top.index,i,top.weight + graph[top.index][i]);
					//i value is transform to top.index
					min_heap.push(node_info(i, top.weight + graph[top.index][i]));
					path[i].front_index = top.index;
					path[i].weight = top.weight + graph[top.index][i];
					printf("PathW _%d,_\n", path[i].weight);
				}
			}
			if (min_heap.empty())
			{
				printf("min_is empty\n");
				break;
			}
		}

		shortest_path = path[end_node].weight;
		int index = end_node;
		s_path_index.push_back(index);
		while (true) 
		{
			printf("index %d_\n", index);
			index = path[index].front_index;
			s_path_index.push_back(index);
			if (index == 0) 
			{
				break;
			}
		}
	}

private:
	vector<vector<int> >    graph;            // 图的数组表示
	int                        node_count;        // 结点个数
	const int                no_edge;        // 无通路
	const int                end_node;        // 目的结点
	vector<int>                s_path_index;    // 最短路径
	int                        shortest_path;    // 最短路径
};

int main()
{
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

	ss_shortest_paths ssp(graph, 10);
	ssp.shortest_paths();
	ssp.print_spaths();
	getchar();
	return 0;
}

//
//end node_10
//Top Info 0_i, 0, size 1
//Empty
//W0_g - 1, (00)_before2147483647_is - 1_
//W0_g2, (01)_before2147483647_is2_
//hit nodecount 1_index(0, 1)_2
//PathW _2, _
//W0_g3, (02)_before2147483647_is3_
//hit nodecount 2_index(0, 2)_3
//isCall 2_3
//PathW _3, _
//W0_g4, (03)_before2147483647_is4_
//hit nodecount 3_index(0, 3)_4
//isCall 2_4
//PathW _4, _
//W0_g - 1, (04)_before2147483647_is - 1_
//W0_g - 1, (05)_before2147483647_is - 1_
//W0_g - 1, (06)_before2147483647_is - 1_
//W0_g - 1, (07)_before2147483647_is - 1_
//W0_g - 1, (08)_before2147483647_is - 1_
//W0_g - 1, (09)_before2147483647_is - 1_
//W0_g - 1, (010)_before2147483647_is - 1_
//Top Info 1_i, 2, size 3
//isCall 2_3
//isCall 2_4
//isCall 3_4
//After_Top Info 2_i, 3, size 2
//W2_g - 1, (10)_before2147483647_is1_
//W2_g - 1, (11)_before2_is1_
//W2_g3, (12)_before3_is5_
//W2_g - 1, (13)_before4_is1_
//W2_g7, (14)_before2147483647_is9_
//hit nodecount 4_index(1, 4)_9
//isCall 3_9
//PathW _9, _
//W2_g2, (15)_before2147483647_is4_
//hit nodecount 5_index(1, 5)_4
//isCall 4_4
//PathW _4, _
//W2_g - 1, (16)_before2147483647_is1_
//W2_g - 1, (17)_before2147483647_is1_
//W2_g - 1, (18)_before2147483647_is1_
//W2_g - 1, (19)_before2147483647_is1_
//W2_g - 1, (110)_before2147483647_is1_
//Top Info 2_i, 3, size 4
//isCall 3_4
//isCall 3_9
//isCall 4_4
//isCall 9_4
//isCall 4_9
//isCall 4_4
//After_Top Info 3_i, 4, size 3
//W3_g - 1, (20)_before2147483647_is2_
//W3_g - 1, (21)_before2_is2_
//W3_g - 1, (22)_before3_is2_
//W3_g - 1, (23)_before4_is2_
//W3_g - 1, (24)_before9_is2_
//W3_g9, (25)_before4_is12_
//W3_g2, (26)_before2147483647_is5_
//hit nodecount 6_index(2, 6)_5
//isCall 4_5
//PathW _5, _
//W3_g - 1, (27)_before2147483647_is2_
//W3_g - 1, (28)_before2147483647_is2_
//W3_g - 1, (29)_before2147483647_is2_
//W3_g - 1, (210)_before2147483647_is2_
//Top Info 3_i, 4, size 4
//isCall 4_4
//isCall 4_9
//isCall 4_5
//isCall 9_4
//isCall 4_9
//isCall 4_5
//After_Top Info 5_i, 4, size 3
//W4_g - 1, (30)_before2147483647_is3_
//W4_g - 1, (31)_before2_is3_
//W4_g - 1, (32)_before3_is3_
//W4_g - 1, (33)_before4_is3_
//W4_g - 1, (34)_before9_is3_
//W4_g - 1, (35)_before4_is3_
//W4_g2, (36)_before5_is6_
//W4_g - 1, (37)_before2147483647_is3_
//W4_g - 1, (38)_before2147483647_is3_
//W4_g - 1, (39)_before2147483647_is3_
//W4_g - 1, (310)_before2147483647_is3_
//Top Info 5_i, 4, size 3
//isCall 4_5
//isCall 4_9
//isCall 5_9
//After_Top Info 6_i, 5, size 2
//W4_g - 1, (50)_before2147483647_is3_
//W4_g - 1, (51)_before2_is3_
//W4_g - 1, (52)_before3_is3_
//W4_g - 1, (53)_before4_is3_
//W4_g - 1, (54)_before9_is3_
//W4_g - 1, (55)_before4_is3_
//W4_g1, (56)_before5_is5_
//W4_g - 1, (57)_before2147483647_is3_
//W4_g3, (58)_before2147483647_is7_
//hit nodecount 8_index(5, 8)_7
//isCall 5_7
//PathW _7, _
//W4_g - 1, (59)_before2147483647_is3_
//W4_g - 1, (510)_before2147483647_is3_
//Top Info 6_i, 5, size 3
//isCall 5_9
//isCall 5_7
//isCall 9_7
//isCall 7_9
//After_Top Info 8_i, 7, size 2
//W5_g - 1, (60)_before2147483647_is4_
//W5_g - 1, (61)_before2_is4_
//W5_g - 1, (62)_before3_is4_
//W5_g - 1, (63)_before4_is4_
//W5_g - 1, (64)_before9_is4_
//W5_g - 1, (65)_before4_is4_
//W5_g - 1, (66)_before5_is4_
//W5_g - 1, (67)_before2147483647_is4_
//W5_g5, (68)_before7_is10_
//W5_g1, (69)_before2147483647_is6_
//hit nodecount 9_index(6, 9)_6
//isCall 7_6
//isCall 6_7
//PathW _6, _
//W5_g - 1, (610)_before2147483647_is4_
//Top Info 9_i, 6, size 3
//isCall 6_9
//isCall 6_7
//isCall 9_7
//isCall 7_9
//After_Top Info 8_i, 7, size 2
//W6_g - 1, (90)_before2147483647_is5_
//W6_g - 1, (91)_before2_is5_
//W6_g - 1, (92)_before3_is5_
//W6_g - 1, (93)_before4_is5_
//W6_g - 1, (94)_before9_is5_
//W6_g - 1, (95)_before4_is5_
//W6_g - 1, (96)_before5_is5_
//W6_g - 1, (97)_before2147483647_is5_
//W6_g2, (98)_before7_is8_
//W6_g - 1, (99)_before6_is5_
//W6_g2, (910)_before2147483647_is8_
//hit nodecount 10_index(9, 10)_8
//isCall 7_8
//PathW _8, _
//Top Info 8_i, 7, size 3
//isCall 7_9
//isCall 7_8
//isCall 9_8
//isCall 8_9
//After_Top Info 10_i, 8, size 2
//W7_g - 1, (80)_before2147483647_is6_
//W7_g - 1, (81)_before2_is6_
//W7_g - 1, (82)_before3_is6_
//W7_g - 1, (83)_before4_is6_
//W7_g - 1, (84)_before9_is6_
//W7_g - 1, (85)_before4_is6_
//W7_g - 1, (86)_before5_is6_
//W7_g - 1, (87)_before2147483647_is6_
//W7_g - 1, (88)_before7_is6_
//W7_g - 1, (89)_before6_is6_
//W7_g2, (810)_before8_is9_
//Top Info 10_i, 8, size 2
//isCall 8_9
//After_Top Info 4_i, 9, size 1
//end
//index 10_
//index 9_
//index 6_
//index 2_
//min weight : 8
//path : 0 2 6 9 10
