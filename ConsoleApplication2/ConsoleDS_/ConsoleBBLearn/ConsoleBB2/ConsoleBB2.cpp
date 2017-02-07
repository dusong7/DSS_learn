// ConsoleBB2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/* ���⣺װ�����⣨��֧�޽編��
* ���ߣ�chinazhangjie
* ���䣺chinajiezhang@gmail.com
* �������ԣ�C++
* ����������Microsoft Visual Studio 2005
* ʱ��: 2010.11.07
*/

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <iterator>
using namespace std;

// BAB for "branch and bound method"
// FIFO����ʽ��֧�޽編
class load_BAB
{
public:
	load_BAB(const vector<int>& w, int c)
		: weight(w), capacity(c), c_count((int)w.size()), best_w(0) {
	}

	int get_best_w() const {
		return best_w;
	}

	// ����ʽ��֧�޽編
	int queue_BAB() {
		live_node_q.push(-1);    // ͬ��ڵ�β����ʶ
		int i = 0;
		int cw = 0;

		while (true) {
			// ������ӽ��
			if (cw + weight[i] <= capacity) {
				__en_queue(cw + weight[i], i);
				/*if ((cw + weight[i]) > best_w) {
				best_w = cw + weight[i];
				}*/
			}
			// ������ӽڵ�(���ܲ������Ž�)
			int best_rest = accumulate(weight.begin() + i + 1, weight.end(), 0);
			if (best_rest > best_w) {
				__en_queue(cw, i);
			}
			// ȡ��һ�����
			cw = live_node_q.front();
			live_node_q.pop();
			if (cw == -1) {
				if (live_node_q.empty()) {
					return best_w;
				}
				live_node_q.push(-1);
				cw = live_node_q.front();
				live_node_q.pop();
				++i;
			}
		}
	}

private:
	void __en_queue(int cw, int i) {
		// ��������뵽�������Q��
		if (i >= c_count - 1) {
			if (cw > best_w) {
				best_w = cw;
			}
		}
		else {
			live_node_q.push(cw);
		}
	}

private:
	vector<int>    weight;            // ��װ������
	queue<int>  live_node_q;    // �������
	int            c_count;        // ��װ�� (container) ����
	int            capacity;        // �ִ�������
	int            best_w;            // ����������
};


// �Ӽ��ռ����н��
class BB_node
{
public:
	BB_node(BB_node* par, bool lc) {
		parent = par;
		left_child = lc;
	}
public:
	BB_node* parent;        // �����
	bool     left_child;    // ����ӽ���־
};

// ���ȼ����н��
class heap_node
{
public:
	heap_node(BB_node* node, int uw, int lev) {
		live_node = node;
		upper_weight = uw;
		level = lev;
	}
	friend
		bool operator < (const heap_node& lth, const heap_node& rth) {
		return lth.upper_weight < rth.upper_weight;
	}
	friend
		bool operator > (const heap_node& lth, const heap_node& rhs) {
		return lth.upper_weight > rhs.upper_weight;
	}
public:
	BB_node* live_node;    // 
	int        upper_weight;  // �������ȼ����Ͻ磩
	int        level;            // �������Ӽ����������Ĳ����
};

// ����Ȩ����ʽ��֧�޽編
class load_PQBAB
{
public:
	load_PQBAB(const vector<int>& w, int c)
		: weight(w), capacity(c), c_count(static_cast<int>(w.size())) {
	}
	~load_PQBAB() {
	}
	void max_loading() {
		BB_node* pbn = NULL;    // ��ǰ��չ���
		int i = 0;            // ��ǰ��չ��������Ĳ�
		int ew = 0;            // ��չ�������Ӧ��������
		vector<int> r(c_count, 0);// ʣ����������
		for (int j = c_count - 2; j >= 0; --j) {
			r[j] = r[j + 1] + weight[j + 1];
		}
		/*copy (r.begin(), r.end(), ostream_iterator<int>(cout, " ")) ;
		cout << endl; */

		// �����Ӽ��ռ���
		while (i != c_count) {
			// ��Ҷ��㣬��鵱ǰ��չ���Ķ��ӽ��
			if (ew + weight[i] <= capacity) {
				// �����Ϊ���н��
				__add_live_node(ew + weight[i] + r[i], i + 1, pbn, true);
			}
			// �Ҷ��ӽ��Ϊ���н��
			__add_live_node(ew + r[i], i + 1, pbn, false);

			// �ͷ��ڴ�
			while (pbn != NULL) {
				BB_node *p = pbn;
				pbn = pbn->parent;
				delete p;
			}
			// ȡ��һ��չ���
			heap_node node = pri_queue.top();
			pri_queue.pop();
			// cout << node.upper_weight <<endl;
			i = node.level;
			pbn = node.live_node;
			ew = node.upper_weight - r[i - 1];
		}
		// �ͷ��ڴ�
		while (pri_queue.size() != 0) {
			heap_node node = pri_queue.top();
			pri_queue.pop();
			while (node.live_node != NULL) {
				BB_node* temp = node.live_node;
				node.live_node = node.live_node->parent;
				delete temp;
			}
		}
		// �������Ž�
		cout << "best capacity: " << ew << endl;
		cout << "path: ";
		vector<bool> temp_path;
		while (pbn != NULL) {
			temp_path.push_back(pbn->left_child);
			BB_node *temp = pbn;
			pbn = pbn->parent;
			delete temp;
		}
		copy(temp_path.rbegin(), temp_path.rend(), ostream_iterator<bool>(cout, " "));
		cout << endl;
	}

private:
	// �����µĻ��㣬���뵽�Ӽ�����
	void __add_live_node(int uw, int lev, BB_node* par, bool lc) {
		// ���
		BB_node *first = NULL;
		BB_node *end = NULL;
		while (par != NULL) {
			BB_node* p = new BB_node(NULL, par->left_child);
			if (first == NULL) {
				first = p;
				end = p;
			}
			else {
				end->parent = p;
				end = end->parent;
			}
			par = par->parent;
		}

		BB_node* p = new BB_node(first, lc);
		pri_queue.push(heap_node(p, uw, lev));
	}

private:
	vector<int>    weight;        // ��װ������    
	int            c_count;    // ��װ�� (container) ����
	int            capacity;    // �ִ�������
	priority_queue<heap_node>    pri_queue;    // �������ȼ�����
};


int main()
{
	const int capacity = 20;
	vector<int> weight;
	weight.push_back(10);
	weight.push_back(8);
	weight.push_back(5);
	weight.push_back(1);
	weight.push_back(3);
	load_PQBAB l(weight, capacity);
	l.max_loading();
	/*load_BAB lb (weight, capacity) ;
	lb.queue_BAB () ;
	cout << lb.get_best_w() << endl ;*/
	return 0;
}