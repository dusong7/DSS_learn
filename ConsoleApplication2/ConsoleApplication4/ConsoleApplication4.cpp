#include "stdafx.h"
#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 5  
//��Ŷ�����ڽӱ�Ԫ��    
typedef struct edge {
	int vertex;
	struct edge* next;
}st_edge;

void createGraph(st_edge** edge, int start, int end);
void displayGraph(st_edge** edge);
void delGraph(st_edge** edge);
void DFT(st_edge** edge, int* vertexStatusArr);
void DFTcore(st_edge** edge, int i, int* vertexStatusArr);

int main(void) {
	//��̬������űߵ�ָ������     
	st_edge** edge = (st_edge**)malloc(sizeof(st_edge*)*VERTEXNUM);
	int i;
	for (i = 0; i<VERTEXNUM; i++) {
		edge[i] = NULL;
	}
	//��Ŷ���ı���״̬��0��δ������1���ѱ���    
	int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);
	for (i = 0; i<VERTEXNUM; i++) {
		vertexStatusArr[i] = 0;
	}

	printf("after init:\n");
	displayGraph(edge);
	//����ͼ    
	createGraph(edge, 0, 3);
	createGraph(edge, 0, 4);
	createGraph(edge, 3, 1);
	createGraph(edge, 3, 2);
	createGraph(edge, 4, 1);

	//createGraph(edge, 3, 0);
	//createGraph(edge, 4, 0);
	//createGraph(edge, 1, 3);
	//createGraph(edge, 2, 3);
	//createGraph(edge, 1, 4);

	printf("after create:\n");
	displayGraph(edge);
	//������ȱ���   
	DFT(edge, vertexStatusArr);
	//�ͷ��ڽӱ�ռ�õ��ڴ�    
	delGraph(edge);
	edge = NULL;
	free(vertexStatusArr);
	vertexStatusArr = NULL;
	return 0;
}
//����ͼ   
void createGraph(st_edge** edge, int start, int end) {
	st_edge* newedge = (st_edge*)malloc(sizeof(st_edge));
	newedge->vertex = end;
	newedge->next = NULL;
	edge = edge + start;
	while (*edge != NULL) {
		edge = &((*edge)->next);
	}
	*edge = newedge;
}
//��ӡ�洢��ͼ   
void displayGraph(st_edge** edge) {
	int i;
	st_edge* p;
	for (i = 0; i<VERTEXNUM; i++) {
		printf("%d:", i);
		p = *(edge + i);
		while (p != NULL) {
			printf("%d ", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}
//�ͷ��ڽӱ�ռ�õ��ڴ�   
void delGraph(st_edge** edge) {
	int i;
	st_edge* p;
	st_edge* del;
	for (i = 0; i<VERTEXNUM; i++) {
		p = *(edge + i);
		while (p != NULL) {
			del = p;
			p = p->next;
			free(del);
		}
		edge[i] = NULL;
	}
	free(edge);
}
//������ȱ���   
void DFT(st_edge** edge, int* vertexStatusArr) {
	printf("start BFT graph:\n");
	int i;
	for (i = 0; i<VERTEXNUM; i++) {
		DFTcore(edge, i, vertexStatusArr);
	}
	printf("\n");
}

void DFTcore(st_edge** edge, int i, int* vertexStatusArr) {
	if (vertexStatusArr[i] == 1) {
		return;
	}
	printf("%d ", i);
	vertexStatusArr[i] = 1;
	st_edge* p = *(edge + i);
	while (p != NULL) {
		DFTcore(edge, p->vertex, vertexStatusArr);
		p = p->next;
	}
}