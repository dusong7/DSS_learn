/*
	���ݽṹ����Դ��
*/

#include "head.h"

void Input(ElemType &e){
	printf("��������:");
	scanf("%s",e.name);
	printf("��������:");
	scanf("%d",&e.age);
}
int Compare(ElemType e1,ElemType e2){
	return e1.age > e2.age;
}