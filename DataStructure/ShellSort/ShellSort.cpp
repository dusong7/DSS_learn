/*
	
	ϣ������

*/

#include"head.h"

void ShellInsert(SqList &L,int dk){
	//��˳������һ��ϣ����������
	//  ǰ���¼λ�õ�����Ϊ dk�������� 1
	//  r[0]���ݴ浥Ԫ���������ڱ�����j<=0ʱ������λ���Ѿ��ҵ�
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

