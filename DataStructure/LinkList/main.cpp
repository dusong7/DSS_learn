/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	LinkList L,Lb,Lc;
	ElemType e;
	int n,i,n2;
	printf("Input Elem number:");
	scanf("%d",&n);
	CreatList(L,n,Input);
	printf("\nThe result is:\n");
	for(i=1;i<=n;i++){
		 GetElem(L,i,e);
		 printf("\t%d => %s\n",e.age,e.name);
	}

	printf("\nInput you need delete id:");
	scanf("%d",&i);
	ListDelete(L,i,e);
	--n;
	printf("Delete data is:\n");
	printf("\t%d => %s\n",e.age,e.name);

	printf("\nThe result is:\n");
	for(i=1;i<=n;i++){
		 GetElem(L,i,e);
		 printf("\t%d => %s\n",e.age,e.name);
	}

	printf("\nCreat new list,number is:");
	scanf("%d",&n2);
	CreatList(Lb,n2,Input);
	printf("\nThe new list result is:\n");
	for(i=1;i<=n;i++){
		 GetElem(L,i,e);
		 printf("\t%d => %s\n",e.age,e.name);
	}

	printf("\nMerage list is:\n");
	MerageList(L,Lb,Lc,Compare);
	n+=n2;
	for(i=1;i<=n;i++){
		 GetElem(L,i,e);
		 printf("\t%d => %s\n",e.age,e.name);
	}

	printf("\nResult End!\n");
	system("pause");
	return 0;
}