/*
	���ݽṹ����Դ��
*/

#include "head.h"

void PrintData(SqList L){
	//��ӡ����
	int i;
	printf("\nThe result is:\n");
	for(i=1;i<=L.length;i++){
		printf("%d ",L.r[i].key);
	}
	printf("\n");
}

void RandomData(SqList &L){
	//���������
	int i;
	L.length=MAXSIZE;
	for(i=1;i<=L.length;i++){
		L.r[i].key=(rand()%100);
	}
}