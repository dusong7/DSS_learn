/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	BiTree T;
	InitBiTree(T);
	CreateBiTree(T,input);
	InOrderTraverse_Stack(T,Visit);

	printf("\nResult End!\n");
	system("pause");
	return 0;
}