/*
	���ݽṹ����Դ��
*/

#include "head.h"

void PrintData(SLinkListType L){
	//��ӡ����
	int i;
	printf("\nThe result is:\n");
	for(i=1;i<=L.length;i++){
		printf("%d ",L.r[i].rc);
	}
	printf("\n");
}

void RandomData(SLinkListType &L){
	//���������
	int i;
	L.r[0].rc=INT_MAX;
	L.length=20;
	for(i=1;i<=L.length;i++){
		L.r[i].rc=(rand()%100);
	}
}