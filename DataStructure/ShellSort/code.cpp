/*
	数据结构操作源码
*/

#include "head.h"

void PrintData(SqList L){
	//打印数据
	int i;
	printf("\nThe result is:\n");
	for(i=1;i<=L.length;i++){
		printf("%d ",L.r[i].key);
	}
	printf("\n");
}

void RandomData(SqList &L){
	//生成随机数
	int i;
	L.length=MAXSIZE;
	for(i=1;i<=L.length;i++){
		L.r[i].key=(rand()%100);
	}
}