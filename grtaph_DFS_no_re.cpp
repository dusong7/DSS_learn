// ConsGraph__.cpp : Defines the entry point for the console application.
//
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

	{ { 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 1 } }
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
					if (G->edge[x][j] == 1 && visit[j] != 1) 
					{
						visit[j] = 1;
						printf(" %d", G->vertex[j]);
						stcVal.push(j);
						break;
					}	
				}
				//break;
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
///
///
//
#include "stdafx.h"
#include "stack.h"

//###Implement stack.cpp##
//
//#define STACK_LENGTH 128  
//#define INT_MIN 0
//
//struct stack {
//	int top;
//
//	int buf[STACK_LENGTH];
//};
//
//struct stack S;
//
//int stack_empty(void)
//{
//	return S.top == 0;
//}
//
//int stack_full(void)
//{
//	return S.top == STACK_LENGTH;
//}
//
//int pop(void)
//{
//	if (stack_empty()) {
//		printf("Stack underflow!\n");
//		return INT_MIN;
//	}
//
//	return S.buf[--S.top];
//}
//
///*int gettop(void)
//{
//if (stack_empty()) {
//printf("Stack underflow!\n");
//return INT_MIN;
//}
//
//return S.buf[S.top - 1];
//}*/
//
//void push(int x)
//{
//	if (stack_full()) {
//		printf("Stack overflow!\n");
//		return;
//	}
//
//	S.buf[S.top++] = x;
//}
////
///
//###Define stack.h##
//
//#pragma once
//#ifndef __STACK_H__
//#define __STACK_H__
//
//int stack_empty(void);
//int stack_full(void);
//int pop(void);
////int gettop(void);  
//void push(int x);
//
//#endif // !__STACK_H__
/////

#include "stdafx.h" 
#include "stack.h"  

#define N 6  

struct adj_matrix {
	int vertex[N];
	int edge[N][N];
};

struct adj_matrix matrix = {
	{ 1, 2, 3, 4, 5, 6 },

	{ { 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 1, 1 },
	{ 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 1 } }
};

int visit[N] = { 0, 0, 0, 0, 0, 0 };

void dfs(struct adj_matrix *G)
{
	int i, j;
	int x;

	for (i = 0; i < N; i++) {
		if (visit[i] != 1) {
			visit[i] = 1;
			printf("%3d", G->vertex[i]);
			push(i);

			while (!stack_empty()) {
				x = pop();
				for (j = 0; j < N; j++) {
					if (G->edge[x][j] == 1 && visit[j] != 1) {
						visit[j] = 1;
						printf("%3d", G->vertex[j]);
						push(j);
						break;
					}
				}
			}
		}
	}
}

int main(void)
{
	dfs(&matrix);
	printf("\n");

	return 0;
}

////
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

	{ { 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 1, 1 },
	{ 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 1 } }
};

int visit[N] = { 0, 0, 0, 0, 0, 0 };

void dfs(struct adj_matrix *G)
{
	int i, j;
	int x;

	for (i = 0; i < N; i++) {
		if (visit[i] != 1) {
			visit[i] = 1;
			printf("%3d", G->vertex[i]);
			stcVal.push(i);

			while (!stcVal.empty()) {
				x = stcVal.top();
				for (j = 0; j < N; j++) {
					if (G->edge[x][j] == 1 && visit[j] != 1) {
						visit[j] = 1;
						printf("->%d", G->vertex[j]);
						stcVal.push(j);
						break;
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
		if (top1<top2)
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
	//dfs(&matrix);
	printf("\n");
	stack<int> stckIntV;
	int randomTable[] = { 1, 6, 4, 2, 3, 8, 7, 5};
	for (size_t i = 0; i < 8; i++)
	{
		stckIntV.push(randomTable[i]);
		maxTop(stckIntV);
		int num = stckIntV.top();
		printf("C_top%d\n", num);
	}

	for (size_t i = 0; i < 8; i++)
	{
		//
	}
	return 0;
}
