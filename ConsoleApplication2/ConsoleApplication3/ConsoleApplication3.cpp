//// ConsoleApplication3.cpp : Defines the entry point for the console application.
////
//
#include "stdafx.h"
#include <iostream>
//#include "Head.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <thread>
//
using namespace std;
//
//const int invalid_p = -1;
//int gtm = 0;
//enum Color { w, g, b };
//
//struct DFS_struct {
//	Color color;
//	int parent;
//	int dtime, ftime;  //�0�5�0�3�0�8�0�0�0�8�0�2���0�4�0�3�0�0�0�8���0�4�0�1�0�2�0�1�0�9�0�3�0�5�0�7�����0�7���0�1���0�1���0�6�0�7�0�8���0�4�0�1
//};
//
//void DFS_visit(adjNode *adjList, DFS_struct *dfsArray, int u) {
//	int v;
//	adjNode *tempNode;
//
//	dfsArray[u].color = g;
//	gtm += 1;
//	dfsArray[u].dtime = gtm;
//
//	tempNode = adjList[u].next;
//	while (tempNode != NULL) {
//		v = tempNode->node;
//		if (dfsArray[v].color == w) {
//			dfsArray[v].parent = u;
//			DFS_visit(adjList, dfsArray, v);
//		}
//
//		tempNode = tempNode->next;
//	}
//
//	dfsArray[u].color = b;
//	gtm += 1;
//	dfsArray[u].ftime = gtm;
//}
//
//void DFS(adjNode *adjList, DFS_struct *dfsArray, int n, vector<int> &forestRoots) {
//	int i;
//	for (i = 0; i<n; ++i) {
//		dfsArray[i].color = w;
//		dfsArray[i].parent = invalid_p;
//		dfsArray[i].dtime = 0;
//		dfsArray[i].ftime = 0;
//	}
//
//	gtm = 0;
//	for (i = 0; i<n; ++i)
//		if (dfsArray[i].color == w) {
//			DFS_visit(adjList, dfsArray, i);    //�0�1�0�7�0�7�0�2�0�8�0�7�0�1�0�9�0�4�0�3���0�7���0�6�0�7�0�6�0�3�0�7�0�1�0�7�0�6�0�9�0�6�0�7�0�3�0�3�0�6�0�9�0�5�0�9�0�8�0�5�0�1���0�6�0�0�0�9�0�7���0�6�0�7�0�7�0�6�0�9�0�6�0�7�0�3�0�3�0�6�0�9�0�5�0�9�0�7�0�2�0�9�0�0
//			forestRoots.push_back(i);
//		}
//}
//
//int main() {
//	int *matrix;
//	adjNode *adjList, *tempNode;
//	int nodeNum = 0, i, j;
//	DFS_struct *dfsArray;
//	vector<int> forestRoots;        //forestRoots�0�0�0�4���0�5�0�7�0�3�0�1�0�7�0�7�0�1�0�7�0�6�0�9�0�6�0�7�0�3�0�3�0�6�0�9�0�5�0�9�0�8�0�8�0�2�0�8�0�0���0�5�0�3�0�8�0�0�����0�2�0�3
//
//	printf("Input node number: ");
//	scanf("%d", &nodeNum);
//
//	matrix = (int *)malloc(sizeof(int)*nodeNum*nodeNum);
//	adjList = (adjNode *)malloc(sizeof(adjNode)*nodeNum);
//
//	for (i = 0; i<nodeNum; ++i)
//		for (j = 0; j<nodeNum; ++j)
//			scanf("%d", matrix + i*nodeNum + j);
//
//	/*�0�6�0�8�0�6�0�1�0�9���0�4�0�2�0�8�0�5�0�8�0�1�0�6�0�2�0�1�0�4*/
//	printf("matrix: \n");
//	for (i = 0; i<nodeNum; ++i) {
//		for (j = 0; j<nodeNum; ++j)
//			printf("%d ", *(matrix + i*nodeNum + j));
//		printf("\n");
//	}
//
//	matrixToAdjlist(matrix, adjList, nodeNum);
//	/*�0�6�0�8�0�9�0�3�0�5�0�7�����0�4�0�2�0�8�0�5�0�8�0�1�0�6�0�2�0�1�0�4*/
//	printf("adjacency list: \n");
//	for (i = 0; i<nodeNum; ++i) {
//		printf("node %d:", adjList[i].node);
//		tempNode = adjList[i].next;
//		while (tempNode != NULL) {
//			printf("->%d", tempNode->node);
//			tempNode = tempNode->next;
//		}
//		printf("\n");
//	}
//
//	dfsArray = (DFS_struct *)malloc(sizeof(DFS_struct)*nodeNum);
//	DFS(adjList, dfsArray, nodeNum, forestRoots);
//
//	/*�0�8�0�3�0�9�0�9�0�8�0�7�0�7�0�6�0�9�0�6�0�7�0�3�0�3�0�6�0�9�0�5�0�9�0�7�0�2�0�9�0�0�0�6�0�5�0�6�0�2�0�5���0�9�0�4�0�5�0�1�0�7�0�7�0�6�0�8�0�5�0�3�0�4�0�4���0�8�0�8�0�2�0�5�0�2����*/
//	printf("DFS learning completed\n");
//	printf("forest roots:");
//	for (i = 0; i<(int)forestRoots.size(); ++i)
//		printf("%d ", forestRoots[i]);
//	printf("\n");
//
//
//	free(matrix);
//	free(dfsArray);
//	freeAdjList(adjList, nodeNum);
//	getchar();
//	return 0;
//}

#include <stdio.h>  
#include <malloc.h>  
#include <vector>
#define VERTEXNUM 5  

void createGraph(int(*edge)[VERTEXNUM], int start, int end);
void displayGraph(int(*edge)[VERTEXNUM]);
void DFT(int(*edge)[VERTEXNUM], int* vertexStatusArr);
void DFTcore(int(*edge)[VERTEXNUM], int i, int* vertexStatusArr);
vector<int> vecTreavse;

int main(void) 
{
	//�0�9�0�4�0�0�0�1�0�7�0�7�0�5���0�7�0�3���0�3���0�8�0�8�0�2�0�9�0�6�0�2�0�1�0�8�0�5����  
	int(*edge)[VERTEXNUM] = (int(*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);
	int i, j;
	for (i = 0; i<VERTEXNUM; i++) {
		for (j = 0; j<VERTEXNUM; j++) {
			edge[i][j] = 0;
		}
	}
	//�0�7�0�3���0�3�0�9�0�6�0�8�0�0�0�8�0�2�����0�8�����0�7�0�0�0�1�0�5�0�10�0�5�0�2�0�2�0�7�����0�8���0�5�0�11�0�5�0�2�0�6�0�5�����0�8��    
	int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);
	for (i = 0; i<VERTEXNUM; i++) {
		vertexStatusArr[i] = 0;
	}

	printf("after init:\n");
	displayGraph(edge);
	//�0�7�0�7�0�5���0�1�0�4  
	createGraph(edge, 0, 1);
	createGraph(edge, 0, 4);
	createGraph(edge, 3, 1);
	//createGraph(edge, 3, 2);
	//createGraph(edge, 4, 1);
	//createGraph(edge, 4, 4);


	printf("after create:\n");
	displayGraph(edge);
	//�0�7�0�6�0�9�0�6�0�7�0�3�0�3�0�6�����0�8��  
	DFT(edge, vertexStatusArr);

	free(edge);
	free(vertexStatusArr);

	for (size_t i = 0; i < vecTreavse.size(); i++)
	{
		cout << vecTreavse[i];
	}

	getchar();

	return 0;
}
//�0�7�0�7�0�5���0�1�0�4   
void createGraph(int(*edge)[VERTEXNUM], int start, int end) {
	edge[start][end] = 1;
}
//�0�7���0�7�0�3�0�7�0�3�0�7�0�4�0�8�0�2�0�1�0�4  
void displayGraph(int(*edge)[VERTEXNUM]) {
	int i, j;
	for (i = 0; i<VERTEXNUM; i++) {
		for (j = 0; j<VERTEXNUM; j++) {
			printf("%d ", edge[i][j]);
		}
		printf("\n");
	}
}
int isEnd = false;
//�0�7�0�6�0�9�0�6�0�7�0�3�0�3�0�6�����0�8��  
void DFT(int(*edge)[VERTEXNUM], int* vertexStatusArr) {
	printf("start BFT graph:\n");
	int i;
	for (i = 0; i<VERTEXNUM; i++) {
		printf("f(%d)", i);
		if (isEnd)
		{
			//break;
		}
		DFTcore(edge, i, vertexStatusArr);
	}
	printf("\n");
}

void DFTcore(int(*edge)[VERTEXNUM], int i, int* vertexStatusArr) {
	if (i == 6)
	{
		isEnd = true;
	}
	//
	printf("i(%d)",i);
	if (vertexStatusArr[i] == 1) {
		return;
	}
	//printf("i(%d)", i);
	vecTreavse.push_back(i);

	vertexStatusArr[i] = 1;

	int j;
	for (j = 0; j<VERTEXNUM; j++) {
		printf("Trev_j(%d,_%d)\n", i, j);
		if (edge[i][j] == 1) {
			printf("Hit(%d,_%d)\n",i, j);
			DFTcore(edge, j, vertexStatusArr);
		}
	}
}
