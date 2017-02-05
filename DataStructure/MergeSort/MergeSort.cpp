/*

归并排序

*/

#include"head.h"
void Merge::merge(RedType SR[],RedType TR[],int i,int m,int n){
	//将有序表SR[i...m]和SR[m+1...n]归并为TR[i..n]
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n; ++k){//由小到大并入TR
		if(LQ(SR[i].key,SR[j].key))TR[k]=SR[i++];
		else TR[k]=SR[j++];
	}
	if(i<=m)for(l=0;l<=n-k;++l)TR[k+l]=SR[i+l];
	if(j<=n)for(l=0;l<=n-k;++l)TR[k+l]=SR[j+l];
}
void Merge::MSort(RedType SR[],RedType TR1[],int s,int t){
	//将SR[s..t]归并为TR1[s..t]
	int m;
	RedType *TR2=new RedType[SL->length];
	if(s==t)TR1[s]=SR[s];
	else{
		m=(s+t)/2;
		MSort(SR,TR2,s,m);
		MSort(SR,TR2,m+1,t);
		merge(TR2,TR1,s,m,t);
	}
}
void Merge::SetValue(SqList * data){
	//设置值
	SL=data;
}
void Merge::Sort(){
	//进行归并排序
	MSort(SL->r,SL->r,1,SL->length);
}
void Merge::OutputData(){
	//输出数据
	int i;
	for(i=1;i<=SL->length;++i){
		cout << SL->r[i].key << " ";
	}
	cout << endl;
}