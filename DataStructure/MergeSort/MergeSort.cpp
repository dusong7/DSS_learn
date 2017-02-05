/*

�鲢����

*/

#include"head.h"
void Merge::merge(RedType SR[],RedType TR[],int i,int m,int n){
	//�������SR[i...m]��SR[m+1...n]�鲢ΪTR[i..n]
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n; ++k){//��С������TR
		if(LQ(SR[i].key,SR[j].key))TR[k]=SR[i++];
		else TR[k]=SR[j++];
	}
	if(i<=m)for(l=0;l<=n-k;++l)TR[k+l]=SR[i+l];
	if(j<=n)for(l=0;l<=n-k;++l)TR[k+l]=SR[j+l];
}
void Merge::MSort(RedType SR[],RedType TR1[],int s,int t){
	//��SR[s..t]�鲢ΪTR1[s..t]
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
	//����ֵ
	SL=data;
}
void Merge::Sort(){
	//���й鲢����
	MSort(SL->r,SL->r,1,SL->length);
}
void Merge::OutputData(){
	//�������
	int i;
	for(i=1;i<=SL->length;++i){
		cout << SL->r[i].key << " ";
	}
	cout << endl;
}