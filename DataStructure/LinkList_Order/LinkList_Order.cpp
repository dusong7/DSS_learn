/*
	������ ˳��� ���ݺ���
*/

#include "head.h"

Status InitList(SqList &L){
	//��ʼ��˳��� LΪ������

	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//����ռ�
	if( !L.elem )exit(OVERFLOW);//�޷�����ռ�ֱ�ӽ������򣬲������������
	L.length = 0;//���ݳ�ʼ����Ϊ0
	L.listsize = LIST_INIT_SIZE;//�����ܳ���Ϊ����ֵ
	return OK;
}

Status ListInsert(SqList &L,int i,ElemType e){
	//����Ԫ�� iΪ���,eΪ����Ԫ��

	if( i>L.length+1 || i<1 )return ERROR;//�Ƿ���ֵ
	if( L.length >= L.listsize ){//����ʱ�����µĿռ�
		ElemType *newbase;
		newbase = (ElemType *)realloc(L.elem , (L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if( !newbase )exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType *p , *q;
	q = &(L.elem[i-1]);
	for(p = &(L.elem[L.length-1]) ; p >= q ; p--)//ѭ���ƶ�
		*(p+1) = *p;
	*q = e;//����Ԫ��
	++L.length;//���ݳ�������
	return OK;
}

Status ListDelete(SqList &L,int i,ElemType &e){
	//ɾ������Ԫ�� iΪ���� eΪɾ���󷵻ص�����

	if( i<1 || i>L.length )return ERROR;
	ElemType *p;
	p = &(L.elem[i-1]);//��ɾ��Ԫ�ص�λ��
	e = *p;
	ElemType *q;
	q = L.elem + L.length - 1;//Ԫ��ĩβ
	for(++p ; p<=q ; p++)*(p-1) = *p;//�ƶ�Ԫ��
	--L.length;
	return OK;
}

int LocateElem(SqList L,ElemType e,int (* compare)(ElemType,ElemType)){
	//��˳����в��ҵ�һ��ֵ���� compare()Ԫ�ص�λ��
	//�ҵ�����λ�ã����򷵻� 0
	int i = 1;
	ElemType *p=L.elem;
	while( i <= L.length && !compare(*p++,e) )++i;//ѭ������
	if( i<=L.length )return i;
	else return 0;
}

void MergeList(SqList La,SqList Lb,SqList &Lc){
	//����֪�ǵݼ�����˳�����й鲢�ϲ�
	ElemType *pa,*pa_last,*pb,*pb_last,*pc;
	pa = La.elem;
	pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listsize*sizeof(ElemType));
	if(!Lc.elem)exit(OVERFLOW);//����ռ�ʧ��
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	while(pa<pa_last && pb<pb_last){//�鲢
		if( *pa<=*pb )*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while( pa<=pa_last )*pc++ = *pa++;
	while( pb<=pb_last )*pc++ = *pb++;
}