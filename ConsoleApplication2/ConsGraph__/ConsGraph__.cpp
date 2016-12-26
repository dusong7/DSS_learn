// ConsGraph__.cpp : Defines the entry point for the console application.
//

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
#include <stack>

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
		//printf("val%d", i);
		if (visit[i] != 1) {
			visit[i] = 1;
			printf("%3d", G->vertex[i]);
			push(i);

			while (!stack_empty()) {
				x = pop();
				printf("x:%d\n", x);
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