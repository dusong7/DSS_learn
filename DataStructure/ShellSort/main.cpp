/*
	主函数
*/

#include "head.h"

int main(void){
	SqList L;
	printf("新数据:");
	RandomData(L);
	PrintData(L);
	printf("\n希尔排序:");
	ShellSort(L);
	PrintData(L);

	printf("\nResult End!\n");
	system("pause");
	return 0;
}