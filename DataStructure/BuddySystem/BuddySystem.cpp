/*
	���ϵͳ
*/

#include"head.h"

void InitBuddy(FreeList &avail){
	//��ʼ��
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
	//avail[0.....m]Ϊ�����ÿռ��nΪ��������������в�С��n�Ŀ��п飬
	//�������Ӧ�Ĵ洢�飬���������׵�ַ�����򷵻�NULL
	WORD_b *pre,*pa,*suc,*pi;
	int k,i;
	for(k = 0; k <= m && (avail[k].nodesize < n + 1 || !avail[k].first); ++k);//�����������Ҫ����ӱ�
	if(k > m)//����ʧ�ܣ�����NULL
	return NULL;
	else//���з���
	{
		pa = avail[k].first;//ָ��ɷ����ӱ�ĵ�һ�����
		pre = pa->llink;
		suc = pa->rlink;//�ֱ�ָ��ǰ���ͺ��
		if(pa = suc)
			avail[k].first = NULL;//�������ӱ��ɿձ�
		else//���ӱ�ɾ��*pa���
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
		}//��ʣ��������Ӧ�ӱ�
		pa->tag = 1;
		pa->kval = k - ( -- i);  
	}
	return pa;
}//AllocBuddy

void PrintBuddyInfo(FreeList avail){
	//����ռ������Ϣ
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

