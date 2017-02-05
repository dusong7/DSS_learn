/*

快速排序

*/
#include"head.h"

int QuickSort::Partition(int low,int high){
	SL->r[0]=SL->r[low];
	int pivotkey = SL->r[low].key;
	while(low<high){
		while(low<high && SL->r[high].key>=pivotkey)
			--high;
		ExchangeValue(SL->r[low],SL->r[high]);
		while(low<high && SL->r[low].key<=pivotkey)
			++low;
		ExchangeValue(SL->r[low],SL->r[high]);
	}
	SL->r[low]=SL->r[0];
	return low;
}

bool QuickSort::ExchangeValue(RedType &a,RedType &b){
	RedType c;
	c=a;
	a=b;
	b=c;
	return true;
}
void QuickSort::QSort(int low,int high){
	//对low...hight做快速排序
	int pivotloc;
	if(low<high){
		pivotloc=Partition(low,high);
		QSort(low,pivotloc-1);
		QSort(pivotloc+1,high);
	}

}
void QuickSort::Sort(){
	QSort(1,SL->length);
}
void QuickSort::SetValue(SqList * data){
	//设置值
	SL=data;
}
void QuickSort::OutputData(){
	//输出数据
	int i;
	for(i=1;i<=SL->length;++i){
		cout << SL->r[i].key << " ";
	}
	cout << endl;
}