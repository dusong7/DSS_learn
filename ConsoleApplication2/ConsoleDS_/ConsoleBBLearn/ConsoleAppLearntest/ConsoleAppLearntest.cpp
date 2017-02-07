// ConsoleAppLearntest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <functional>
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

	friend
		bool operator > (const node_info& lth, const node_info& rth) {
		printf("isCall %d_%d\n", lth.weight, rth.weight);
		return lth.weight < rth.weight; // 为了实现从小到大的顺序
	}

public:
	int index; // 结点位置
	int weight; // 权值
};

int main()
{
	priority_queue<node_info> queInfo;
	queInfo.push(node_info(1, 4));
	queInfo.push(node_info(2, 2));
	queInfo.push(node_info(4, 5));
	queInfo.push(node_info(5, 1));

	printf("%d_\n", queInfo.top().weight);
	queInfo.pop();

	printf("%d_\n", queInfo.top().weight);
	queInfo.pop();
	printf("%d_\n", queInfo.top().weight);
	queInfo.pop();
	printf("%d_\n", queInfo.top().weight);
	queInfo.pop();
    return 0;
}

