/*
	������
*/

#include"head.h"

Status InitList(LinkList &L){
	//����յ���������
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)exit(OVERFLOW);
	L->next=NULL;
	return OK;
}//InitList

LinkList GetHead(LinkList L){
	return L;
}//GetHead

Status SetCurElem(LinkList &L,ElemType e){
	//����L��������ֵ
	L->data=e;
	return OK;
}//SetCurElem

Status LocateElem(LinkList L,ElemType e,LinkList &q,int (* compare)(ElemType,ElemType)){
	//LΪ����,eΪ�Ƚ�����,qΪ���ص�λ��,compareΪ�ȽϺ���,��������ҵ���֮ƥ��ĵ�һ��Ԫ��,p���ص�һ������compare����0��λ��
	LinkList p=L->next,p2=NULL;
	int flag=0,value=-2;
	while(p){
		value=compare(e,p->data);
		if(value==0){
			q=p;
			return OK;
		}
		if(!p2 && value>0){
			p2=p;
			flag=1;
		}
		p=p->next;
	}
	if(flag!=0)q=p2;
	else q=L;
	return ERROR;
}//LocateElem

Status MakeNode(LinkList &p,ElemType e){
	//�����µĿռ�
	p=(LinkList)malloc(sizeof(LNode));
	if(!p)return ERROR;
	p->data=e;
	return OK;
}//MakeNode

Status InsFirst(LinkList &h,LinkList &p){
	//��p���뵽h֮��
	p->next=h->next;
	h->next=p;
	return OK;
}//InsFirst

LinkList NextPos(LinkList L,LinkList p){
	//����L������p����һ��
	LinkList p2=L;
	int flag=0;
	while(p2){
		if(p2==p){
			flag=1;
			break;
		}
		p2=p2->next;
	}
	if(flag==1)return p->next;
	return NULL;
}//NextPos

ElemType GetCurElem(LinkList p){
	//��������Ԫ��
	return p->data;
}//GetCurElem

Status DelFirst(LinkList &L,LinkList &q){
	//ɾ��L�еĵ�һ����㣬����q����
	LinkList p=L;
	q=L->next;
	L->next=q->next;
	return OK;
}//DelFirst

Status FreeNode(LinkList &p){
	//�ͷ�p�Ŀռ�
	free(p);
	return OK;
}//FreeNode

Status ListEmpty(LinkList L){
	if(L->next==NULL)return OK;
	else return ERROR;
}//ListEmpty

Status Append(LinkList &La,LinkList s){
	//����s��La֮��,s��ͷ���
	LinkList p=La;
	while(p->next)p=p->next;
	p->next=s;
	return OK;
}