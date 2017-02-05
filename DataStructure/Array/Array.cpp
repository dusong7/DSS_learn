/*
	����˳��洢����

#define MAX_ARRAY_DIM 8//�䳤���� ���ֵ

typedef int ElemType;

typedef struct{
	ElemType *base;
	int	     dim;//���鳤��
	int      *bounds;//������ַ
	int	     *constans;//����ӳ����������ַ
}Array;

Status InitArray(Array &A,int dim,...);    //��ʼ��һ������
Status DestoryArray(Array &A);             //��������
Status Locate(Array A,va_list ap,int &off);//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�����Ӧ��ַoff
Status Value(ElemType &e,Array A,...);     //A�����飬e�Ƿ���ֵ��������±� ��e��A��˳����ȷʱ��λ�ȡ����
Status Assign(Array &A,ElemType e,...);    //AΪ����,eΪԪ�ر���,�����n���±��ֵ
*/

#include"head.h"

Status InitArray(Array &A,int dim,...){
	//��ʼ��һ������
	if(dim<1 || dim>MAX_ARRAY_DIM)return ERROR;
	A.dim=dim;
	A.bounds=(int *)malloc(dim*sizeof(int));
	if(!A.bounds)exit(OVERFLOW);
	//����ά���ȺϷ��������A.bounds
	int elemtotal=1;
	va_list ap;
	va_start(ap,dim);
	for(int i=0;i<dim;++i){
		A.bounds[i]=va_arg(ap,int);
		elemtotal*=A.bounds[i];
	}
	va_end(ap);
	A.base=(ElemType *)malloc(elemtotal*sizeof(ElemType));
	if(!A.base)exit(OVERFLOW);
	A.constans=(int *)malloc(dim*sizeof(int));
	if(!A.constans)exit(OVERFLOW);
	A.constans[dim-1]=1;//L=1,ָ���������Ԫ�صĴ�СΪ��λ
	for(int i=dim-2;i>=0;--i)
		A.constans[i]=A.bounds[i+1]*A.constans[i+1];
	return OK;
}

Status DestoryArray(Array &A){
	//��������
	if(!A.base)return ERROR;
	free(A.base);A.base=NULL;
	if(!A.bounds)return ERROR;
	free(A.bounds);A.bounds=NULL;
	if(!A.constans)return ERROR;
	free(A.constans);A.constans=NULL;
	return OK;
}

Status Locate(Array A,va_list ap,int &off){
	//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�����Ӧ��ַoff
	off=0;
	int ind;
	for(int i=0;i<A.dim;++i){
		ind=va_arg(ap,int);	
		if(ind<0 || ind>=A.bounds[i])return OVERFLOW;
		off+=A.constans[i]*ind;
	}
	return OK;
}

Status Value(ElemType &e,Array A,...){
	//A�����飬e�Ƿ���ֵ��������±�
	va_list ap;
	va_start(ap,A);
	int off;
	Status result;
	if((result=Locate(A,ap,off))<=0)return result;
	e=*(A.base+off);
	return OK;
}

Status Assign(Array &A,ElemType e,...){
	//AΪ����,eΪԪ�ر���,�����n���±��ֵ
	//���±겻Խ�磬e��ֵ��A��Ӧ��λ��
	va_list ap;
	int off;
	va_start(ap,e);
	Status result;
	if((result=Locate(A,ap,off))<=0)return result;
	*(A.base+off)=e;
	return OK;
}

