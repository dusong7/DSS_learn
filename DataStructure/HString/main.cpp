/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	HString T,T2,T3;
	InitString(T);
	InitString(T2);
	InitString(T3);
	StrAssigne(T,"123456789");
	printf("T:%s\n",T.ch);
	SubString(T2,T,2,6);
	printf("T2:%s\n",T2.ch);
	Concat(T3,T2,T);
	printf("T3:%s\n",T3.ch);
	printf("T2 cmp T3 is %d\n",StrCompare(T2,T3));
	printf("\nResult End!\n");
	system("pause");
	return 0;
}