/*
	主函数
*/

#include "head.h"

int main(void){
	BiTree T;
	int i,j;
	printf("创建15个随机数据\n");
	CreatBST(T,15,InputElemType);
	printf("\n中序遍历随机数据:\n");
	PreOrderTraverse(T,VisitElemType);
	printf("\n\n随机删除10个数据:\n");
	for(i=0;i<10;i++){
		j=rand()%50;
		if(DeleteBST(T,j))printf("%3d %3d 删除成功! V\n",i,j);
		else printf("%3d %3d 删除失败! X\n",i,j);
	}
	printf("\n中序遍历删除后的数据:\n");
	PreOrderTraverse(T,VisitElemType);
	printf("\nResult End!\n");
	system("pause");
	return 0;
}