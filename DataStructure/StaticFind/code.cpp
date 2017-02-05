/*
	数据结构操作源码
*/

#include "head.h"

Status RandNumber(SSTable &ST){
	//随机输入一些数字到数组中
	int i;
	for(i=1;i<=ST.length;i++){
		ST.elem[i].key=rand()%50+1;
	}
	return OK;
}
Status RandOrderNumber(SSTable &ST){
	//随机生成有序数字到数组中
	int n;
	ST.elem[0].key=0;
	for(int i=1;i<=ST.length;i++){
		//n=rand()%5+1;
		n=i;
		ST.elem[i].key=n;
	}
	return OK;
}

void OutArray(SSTable ST){
	//输出ST的数组
	printf("\nElem Array:");
	for(int i=1;i<=ST.length;++i)printf("%d ",ST.elem[i].key);
	printf("\n");
}
