/*
	������
*/

#include "head.h"

int main(void){
	OLGraph G;
	int visited[MAX_VERTEX_NUM];
	CreatDG(G);
	printDG(G);
	printf("\n��ȱ���:\n");
	DFSTraverse(G,VisitG,visited);
	printf("\n��ȱ���:\n");
	BFSTraverse(G,VisitG,visited);
	printf("\nResult End!\n");
	system("pause");
	return 0;
}