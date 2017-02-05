/*
	线索二叉树数据

typedef enum PointerTag{
	Link,//指针
	Thread//线索
};
typedef struct BiThrNode{
	TElemType data;//数据域
	struct BiThrNode *lchild;//左孩子
	struct BiThrNode *rchild;//右孩子
	PointerTag LTag,RTag;//左右标记
}BiThrNode , *BiThrTree;

	Status InitBiTree(BiThrTree &T);//构建空树
	Status InitThrBiTree(BiThrTree &T);//构建空线索树
	Status CreateBiTree(BiThrTree &T,Status (* input)(TElemType &));//按先后顺序依次输入二叉树中的节点
	Status InOrderTraverse_Thr(BiThrTree T,Status (* Visit)(TElemType e));//中序遍历二叉树T的非递归算法
	Status InOrderThreading(BiThrTree &Thrt,BiThrTree T);//中序遍历二叉树，将其线索化
	void InThreading(BiThrTree p,BiThrTree &pre);//线索化遍历方法

*/

#include"head.h"

Status InitBiTree(BiThrTree &T){
	//构建空树
	T=NULL;
	return OK;
}

Status InitThrBiTree(BiThrTree &T){
	//构建空线索树
	if(!(T=(BiThrTree)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
	T->LTag=Link;
	T->RTag=Thread;
	T->lchild=NULL;
	T->rchild=NULL;
	return OK;
}

Status CreateBiTree(BiThrTree &T,Status (* input)(TElemType &)){
	//按先后顺序依次输入二叉树中的节点
	//构造二叉树T
	TElemType temp;
	if(!input(temp))T=NULL;
	else{
		if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
		T->data=temp;//生成根节点
		T->LTag=Link;
		T->RTag=Link;
		CreateBiTree(T->lchild,input);//构造左子树
		CreateBiTree(T->rchild,input);//构造又子树
	}
	return OK;
}

Status InOrderTraverse_Thr(BiThrTree T,Status (* Visit)(TElemType e)){
	//中序遍历二叉树T的非递归算法
	BiThrTree p;
	p=T->lchild;
	while(p!=T){//空树结束时,p==T
		while(p->LTag==Link)p=p->lchild;
		if(!Visit(p->data))return ERROR;//访问左子树的非空结点
		while(p->RTag==Thread && p->rchild!=T){//访问后继结点
			p=p->rchild;
			Visit(p->data);
		}
		p=p->rchild;
	}
	return OK;
}//InOrderTraverse_Thr

void InThreading(BiThrTree p,BiThrTree &pre){
	//线索化遍历方法 pre为局部变量，需要传引用
	if(p){
		InThreading(p->lchild,pre);//左子树线索化
		if(!p->lchild){//前驱线索
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild){//后继线索
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;//保持pre指向p的前驱
		InThreading(p->rchild,pre);//右子树线索化
	}
}

Status InOrderThreading(BiThrTree &Thrt,BiThrTree T){
	//中序遍历二叉树，将其线索化
	if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
	Thrt->LTag=Link;//建立结点
	Thrt->RTag=Thread;
	Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;//若二叉树空，则左指针回指
	else{
		Thrt->lchild=T;
		BiThrTree pre=Thrt;
		InThreading(T,pre);
		pre->rchild=Thrt;
		pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return OK;
}