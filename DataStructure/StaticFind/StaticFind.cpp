/*
	静态查找	
*/
#include "head.h"

int Init_Seq(SSTable &ST,int length,Status (* input)(SSTable &ST)){
	//初始化
	ST.length=length;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*(length+1));
	if(!ST.elem)exit(OVERFLOW);
	return input(ST);
}

int Search_Seq(SSTable ST,KeyType key){
	//在ST中顺序查找等于key的元素 找到返回元素在表中的位置 否则返回0
	int i;
	ST.elem[0].key=key;//哨兵，检测到此时没有，返回0
	for(i=ST.length;!EQ(ST.elem[i].key,key);--i);//从前往后查找
	return i;//找不到是返回0
}

int Search_Bin(SSTable ST,KeyType key){
	//在有序表ST中查找其关键字等于Key的数据元素。找到返回位置，否则返回0
	int low=0,mid;
	int high=ST.length;
	while(low<=high){
		mid=(low+high)/2;
		if(EQ(key,ST.elem[mid].key))return mid;
		else if(LT(key,ST.elem[mid].key)) high=mid-1;
		else low=mid+1;

	}
	return 0;
}

Status FindSW(float *sw,SSTable ST){
	//根据ST的权域weight 计算 sw
	if(ST.length>0){
		for(int i=1;i<=ST.length;++i){
			//sw[i]=ST.elem[i].weight;
			sw[i]=(float)(rand()%5+1);//该数据位记录权值
		}
		return OK;
	}else return ERROR;
}

Status CreateSOSTree(SOSTree &T,SSTable ST){
	//由有序表ST创建一个次优先查找树
	//ST的权值域含有权域weight
	float *sw;
	sw=(float *)malloc(sizeof(float)*ST.length);
	if(!sw)exit(OVERFLOW);
	if(ST.length == 0)T=NULL;
	else{
		if(!FindSW(sw,ST))return ERROR;
		SecondOptimal(T,ST.elem,sw,1,ST.length);
	}
	free(sw);
	return OK;
}

Status SecondOptimal(BiTree &T,ElemType R[],float sw[],int low,int high){
	//由有序表R[low high]及其累计的权值表sw(sw[0]==0)递归构造次优先查找树
	int i=low;
	float min=(float)fabs(sw[high]-sw[low]);
	float dw=(sw[high]+sw[low-1]);
	for(int j=low+1;j<=high;++j){//选择最小ph值
		if(fabs(dw-sw[j]-sw[j-1])<min){
			i=j;
			min=(float)abs(dw-sw[j]-sw[j-1]);
		}
	}
	T=(BiTree)malloc(sizeof(BiTNode));
	T->data=R[i];
	T->id=i;

	if(i==low)T->lchild=NULL;
	else SecondOptimal(T->lchild,R,sw,low,i-1);
	if(i==high)T->rchild=NULL;
	else SecondOptimal(T->rchild,R,sw,i+1,high);

	return OK;
}

int Search_SOSTree(SOSTree T,KeyType key){
	//在次优先树中查找key 未找到返回0
	if(T){
		if(EQ(key,T->data.key))return T->id;
		else if(LT(key,T->data.key)){
			if(T->lchild)Search_SOSTree(T->lchild,key);
			else return 0;
		}else{
			if(T->rchild)Search_SOSTree(T->rchild,key);
			else return 0;
		}
	}
	return 0;
}