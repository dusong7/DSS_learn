/*
	数据结构操作源码
*/

#include "head.h"

Status input(TElemType &e){
	//输入
	printf("Input num:");
	scanf("%d",&e);
	if(e==0)return ERROR;
	return OK;
}

Status Visit(TElemType e){
	//遍历访问
	printf("%4d ",e);
	if(e==0)return ERROR;
	return OK;
}