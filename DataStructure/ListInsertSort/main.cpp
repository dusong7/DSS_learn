/*
	������
*/

#include "head.h"

int main(void){
	SLinkListType SL;

	printf("�����������:");
	RandomData(SL);
	PrintData(SL);
	printf("\n���������");
	Arrange(SL);
	PrintData(SL);	
	printf("\nResult End!\n");
	system("pause");
	return 0;
}