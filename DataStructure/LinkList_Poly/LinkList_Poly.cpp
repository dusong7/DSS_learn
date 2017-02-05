/*
	多项式函数
*/

#include"head.h"

void CreatPolyn(polynomail &P,int n,void (* Input)(ElemType &)){
	//创建数据
	InitList(P);

	LinkList h,s;	
	h=GetHead(P);//获取头结点
	ElemType e;
	e.coef=0.0;e.expn=-1;//头结点初始数据
	SetCurElem(h,e);

	Postion q=NULL;//位置变量
	for(int i=0;i<n;++i){
		Input(e);
		if(!LocateElem(P,e,q,com)){
			if(MakeNode(s,e))InsFirst(q,s);
		}//if
	}//for
}//CreatPloyn

void PrintPolyn(polynomail P){
	//打印数据
	polynomail p2=P->next;
	printf("\nThe retult is:\n\t");
	while(p2){
		if(!p2->next)printf("%0.2fx^%d\n",p2->data.coef,p2->data.expn);
		else printf("%0.2fx^%d + ",p2->data.coef,p2->data.expn);
		p2=p2->next;
	}//while
}//PrintPolyn

void AddPoly(polynomail &Pa,polynomail &Pb,int (* compare)(ElemType,ElemType)){
	//多项式加法
	LinkList ha,hb,qa,qb;
	ElemType a,b;
	ha=GetHead(Pa);
	hb=GetHead(Pb);
	qa=NextPos(Pa,ha);
	qb=NextPos(Pb,hb);
	float sum;
	while(qa && qb){
		a=GetCurElem(qa);
		b=GetCurElem(qb);
		switch(compare(a,b)){
		case -1:
			ha=qa;
			qa=NextPos(Pa,qa);
			break;
		case 0:
			sum=a.coef+b.coef;//将系数相加
			if(sum!=0.0){//修改当前结点的数值
				a.coef=sum;
				SetCurElem(qa,a);
				ha=qa;
			}else{//删除结点
				DelFirst(ha,qa);
				FreeNode(qa);
			}//if else
			DelFirst(hb,qb);
			FreeNode(qb);
			qb=NextPos(Pb,hb);
			qa=NextPos(Pa,ha);
			break;
		case 1://qb的结点比较小
			DelFirst(hb,qb);
			InsFirst(ha,qb);
			qb=NextPos(Pb,hb);
			ha=NextPos(Pa,ha);
			break;
		}//switch
	}//while
	if(!ListEmpty(Pb))Append(Pa,qb);
	FreeNode(hb);
}//AddPoly

void SubPoly(polynomail &Pa,polynomail &Pb,int (* compare)(ElemType,ElemType)){
	//多项式减法
	LinkList ha,hb,qa,qb;
	ElemType a,b;
	ha=GetHead(Pa);
	hb=GetHead(Pb);
	qa=NextPos(Pa,ha);
	qb=NextPos(Pb,hb);
	float sum;
	while(qa && qb){
		a=GetCurElem(qa);
		b=GetCurElem(qb);
		switch(compare(a,b)){
		case -1:
			ha=qa;
			qa=NextPos(Pa,qa);
			break;
		case 0:
			sum=a.coef-b.coef;//将系数相减
			if(sum!=0.0){//修改当前结点的数值
				a.coef=sum;
				SetCurElem(qa,a);
				ha=qa;
			}else{//删除结点
				DelFirst(ha,qa);
				FreeNode(qa);
			}//if else
			DelFirst(hb,qb);
			FreeNode(qb);
			qb=NextPos(Pb,hb);
			qa=NextPos(Pa,ha);
			break;
		case 1://qb的结点比较小
			DelFirst(hb,qb);
			InsFirst(ha,qb);
			qb=NextPos(Pb,hb);
			ha=NextPos(Pa,ha);
			break;
		}//switch
	}//while
	if(!ListEmpty(Pb))Append(Pa,qb);
	FreeNode(hb);
}//SubPoly

