/*
	数据结构操作源码
*/

#include "head.h"

Status InputElemType(ElemType &e){
	//输入元素
	//printf("输入数字:");
	//scanf("%d",&e.key);
	e.key=rand()%50;
	return TRUE;
}
Status VisitElemType(ElemType e){
	//输出数
	printf("%3d ,",e.key);
	return TRUE;
}