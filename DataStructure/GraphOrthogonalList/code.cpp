/*
	���ݽṹ����Դ��
*/

#include "head.h"

Status VisitG(OLGraph G,int v){//��������
	printf("ID:%d\t���:%d\n",v,G.xlist[v].data);
	return OK;
}

void PrintList(int list[MAX_VERTEX_NUM],int n){
	//����б�
	printf("list:");
	for(int i=0;i<n;i++)printf("%d ",list[i]);
	printf("\n");
}