/*
	���ݽṹ����Դ��
*/

#include "head.h"

SqList * RandomData(){
	//���������
	int i;
	SqList *L=new SqList();
	L->length=MAXSIZE;
	for(i=1;i<=L->length;i++){
		L->r[i].key=(rand()%100);
	}
	return L;
}