/*
	主函数
*/

#include "head.h"

int main(void){
	SLinkListType SL;

	printf("生成随机数字:");
	RandomData(SL);
	PrintData(SL);
	printf("\n表插入排序：");
	Arrange(SL);
	PrintData(SL);	
	printf("\nResult End!\n");
	system("pause");
	return 0;
}