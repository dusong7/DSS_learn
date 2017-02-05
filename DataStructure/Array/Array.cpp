/*
	数组顺序存储定义

#define MAX_ARRAY_DIM 8//变长数组 最大值

typedef int ElemType;

typedef struct{
	ElemType *base;
	int	     dim;//数组长度
	int      *bounds;//数组界基址
	int	     *constans;//数组映像函数常量基址
}Array;

Status InitArray(Array &A,int dim,...);    //初始化一个数组
Status DestoryArray(Array &A);             //销毁数据
Status Locate(Array A,va_list ap,int &off);//若ap指示的各下标值合法，则求出该元素在A中相对应地址off
Status Value(ElemType &e,Array A,...);     //A是数组，e是返回值，随后是下标 当e和A的顺序不正确时变参获取错误
Status Assign(Array &A,ElemType e,...);    //A为数组,e为元素变量,随后是n个下标的值
*/

#include"head.h"

Status InitArray(Array &A,int dim,...){
	//初始化一个数组
	if(dim<1 || dim>MAX_ARRAY_DIM)return ERROR;
	A.dim=dim;
	A.bounds=(int *)malloc(dim*sizeof(int));
	if(!A.bounds)exit(OVERFLOW);
	//若各维长度合法，则存入A.bounds
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
	A.constans[dim-1]=1;//L=1,指针的增减以元素的大小为单位
	for(int i=dim-2;i>=0;--i)
		A.constans[i]=A.bounds[i+1]*A.constans[i+1];
	return OK;
}

Status DestoryArray(Array &A){
	//销毁数据
	if(!A.base)return ERROR;
	free(A.base);A.base=NULL;
	if(!A.bounds)return ERROR;
	free(A.bounds);A.bounds=NULL;
	if(!A.constans)return ERROR;
	free(A.constans);A.constans=NULL;
	return OK;
}

Status Locate(Array A,va_list ap,int &off){
	//若ap指示的各下标值合法，则求出该元素在A中相对应地址off
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
	//A是数组，e是返回值，随后是下标
	va_list ap;
	va_start(ap,A);
	int off;
	Status result;
	if((result=Locate(A,ap,off))<=0)return result;
	e=*(A.base+off);
	return OK;
}

Status Assign(Array &A,ElemType e,...){
	//A为数组,e为元素变量,随后是n个下标的值
	//若下标不越界，e赋值到A对应的位置
	va_list ap;
	int off;
	va_start(ap,e);
	Status result;
	if((result=Locate(A,ap,off))<=0)return result;
	*(A.base+off)=e;
	return OK;
}

