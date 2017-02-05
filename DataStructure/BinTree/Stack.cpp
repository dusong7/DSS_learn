/*
	ջ����


typedef int ElemType;

#define STACK_INIT_SIZE 100//��ʼ��С
#define STACKINCREMENT 10//�����������С

typedef struct{
	ElemType *top;//ջ��ָ��
	ElemType *base;//ջ�ĳ�ʼΪ��
	int stacksize;//�ѷ����ջ�ռ�
}SqStack;


//ջ��������
Status InitStack(SqStack &S);//������ջ
ElemType GetTop(SqStack S);//ջ��Ϊ�գ�����ջ��Ԫ��
Status GetTop(SqStack S,ElemType &e);//ջ��Ϊ�գ�����ջ��Ԫ�ظ�e
Status Push(SqStack &S,ElemType e);//��e����ջ��
Status Pop(SqStack &S,ElemType &e);//ɾ��ջ��Ԫ�ز����ص�e
Status DestroyStack(SqStack &S);//��������
Status ClearStack(SqStack &S);//���ջ��������������
int StackLength(SqStack S);//�������ݳ���
Status StackTraverse(SqStack S,Status (* vist)(ElemType));//��ջ�׵�ջ�����ζ�ÿ��Ԫ�ص���visit()��һ������ʧ�ܺ�������
Status StackEmpty(SqStack S);//�ж��Ƿ�Ϊ��ջ
*/

#include "head.h"

Status InitStack(SqStack &S){
	//������ջ
	S.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack

Status GetTop(SqStack S,ElemType &e){
	//ջ��Ϊ�գ�����ջ��Ԫ�ظ�e
	if(S.top==S.base)return ERROR;//û������
	e=*(S.top-1);
	return OK;
}//GetTop

ElemType GetTop(SqStack S){
	//ջ��Ϊ�գ�����ջ��Ԫ��
	if(S.top==S.base)return ERROR;//û������
	return *(S.top-1);
}//GetTop


Status Push(SqStack &S,ElemType e){
	//��e����ջ��
	if(S.top-S.base>=S.stacksize){
		S.base=(ElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S.base)exit(OVERFLOW);
		S.top=S.base+S.stacksize;//��λջ���ڶ���
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;//��ֵ����1
	return OK;
}//Push

Status Pop(SqStack &S,ElemType &e){
	//ɾ��ջ��Ԫ�ز����ص�e
	if(S.top==S.base)return ERROR;
	e=*--S.top;//���Լ���ֵ
	return OK;
}//Pop

Status DestroyStack(SqStack &S){
	//��������
	free(S.base);
	S.stacksize=0;
	S.top=S.base=NULL;
	return OK;
}//DestroyStack

Status ClearStack(SqStack &S){
	//���ջ��������������
	S.top=S.base;
	return OK;
}//ClearStack

int StackLength(SqStack S){
	//�������ݳ���
	return S.top-S.base;
}//StackLength

Status StackTraverse(SqStack S,Status (* vist)(ElemType)){
	//��ջ�׵�ջ�����ζ�ÿ��Ԫ�ص���visit()��һ������ʧ�ܺ�������
	int l=StackLength(S);
	for(int i=0;i<l;i++){
		if(vist(S.base[i]))return ERROR;
	}
	return OK;
}//StackTraverse

Status StackEmpty(SqStack S){
	return S.base==S.top;
}