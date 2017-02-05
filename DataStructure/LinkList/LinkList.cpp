/*
	���Ե����� ���ݺ���
*/

#include "head.h"

void CreatList(LinkList &L,int n,void (* InputData)(ElemType &)){
	//�������� ������ͷ֮����� ��ĩβ����
	LinkList p;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=n;i>0;--i){
		p=(LinkList)malloc(sizeof(LNode));
		InputData(p->data);
		p->next=L->next;
		L->next=p;
	}
}

Status GetElem(LinkList L,int i,ElemType &e){
	//��ȡ�� i ��Ԫ��
	//L Ϊͷָ��
	LinkList p;
	int j=1;//��ʱ��
	p=L->next;
	while(p && j<i){
		p=p->next;
		++j;
	}
	if(!p || j>i)return ERROR;//��Ԫ�ز�����
	e=p->data;
	return OK;
}
Status ListInsert(LinkList &L,int i,ElemType e){
	//�ڵ� i ��Ԫ��֮ǰ����e
	//copy Ϊ���ƺ���
	LinkList p=L,s;
	int j=0;
	while(p && j<i-1){
		p=p->next;
		++j;
	}
	if(!p || j>i-1)return ERROR;//λ�ô���
	s=(LinkList)malloc(sizeof(LNode));
	if(!s)exit(OVERFLOW);
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
Status ListDelete(LinkList &L,int i,ElemType &e){
	//ɾ���ڵ��еĵ�i ��Ԫ�أ��������� e��
	LinkList p=L,q;
	int j=0;
	while(p->next && j<i-1){//Ѱ�ҵ� i ��Ԫ�ص��յ㣬��pָ���Ԫ����һ��
		p=p->next;
		++j;
	}
	if(!(p->next) || j>i-1 )return ERROR;//λ���д���
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}
void MerageList(LinkList &La,LinkList &Lb,LinkList &Lc,int (* compare)(ElemType,ElemType)){
	//�ϲ�����a b ��c compareΪ�ȽϺ���
	//����Ϊ������
	LinkList pa,pb,pc;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;//C�ڵ���La��ʼ
	while(pa && pb){
		if(compare(pa->data,pb->data)){
			pc->next=pa;
			pc=pa;

			pa=pa->next;//�ƶ�����La
		}else{
			pc->next=pb;
			pc=pb;

			pb=pb->next;//�ƶ�����Lb
		}
	}
	pc->next=pa?pa:pb;//����ʣ���
	free(Lb);//�Ƿ�Lb�ڵ���Ϣ
}
