/*
	������
*/

#include "head.h"

int main(void){
	BiTree T;
	int i,j;
	printf("����15���������\n");
	CreatBST(T,15,InputElemType);
	printf("\n��������������:\n");
	PreOrderTraverse(T,VisitElemType);
	printf("\n\n���ɾ��10������:\n");
	for(i=0;i<10;i++){
		j=rand()%50;
		if(DeleteBST(T,j))printf("%3d %3d ɾ���ɹ�! V\n",i,j);
		else printf("%3d %3d ɾ��ʧ��! X\n",i,j);
	}
	printf("\n�������ɾ���������:\n");
	PreOrderTraverse(T,VisitElemType);
	printf("\nResult End!\n");
	system("pause");
	return 0;
}