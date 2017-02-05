/*
	主函数
	//该程序调试未通过
*/

#include "head.h"

int main(void){
	srand((unsigned int)time(NULL));//随机数不同
	Bank_simulation(1000);

	printf("\nResult End!\n");
	system("pause");
	return 0;
}