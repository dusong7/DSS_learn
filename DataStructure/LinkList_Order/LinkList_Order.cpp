/*
	单链表 顺序表 数据函数
*/

#include "head.h"

Status InitList(SqList &L){
	//初始化顺序表 L为单链表

	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//分配空间
	if( !L.elem )exit(OVERFLOW);//无法分配空间直接结束程序，并返回溢出错误
	L.length = 0;//数据初始长度为0
	L.listsize = LIST_INIT_SIZE;//数据总长度为定义值
	return OK;
}

Status ListInsert(SqList &L,int i,ElemType e){
	//插入元素 i为序号,e为数据元素

	if( i>L.length+1 || i<1 )return ERROR;//非法数值
	if( L.length >= L.listsize ){//表不足时分配新的空间
		ElemType *newbase;
		newbase = (ElemType *)realloc(L.elem , (L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if( !newbase )exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType *p , *q;
	q = &(L.elem[i-1]);
	for(p = &(L.elem[L.length-1]) ; p >= q ; p--)//循环移动
		*(p+1) = *p;
	*q = e;//插入元素
	++L.length;//数据长度增加
	return OK;
}

Status ListDelete(SqList &L,int i,ElemType &e){
	//删除数据元素 i为个数 e为删除后返回的数据

	if( i<1 || i>L.length )return ERROR;
	ElemType *p;
	p = &(L.elem[i-1]);//待删除元素的位置
	e = *p;
	ElemType *q;
	q = L.elem + L.length - 1;//元素末尾
	for(++p ; p<=q ; p++)*(p-1) = *p;//移动元素
	--L.length;
	return OK;
}

int LocateElem(SqList L,ElemType e,int (* compare)(ElemType,ElemType)){
	//在顺序表中查找第一个值满足 compare()元素的位置
	//找到返回位置，否则返回 0
	int i = 1;
	ElemType *p=L.elem;
	while( i <= L.length && !compare(*p++,e) )++i;//循环查找
	if( i<=L.length )return i;
	else return 0;
}

void MergeList(SqList La,SqList Lb,SqList &Lc){
	//将已知非递减线性顺序表进行归并合并
	ElemType *pa,*pa_last,*pb,*pb_last,*pc;
	pa = La.elem;
	pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listsize*sizeof(ElemType));
	if(!Lc.elem)exit(OVERFLOW);//分配空间失败
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	while(pa<pa_last && pb<pb_last){//归并
		if( *pa<=*pb )*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while( pa<=pa_last )*pc++ = *pa++;
	while( pb<=pb_last )*pc++ = *pb++;
}