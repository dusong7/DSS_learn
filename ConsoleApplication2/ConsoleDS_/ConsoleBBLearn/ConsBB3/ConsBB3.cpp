// ConsBB3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iterator>

using namespace std;

class heap_node
{
public:
	heap_node(float lc, float cc, float rc, int s, const vector<int>& p)
		: lower_cost(lc), current_cost(cc), remainder_cost(rc), size(s)
	{
		path = p;
	}

	friend
		bool operator < (const heap_node& rhs, const heap_node& lhs) {
		return rhs.lower_cost > lhs.lower_cost;
	}

public:
	float		lower_cost;	// �������õ��½�
	float		current_cost;	// ��ǰ����
	float		remainder_cost;// ʣ�ඥ�����С���߷��ú�
	int			size;	// ���ڵ㵽��ǰ����·��Ϊpath [0 : s]
	vector<int> path;	// ��Ҫ��һ�������Ķ�����path [s+1 : n-1]
};

class BBTSP
{

public:
	static float MAX_VALUE;
	static float NO_EDGE_VALUE;
	typedef priority_queue<heap_node>	min_heap;

public:
	// ���캯��
	BBTSP(const vector<vector<float> >& g) {
		graph = g;
		node_count = (int)g.size();
		best_p.resize(node_count);
	}

	void bb_TSP() {
		int n = node_count;
		min_heap	mh;	// ��С��	
						// min_out[i] = ����i��С���߷���
		vector<float>	min_out(node_count);
		float			min_sum = 0.0f;	// ��С���߷��ú�

		for (int i = 0; i < node_count; ++i) {
			float min = MAX_VALUE;
			for (int j = 0; j < node_count; ++j) {
				if (graph[i][j] != NO_EDGE_VALUE && graph[i][j] < min) {
					min = graph[i][j];
				}
			}
			if (min == MAX_VALUE) {
				cerr << " No cycle !" << endl;
				return;
			}
			min_out[i] = min;
			min_sum += min;
		}

		for (int i = 0; i < node_count; ++i) {
			cout << "���" << i << "����С���߷��ú�Ϊ: " << min_out[i] << endl;
		}
		cout << "�ܳ��߷���Ϊ: " << min_sum << endl << endl;

		// ��ʼ��
		vector<int>	path(n);
		for (int i = 0; i < n; ++i) {
			path[i] = i;
		}
		heap_node hn(0, 0, min_sum, 0, path);
		float	best_c = MAX_VALUE;

		// �������пռ���
		while (hn.size < n - 1) {
			// ��Ҷ���
			path = hn.path;
			cout << "path: ";
			copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
			cout << endl;
			if (hn.size == n - 2) {
				// ��ǰ��չ�����Ҷ���ĸ����
				// �ټ����߹��ɻ�·
				// �����ɵĻ�·�Ƿ����ڵ�ǰ���Ž�
				if (graph[path[n - 2]][path[n - 1]] != NO_EDGE_VALUE &&
					graph[path[n - 1]][1] != NO_EDGE_VALUE &&
					hn.current_cost + graph[path[n - 2]][path[n - 1]] +
					graph[path[n - 1]][1] < best_c) {
					// �ҵ����ø�С�Ļ�·
					best_c = hn.current_cost + graph[path[n - 2]][path[n - 1]] +
						graph[path[n - 1]][1];
					hn.current_cost = best_c;
					hn.lower_cost = best_c;
					hn.size++;
					mh.push(hn);
				}
			}
			else {
				// ������ǰ��չ���Ķ��ӽ��
				for (int i = hn.size + 1; i < n; ++i) {
					if (graph[path[hn.size]][path[i]] != NO_EDGE_VALUE) {
						// ���еĶ��ӽ��
						float cc = hn.current_cost + graph[path[hn.size]][path[i]];
						float rcost = hn.remainder_cost - min_out[path[hn.size]];
						// ���ȼ�= ��ǰ����+ ʣ�������С���ú�- ��ǰ�ڵ����С����
						float b = cc + rcost;	// �½�
						if (b < best_c) {
							// �������ܺ����Ž⣬��������С��
							vector<int>	p(n);
							for (int j = 0; j < n; ++j) {
								p[j] = path[j];
							}

							//copy (p.begin(), p.end(), ostream_iterator<int> (cout, " ")) ;
							//cout << ", " ;

							p[hn.size + 1] = path[i];
							p[i] = path[hn.size + 1];

							//copy (p.begin(), p.end(), ostream_iterator<int> (cout, " ")) ;
							//cout << endl; 

							heap_node in(b, cc, rcost, hn.size + 1, p);
							mh.push(in);
						}
					}
				}

			}
			// ȡ��һ��չ���
			hn = mh.top();
			mh.pop();
		}
		best_cost = best_c;
		for (int i = 0; i < node_count; ++i) {
			best_p[i] = path[i];
		}
		copy(best_p.begin(), best_p.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
		cout << "best cost : " << best_cost << endl;
	}
private:
	vector<vector<float> >	graph;		// ͼ�������ʾ
	int						node_count;// ������
	vector<int>				best_p;	// �������Ž��·��
	float					best_cost;	// ���Ž�

};
float BBTSP::MAX_VALUE = numeric_limits<float>::max();
float BBTSP::NO_EDGE_VALUE = -1.0f;

int main()
{
	// ͼ�ĳ�ʼ��
	const int size = 6;
	vector<vector<float> > g(size);
	for (int i = 0; i < size; ++i) {
		g[i].resize(size);
	}
	for (int i = 0; i < size; ++i) {
		g[i][i] = BBTSP::NO_EDGE_VALUE;
	}
	g[0][1] = 30;
	g[0][2] = 6;
	g[0][3] = 4;
	g[0][4] = 5;
	g[0][5] = 6;

	g[1][0] = 30;
	g[1][2] = 4;
	g[1][3] = 5;
	g[1][4] = 2;
	g[1][5] = 1;

	g[2][0] = 6;
	g[2][1] = 4;
	g[2][3] = 7;
	g[2][4] = 8;
	g[2][5] = 9;

	g[3][0] = 4;
	g[3][1] = 5;
	g[3][2] = 7;
	g[3][4] = 10;
	g[3][5] = 20;

	g[4][0] = 5;
	g[4][1] = 2;
	g[4][2] = 8;
	g[4][3] = 10;
	g[4][5] = 3;

	g[5][0] = 6;
	g[5][1] = 1;
	g[5][2] = 9;
	g[5][3] = 20;
	g[5][4] = 3;

	BBTSP	bt(g);
	bt.bb_TSP();

	return 0;
}