/*
	主函数
*/

#include "head.h"

int main(void){
	ElemType *T,v,v1,v2,v3;
	int i;
	printf("Input v1,v2,v3 values:");
	scanf("%d%d%d",&v1,&v2,&v3);
	InitTriplet(T,v1,v2,v3);
	
	printf("\nThe result is:\n");
	for(i=1;i<=3;i++){
		 Get(T,i,v);
		 printf("%d => %d\n",i,v);
	}
	if(IsAsceding(T))printf("\n\n数据以升序排列!\n\n");
	else if(IsDsceding(T))printf("\n\n数据以降序排列!\n\n");
	else printf("\n\n无序排列!\n\n");

	Max(T,v);
	printf("最大值:%d\n",v);
	Min(T,v);
	printf("最小值:%d\n",v);

	printf("\n更新数值的序号:");
	scanf("%d",&i);
	printf("输入值:");
	scanf("%d",&v);
	Put(T,i,v);
	printf("\nThe new result is:\n");
	for(i=1;i<=3;i++){
		 Get(T,i,v);
		 printf("%d => %d\n",i,v);
	}
	
	printf("\nResult End!\n");
	system("pause");
	return 0;
}