#include "head.h"

bool SelectionSort::SetValue(SqList data){
	//�洢����
	DataList=data;
	return true;
}
void SelectionSort::OutputData(){
	//�������
	int i;
	for(i=1;i<=DataList.length;++i){
		cout << DataList.r[i].key << " ";
	}
	cout << endl;
}
void SelectionSort::Adjust(int s,int m){
	//��������
	RedType rc=DataList.r[s];
	int j;
	for(j=2*s;j<=m;j*=2){
		if(j<m && LT(DataList.r[j].key,DataList.r[j+1].key))++j;//jΪ�ϴ�ļ�¼�±�
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
		
		//���� 1 �� i ��ֵ
		rc=DataList.r[1];
		DataList.r[1]=DataList.r[i];
		DataList.r[i]=rc;

		Adjust(1,i-1);
	}
	return true;
}