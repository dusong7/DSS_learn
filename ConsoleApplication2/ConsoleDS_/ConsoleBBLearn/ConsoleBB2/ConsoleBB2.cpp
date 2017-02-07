// ConsoleBB2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/* 主题：装载问题（分支限界法）
* 作者：chinazhangjie
* 邮箱：chinajiezhang@gmail.com
* 开发语言：C++
* 开发环境：Microsoft Visual Studio 2005
* 时间: 2010.11.07
*/

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <iterator>
using namespace std;

// BAB for "branch and bound method"
// FIFO队列式分支限界法
class load_BAB
{
public:
	load_BAB(const vector<int>& w, int c)
		: weight(w), capacity(c), c_count((int)w.size()), best_w(0) {
	}

	int get_best_w() const {
		return best_w;
	}

	// 队列式分支限界法
	int queue_BAB() {
		live_node_q.push(-1);    // 同层节点尾部标识
		int i = 0;
		int cw = 0;

		while (true) {
			// 检查左子结点
			if (cw + weight[i] <= capacity) {
				__en_queue(cw + weight[i], i);
				/*if ((cw + weight[i]) > best_w) {
				best_w = cw + weight[i];
				}*/
			}
			// 检查右子节点(可能产生最优解)
			int best_rest = accumulate(weight.begin() + i + 1, weight.end(), 0);
			if (best_rest > best_w) {
				__en_queue(cw, i);
			}
			// 取下一个结点
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
		// 将活结点加入到活结点队列Q中
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
	vector<int>    weight;            // 集装箱重量
	queue<int>  live_node_q;    // 活结点队列
	int            c_count;        // 集装箱 (container) 个数
	int            capacity;        // 轮船承载量
	int            best_w;            // 最优载重量
};


// 子集空间树中结点
class BB_node
{
public:
	BB_node(BB_node* par, bool lc) {
		parent = par;
		left_child = lc;
	}
public:
	BB_node* parent;        // 父结点
	bool     left_child;    // 左儿子结点标志
};

// 优先级队列结点
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
	int        upper_weight;  // 活结点优先级（上界）
	int        level;            // 活结点在子集树中所处的层序号
};

// 优先权队列式分支限界法
class load_PQBAB
{
public:
	load_PQBAB(const vector<int>& w, int c)
		: weight(w), capacity(c), c_count(static_cast<int>(w.size())) {
	}
	~load_PQBAB() {
	}
	void max_loading() {
		BB_node* pbn = NULL;    // 当前扩展结点
		int i = 0;            // 当前扩展结点所处的层
		int ew = 0;            // 扩展结点所相应的载重量
		vector<int> r(c_count, 0);// 剩余重量数组
		for (int j = c_count - 2; j >= 0; --j) {
			r[j] = r[j + 1] + weight[j + 1];
		}
		/*copy (r.begin(), r.end(), ostream_iterator<int>(cout, " ")) ;
		cout << endl; */

		// 搜索子集空间树
		while (i != c_count) {
			// 非叶结点，检查当前扩展结点的儿子结点
			if (ew + weight[i] <= capacity) {
				// 左儿子为可行结点
				__add_live_node(ew + weight[i] + r[i], i + 1, pbn, true);
			}
			// 右儿子结点为可行结点
			__add_live_node(ew + r[i], i + 1, pbn, false);

			// 释放内存
			while (pbn != NULL) {
				BB_node *p = pbn;
				pbn = pbn->parent;
				delete p;
			}
			// 取下一扩展结点
			heap_node node = pri_queue.top();
			pri_queue.pop();
			// cout << node.upper_weight <<endl;
			i = node.level;
			pbn = node.live_node;
			ew = node.upper_weight - r[i - 1];
		}
		// 释放内存
		while (pri_queue.size() != 0) {
			heap_node node = pri_queue.top();
			pri_queue.pop();
			while (node.live_node != NULL) {
				BB_node* temp = node.live_node;
				node.live_node = node.live_node->parent;
				delete temp;
			}
		}
		// 构造最优解
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
	// 产生新的活结点，加入到子集树中
	void __add_live_node(int uw, int lev, BB_node* par, bool lc) {
		// 深拷贝
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
	vector<int>    weight;        // 集装箱重量    
	int            c_count;    // 集装箱 (container) 个数
	int            capacity;    // 轮船承载量
	priority_queue<heap_node>    pri_queue;    // 活结点优先级队列
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