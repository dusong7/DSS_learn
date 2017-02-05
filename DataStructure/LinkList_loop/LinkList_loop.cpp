/*
	˫��ѭ������ ��ͷ��� ���ݺ���
*/

#include"head.h"

void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &)){
	//�������� ������ͷ֮ǰ����
	L=NULL;//����ֵ��ʼ��Ϊ��
	if(n<1)return;//��Ԫ�ظ���С��1ʱֱ���˳�����
	
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->prior=L;
	L->next=L;
	InputData(L->data);//�����ʼ����

	DuLinkList p;
	for(int i=n-1;i>0;--i){
		p=(DuLinkList)malloc(sizeof(DuLNode));
		InputData(p->data);
		L->prior->next=p;
		p->prior=L->prior;
		p->next=L;
		L=p;
	}//for
}//CreatList

int ListLength(DuLinkList L){
	//�������ݳ���,�����ж�Ϊ��һ����ַ�ıȽϣ���ȱ��һ��ֵ����˴�1��ʼ����
	//L�����Ǿ�����ʼ��������
	int i=1;
	if(L==NULL)return 0;
	DuLinkList p=L;
	while(p->next!=L && ++i )p=p->next;
	return i;
}//ListLength

DuLinkList GetElemP_Dul(DuLinkList L,int i){
	if(L==NULL)return NULL;
	DuLinkList p=L;
	int j=0;
	while(++j!=i){
		if(j!=1)if(p->next==L)break;
		p=p->next;
	}//while
	if(j!=i)return NULL;
	else return p;
}//GetElemP_Dul

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	//�ڵ�i��λ��֮ǰ����Ԫ��e
	DuLinkList p,s;
	if(!(p=GetElemP_Dul(L,i)))return ERROR;//���ݲ���㲻��ȷ
	if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))return ERROR;//����ռ䲻��ȷ
	s->data=e;
	s->prior=p->prior;
	s->next=p->next;
	p->prior=s;
	return OK;
}//ListInsert_DuL

Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e){
	//ɾ��L������ͷ���ĵ�i ��Ԫ��
	DuLinkList p;
	if(!(p=GetElemP_Dul(L,i)))return ERROR;//Ҫɾ�������ݲ���ȷ
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return OK;
}//ListDelete_Dul

Status DestroyList_Dul(DuLinkList &L){
	//��������
	if(L==NULL)return OK;
	DuLinkList p=L,p2=L;
	int i=0;
	while(p!=L || ++i==1){
		p=p->next;
		free(p2);
		p2=p;
	}
	L=NULL;
	return OK;
}//ClearList_Dul

Status Append(DuLinkList &La,DuLinkList &Lb){
	//������Lb���ӵ�La֮��
	if(!La || !Lb )return ERROR;
	DuLinkList p=Lb->prior;;
	Lb->prior->next=La;
	Lb->prior=La->prior;
	La->prior->next=Lb;
	La->prior=p;
	return OK;
}//Append