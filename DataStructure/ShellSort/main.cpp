/*
	������
*/

#include "head.h"

int main(void){
	SqList L;
	printf("������:");
	RandomData(L);
	PrintData(L);
	printf("\nϣ������:");
	ShellSort(L);
	PrintData(L);

	printf("\nResult End!\n");
	system("pause");
	return 0;
}