/*
	�߽��ʾ��

	//���ݶ���
	typedef int OtherType;
	typedef struct WORD{
		union {//head �� foot�ֱ��ǽ��ĵ�һ���ֺ�������
			WORD *llink;//ͷ����ָ��ǰ�����
			WORD *uplink;//�ײ���ָ�򱾽��ͷ��
		};
		int tag;//���־��0:���� 1:ռ�ã�ͷ����β������
		int size;//ͷ���򣬿��С
		WORD *rlink;//ͷ����ָ���̽��
		OtherType other;//�ֵ���������
	} WORD, head, foot, *Space;
	#define FootLoc(p) p+p->size-1//ָ��p��ָ���ĵײ�

	//��������
	Status InitSpace(Space &pav,int size);//��ʼ��
	void PrintSpaceInfo(Space pav);//����ռ���Ϣ
	Space AllocBoundTag(Space &pav,int n,int e);//���в�С��n�Ŀ飬�������Ӧ�Ŀ飬���������׵�ַ
	void FreeSpace(Space &p,Space &pav);//���տռ�p
	void FreeSpaceOnly(Space &p,Space &pav);//���տռ�pǰ���Ϊ��Ϊ����
	void FreeSpaceMergerLeft(Space p);//�ϲ���ߵ�
	void FreeSpaceMergerRight(Space &p);//�ϲ��ұߵ�
	void FreeSpaceMergerLeftRight(Space p);//����ͬʱ�ϲ�
*/

#include"head.h"

Status InitSpace(Space &pav,int size){
	//��ʼ��
	Space f;
	pav=(Space)calloc(size,sizeof(WORD));//�����ʼ����Ϊ�� �ദ�жϴ���
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
	//���в�С��n�Ŀ飬�������Ӧ�Ŀ飬���������׵�ַ
	//�����������ÿռ䲻�գ���pavָ����иշ�����Ľ��ĺ��
	//eΪ������� ������С�ڵ��� e �Ŀ�

	Space p,f;
	for(p=pav; p && p->size<n && p->rlink!=pav; p=p->rlink);//���ҿ鲻С��n�Ŀռ�

	if(!p || p->size<n)return NULL;
	else{
		f=FootLoc(p);//ָ��ײ�
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
	//����ռ���Ϣ
	Space p=pav;
	printf("  %15s  %6s %5s\n","Address","size","tag");
	while(p){
		printf("  %15d  %6d %5d\n",p,p->size,p->tag);
		p=p->rlink;
		if(p==pav)break;
	}

}

void FreeSpace(Space &p,Space &pav){
	//�ͷſռ�p
	int left=0,right=0;
	if(p->llink && p->llink->tag==0)left=1;
	if(p->rlink && p->rlink->tag==0)right=1;
	if(left && right)FreeSpaceMergerLeftRight(p);
	else if(left)FreeSpaceMergerLeft(p);
	else if(right)FreeSpaceMergerRight(p);
	else FreeSpaceOnly(p,pav);
}

void FreeSpaceOnly(Space &p,Space &pav){
	//���տռ�pǰ���Ϊ��Ϊ����
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
		pav=p;//�ͷŵĽ�����Ȳ�ѯ
	}
}

void FreeSpaceMergerLeft(Space p){
	//�ϲ���ߵ�
	int size=p->size;
	Space leftSpace=(p-1)->uplink;
	leftSpace+=size;
	Space f=p+size-1;
	f->uplink=leftSpace;
	f->tag=0;
}

void FreeSpaceMergerRight(Space &p){
	//�ϲ��ұߵ�
	Space t,q,q1;
	t=p+p->size;//���ڿ��п���׵�ַ
	p->tag=0;// p Ϊ�ϲ�����ͷ����ַ
	q=t->llink;//qΪ�����ÿռ��ǰ��
	
	p->llink=q;
	q->rlink=p;

	q1=t->rlink;//q1Ϊ�����ÿռ�ĺ�̵�ַ
	
	p->rlink=q1;
	q1->llink=p;

	p->size+=t->size;//�����С
	
	(t+t->size-1)->uplink=p;//FootLoc(t)->uplink-p
}

void FreeSpaceMergerLeftRight(Space p){
	//����ͬʱ�ϲ�
	int n;
	Space s,t,q,q1;
	n=p->size;//�ͷŵĴ�С
	s=(p-1)->uplink;//ָ�����ڿ�
	t=p+p->size;//ָ�����ڿ�
	s->size+=n+t->size;//�½��Ĵ�С
	
	q=t->llink;//��t��ǰ������
	q1=t->rlink;
	if(q)q->rlink=q1;
	if(q1)q1->llink=q;

	(t+t->size-1)->uplink=s;//FootLoc(t)->uplink-s
}