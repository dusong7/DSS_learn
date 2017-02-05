/*
	主函数
*/

#include "head.h"

int main(void){
	SSTable ST,ST2;
	int num,i;//随机生成的查找数字

	//Swquential Search
	printf("\nSwquential Search:\n");
	Init_Seq(ST,30,RandNumber);
	OutArray(ST);

	for(i=0;i<20;i++){
		num=rand()%50+1;
		printf("%d: Sreach: %d , Result: %d\n",i+1,num,Search_Seq(ST,num));
	}

	//Binary Search
	printf("\nBinary Search:\n");
	Init_Seq(ST2,30,RandOrderNumber);
	OutArray(ST2);
	for(i=0;i<30;i++){
		//num=rand()%80+1;
		num=i+1;
		printf("%d: Sreach: %d , Result: %d\n",i+1,num,Search_Bin(ST2,num));
	}

	//次优先树查找
	printf("\nNearly Optimal Search Tree:\n");
	SOSTree T;
	CreateSOSTree(T,ST2);
	for(i=0;i<30;i++){
		//num=rand()%80+1;
		num=i+1;
		printf("%d: Sreach: %d , Result: %d\n",i+1,num,Search_SOSTree(T,num));
	}

	printf("\nResult End!\n");
	system("pause");
	return 0;
}