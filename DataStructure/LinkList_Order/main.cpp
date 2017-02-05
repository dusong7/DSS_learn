/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	SqList List,OtherList,NewList;
	InitList(List);
	ElemType e,ef;
	int n,i,f;
	printf("Insert Elem number:");
	scanf("%d",&n);
	for(i=1 ; i<=n ; i++){
		e = (DATA)malloc(sizeof(Data));
		if(!e){printf("malloc err!");break;}
		printf("Input name:");
		scanf("%s",e->name);
		printf("Input age:");
		scanf("%d",&e->age);
		ListInsert(List,i,e);
	}

	//print
	printf("\nThe result is:\n");
	printf("%-20s  age\n","name");
	for( i=0 ; i<n ; i++ ){
		printf("%-20s  %d\n",List.elem[i]->name,List.elem[i]->age);	
	}

	//find
	printf("\nInput you find age:");
	ef=(DATA)malloc(sizeof(Data));
	scanf("%d",&ef->age);
	f = LocateElem(List,ef,find);
	if(!f)printf("NO FIND!\n");
	else printf("Found : %s -> %d\n",List.elem[f-1]->name,List.elem[f-1]->age);

	//merger
	printf("\nInsert other Elem number:");
	scanf("%d",&n);
	InitList(OtherList);
	for(i=1 ; i<=n ; i++){
		e = (DATA)malloc(sizeof(Data));
		if(!e){printf("malloc err!");break;}
		printf("Input name:");
		scanf("%s",e->name);
		printf("Input age:");
		scanf("%d",&e->age);
		ListInsert(List,i,e);
	}
	MergeList(List,OtherList,NewList);
	//print
	printf("\nThe new result is:\n");
	printf("%-20s  age\n","name");
	for( i=0 ; i<NewList.length ; i++ ){
		printf("%-20s  %d\n",NewList.elem[i]->name,NewList.elem[i]->age);	
	}

	printf("Looks good!\n\n");

	printf("\nResult End!\n");
	system("pause");
	return 0;
}