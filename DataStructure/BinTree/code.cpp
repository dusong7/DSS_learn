/*
	���ݽṹ����Դ��
*/

#include "head.h"

Status input(TElemType &e){
	//����
	printf("Input num:");
	scanf("%d",&e);
	if(e==0)return ERROR;
	return OK;
}

Status Visit(TElemType e){
	//��������
	printf("%4d ",e);
	if(e==0)return ERROR;
	return OK;
}