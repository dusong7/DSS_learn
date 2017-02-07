//����Ա�ۻ����� ���ȶ��з�֧�޽編��� 
#include "stdafx.h"
#include "MinHeap2.h"
#include <iostream>
#include <fstream> 
using namespace std;

ifstream fin("6d7.txt");
const int N = 4;//ͼ�Ķ�����  

template<class Type>
class Traveling
{
	friend int main();
public:
	Type BBTSP(int v[]);
private:
	int n;		//ͼG�Ķ�����
	Type **a,	//ͼG���ڽӾ���
		NoEdge,		//ͼG���ޱ߱�ʶ
		cc,			//��ǰ����
		bestc;		//��ǰ��С����
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
	Type lcost,		//�������õ��½�
		cc,		//��ǰ����
		rcost;	//x[s:n-1]�ж�����С���߷��ú�
	int s,			//���ڵ㵽��ǰ�ڵ��·��Ϊx[0:s]
		*x;			//��Ҫ��һ�������Ķ�����x[s+1,n-1]
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

//������Ա�ۻ���������ȶ���ʽ��֧�޽編
template<class Type>
Type Traveling<Type>::BBTSP(int v[])
{
	MinHeap<MinHeapNode<Type>> H(1000);
	Type * MinOut = new Type[n + 1];
	//����MinOut[i] = ����i����С���߷���
	Type MinSum = 0; //��С���߷��ú�
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
			return NoEdge;		//�޻�·
		}
		MinOut[i] = Min;
		MinSum += Min;
	}

	//��ʼ��
	MinHeapNode<Type> E;
	E.x = new int[n];
	for (int i = 0; i<n; i++)
	{
		E.x[i] = i + 1;
	}
	E.s = 0;		//���ڵ㵽��ǰ�ڵ�·��Ϊx[0:s]
	E.cc = 0;		//��ǰ����
	E.rcost = MinSum;//��С���߷��ú�
	Type bestc = NoEdge;

	//�������пռ���
	while (E.s<n - 1)//��Ҷ���
	{
		if (E.s == n - 2)//��ǰ��չ�ڵ���Ҷ�ڵ�ĸ��ڵ�
		{
			//�ټ�2���߹��ɻ�·
			//�����ɻ�·�Ƿ����ڵ�ǰ���Ž�
			if (a[E.x[n - 2]][E.x[n - 1]] != NoEdge && a[E.x[n - 1]][1] != NoEdge
				&& (E.cc + a[E.x[n - 2]][E.x[n - 1]] + a[E.x[n - 1]][1]<bestc
					|| bestc == NoEdge))
			{
				//���ø�С�Ļ�·
				bestc = E.cc + a[E.x[n - 2]][E.x[n - 1]] + a[E.x[n - 1]][1];
				E.cc = bestc;
				E.lcost = bestc;
				E.s++;
				H.Insert(E);
			}
			else
			{
				delete[] E.x;//������չ�ڵ�
			}
		}
		else//������ǰ��չ�ڵ�Ķ��ӽڵ�
		{
			for (int i = E.s + 1; i<n; i++)
			{
				if (a[E.x[E.s]][E.x[i]] != NoEdge)
				{
					//���ж��ӽڵ�
					Type cc = E.cc + a[E.x[E.s]][E.x[i]];
					Type rcost = E.rcost - MinOut[E.x[E.s]];
					Type b = cc + rcost;//�½�
					if (b<bestc || bestc == NoEdge)
					{
						//�������ܺ������Ž�
						//�ڵ������С��
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
			delete[]E.x;//��ɽڵ���չ
		}
		if (H.Size() == 0)
		{
			break;
		}
		H.DeleteMin(E);//ȡ��һ��չ�ڵ�
	}

	if (bestc == NoEdge)
	{
		return NoEdge;//�޻�·
	}
	//�����Ž⸴�Ƶ�v[1:n]
	for (int i = 0; i<n; i++)
	{
		v[i + 1] = E.x[i];
	}

	while (true)//�ͷ���С�������нڵ�
	{
		delete[]E.x;
		if (H.Size() == 0)
		{
			break;
		}
		H.DeleteMin(E);//ȡ��һ��չ�ڵ�
	}
	return bestc;
}