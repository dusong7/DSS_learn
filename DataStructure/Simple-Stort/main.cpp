/*
	主函数
*/

#include "head.h"

int main(void){
	SqList L;
	printf("新数据:");
	RandomData(L);
	PrintData(L);
	printf("插入排序:");
	InsertSort(L);
	PrintData(L);

	printf("\n新数据:");
	RandomData(L);
	PrintData(L);
	printf("折半插入排序:");	
	BInsertSort(L);
	PrintData(L);

	printf("\nResult End!\n");
	system("pause");
	return 0;
}