/*
	数据结构操作源码
*/

#include "head.h"

Status VisitG(OLGraph G,int v){//遍历函数
	printf("ID:%d\t序号:%d\n",v,G.xlist[v].data);
	return OK;
}

void PrintList(int list[MAX_VERTEX_NUM],int n){
	//输出列表
	printf("list:");
	for(int i=0;i<n;i++)printf("%d ",list[i]);
	printf("\n");
}