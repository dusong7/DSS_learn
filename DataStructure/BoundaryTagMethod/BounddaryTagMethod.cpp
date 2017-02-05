/*
	边界标示法

	//数据定义
	typedef int OtherType;
	typedef struct WORD{
		union {//head 和 foot分别是结点的第一个字和最后的字
			WORD *llink;//头部域，指向前驱结点
			WORD *uplink;//底部域，指向本结点头部
		};
		int tag;//块标志，0:空闲 1:占用，头部和尾部均有
		int size;//头部域，块大小
		WORD *rlink;//头部域，指向后继结点
		OtherType other;//字的其他部分
	} WORD, head, foot, *Space;
	#define FootLoc(p) p+p->size-1//指向p所指结点的底部

	//函数定义
	Status InitSpace(Space &pav,int size);//初始化
	void PrintSpaceInfo(Space pav);//输出空间信息
	Space AllocBoundTag(Space &pav,int n,int e);//若有不小于n的块，则分配相应的块，并返回其首地址
	void FreeSpace(Space &p,Space &pav);//回收空间p
	void FreeSpaceOnly(Space &p,Space &pav);//回收空间p前后均为不为空闲
	void FreeSpaceMergerLeft(Space p);//合并左边的
	void FreeSpaceMergerRight(Space &p);//合并右边的
	void FreeSpaceMergerLeftRight(Space p);//左右同时合并
*/

#include"head.h"

Status InitSpace(Space &pav,int size){
	//初始化
	Space f;
	pav=(Space)calloc(size,sizeof(WORD));//如果初始化不为空 多处判断错误
	if(!pav)exit(OVERFLOW);
	pav->tag=0;
	pav->rlink=pav;
	pav->llink=pav;
	pav->uplink=pav;
	pav->size=size;
	f=FootLoc(pav);
	f->uplink=pav;
	f->tag=0;
	return OK;
}

Space AllocBoundTag(Space &pav,int n,int e){
	//若有不小于n的块，则分配相应的块，并返回其首地址
	//若分配后可利用空间不空，则pav指向表中刚分配过的结点的后继
	//e为整块分配 不保留小于等于 e 的块

	Space p,f;
	for(p=pav; p && p->size<n && p->rlink!=pav; p=p->rlink);//查找块不小于n的空间

	if(!p || p->size<n)return NULL;
	else{
		f=FootLoc(p);//指向底部
		pav=p->rlink;
		if(p->size-n<=e){
			if(pav==p)pav=NULL;
			else{
				pav->llink=p->llink;
				p->llink->rlink=pav;
			}//if
			p->tag=f->tag=1;
		}else{//if
			f->tag=1;
			p->size-=n;
			f=FootLoc(p);
			f->tag=0;
			f->uplink=p;
			p=f+1;
			p->tag=1;
			p->size=n;
		}//if
		return p;
	}
}

void PrintSpaceInfo(Space pav){
	//输出空间信息
	Space p=pav;
	printf("  %15s  %6s %5s\n","Address","size","tag");
	while(p){
		printf("  %15d  %6d %5d\n",p,p->size,p->tag);
		p=p->rlink;
		if(p==pav)break;
	}

}

void FreeSpace(Space &p,Space &pav){
	//释放空间p
	int left=0,right=0;
	if(p->llink && p->llink->tag==0)left=1;
	if(p->rlink && p->rlink->tag==0)right=1;
	if(left && right)FreeSpaceMergerLeftRight(p);
	else if(left)FreeSpaceMergerLeft(p);
	else if(right)FreeSpaceMergerRight(p);
	else FreeSpaceOnly(p,pav);
}

void FreeSpaceOnly(Space &p,Space &pav){
	//回收空间p前后均为不为空闲
	Space f,q;
	p->tag=0;
	f=FootLoc(p);
	f->uplink=p;
	f->tag=0;
	if(!pav)pav=p->llink=p->rlink=p;
	else{
		q=pav->llink;
		p->rlink=pav;
		p->llink=q;
		q->rlink=pav->llink=p;
		pav=p;//释放的结点优先查询
	}
}

void FreeSpaceMergerLeft(Space p){
	//合并左边的
	int size=p->size;
	Space leftSpace=(p-1)->uplink;
	leftSpace+=size;
	Space f=p+size-1;
	f->uplink=leftSpace;
	f->tag=0;
}

void FreeSpaceMergerRight(Space &p){
	//合并右边的
	Space t,q,q1;
	t=p+p->size;//右邻空闲块的首地址
	p->tag=0;// p 为合并后结点头部地址
	q=t->llink;//q为可利用空间的前驱
	
	p->llink=q;
	q->rlink=p;

	q1=t->rlink;//q1为可利用空间的后继地址
	
	p->rlink=q1;
	q1->llink=p;

	p->size+=t->size;//计算大小
	
	(t+t->size-1)->uplink=p;//FootLoc(t)->uplink-p
}

void FreeSpaceMergerLeftRight(Space p){
	//左右同时合并
	int n;
	Space s,t,q,q1;
	n=p->size;//释放的大小
	s=(p-1)->uplink;//指向左邻块
	t=p+p->size;//指向右邻块
	s->size+=n+t->size;//新结点的大小
	
	q=t->llink;//将t的前后连接
	q1=t->rlink;
	if(q)q->rlink=q1;
	if(q1)q1->llink=q;

	(t+t->size-1)->uplink=s;//FootLoc(t)->uplink-s
}