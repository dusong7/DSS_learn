// LogTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <Windows.h>
#include <iostream>
#include <stack>

using namespace std;
stack<int> stcVal;

//int main()
//{
//	stack<int> stcVal;
//	
//	for (size_t i = 0; i < 10; i++)
//	{
//		stcVal.push(i*i);
//	}
//	printf("%d",stcVal.top());
//
//    return 0;
//}

#define N 6  

struct adj_matrix {
	int vertex[N];
	int edge[N][N];
};

struct adj_matrix matrix = {
	{ 1, 2, 3, 4, 5, 6 },

	{ { 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 } }
};

int visit[N] = { 0, 0, 0, 0, 0, 0 };

void dfs(struct adj_matrix *G)
{
	int i, j;
	int x;

	for (i = 0; i < N; i++) 
	{
		//printf("i_val%d", i);
		if (visit[i] != 1) 
		{
			visit[i] = 1;
			printf("%2d", G->vertex[i]);
			stcVal.push(i);

			while (!stcVal.empty()) 
			{
				x = stcVal.top();
				stcVal.pop(); //get topvalue then pop,avoid dead loop 

				//printf("x:%d\n", x);
				for (j = 0; j < N; j++) 
				{
					//printf("j(%d,%d)\n", x, j);
					if (G->edge[x][j] == 1 && visit[j] != 1) 
					{
						//printf("curPath(%d,%d)", x, j);
						visit[j] = 1;
						printf("Hit%d\n", G->vertex[j]);
						stcVal.push(j);
						break;//error 2 sides
					}
				}
			}
		}
	}
}


void maxTop(stack<int> &s)
{
	if (s.empty())
	{
		return;
	}

	int top1 = s.top();
	s.pop();
	if (!s.empty())
	{
		maxTop(s);
		int top2 = s.top();
		if (top1 < top2)
		{
			s.pop();
			s.push(top1);
			s.push(top2);
			return;
		}
	}
	s.push(top1);
}

int main(void)
{
	dfs(&matrix);
	printf("\n");
	//stack<int> stckIntV;
	//int randomTable[] = { 1, 6, 4, 2, 3, 8, 7, 5};
	//for (size_t i = 0; i < 8; i++)
	//{
	//	stckIntV.push(randomTable[i]);
	//	maxTop(stckIntV);
	//	int num = stckIntV.top();
	//	printf("C_top%d\n", num);
	//}

	//for (size_t i = 0; i < 8; i++)
	//{
	//	//
	//}
	return 0;
}