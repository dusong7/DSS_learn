/*
	���ݽṹ����Դ��
*/

#include "head.h"

Status InputElemType(ElemType &e){
	//����Ԫ��
	//printf("��������:");
	//scanf("%d",&e.key);
	e.key=rand()%50;
	return TRUE;
}
Status VisitElemType(ElemType e){
	//�����
	printf("%3d ,",e.key);
	return TRUE;
}