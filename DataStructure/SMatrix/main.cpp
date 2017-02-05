/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
/*
	TSMatrix T,M,K;
	for(int i=1;i<9;i++){
		printf("%d i j k:",i);
		scanf("%d%d%d",&T.data[i].i,&T.data[i].j,&T.data[i].e);
	}
	printf("\n");
	T.mu=6,T.nu=7,T.tu=8;
	printSMatrix(T);
	
	TransposeSMatrix(T,M);
	printf("\n");
	printSMatrix(M);
	FastTransposeSMatrix(M,K);
	printf("\n");
	printSMatrix(K);
*/
	RLSMatrix T,T2,M;
	int i=0,j=0,num,l;
	printf("input num:");
	scanf("%d",&l);
	for(num=1;num<=l;num++){
		printf("%d i j k:",num);
		scanf("%d%d%d",&T.data[num].i,&T.data[num].j,&T.data[num].e);	
		if(T.data[num].i>i)i=T.data[num].i;
		if(T.data[num].j>j)j=T.data[num].j;
	}
	T.mu=i;
	T.nu=j;
	T.tu=l;
	printMultSMatrix(T);
	InitRLSMatrixRpos(T);

	i=0,j=0;
	for(num=1;num<=l;num++){
		printf("%d i j k:",num);
		scanf("%d%d%d",&T2.data[num].i,&T2.data[num].j,&T2.data[num].e);	
		if(T2.data[num].i>i)i=T2.data[num].i;
		if(T2.data[num].j>j)j=T2.data[num].j;
	}
	T2.mu=i;
	T2.nu=j;
	T2.tu=l;
	printMultSMatrix(T2);
	InitRLSMatrixRpos(T2);

	system("pause");
	MultSMatrix(T,T2,M);
	printf("\n");
	printMultSMatrix(M);
	printf("\n");
	printf("\nResult End!\n");
	system("pause");
	return 0;
}