/*
	数据结构操作源码
*/

#include "head.h"

int com(ElemType e1,ElemType e2){
	//比较函数
	if(e1.expn==e2.expn)return 0;
	if(e1.expn>=e2.expn)return 1;
	return -1;
}//com

void InputData(ElemType &e){
	//输入数据
	printf("Input coef(float) and expn(int):");
	scanf("%f%d",&e.coef,&e.expn);
}