/*
	数据结构操作源码
*/

#include "head.h"

char Precede(char a,char b){
	//比较符号的优先级
	switch(a){
		case '+':case '-':
		switch(b){
		case '+':case '-':case ')':case '\n':return '>';
		default:return '<';
		}break;
	case '*':case '/':
		switch(b){
		case '+':case '-':case '*':case '/':case ')':case '\n':return '>';
		default:return '<';
		}break;
	case '(':
		switch(b){
		case '+':case '-':case '*':case '/':case '(':return '<';break;
		case ')':return '=';
		default:return NULL;
		}break;
	case ')':
		switch(b){
		case '(':return NULL;
		default:return '>';
		}
	case '#':
		switch(b){
		case ')':return NULL;
		case '#':return '=';
		default:return '<';
		}
	default:return NULL;
	}
}//Precede

Status In(char c){
	//判断字符是否在s字符数组中
	if(c=='#')return OK;
	if(c=='+')return OK;
	if(c=='-')return OK;
	if(c=='*')return OK;
	if(c=='/')return OK;
	if(c=='(')return OK;
	if(c==')')return OK;
	return ERROR;
}//In

int Operate(int a,char theta,int b){
	switch(theta){
	case '+':return a+b;
	case '-':return a-b;
	case '*':return a*b;
	case '/':return a/b;
	default:return 0;
	}
}

ElemType OperaType(void){
	//全数据为整型操作
	SqStack OPTR,OPND;//OPTR运算符栈，OPND运算栈
	InitStack(OPTR);
	Push(OPTR,'#');
	InitStack(OPND);
	int ch,x,a,b,theta;
	ch=getche();
	while(ch!='#' || GetTop(OPTR)!='#'){
		if(!In(ch)){
			Push(OPND,ch-48);
			ch=getche();
		}else{
			switch(Precede(GetTop(OPTR),ch)){
			case '<':
				Push(OPTR,ch);
				ch=getche();
				break;
			case '=':
				Pop(OPTR,x);
				ch=getche();
				break;
			case '>':
				Pop(OPTR,theta);
				Pop(OPND,b);
				Pop(OPND,a);
				Push(OPND,Operate(a,theta,b));
				break;
			}//switch
		}//if else
	}//while
	return GetTop(OPND);
}// OperaTyp