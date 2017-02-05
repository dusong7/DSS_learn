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
int com(ElemType e1,ElemType e2){
	return (e1.age==e2.age && strcmp(e1.name,e2.name)==0);
}