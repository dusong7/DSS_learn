/*
数据结构操作源码
*/

#include "head.h"

void get_next(SString T, int next[]){
	//求模式串T的next函数值并存入数组next
	int i,j;
	i = 1; next[1] = 0; j = 0;
	while (i < T[0]){
		if(j ==0 || T[i] == T[j]){
			++i; ++j; next[i] = j;
		}else{
			j = next[j];
		}
	}
}

void get_nextval(SString T,int nextval[]){
	//求模式串T的next函数值修正并存入nextval中
	int i,j;
	i=1;
	j=0;
	nextval[1]=0;
	while(i<T[0]){
		if(j == 0 || T[i] == T[j]){
			++i;++j;
			if(T[i]  != T[j])nextval[i] = j;
			else nextval[i] = nextval[j];
		}else{
			j = nextval[j];
		}
	}
}