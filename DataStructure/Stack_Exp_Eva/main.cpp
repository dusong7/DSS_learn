/*
	������
*/

#include "head.h"

int main(void){
	int n;
	printf("Input expression(Must end by '-' '+' ')'):\n");
	//�����ַ������� - + ���� ����β����˫##��������
	n=OperaType();

	printf("\nThe result is:%d\n",n);
	printf("\nResult End!\n");
	system("pause");
	return 0;
}