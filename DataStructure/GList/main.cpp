/*
	主函数
	该主函数写得不咋地，没办法运行
*/

#include "head.h"

int main(void){
	GList L;
	InitGList(L);
	SString S;
	InitString(S,"(123),(12ddfa)");
	CreateGList(L,S);

	printf("\nResult End!\n");
	system("pause");
	return 0;
}