/*
	������
*/

#include "head.h"

int main(void){
	SqList L;
	printf("������:");
	RandomData(L);
	PrintData(L);
	printf("��������:");
	InsertSort(L);
	PrintData(L);

	printf("\n������:");
	RandomData(L);
	PrintData(L);
	printf("�۰��������:");	
	BInsertSort(L);
	PrintData(L);

	printf("\nResult End!\n");
	system("pause");
	return 0;
}