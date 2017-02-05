/*
	数据结构操作源码
*/

#include "head.h"

void input(ElemType &e){
	printf("Input name:");
	scanf("%s",e.name);
	printf("Input age:");
	scanf("%d",&e.age);
}