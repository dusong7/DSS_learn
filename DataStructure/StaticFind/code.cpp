/*
	���ݽṹ����Դ��
*/

#include "head.h"

Status RandNumber(SSTable &ST){
	//�������һЩ���ֵ�������
	int i;
	for(i=1;i<=ST.length;i++){
		ST.elem[i].key=rand()%50+1;
	}
	return OK;
}
Status RandOrderNumber(SSTable &ST){
	//��������������ֵ�������
	int n;
	ST.elem[0].key=0;
	for(int i=1;i<=ST.length;i++){
		//n=rand()%5+1;
		n=i;
		ST.elem[i].key=n;
	}
	return OK;
}

void OutArray(SSTable ST){
	//���ST������
	printf("\nElem Array:");
	for(int i=1;i<=ST.length;++i)printf("%d ",ST.elem[i].key);
	printf("\n");
}
