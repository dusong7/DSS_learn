/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	LinkList La,Lb;
	int N;
	printf("Input La node link number:");
	scanf("%d",&N);
	CreatPolyn(La,N,InputData);
	PrintPolyn(La);

	printf("\nInput Lb node link number:");
	scanf("%d",&N);
	CreatPolyn(Lb,N,InputData);
	PrintPolyn(Lb);
	
	printf("\nLa Sub Lb:");
	SubPoly(La,Lb,com);
	PrintPolyn(La);
	printf("\n");


	printf("\nResult End!\n");
	system("pause");
	return 0;
}