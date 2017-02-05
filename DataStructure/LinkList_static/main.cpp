/*
	主函数
*/

#include "head.h"

int main(void){
	SLinkList space;
	int s;
	difference(space,s,input,com);
	printf("\nThe result is:\n\n");
	while(s=space[s].cur){//以s为游标移动并起判断作用
		printf("%s => %d\n",space[s].data.name,space[s].data.age);
	}

	printf("\nResult End!\n");
	system("pause");
	return 0;
}