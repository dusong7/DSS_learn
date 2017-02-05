/*
	数据结构操作源码
*/

#include "head.h"

void inputNum(int &m,int &n,int &tu){
	//输入数值 m为行 n为列 tu为总数
	printf("Input m n tu:");
	scanf("%d%d%d",&m,&n,&tu);
}

Status InputData(OLNode &e,CrossList M){
	//输入e的稀疏数值
	printf("i j e:");
	scanf("%d%d%d",&e.i,&e.j,&e.e);
	if(e.i==0 || e.j==0 || e.i>M.mu || e.j>M.nu)return ERROR;
	else return OK;
}