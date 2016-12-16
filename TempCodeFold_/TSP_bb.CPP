//6d7.txt
0 30 6 4
30 0 5 10
6 5 0 20
4 10 20 0

//main.cpp

//旅行员售货问题 优先队列分支限界法求解 
#include "stdafx.h"
#include "MinHeap2.h"
#include <iostream>
#include <fstream> 
using namespace std;

ifstream fin("6d7.txt");
const int N = 4;//图的顶点数  

template<class Type>
class Traveling
{
	friend int main();
public:
	Type BBTSP(int v[]);
private:
	int n;		//图G的顶点数
	Type **a,	//图G的邻接矩阵
		NoEdge,		//图G的无边标识
		cc,			//当前费用
		bestc;		//当前最小费用
};

template<class Type>
class MinHeapNode
{
	friend Traveling<Type>;
public:
	operator Type() const
	{
		return lcost;
	}
private:
	Type lcost,		//子树费用的下届
		cc,		//当前费用
		rcost;	//x[s:n-1]中顶点最小出边费用和
	int s,			//根节点到当前节点的路径为x[0:s]
		*x;			//需要进一步搜索的顶点是x[s+1,n-1]
};

int main()
{
	int bestx[N + 1];
	cout << "Graph is vertus is  n=" << N << endl;

	int **a = new int*[N + 1];
	for (int i = 0; i <= N; i++)
	{
		a[i] = new int[N + 1];
	}

	cout << "Graph adj Mutex :" << endl;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			fin >> a[i][j];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	Traveling<int> t;
	t.a = a;
	t.n = N;

	cout << "Mini close loop lenth:" << t.BBTSP(bestx) << endl;
	cout << "close loop is:" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << bestx[i] << "-->";
	}
	cout << bestx[1] << endl;

	for (int i = 0; i <= N; i++)
	{
		delete[]a[i];
	}
	delete[]a;

	a = 0;
	return 0;
}

//解旅行员售货问题的优先队列式分支限界法
template<class Type>
Type Traveling<Type>::BBTSP(int v[])
{
	MinHeap<MinHeapNode<Type>> H(1000);
	Type * MinOut = new Type[n + 1];
	//计算MinOut[i] = 顶点i的最小出边费用
	Type MinSum = 0; //最小出边费用和
	for (int i = 1; i <= n; i++)
	{
		Type Min = NoEdge;
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] != NoEdge && (a[i][j]<Min || Min == NoEdge))
			{
				Min = a[i][j];
			}
		}
		if (Min == NoEdge)
		{
			return NoEdge;		//无回路
		}
		MinOut[i] = Min;
		MinSum += Min;
	}

	//初始化
	MinHeapNode<Type> E;
	E.x = new int[n];
	for (int i = 0; i<n; i++)
	{
		E.x[i] = i + 1;
	}
	E.s = 0;		//根节点到当前节点路径为x[0:s]
	E.cc = 0;		//当前费用
	E.rcost = MinSum;//最小出边费用和
	Type bestc = NoEdge;

	//搜索排列空间树
	while (E.s<n - 1)//非叶结点
	{
		if (E.s == n - 2)//当前扩展节点是叶节点的父节点
		{
			//再加2条边构成回路
			//所构成回路是否优于当前最优解
			if (a[E.x[n - 2]][E.x[n - 1]] != NoEdge && a[E.x[n - 1]][1] != NoEdge
				&& (E.cc + a[E.x[n - 2]][E.x[n - 1]] + a[E.x[n - 1]][1]<bestc
					|| bestc == NoEdge))
			{
				//费用更小的回路
				bestc = E.cc + a[E.x[n - 2]][E.x[n - 1]] + a[E.x[n - 1]][1];
				E.cc = bestc;
				E.lcost = bestc;
				E.s++;
				H.Insert(E);
			}
			else
			{
				delete[] E.x;//舍弃扩展节点
			}
		}
		else//产生当前扩展节点的儿子节点
		{
			for (int i = E.s + 1; i<n; i++)
			{
				if (a[E.x[E.s]][E.x[i]] != NoEdge)
				{
					//可行儿子节点
					Type cc = E.cc + a[E.x[E.s]][E.x[i]];
					Type rcost = E.rcost - MinOut[E.x[E.s]];
					Type b = cc + rcost;//下界
					if (b<bestc || bestc == NoEdge)
					{
						//子树可能含有最优解
						//节点插入最小堆
						MinHeapNode<Type> N;
						N.x = new int[n];
						for (int j = 0; j<n; j++)
						{
							N.x[j] = E.x[j];
						}
						N.x[E.s + 1] = E.x[i];
						N.x[i] = E.x[E.s + 1];
						N.cc = cc;
						N.s = E.s + 1;
						N.lcost = b;
						N.rcost = rcost;
						H.Insert(N);
					}
				}
			}
			delete[]E.x;//完成节点扩展
		}
		if (H.Size() == 0)
		{
			break;
		}
		H.DeleteMin(E);//取下一扩展节点
	}

	if (bestc == NoEdge)
	{
		return NoEdge;//无回路
	}
	//将最优解复制到v[1:n]
	for (int i = 0; i<n; i++)
	{
		v[i + 1] = E.x[i];
	}

	while (true)//释放最小堆中所有节点
	{
		delete[]E.x;
		if (H.Size() == 0)
		{
			break;
		}
		H.DeleteMin(E);//取下一扩展节点
	}
	return bestc;
}

//MinHeap.h
#include <iostream>

template<class Type>
class Graph;

template<class T>
class MinHeap
{
	template<class Type>
	friend class Graph;
public:
	MinHeap(int maxheapsize = 10);
	~MinHeap() { delete[]heap; }

	int Size() const { return currentsize; }
	T Max() { if (currentsize) return heap[1]; }

	MinHeap<T>& Insert(const T& x);
	MinHeap<T>& DeleteMin(T &x);

	void Initialize(T x[], int size, int ArraySize);
	void Deactivate();
	void output(T a[], int n);
private:
	int currentsize, maxsize;
	T *heap;
};

template <class T>
void MinHeap<T>::output(T a[], int n)
{
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

template <class T>
MinHeap<T>::MinHeap(int maxheapsize)
{
	maxsize = maxheapsize;
	heap = new T[maxsize + 1];
	currentsize = 0;
}

template<class T>
MinHeap<T>& MinHeap<T>::Insert(const T& x)
{
	if (currentsize == maxsize)
	{
		return *this;
	}
	int i = ++currentsize;
	while (i != 1 && x < heap[i / 2])
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}

	heap[i] = x;
	return *this;
}

template<class T>
MinHeap<T>& MinHeap<T>::DeleteMin(T& x)
{
	if (currentsize == 0)
	{
		cout << "Empty heap!" << endl;
		return *this;
	}

	x = heap[1];

	T y = heap[currentsize--];
	int i = 1, ci = 2;
	while (ci <= currentsize)
	{
		if (ci < currentsize && heap[ci] > heap[ci + 1])
		{
			ci++;
		}

		if (y <= heap[ci])
		{
			break;
		}
		heap[i] = heap[ci];
		i = ci;
		ci *= 2;
	}

	heap[i] = y;
	return *this;
}

template<class T>
void MinHeap<T>::Initialize(T x[], int size, int ArraySize)
{
	delete[]heap;
	heap = x;
	currentsize = size;
	maxsize = ArraySize;

	for (int i = currentsize / 2; i >= 1; i--)
	{
		T y = heap[i];
		int c = 2 * i;
		while (c <= currentsize)
		{
			if (c < currentsize && heap[c] > heap[c + 1])
				c++;
			if (y <= heap[c])
				break;
			heap[c / 2] = heap[c];
			c *= 2;
		}
		heap[c / 2] = y;
	}
}

template<class T>
void MinHeap<T>::Deactivate()
{
	heap = 0;
}
