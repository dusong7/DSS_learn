/*
	���ݽṹ����Դ��
*/

#include "head.h"

void inputNum(int &m,int &n,int &tu){
	//������ֵ mΪ�� nΪ�� tuΪ����
	printf("Input m n tu:");
	scanf("%d%d%d",&m,&n,&tu);
}

Status InputData(OLNode &e,CrossList M){
	//����e��ϡ����ֵ
	printf("i j e:");
	scanf("%d%d%d",&e.i,&e.j,&e.e);
	if(e.i==0 || e.j==0 || e.i>M.mu || e.j>M.nu)return ERROR;
	else return OK;
}