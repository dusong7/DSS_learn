/*
	��̬����	
*/
#include "head.h"

int Init_Seq(SSTable &ST,int length,Status (* input)(SSTable &ST)){
	//��ʼ��
	ST.length=length;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*(length+1));
	if(!ST.elem)exit(OVERFLOW);
	return input(ST);
}

int Search_Seq(SSTable ST,KeyType key){
	//��ST��˳����ҵ���key��Ԫ�� �ҵ�����Ԫ���ڱ��е�λ�� ���򷵻�0
	int i;
	ST.elem[0].key=key;//�ڱ�����⵽��ʱû�У�����0
	for(i=ST.length;!EQ(ST.elem[i].key,key);--i);//��ǰ�������
	return i;//�Ҳ����Ƿ���0
}

int Search_Bin(SSTable ST,KeyType key){
	//�������ST�в�����ؼ��ֵ���Key������Ԫ�ء��ҵ�����λ�ã����򷵻�0
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
	//����ST��Ȩ��weight ���� sw
	if(ST.length>0){
		for(int i=1;i<=ST.length;++i){
			//sw[i]=ST.elem[i].weight;
			sw[i]=(float)(rand()%5+1);//������λ��¼Ȩֵ
		}
		return OK;
	}else return ERROR;
}

Status CreateSOSTree(SOSTree &T,SSTable ST){
	//�������ST����һ�������Ȳ�����
	//ST��Ȩֵ����Ȩ��weight
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
	//�������R[low high]�����ۼƵ�Ȩֵ��sw(sw[0]==0)�ݹ鹹������Ȳ�����
	int i=low;
	float min=(float)fabs(sw[high]-sw[low]);
	float dw=(sw[high]+sw[low-1]);
	for(int j=low+1;j<=high;++j){//ѡ����Сphֵ
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
	//�ڴ��������в���key δ�ҵ�����0
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