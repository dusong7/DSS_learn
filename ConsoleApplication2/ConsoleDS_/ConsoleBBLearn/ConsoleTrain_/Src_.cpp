////��Դ���·������ ��֧ �޽編���
#include "stdafx.h"
//#include "MinHeap2.h"
//#include <iostream>
//#include <fstream> 
//using namespace std;
//
//ifstream fin("6d2.txt");
//
//template<class Type>
//class Graph
//{
//	friend int main();
//public:
//	void ShortesPaths(int);
//private:
//	int		n,		   //ͼG�Ķ�����
//		*prev;     //ǰ����������
//	Type	**c,       //ͼG����Ӿ���
//		*dist;     //��̾�������
//};
//
//template<class Type>
//class MinHeapNode
//{
//	friend Graph<Type>;
//public:
//	operator int()const { return length; }
//private:
//	int       i;		  //������
//	Type  length;	  //��ǰ·��
//};
//
//template<class Type>
//void Graph<Type>::ShortesPaths(int v)//��Դ���·����������ȶ���ʽ��֧�޽編
//{
//	MinHeap<MinHeapNode<Type>> H(1000);
//	MinHeapNode<Type> E;
//
//	//����ԴΪ��ʼ��չ�ڵ�
//	E.i = v;
//	E.length = 0;
//	dist[v] = 0;
//
//	while (true)//��������Ľ�ռ�
//	{
//		for (int j = 1; j <= n; j++)
//			if ((c[E.i][j] != 0) && (E.length + c[E.i][j]<dist[j])) {
//
//				// ����i������j�ɴ���������Լ��
//				dist[j] = E.length + c[E.i][j];
//				prev[j] = E.i;
//
//				// ����������ȶ���
//				MinHeapNode<Type> N;
//				N.i = j;
//				N.length = dist[j];
//				H.Insert(N);
//			}
//				try
//			{
//				H.DeleteMin(E); // ȡ��һ��չ���
//			}
//			catch (int)
//			{
//				break;
//			}
//			if (H.currentsize == 0)// ���ȶ��п�
//			{
//				break;
//			}
//	}
//}
//
//int mainTest()
//{
//	int n = 11;
//	int prev[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
//
//	int dist[12] = { 1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000 };
//
//	cout << "��Դͼ���ڽӾ������£�" << endl;
//	int **c = new int*[n + 1];
//
//	for (int i = 1; i <= n; i++)
//	{
//		c[i] = new int[n + 1];
//		for (int j = 1; j <= n; j++)
//		{
//			fin >> c[i][j];
//			cout << c[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	int v = 1;
//	Graph<int> G;
//	G.n = n;
//	
//	G.c = c;
//	G.dist = dist;
//	G.prev = prev;
//	G.ShortesPaths(v);
//
//	cout << "��S��T�����·���ǣ�" << dist[11] << endl;
//	for (int i = 2; i <= n; i++)
//	{
//		cout << "prev(" << i << ")=" << prev[i] << "   " << endl;
//	}
//
//	for (int i = 2; i <= n; i++)
//	{
//		cout << "��1��" << i << "�����·���ǣ�" << dist[i] << endl;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		delete[]c[i];
//	}
//
//	delete[]c;
//	c = 0;
//	return 0;
//}