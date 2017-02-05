/*
	数据结构操作源码
*/

#include "head.h"

SqList * RandomData(){
	//生成随机数
	int i;
	SqList *L=new SqList();
	L->length=MAXSIZE;
	for(i=1;i<=L->length;i++){
		L->r[i].key=(rand()%100);
	}
	return L;
}