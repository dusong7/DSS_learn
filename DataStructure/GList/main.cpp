/*
	������
	��������д�ò�զ�أ�û�취����
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