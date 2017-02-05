/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	BiThrTree T,T2;
	InitBiTree(T);
	CreateBiTree(T,input);
	InOrderThreading(T2,T);
	InOrderTraverse_Thr(T2,Visit);

	printf("\nResult End!\n");
	system("pause");
	return 0;
}