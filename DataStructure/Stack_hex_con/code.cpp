/*
	���ݽṹ����Դ��
*/

#include "head.h"

void conversion(void){
	//10����װ��8
	SqStack S;
	InitStack(S);
	int d;
	ElemType e;
	printf("Input a Decimal number:");
	scanf("%d",&d);
	while(d){
		Push(S,d%8);
		d/=8;
	}
	printf("The Octal is:");
	while(!StackEmpty(S)){
		Pop(S,e);
		printf("%d",e);
	}
	printf("\n");
}//conversion


void LineEdit(){
	//�б༭��
	SqStack S;
	InitStack(S);
	int d;
	ElemType e;
	printf("\nInput the String:");
	d=getche();
	while(d!=13){
		switch(d){
		case '@':ClearStack(S);break;
		case '#':Pop(S,e);break;
		default:Push(S,d);break;
		}
		d=getche();
	}

	printf("\nThe result is:\n\t");
	for(ElemType * i=S.base;i<S.top;++i){
		printf("%c",*i);
	}
	printf("\n");
	
}//LineEdit