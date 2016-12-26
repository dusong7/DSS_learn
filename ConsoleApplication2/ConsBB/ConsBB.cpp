// ConsBB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>

#define NoEdge           1000

struct MinHeapNode
{
	int lcost; //子树费用的下界
	int cc; //当前费用
	int rcost; //x[s:n-1]中顶点最小出边费用和
	int s; //根节点到当前节点的路径为x[0:s]
	int *x; //需要进一步搜索的顶点是//x[s+1:n-1]
	struct MinHeapNode *next;
};

int n; //图G的顶点数
int **a; //图G的邻接矩阵
		 //int   NoEdge;   //图G的无边标记
int cc; //当前费用
int bestc; //当前最小费用
MinHeapNode* head = 0; /*堆头*/
MinHeapNode* lq = 0; /*堆第一个元素*/
MinHeapNode* fq = 0; /*堆最后一个元素*/

int DeleteMin(MinHeapNode*&E)
{
	MinHeapNode* tmp = NULL;
	tmp = fq;
	// w = fq->weight ;
	E = fq;
	if (E == NULL)
		return 0;
	head->next = fq->next; /*一定不能丢了链表头*/
	fq = fq->next;
	// free(tmp) ;
	return 0;
}

int Insert(MinHeapNode* hn)
{
	if (head->next == NULL)
	{
		head->next = hn; //将元素放入链表中
		fq = lq = head->next; //一定要使元素放到链中
	}
	else
	{
		MinHeapNode *tmp = NULL;
		tmp = fq;
		if (tmp->cc > hn->cc)
		{
			hn->next = tmp;
			head->next = hn;
			fq = head->next; /*链表只有一个元素的情况*/
		}
		else
		{
			for (; tmp != NULL;)
			{
				if (tmp->next != NULL && tmp->cc > hn->cc)
				{
					hn->next = tmp->next;
					tmp->next = hn;
					break;
				}
				tmp = tmp->next;
			}
		}
		if (tmp == NULL)
		{
			lq->next = hn;
			lq = lq->next;
		}
	}
	return 0;
}

int BBTSP(int v[])
{//解旅行售货员问题的优先队列式分支限界法

 /*初始化最优队列的头结点*/
	head = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	head->cc = 0;
	head->x = 0;
	head->lcost = 0;
	head->next = NULL;
	head->rcost = 0;
	head->s = 0;
	int *MinOut = new int[n + 1]; /*定义定点i的最小出边费用*/
								  //计算MinOut[i]=顶点i的最小出边费用
	int MinSum = 0;//最小出边费用总合
	for (int i = 1; i <= n; i++)
	{
		int Min = NoEdge; /*定义当前最小值*/
		for (int j = 1; j <= n; j++)
			if (a[i][j] != NoEdge && /*当定点i,j之间存在回路时*/
				(a[i][j] < Min || Min == NoEdge)) /*当顶点i,j之间的距离小于Min*/
				Min = a[i][j]; /*更新当前最小值*/
		if (Min == NoEdge)
			return NoEdge;//无回路
		MinOut[i] = Min;
		//printf("%d\n",MinOut[i]);/*顶点i的最小出边费用*/
		MinSum += Min;
		// printf("%d\n",MinSum); /*最小出边费用的总和*/
	}

	MinHeapNode *E = 0;
	E = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	E->x = new int[n];
	// E.x=new int[n];
	for (int i = 0; i < n; i++)
		E->x[i] = i + 1;
	E->s = 0;
	E->cc = 0;
	E->rcost = MinSum;
	E->next = 0; //初始化当前扩展节点
	int bestc = NoEdge; /*记录当前最小值*/
						//搜索排列空间树
	while (E->s < n - 1)
	{//非叶结点
		if (E->s == n - 2)
		{//当前扩展结点是叶结点的父结点
		 /*
		 首先考虑s=n-2的情形，此时当前扩展结点是排列树中某个叶结点的父结点。如果该叶结点相应一条可行回路
		 且费用小于当前最小费用，则将该叶结点插入到优先队列中，否则舍去该叶结点
		 */
			if (a[E->x[n - 2]][E->x[n - 1]] != NoEdge && /*当前要扩展和叶节点有边存在*/
				a[E->x[n - 1]][1] != NoEdge && /*当前页节点有回路*/
				(E->cc + a[E->x[n - 2]][E->x[n - 1]] + a[E->x[n - 1]][1] < bestc /*该节点相应费用小于最小费用*/
					|| bestc == NoEdge))
			{
				bestc = E->cc + a[E->x[n - 2]][E->x[n - 1]] + a[E->x[n - 1]][1]; /*更新当前最新费用*/
				E->cc = bestc;
				E->lcost = bestc;
				E->s++;
				E->next = NULL;
				Insert(E); /*将该页节点插入到优先队列中*/
			}
			else
				free(E->x);//该页节点不满足条件舍弃扩展结点 
		}
		else
		{/*产生当前扩展结点的儿子结点
		 当s<n-2时，算法依次产生当前扩展结点的所有儿子结点。由于当前扩展结点所相应的路径是x[0:s]，
		 其可行儿子结点是从剩余顶点x[s+1:n-1]中选取的顶点x[i]，且(x[s]，x[i])是所给有向图G中的一条边。
		 对于当前扩展结点的每一个可行儿子结点，计算出其前缀(x[0:s]，x[i])的费用cc和相应的下界lcost。
		 当lcost<bestc时，将这个可行儿子结点插入到活结点优先队列中。*/
			for (int i = E->s + 1; i < n; i++)
				if (a[E->x[E->s]][E->x[i]] != NoEdge)
				{ /*当前扩展节点到其他节点有边存在*/
				  //可行儿子结点
					int cc = E->cc + a[E->x[E->s]][E->x[i]]; /*加上节点i后当前节点路径*/
					int rcost = E->rcost - MinOut[E->x[E->s]]; /*剩余节点的和*/
					int b = cc + rcost; //下界
					if (b < bestc || bestc == NoEdge)
					{//子树可能含最优解,结点插入最小堆
						MinHeapNode * N;
						N = (MinHeapNode*)malloc(sizeof(MinHeapNode));
						N->x = new int[n];
						for (int j = 0; j < n; j++)
							N->x[j] = E->x[j];
						N->x[E->s + 1] = E->x[i];
						N->x[i] = E->x[E->s + 1];/*添加当前路径*/
						N->cc = cc; /*更新当前路径距离*/
						N->s = E->s + 1; /*更新当前节点*/
						N->lcost = b; /*更新当前下界*/
						N->rcost = rcost;
						N->next = NULL;
						Insert(N); /*将这个可行儿子结点插入到活结点优先队列中*/
					}
				}
			free(E->x);
		}//完成结点扩展
		DeleteMin(E);//取下一扩展结点
		if (E == NULL)
			break; //堆已空
	}
	if (bestc == NoEdge)
		return NoEdge;//无回路
	for (int i = 0; i < n; i++)
		v[i + 1] = E->x[i];//将最优解复制到v[1:n]
	while (true)
	{//释放最小堆中所有结点
		free(E->x);
		DeleteMin(E);
		if (E == NULL)
			break;
	}
	return bestc;
}

int main()
{
	n = 0;
	int i = 0;
	//FILE *in, *out;
	//in = fopen("input.txt", "r");
	//out = fopen("output.txt", "w");
	//if(in == NULL || out == NULL)
	//{
	//	printf("没有输入输出文件\n");
	//	return 1;
	//}
	//fscanf(in, "%d", &n);
	n = 5;
	a = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 1; i <= n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	// 	for(i = 1; i <= n; i++)
	// 		for(int j = 1; j <= n; j++)
	// 			//fscanf(in, "%d", &a[i][j]);
	// 			a[i][j]=1;
	a[1][1] = 0;
	a[1][2] = 5;
	a[1][3] = 8;
	a[1][4] = 5;
	a[1][5] = 4;

	a[2][1] = 5;
	a[2][2] = 0;
	a[2][3] = 5;
	a[2][4] = 6;
	a[2][5] = 3;

	a[3][1] = 8;
	a[3][2] = 5;
	a[3][3] = 0;
	a[3][4] = 5;
	a[3][5] = 4;

	a[4][1] = 5;
	a[4][2] = 6;
	a[4][3] = 6;
	a[4][4] = 0;
	a[4][5] = 3;

	a[5][1] = 4;
	a[5][2] = 3;
	a[5][3] = 4;
	a[5][4] = 3;
	a[5][5] = 0;

	// prev = (int*)malloc(sizeof(int)*(n+1)) ;
	int*v = (int*)malloc(sizeof(int) * (n + 1));// MaxLoading(w , c , n) ;
	for (i = 1; i <= n; i++)
		v[i] = 0;
	bestc = BBTSP(v);

	printf("\n");
	for (i = 1; i <= n; i++)
		fprintf(stdout, "%d\t", v[i]);
	fprintf(stdout, "\n");
	fprintf(stdout, "%d\n", bestc);
	return 0;
}

//
//#include"stdlib.h"
//#include <iostream>
//using namespace std;
//
////各个城市之间的路径长度
//int CityVal[4][4] = {
//	{ 0 ,30,6,4 },
//	{ 30,0 ,5,10 },
//	{ 6,5,0 ,20 },
//	{ 4,10,20 ,0 } };
//
//struct CityNum {
//	int MinVal[2];       //最短路径长度
//	int PastCity[2][4]; //走过的路径
//}city[4];
//
//int find(int j, int k, int boolnum)
//{
//	int i;
//	for (i = 0; i<4; i++)
//		if (j == city[k].PastCity[boolnum][i])
//			return 1;
//	return 0;
//}
//void copy(int k, int boolnum1, int j, int boolnum2)
//{
//	int i = 0;
//	while (city[k].PastCity[boolnum1][i] != 0)
//	{
//		city[j].PastCity[boolnum2][i] = city[k].PastCity[boolnum1][i];
//		i++;
//	}
//	city[j].PastCity[boolnum2][i] = k;
//}
//
//
//
//int main()
//{
//	int i, j, k;
//	int boolnum = 0;
//	int TempMinVal;
//	int TempCity;
//	int TempVal;
//	for (i = 0; i<2; i++)
//		for (j = 0; j<4; j++)
//			for (k = 0; k<4; k++)
//				city[k].PastCity[i][j] = 0;
//	for (i = 1; i<4; i++)
//		city[i].MinVal[boolnum] = CityVal[i][0];
//	for (i = 0; i<2; i++)
//	{
//		for (j = 1; j<4; j++)
//		{
//			TempMinVal = 32767;
//			for (k = 1; k<4; k++)
//			{
//				if (j != k && !find(j, k, boolnum))
//				{
//					TempVal = CityVal[j][k] + city[k].MinVal[boolnum];
//					if (TempMinVal>TempVal)
//					{
//						TempMinVal = TempVal;
//						TempCity = k;
//					}
//				}
//			}
//			city[j].MinVal[(boolnum + 1) % 2] = TempMinVal;
//			copy(TempCity, boolnum, j, (boolnum + 1) % 2);
//		}
//		boolnum = (boolnum + 1) % 2;
//	}
//	TempMinVal = 32767;
//	for (i = 1; i<4; i++)
//	{
//		TempVal = CityVal[0][i] + city[i].MinVal[boolnum];
//		if (TempMinVal>TempVal)
//		{
//			TempMinVal = TempVal;
//			TempCity = i;
//		}
//	}
//	cout << "最小费用为:" << TempMinVal << endl;
//	cout << "最佳周游路径为:";
//	cout << 1 << ' ';
//	cout << TempCity + 1 << ' ';
//	for (i = 1; i >= 0; i--)
//		cout << city[TempCity].PastCity[boolnum][i] + 1 << ' ';
//	cout << 1 << endl;
//}