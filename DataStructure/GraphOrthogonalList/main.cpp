/*
	主函数
*/

#include "head.h"

int main(void){
	OLGraph G;
	int visited[MAX_VERTEX_NUM];
	CreatDG(G);
	printDG(G);
	printf("\n广度遍历:\n");
	DFSTraverse(G,VisitG,visited);
	printf("\n深度遍历:\n");
	BFSTraverse(G,VisitG,visited);
	printf("\nResult End!\n");
	system("pause");
	return 0;
}