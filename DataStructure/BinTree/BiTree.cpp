/*
	二叉树数据操作
	
//二叉树定义
typedef int TElemType;
typedef struct BiTNode{
	TElemType data;//数据域
	struct BiTNode *lchild;//左指针
	struct BiTNode *rchild;//右指针
}BiTNode,*BiTree;
	
Status InitBiTree(BiTree &T);//构建空树
Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e));//遍历递归算法
Status CreateBiTree(BiTree &T,Status (* input)(TElemType &));//构建二叉树
Status InOrderTraverse_Stack(BiTree T,Status (* Visit)(TElemType e));//中序遍历//使用栈 非递归
Status InOrderTraverse_Stack2(BiTree T,Status (* Visit)(TElemType e));//中序遍历//使用栈 非递归

*/
#include"head.h"

Status InitBiTree(BiTree &T){
	//构建空树
	T=NULL;
	return OK;
}

Status CreateBiTree(BiTree &T,Status (* input)(TElemType &)){
	//按先后顺序依次输入二叉树中的节点
	//构造二叉树T
	TElemType temp;
	if(!input(temp))T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		T->data=temp;//生成根节点
		CreateBiTree(T->lchild,input);//构造左子树
		CreateBiTree(T->rchild,input);//构造又子树
	}
	return OK;
}

Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e)){
	//遍历递归算法
	
	//先序遍历
	if(T){
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))return OK;
		return ERROR;
	}else return OK;

	/*
	//中序遍历
	if(T){
		if(PreOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
				if(PreOrderTraverse(T->rchild,Visit))return OK;
		return ERROR;
	}else return OK;	
	*/

	/*
	//后序遍历
	if(T){
		if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))
					if(Visit(T->data))return OK;
		return ERROR;
	}else return OK;	
	*/
}

Status InOrderTraverse_Stack(BiTree T,Status (* Visit)(TElemType e)){
	//中序遍历
	//使用栈 非递归
	SqStack S;
	InitStack(S);
	Push(S,T);
	ElemType p;
	while(!StackEmpty(S)){
		while(GetTop(S,p) && p)Push(S,p->lchild);//向左走到尽头
		Pop(S,p);//空指针退栈
		if(!StackEmpty(S)){//访问结点，向右
			Pop(S,p);
			if(!Visit(p->data))return ERROR;
			Push(S,p->rchild);
		}
	}
	return OK;
}

Status InOrderTraverse_Stack2(BiTree T,Status (* Visit)(TElemType e)){
	//中序遍历
	//使用栈 非递归 方法二
	SqStack S;
	InitStack(S);
	ElemType p=T;
	while(p || !StackEmpty(S)){
		if(p){//根指针进栈，遍历左子树
			Push(S,p);
			p=p->lchild;
		}else{//根指针退栈，遍历右子树
			Pop(S,p);
			if(!Visit(p->data))return ERROR;
			p=p->rchild;
		}
	}
	return OK;
}

