/*
	双向循环链表 无头结点 数据函数
*/

#include"head.h"

void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &)){
	//创建链表 向链表头之前插入
	L=NULL;//将数值初始化为空
	if(n<1)return;//当元素个数小于1时直接退出函数
	
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->prior=L;
	L->next=L;
	InputData(L->data);//输入初始数据

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
	//返回数据长度,由于判断为下一个地址的比较，故缺少一个值，因此从1开始计数
	//L必须是经过初始化的数据
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
	//在第i个位置之前插入元素e
	DuLinkList p,s;
	if(!(p=GetElemP_Dul(L,i)))return ERROR;//数据插入点不正确
	if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))return ERROR;//分配空间不正确
	s->data=e;
	s->prior=p->prior;
	s->next=p->next;
	p->prior=s;
	return OK;
}//ListInsert_DuL

Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e){
	//删除L链表中头结点的第i 个元素
	DuLinkList p;
	if(!(p=GetElemP_Dul(L,i)))return ERROR;//要删除的数据不正确
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return OK;
}//ListDelete_Dul

Status DestroyList_Dul(DuLinkList &L){
	//销毁链表
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
	//将链表Lb链接到La之后
	if(!La || !Lb )return ERROR;
	DuLinkList p=Lb->prior;;
	Lb->prior->next=La;
	Lb->prior=La->prior;
	La->prior->next=Lb;
	La->prior=p;
	return OK;
}//Append