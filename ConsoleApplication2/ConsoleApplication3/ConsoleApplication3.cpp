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
//	int dtime, ftime;  //½ÚµãµÄ·¢ÏÖÊ±¼äºÍÁÚ½Ó±íÉ¨ÃèÍê³ÉÊ±¼ä
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
//			DFS_visit(adjList, dfsArray, i);    //Ã¿´Îµ÷ÓÃ¶¼»áÉú³ÉÒ»¿ÃÉî¶ÈÓÅÏÈËÑË÷Ê÷£¬×îÖÕÉú³ÉÉî¶ÈÓÅÏÈËÑË÷É­ÁÖ
//			forestRoots.push_back(i);
//		}
//}
//
//int main() {
//	int *matrix;
//	adjNode *adjList, *tempNode;
//	int nodeNum = 0, i, j;
//	DFS_struct *dfsArray;
//	vector<int> forestRoots;        //forestRootsÖÐ±£´æÃ¿¿ÃÉî¶ÈÓÅÏÈËÑË÷Ê÷µÄÊ÷¸ù½Úµã±àºÅ
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
//	/*ÒÔ¾ØÕóÐÎÊ½Êä³öÍ¼*/
//	printf("matrix: \n");
//	for (i = 0; i<nodeNum; ++i) {
//		for (j = 0; j<nodeNum; ++j)
//			printf("%d ", *(matrix + i*nodeNum + j));
//		printf("\n");
//	}
//
//	matrixToAdjlist(matrix, adjList, nodeNum);
//	/*ÒÔÁÚ½Ó±íÐÎÊ½Êä³öÍ¼*/
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
//	/*ÔÚÕâÀïÉî¶ÈÓÅÏÈËÑË÷É­ÁÖÒÑ¾­½¨Á¢£¬¿ÉÒÔ½øÐÐ±ðµÄ²Ù×÷*/
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
	//¶¯Ì¬´´½¨´æ·Å±ßµÄ¶þÎ¬Êý×é  
	int(*edge)[VERTEXNUM] = (int(*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);
	int i, j;
	for (i = 0; i<VERTEXNUM; i++) {
		for (j = 0; j<VERTEXNUM; j++) {
			edge[i][j] = 0;
		}
	}
	//´æ·Å¶¥µãµÄ±éÀú×´Ì¬£¬0£ºÎ´±éÀú£¬1£ºÒÑ±éÀú    
	int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);
	for (i = 0; i<VERTEXNUM; i++) {
		vertexStatusArr[i] = 0;
	}

	printf("after init:\n");
	displayGraph(edge);
	//´´½¨Í¼  
	createGraph(edge, 0, 1);
	createGraph(edge, 0, 4);
	createGraph(edge, 3, 1);
	//createGraph(edge, 3, 2);
	//createGraph(edge, 4, 1);
	//createGraph(edge, 4, 4);


	printf("after create:\n");
	displayGraph(edge);
	//Éî¶ÈÓÅÏÈ±éÀú  
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
//´´½¨Í¼   
void createGraph(int(*edge)[VERTEXNUM], int start, int end) {
	edge[start][end] = 1;
}
//´òÓ¡´æ´¢µÄÍ¼  
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
//Éî¶ÈÓÅÏÈ±éÀú  
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
