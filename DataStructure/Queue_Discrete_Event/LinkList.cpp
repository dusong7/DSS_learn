/*
	链表函数
*/

#include"head.h"

Status InitList(LinkList &L){
	//构造空的线性链表
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)exit(OVERFLOW);
	L->next=NULL;
	return OK;
}//InitList

LinkList GetHead(LinkList L){
	return L;
}//GetHead

Status SetCurElem(LinkList &L,ElemType e){
	//设置L结点的数据值
	L->data=e;
	return OK;
}//SetCurElem

Status LocateElem(LinkList L,ElemType e,LinkList &q,int (* compare)(ElemType,ElemType)){
	//L为链表,e为比较数据,q为返回的位置,compare为比较函数,如果不能找到与之匹配的第一个元素,p返回第一个满足compare大于0的位置
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
	//分配新的空间
	p=(LinkList)malloc(sizeof(LNode));
	if(!p)return ERROR;
	p->data=e;
	return OK;
}//MakeNode

Status InsFirst(LinkList &h,LinkList &p){
	//将p插入到h之后
	p->next=h->next;
	h->next=p;
	return OK;
}//InsFirst

LinkList NextPos(LinkList L,LinkList p){
	//返回L链表中p的下一个
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
	//返回数据元素
	return p->data;
}//GetCurElem

Status DelFirst(LinkList &L,LinkList &q){
	//删除L中的第一个结点，并用q返回
	LinkList p=L;
	q=L->next;
	L->next=q->next;
	return OK;
}//DelFirst

Status FreeNode(LinkList &p){
	//释放p的空间
	free(p);
	return OK;
}//FreeNode

Status ListEmpty(LinkList L){
	if(L->next==NULL)return OK;
	else return ERROR;
}//ListEmpty

Status Append(LinkList &La,LinkList s){
	//链接s到La之后,s非头结点
	LinkList p=La;
	while(p->next)p=p->next;
	p->next=s;
	return OK;
}