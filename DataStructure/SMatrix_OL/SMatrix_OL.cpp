/*
	ϡ�����ʮ������洢
*/

#include"head.h"

Status InitSMatrix_OL(CrossList &M){
	//��ʼ��ϡ�����
	M.chead=NULL;
	M.rhead=NULL;
	M.mu=M.nu=M.tu=0;
	return OK;
}
Status CreatSMatrix_OL(CrossList &M,void (* inputNum)(int &,int &,int &),Status(* InputData)(OLNode &,CrossList)){
	//inputNum Ϊ�������� ���� ���� InputData Ϊ�������ݣ����ݳɹ��򷵻�OK ���򷵻�ERROR
	if(M.chead)free(M.chead);
	if(M.rhead)free(M.rhead);
	inputNum(M.mu,M.nu,M.tu);
	//ʹ��calloc��ʼ��Ϊ��
	if(!(M.rhead=(OLink *)calloc((M.mu+1),sizeof(OLink))))exit(OVERFLOW);
	if(!(M.chead=(OLink *)calloc((M.nu+1),sizeof(OLink))))exit(OVERFLOW);
	OLNode e;
	OLink p,q;
	int n=0;
	while(InputData(e,M)){//������ȷ����
		if(++n>M.tu)break;
		if(!(p=(OLink)malloc(sizeof(OLNode))))exit(OVERFLOW);
		//���ɽ��
		p->i=e.i;
		p->j=e.j;
		p->e=e.e;
		if(M.rhead[e.i]==NULL || M.rhead[e.i]->j>e.j){
			p->right=M.rhead[e.i];
			M.rhead[e.i]=p;
		}else{//������
			for(q=M.rhead[e.i] ; (q->right)&&(q->right->j<e.j) ; q=q->right);
			p->right=q->right;
			q->right=p;
		}//if
		if(M.chead[e.j]==NULL || M.chead[e.j]->i>e.i){
			p->down=M.chead[e.j];
			M.chead[e.j]=p;
		}else{
			for(q=M.chead[e.j];(q->down)&&(q->down->i<e.i);q=q->down);
			p->down=q->down;
			q->down=p;
		}//if
	}//while
	return OK;
}//CreatSMatrix_OL

void PrintSMatrix_OL(CrossList M){
	//��������ʽ���ϡ�����M
	OLink p;
	int n;
	for(int i=1;i<=M.mu;++i){
		p=M.rhead[i];
		n=1;
		while(p){
			if(p->j==n++){
				printf("%3d",p->e);
				p=p->right;
			}else printf("%3d",0);
			if(n>M.nu)break;
		}
		for(;n<=M.nu;++n)printf("%3d",0);
		printf("\n");
	}
}