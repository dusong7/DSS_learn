/*
	三元组 数据函数
*/

#include "head.h"

Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3){
	T = (ElemType *)malloc(3*sizeof(ElemType));
	if(!T)exit(OVERFLOW);
	//当ElemType为非数值时，以下语句无效
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return OK;
}

Status DestroyTriplet(Triplet &T){
	//销毁数据
	free(T);
	T=NULL;
	return OK;
}

Status Get(Triplet T,int i,ElemType &e){
	//返回值
	if(i<1 || i>3)return ERROR;
	e = T[i-1];
	return OK;
} 

Status Put(Triplet &T,int i,ElemType e){
	//更新值
	if(i<1 || i>3)return ERROR;
	T[i-1] = e;
	return OK;
}

Status IsAsceding(Triplet T){
	//判断是否以升序排列
	return (T[0]<T[1] && T[1]<T[2]);
}

Status IsDsceding(Triplet T){
	//判断是否以降序排列
	return (T[0]>T[1] && T[1]>T[2]);
}
Status Max(Triplet T,ElemType &e){
	//返回最大值
	e = (T[0]>=T[1])?((T[0]>=T[2])?T[0]:T[2]):((T[1]>=T[2])?T[1]:T[2]);
	return OK;
}

Status Min(Triplet T,ElemType &e){
	//返回最大值
	e = (T[0]<=T[1])?((T[0]<=T[2])?T[0]:T[2]):((T[1]<=T[2])?T[1]:T[2]);
	return OK;
}
