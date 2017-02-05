/*
	��������������

typedef enum PointerTag{
	Link,//ָ��
	Thread//����
};
typedef struct BiThrNode{
	TElemType data;//������
	struct BiThrNode *lchild;//����
	struct BiThrNode *rchild;//�Һ���
	PointerTag LTag,RTag;//���ұ��
}BiThrNode , *BiThrTree;

	Status InitBiTree(BiThrTree &T);//��������
	Status InitThrBiTree(BiThrTree &T);//������������
	Status CreateBiTree(BiThrTree &T,Status (* input)(TElemType &));//���Ⱥ�˳����������������еĽڵ�
	Status InOrderTraverse_Thr(BiThrTree T,Status (* Visit)(TElemType e));//�������������T�ķǵݹ��㷨
	Status InOrderThreading(BiThrTree &Thrt,BiThrTree T);//�������������������������
	void InThreading(BiThrTree p,BiThrTree &pre);//��������������

*/

#include"head.h"

Status InitBiTree(BiThrTree &T){
	//��������
	T=NULL;
	return OK;
}

Status InitThrBiTree(BiThrTree &T){
	//������������
	if(!(T=(BiThrTree)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
	T->LTag=Link;
	T->RTag=Thread;
	T->lchild=NULL;
	T->rchild=NULL;
	return OK;
}

Status CreateBiTree(BiThrTree &T,Status (* input)(TElemType &)){
	//���Ⱥ�˳����������������еĽڵ�
	//���������T
	TElemType temp;
	if(!input(temp))T=NULL;
	else{
		if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
		T->data=temp;//���ɸ��ڵ�
		T->LTag=Link;
		T->RTag=Link;
		CreateBiTree(T->lchild,input);//����������
		CreateBiTree(T->rchild,input);//����������
	}
	return OK;
}

Status InOrderTraverse_Thr(BiThrTree T,Status (* Visit)(TElemType e)){
	//�������������T�ķǵݹ��㷨
	BiThrTree p;
	p=T->lchild;
	while(p!=T){//��������ʱ,p==T
		while(p->LTag==Link)p=p->lchild;
		if(!Visit(p->data))return ERROR;//�����������ķǿս��
		while(p->RTag==Thread && p->rchild!=T){//���ʺ�̽��
			p=p->rchild;
			Visit(p->data);
		}
		p=p->rchild;
	}
	return OK;
}//InOrderTraverse_Thr

void InThreading(BiThrTree p,BiThrTree &pre){
	//�������������� preΪ�ֲ���������Ҫ������
	if(p){
		InThreading(p->lchild,pre);//������������
		if(!p->lchild){//ǰ������
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild){//�������
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;//����preָ��p��ǰ��
		InThreading(p->rchild,pre);//������������
	}
}

Status InOrderThreading(BiThrTree &Thrt,BiThrTree T){
	//�������������������������
	if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
	Thrt->LTag=Link;//�������
	Thrt->RTag=Thread;
	Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;//���������գ�����ָ���ָ
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