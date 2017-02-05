/*

简单插入排序

*/

#include"head.h"

void InsertSort(SqList &L){
	//对顺序表进行直接插入排序
	int i,j;
	for(i=2;i<=L.length;i++){
		if(LT(L.r[i].key,L.r[i-1].key)){
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for(j=i-2;LT(L.r[0].key,L.r[j].key);--j){
				L.r[j+1]=L.r[j];
			}
			L.r[j+1]=L.r[0];
		}
	}
}

void BInsertSort(SqList &L){
	//折半插入排序
	int i,j,low,high,m;
	for(i=2;i<=L.length;++i){
		L.r[0].key=L.r[i].key;//数据暂存r[0]
		low=1;
		high=i-1;
		while(low<=high){
			m=(low+high)/2;
			if(LT(L.r[0].key,L.r[m].key))
				high=m-1;
			else 
				low=m+1;
		}
		for(j=i-1;j>=high+1;--j)
			L.r[j+1]=L.r[j];
		L.r[high+1]=L.r[0];
	}
}//BInsertSort

