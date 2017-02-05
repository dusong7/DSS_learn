/*
	数据结构操作源码
*/

#include "head.h"

void Input(ElemType &e){
	printf("输入姓名:");
	scanf("%s",e.name);
	printf("输入年龄:");
	scanf("%d",&e.age);
}
int Compare(ElemType e1,ElemType e2){
	return e1.age > e2.age;
}