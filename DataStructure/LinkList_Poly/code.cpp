/*
	���ݽṹ����Դ��
*/

#include "head.h"

int com(ElemType e1,ElemType e2){
	//�ȽϺ���
	if(e1.expn==e2.expn)return 0;
	if(e1.expn>=e2.expn)return 1;
	return -1;
}//com

void InputData(ElemType &e){
	//��������
	printf("Input coef(float) and expn(int):");
	scanf("%f%d",&e.coef,&e.expn);
}