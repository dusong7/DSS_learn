/*
	��̬����
*/

#include"head.h"

BiTree SearchBST(BiTree T,KeyType key){
	//����ָ��T��ָ�����������еݹ����ĳ���ؼ��ֵ���Key��Ԫ������
	//�ҵ�����ָ���Ԫ�ؽ���ָ�룬���򷵻ؿ�
	if((!T) || EQ(key,T->data.key))return T;//���ҽ���
	else if(LT(key,T->data.key))return SearchBST(T->lchild,key);
	else return SearchBST(T->rchild,key);
}

Status SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p){
	//��T�в���key�����ҳɹ�Pָ���Ԫ�ؽڵ㣬����TURE��
	//����Pָ�����·�����Ϸ��ʵ����һ���ڵ㣬������FLASE,ָ��fָ��T��˫�ף���ʼֵΪNULL
	if(!T){
		p=f;
		return FALSE;
	}else if EQ(key,T->data.key){
		p=T;
		return TRUE;
	}else if LT(key,T->data.key){
		return SearchBST(T->lchild,key,T,p);
	}else return SearchBST(T->rchild,key,T,p);
}

Status InsertBST(BiTree &T,ElemType e){
	//��������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ������e����TRUE
	BiTree p,s;
	if(!SearchBST(T,e.key,NULL,p)){//����ʧ��
		s = (BiTree)malloc(sizeof(BiTNode));
		if(!s)exit(OVERFLOW);
		s->data=e;
		s->lchild=s->rchild=NULL;
		if(!p)T=s;
		else if LT(e.key,p->data.key)p->lchild=s;
		else p->rchild=s;
		return TRUE;
	}
	else return FALSE;
}

Status CreatBST(BiTree &T,int num,Status(* input)(ElemType &)){
	//����һ����
	T = NULL;
	ElemType e;
	for(int i=0;i<num;++i){
		input(e);
		if(!InsertBST(T,e))printf("%3d %3d ����ʧ��! X\n",i+1,e.key);
		else printf("%3d %3d �����ɹ�! V\n",i+1,e.key);
	}
	return TRUE;
}

Status PreOrderTraverse(BiTree T,Status(* Visit)(ElemType e)){
	//���������
	if(T){
		if(PreOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
				if(PreOrderTraverse(T->rchild,Visit))return OK;
		return ERROR;
	}else return OK;	
}

Status DeleteBST(BiTree &T, KeyType key){
	//������key��ɾ����Ԫ�أ�����TRUE ���򷵻�FALSE
	if(!T)return FALSE;
	else {
		if(EQ(key,T->data.key))return Delete(T);//�ҵ�����ˣ�ɾ��
		else if(LT(key,T->data.key))return DeleteBST(T->lchild,key);
		else return DeleteBST(T->rchild,key);
	}
}

Status Delete(BiTree &p){
	//������ɾ��p����������������������
	BiTree q,s;
	if(!p->rchild){//������Ϊ�� ֻ��Ҫ��������������
		q=p;
		p=p->lchild;
		free(q);
	}else if(!p->lchild){//�������� ����������
		q=p;
		p=p->rchild;
		free(q);
	}else {//���Ҷ���Ϊ��
		q=p;
		s=p->lchild;
		while(s->rchild){
			q=s;
			s=s->rchild;//��תȻ�����ҵ���ͷ
		}
		p->data=s->data;//sָ��ɾ����ǰ��
		if(q!=p)q->rchild=s->lchild;//����������
		else q->lchild=s->lchild;//����������
		free(s);
	}
	return TRUE;
}