/*
	主函数
*/

#include "head.h"

int main(void){
	int n;
	printf("Input expression(Must end by '-' '+' ')'):\n");
	//输入字符必须以 - + 或者 ）结尾，且双##结束输入
	n=OperaType();

	printf("\nThe result is:%d\n",n);
	printf("\nResult End!\n");
	system("pause");
	return 0;
}