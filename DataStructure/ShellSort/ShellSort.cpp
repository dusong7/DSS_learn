/*
	
	希尔排序

*/

#include"head.h"

void ShellInsert(SqList &L,int dk){
	//对顺序表进行一次希尔插入排序
	//  前后记录位置的增量为 dk，而不是 1
	//  r[0]是暂存单元，而不是哨兵。当j<=0时，插入位置已经找到
	int i,j;
	for(i=dk+1;i<=L.length;++i){
		if(LT(L.r[i].key,L.r[i-dk].key)){
			L.r[0]=L.r[i];
			for(j=i-dk;j>0 && LT(L.r[0].key,L.r[j].key);j-=dk){
				L.r[j+dk]=L.r[j];
			}
			L.r[j+dk]=L.r[0];
		}
	}
}
void ShellSort(SqList &L){
	int increment=1;
	do{
		increment=increment/3+1;
		ShellInsert(L,increment);
	}while(increment>1);
}

