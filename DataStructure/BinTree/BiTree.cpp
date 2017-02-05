/*
	���������ݲ���
	
//����������
typedef int TElemType;
typedef struct BiTNode{
	TElemType data;//������
	struct BiTNode *lchild;//��ָ��
	struct BiTNode *rchild;//��ָ��
}BiTNode,*BiTree;
	
Status InitBiTree(BiTree &T);//��������
Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e));//�����ݹ��㷨
Status CreateBiTree(BiTree &T,Status (* input)(TElemType &));//����������
Status InOrderTraverse_Stack(BiTree T,Status (* Visit)(TElemType e));//�������//ʹ��ջ �ǵݹ�
Status InOrderTraverse_Stack2(BiTree T,Status (* Visit)(TElemType e));//�������//ʹ��ջ �ǵݹ�

*/
#include"head.h"

Status InitBiTree(BiTree &T){
	//��������
	T=NULL;
	return OK;
}

Status CreateBiTree(BiTree &T,Status (* input)(TElemType &)){
	//���Ⱥ�˳����������������еĽڵ�
	//���������T
	TElemType temp;
	if(!input(temp))T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		T->data=temp;//���ɸ��ڵ�
		CreateBiTree(T->lchild,input);//����������
		CreateBiTree(T->rchild,input);//����������
	}
	return OK;
}

Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e)){
	//�����ݹ��㷨
	
	//�������
	if(T){
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))return OK;
		return ERROR;
	}else return OK;

	/*
	//�������
	if(T){
		if(PreOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
				if(PreOrderTraverse(T->rchild,Visit))return OK;
		return ERROR;
	}else return OK;	
	*/

	/*
	//�������
	if(T){
		if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))
					if(Visit(T->data))return OK;
		return ERROR;
	}else return OK;	
	*/
}

Status InOrderTraverse_Stack(BiTree T,Status (* Visit)(TElemType e)){
	//�������
	//ʹ��ջ �ǵݹ�
	SqStack S;
	InitStack(S);
	Push(S,T);
	ElemType p;
	while(!StackEmpty(S)){
		while(GetTop(S,p) && p)Push(S,p->lchild);//�����ߵ���ͷ
		Pop(S,p);//��ָ����ջ
		if(!StackEmpty(S)){//���ʽ�㣬����
			Pop(S,p);
			if(!Visit(p->data))return ERROR;
			Push(S,p->rchild);
		}
	}
	return OK;
}

Status InOrderTraverse_Stack2(BiTree T,Status (* Visit)(TElemType e)){
	//�������
	//ʹ��ջ �ǵݹ� ������
	SqStack S;
	InitStack(S);
	ElemType p=T;
	while(p || !StackEmpty(S)){
		if(p){//��ָ���ջ������������
			Push(S,p);
			p=p->lchild;
		}else{//��ָ����ջ������������
			Pop(S,p);
			if(!Visit(p->data))return ERROR;
			p=p->rchild;
		}
	}
	return OK;
}

