/*
	稀疏矩阵十字链表存储
*/

#include"head.h"

Status InitSMatrix_OL(CrossList &M){
	//初始化稀疏矩阵
	M.chead=NULL;
	M.rhead=NULL;
	M.mu=M.nu=M.tu=0;
	return OK;
}
Status CreatSMatrix_OL(CrossList &M,void (* inputNum)(int &,int &,int &),Status(* InputData)(OLNode &,CrossList)){
	//inputNum 为输入行数 列数 总数 InputData 为输入数据，数据成功则返回OK 否则返回ERROR
	if(M.chead)free(M.chead);
	if(M.rhead)free(M.rhead);
	inputNum(M.mu,M.nu,M.tu);
	//使用calloc初始化为空
	if(!(M.rhead=(OLink *)calloc((M.mu+1),sizeof(OLink))))exit(OVERFLOW);
	if(!(M.chead=(OLink *)calloc((M.nu+1),sizeof(OLink))))exit(OVERFLOW);
	OLNode e;
	OLink p,q;
	int n=0;
	while(InputData(e,M)){//输入正确数据
		if(++n>M.tu)break;
		if(!(p=(OLink)malloc(sizeof(OLNode))))exit(OVERFLOW);
		//生成结点
		p->i=e.i;
		p->j=e.j;
		p->e=e.e;
		if(M.rhead[e.i]==NULL || M.rhead[e.i]->j>e.j){
			p->right=M.rhead[e.i];
			M.rhead[e.i]=p;
		}else{//插入行
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
	//以数组形式输出稀疏矩阵M
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