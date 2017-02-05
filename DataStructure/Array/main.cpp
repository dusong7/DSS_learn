/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	Array arr;
	InitArray(arr,3,2,3,4);
	ElemType e;
	int i,j,k;
	for(i=0;i<2;i++)for(j=0;j<3;j++)for(k=0;k<4;k++)
	{
		printf("arr %d %d %d:",i,j,k);
		scanf("%d",&e);
		Assign(arr,e,i,j,k);
	}
	printf("\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			for(k=0;k<4;k++)
			{
				Value(e,arr,i,j,k);
				printf("%d ",e);
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("\nResult End!\n");
	system("pause");
	return 0;
}