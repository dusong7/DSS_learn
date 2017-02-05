/*
	稀疏矩阵 转换
*/
#include"head.h"

Status TransposeSMatrix(TSMatrix M,TSMatrix &T){
	//采用三元组表示，将稀疏矩阵M转置为T
	T.mu=M.nu;
	T.nu=M.mu;
	T.tu=M.tu;
	int q,col,p;
	if(T.tu){
		q=1;
		for(col=1; col<=M.nu; ++col)
			for(p=1; p<=M.tu; ++p)
				if(M.data[p].j==col){
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i;
					T.data[q].e=M.data[p].e;
					++q;
				}
	}
	return OK;
}

Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T){
	//采用三元组顺序表表示，求稀疏矩阵M转置矩阵T
	T.mu=M.nu;
	T.nu=M.mu;
	T.tu=M.tu;

	int col,t;
	if(T.tu){
		int *num=(int *)malloc((M.nu+1)*sizeof(int));
		int *cpot=(int *)malloc((M.nu+1)*sizeof(int));		
		for(col=1;col<=M.nu;++col)num[col]=0;
		for(t=1;t<=M.tu;++t)++num[M.data[t].j];//求M中每列所含的非零元素
		cpot[1]=1;
		for(col=2;col<=M.nu;++col)cpot[col]=cpot[col-1]+num[col-1];
		int p,q;
		for(p=1;p<=M.tu;++p){
			col=M.data[p].j;
			q=cpot[col];
			//printf("%d %d %d \n",M.data[p].i,M.data[p].j,M.data[p].e);
			T.data[q].i=M.data[p].j;
			T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e;
			++cpot[col];
		}//for
		free(num);
		free(cpot);
	}//if
	return OK;
}
Status InitRLSMatrixRpos(RLSMatrix &M){
	//计算各行第一个非零元素的位置
	int i;
	for(i=1;i<=M.mu;++i)M.rpos[i]=0;
	for(i=1;i<=M.tu;++i){
		if(M.rpos[M.data[i].i]==0)M.rpos[M.data[i].i]=i;
		else if(i<M.rpos[M.data[i].i])M.rpos[M.data[i].i]=i;
	}
	//for(i=1;i<=M.mu;i++){
	//	printf("%d\n",M.rpos[i]);
	//}
	return OK;
}
Status MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q){
	//求矩阵乘积Q=M*N，采用逻辑链接存储表示
	if(M.nu!=N.mu)return ERROR;
	Q.mu=M.mu;
	Q.nu=N.nu;
	Q.tu=0;
	if(M.tu*N.tu!=0){//非零矩阵
		int arow,tp,p,q,brow,t,ccol;
		int ctemp[MAXSIZE];
		for(arow=1;arow<=M.mu;++arow){//逐行处理
			for(int i=0;i<MAXSIZE;++i)ctemp[i]=0;//当前各行元素累加器清零
			Q.rpos[arow]=Q.tu+1;
			if(arow<M.mu)tp=M.rpos[arow+1];
			else tp=M.tu+1;
			for(p=M.rpos[arow];p<tp;++p){
				brow=M.data[p].j;
				if(brow<N.mu)t=N.rpos[brow+1];
				else t=N.tu+1;
				for(q=N.rpos[brow];q<t;++q){
					ccol=N.data[q].j;
					ctemp[ccol]+=M.data[p].e*N.data[q].e;
				}//for q
			}//for p 求得Q中第crow(=arow)行的非零元素
			for(ccol=1;ccol<=Q.nu;++ccol){
				if(ctemp[ccol]){
					if(++Q.tu>MAXSIZE)return ERROR;
					Q.data[Q.tu].i=arow;
					Q.data[Q.tu].j=ccol;
					Q.data[Q.tu].e=ctemp[ccol];
				}//if
			}//for ccol
		}//for arow
	}//if
	return OK;
}