/*
	栈操作
*/

#include "head.h"

Status InitStack(SqStack &S){
	//构建空栈
	S.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack

Status GetTop(SqStack S,ElemType &e){
	//栈不为空，返回栈顶元素给e，而不是栈顶指针
	if(S.top==S.base)return ERROR;//没有数据
	e=*(S.top-1);
	return OK;
}//GetTop

Status Push(SqStack &S,ElemType e){
	//将e插入栈顶
	if(S.top-S.base>=S.stacksize){
		S.base=(ElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S.base)exit(OVERFLOW);
		S.top=S.base+S.stacksize;//定位栈顶在顶层
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;//赋值并加1
	return OK;
}//Push

Status Pop(SqStack &S,ElemType &e){
	//删除栈顶元素并返回到e
	if(S.top==S.base)return ERROR;
	e=*--S.top;//先自减后赋值
	return OK;
}//Pop

Status DestroyStack(SqStack &S){
	//销毁数据
	free(S.base);
	S.stacksize=0;
	S.top=S.base=NULL;
	return OK;
}//DestroyStack

Status ClearStack(SqStack &S){
	//清空栈，并不销毁数据
	S.top=S.base;
	return OK;
}//ClearStack

int StackLength(SqStack S){
	//返回数据长度
	return S.top-S.base;
}//StackLength

Status StackTraverse(SqStack S,Status (* vist)(ElemType)){
	//从栈底到栈顶依次对每个元素调用visit()，一旦操作失败函数结束
	int l=StackLength(S);
	for(int i=0;i<l;i++){
		if(vist(S.base[i]))return ERROR;
	}
	return OK;
}//StackTraverse

Status StackEmpty(SqStack S){
	return S.base==S.top;
}