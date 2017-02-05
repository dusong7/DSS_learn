#include "head.h"

bool SelectionSort::SetValue(SqList data){
	//存储数据
	DataList=data;
	return true;
}
void SelectionSort::OutputData(){
	//输出数据
	int i;
	for(i=1;i<=DataList.length;++i){
		cout << DataList.r[i].key << " ";
	}
	cout << endl;
}
void SelectionSort::Adjust(int s,int m){
	//调整数据
	RedType rc=DataList.r[s];
	int j;
	for(j=2*s;j<=m;j*=2){
		if(j<m && LT(DataList.r[j].key,DataList.r[j+1].key))++j;//j为较大的记录下标
		if(!LT(rc.key,DataList.r[j].key))break;
		DataList.r[s]=DataList.r[j];
		s=j;
	}
	DataList.r[s]=rc;
}
bool SelectionSort::Sort(){
	int i;
	RedType rc;
	for(i=DataList.length/2;i>0;--i){
		Adjust(i,DataList.length);
	}
	for(i=DataList.length;i>1;--i){
		
		//交换 1 和 i 的值
		rc=DataList.r[1];
		DataList.r[1]=DataList.r[i];
		DataList.r[i]=rc;

		Adjust(1,i-1);
	}
	return true;
}