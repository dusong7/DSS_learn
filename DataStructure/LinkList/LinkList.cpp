/*
	线性单链表 数据函数
*/

#include "head.h"

void CreatList(LinkList &L,int n,void (* InputData)(ElemType &)){
	//创建链表 向链表头之后插入 非末尾插入
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
	//获取第 i 个元素
	//L 为头指针
	LinkList p;
	int j=1;//计时器
	p=L->next;
	while(p && j<i){
		p=p->next;
		++j;
	}
	if(!p || j>i)return ERROR;//该元素不存在
	e=p->data;
	return OK;
}
Status ListInsert(LinkList &L,int i,ElemType e){
	//在第 i 个元素之前插入e
	//copy 为复制函数
	LinkList p=L,s;
	int j=0;
	while(p && j<i-1){
		p=p->next;
		++j;
	}
	if(!p || j>i-1)return ERROR;//位置错误
	s=(LinkList)malloc(sizeof(LNode));
	if(!s)exit(OVERFLOW);
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
Status ListDelete(LinkList &L,int i,ElemType &e){
	//删除节点中的第i 个元素，并保存在 e中
	LinkList p=L,q;
	int j=0;
	while(p->next && j<i-1){//寻找第 i 个元素的终点，且p指向该元素上一个
		p=p->next;
		++j;
	}
	if(!(p->next) || j>i-1 )return ERROR;//位置有错误
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}
void MerageList(LinkList &La,LinkList &Lb,LinkList &Lc,int (* compare)(ElemType,ElemType)){
	//合并链表a b 到c compare为比较函数
	//插入为向后插入
	LinkList pa,pb,pc;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;//C节点重La开始
	while(pa && pb){
		if(compare(pa->data,pb->data)){
			pc->next=pa;
			pc=pa;

			pa=pa->next;//移动链表La
		}else{
			pc->next=pb;
			pc=pb;

			pb=pb->next;//移动链表Lb
		}
	}
	pc->next=pa?pa:pb;//插入剩余段
	free(Lb);//是否Lb节点信息
}
