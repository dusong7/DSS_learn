/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	DuLinkList L,p;
	int i=0,n;
	printf("Input list number:");
	scanf("%d",&n);
	CreatList_DuL(L,n,input);
	p=L;
	printf("\nThe result is\n");
	while(p!=L || i++==0){
		printf("%s => %d\n",p->data.name,p->data.age);
		p=p->next;
	}//while
	printf("\nGetElem:\n");
	for(i=1;i<=n;i++){
		p=GetElemP_Dul(L,i);
		printf("%d %s => %d\n",i,p->data.name,p->data.age);
	}

	printf("\nResult End!\n");
	system("pause");
	return 0;
}