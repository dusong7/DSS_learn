/*
	线性静态链表 数据函数
*/

#include"head.h"

int LocateElem_SL(SLinkList S,ElemType e,int (* compare)(ElemType,ElemType)){
	//在链表中查找第一个值为 e 的元素
	//找到返回位置，否则返回 0
	//compare 为比较函数
	int i=S[0].cur;
	while(i && !compare(S[i].data,e))i=S[i].cur;
	return i;
}//LocateElem_SL
void InitSpace_SL(SLinkList &space){
	//将一维数组中各各分量链成一个备用链表,space[0].cur为头指针
	// "0" 表示空
	int i;
	for(i=0;i<MAXSIZE-1;++i)
		space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;
}//InitSpace_SL

int Malloc_SL(SLinkList &space){
	//若备用链表不为空，则返回分配的结点下标，否则返回0
	int i=space[0].cur;
	if(space[0].cur)space[0].cur=space[i].cur;
	return i;
}//Malloc_SL

void Free_SL(SLinkList &space,int i){
	//将下标为i的空间作为备用空间
	space[i].cur=space[0].cur;
	space[0].cur=i;
}//Free_SL

void difference(SLinkList &space, int &S,void (* InputData)(ElemType &),int (* compare)(ElemType,ElemType)){
	//依次输入集合A和集合B的元素，在一维数组space中建立表示集合（A-B）U (B-A)的静态链表,S为其头指针，假设备用空间足够大,space[0].cur为其头指针
	//InputData为输入函数
	int m,n,i,j,r,p,k;
	ElemType b;
	InitSpace_SL(space);
	r=S=Malloc_SL(space);
	printf("Input m and n of A and B number:");
	scanf("%d%d",&m,&n);
	printf("\nA:\n");
	for(j=1;j<=m;++j){//输入集合A
		i=Malloc_SL(space);//分配结点
		InputData(space[i].data);
		space[r].cur=i;//在末尾插入
		r=i;
	}//for
	space[r].cur=0;//将结尾指针点设为空

	printf("\nB:\n");
	for(j=1;j<=n;++j){//输入集合B
		InputData(b);//输入元素b
		p=S;
		k=space[S].cur;//K指向A中的第一个结点
		while(k != space[r].cur && !compare(space[k].data,b)){//在当前链表中查找
			p=k;
			k=space[k].cur;
		}//while
		if(k==space[r].cur){//当元素不存在时，将元素插入到r所指结点之后,且r位置不改变
			i=Malloc_SL(space);
			space[i].data=b;
			space[i].cur=space[r].cur;
			space[r].cur=i;
		}else{//if 当该元素存在时，将其删除
			space[p].cur=space[k].cur;
			Free_SL(space,k);
			if(r==k)r=p;//若将r删除，那么需要修改尾指针
		}//else
	}//for
}//difference
