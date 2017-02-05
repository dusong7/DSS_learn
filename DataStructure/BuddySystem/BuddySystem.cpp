/*
	伙伴系统
*/

#include"head.h"

void InitBuddy(FreeList &avail){
	//初始化
	int i;
	for(i=0;i<=m;i++){
		avail[i].first=NULL;
		avail[i].nodesize=(int)pow((double)2,i);
		avail[i].first=(WORD_b *)malloc(sizeof(WORD_b)*avail[i].nodesize);
		avail[i].first->kval=i;
		avail[i].first->llink=avail[i].first;
		avail[i].first->rlink=avail[i].first;
		avail[i].first->tag=0;
	}
}

WORD_b* ALLocBuddy (FreeList &avail,int n){
	//avail[0.....m]为可利用空间表，n为申请分配量，若有不小于n的空闲块，
	//则分配相应的存储块，并返回其首地址；否则返回NULL
	WORD_b *pre,*pa,*suc,*pi;
	int k,i;
	for(k = 0; k <= m && (avail[k].nodesize < n + 1 || !avail[k].first); ++k);//查找满足分配要求的子表
	if(k > m)//分配失败，返回NULL
	return NULL;
	else//进行分配
	{
		pa = avail[k].first;//指向可分配子表的第一个结点
		pre = pa->llink;
		suc = pa->rlink;//分别指向前驱和后继
		if(pa = suc)
			avail[k].first = NULL;//分配后该子表变成空表
		else//从子表删除*pa结点
		{
			pre->rlink = suc;
			suc->llink = pre;
			avail[k].first = suc;
		}
		for(i = 1; avail[k-i].nodesize >= n+1; ++i){
			pi = pa+(int)pow((double)2,k-i);
			pi->rlink = pi;
			pi->llink = pi;
			pi->tag = 0;
			pi->kval = k - i;
			avail[k-i].first = pi;
		}//将剩余块插入相应子表
		pa->tag = 1;
		pa->kval = k - ( -- i);  
	}
	return pa;
}//AllocBuddy

void PrintBuddyInfo(FreeList avail){
	//输出空间分配信息
	int i;
	WORD_b *p;
	printf("%5s%10s%8s%10s\n----------------------------------------\n","k","nodesize","first","node");
	for(i=0;i<m+1;i++){
		printf("%5d%10d%6s  ",i,avail[i].nodesize,avail[i].first?"->":"^");
		p=avail[i].first;
		while(p){
			printf(" %d",p);
			p=p->rlink;
			if(p==avail[i].first)break;
		}
		printf("\n");
	}
}

