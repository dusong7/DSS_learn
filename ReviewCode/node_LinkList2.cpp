//Test for Node Link List.
//
//
// ConsoleDSC.cpp : Defines the entry point for the console application.
//
//
//  main.cpp
//  tempCodePjCpp
//
//  Created by apple on 17/2/5.
//  Copyright © 2017年 apple. All rights reserved.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

//#define OVERFLOW -2
#define INFEASIBLE -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//
//typedef struct {
//	char name[20];
//	int age;
//}ElemType;
//
//typedef struct DuLNode {
//	ElemType data;
//	struct DuLNode *prior;
//	struct DuLNode *next;
//}DuLNode, *DuLinkList;
//
//void CreatList_DuL(DuLinkList &L, int n, void(*InputData)(ElemType &));//创建链表 向链表头之前插入
//int ListLength(DuLinkList L);
////返回数据长度,由于判断为下一个地址的比较，故缺少一个值，因此从1开始计数
////L必须是经过初始化的数据
//DuLinkList GetElemP_Dul(DuLinkList L, int i);//返回第i个结点
//Status ListInsert_DuL(DuLinkList &L, int i, ElemType e);//在第i个位置之前插入元素e
//Status ListDelete_Dul(DuLinkList &L, int i, ElemType &e);//删除L链表中头结点的第i 个元素
//Status DestroyList_Dul(DuLinkList &L);//销毁链表
//Status Append(DuLinkList &La, DuLinkList &Lb);//将链表Lb链接到La之后
//
////其他操作函数
//void input(ElemType &e);//输入数据
//
//void input(ElemType &e) {
//	printf("Input name:");
//	scanf_s("%s", e.name,20);
//	printf("Input age:");
//	scanf_s("%d", &e.age);
//}
//
//
//void CreatList_DuL(DuLinkList &L, int n, void(*InputData)(ElemType &)) {
//	//
//	L = NULL;
//	if (n<1)return;//
//
//	L = (DuLinkList)malloc(sizeof(DuLNode));
//	L->prior = L;
//	L->next = L;
//	InputData(L->data);//
//	printf("Initied\n");
//
//}//CreatList
//
//int ListLength(DuLinkList L) {
//
//	int i = 1;
//	if (L == NULL)return 0;
//	DuLinkList p = L;
//	printf("L_%d_\n", L->data.age);
//
//	while (p->next != L && ++i)
//	{
//		p = p->next;
//	}
//	return i;
//}//ListLength
//
//DuLinkList GetElemP_Dul(DuLinkList L, int i) {
//	if (L == NULL)return NULL;
//	DuLinkList p = L;
//	int j = 0;
//	while (++j != i) {
//		if (j != 1)if (p->next == L)break;
//		p = p->next;
//	}//while
//	if (j != i)return NULL;
//	else return p;
//}//GetElemP_Dul
//
//Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
//
//	DuLinkList p, s;
//	if (!(p = GetElemP_Dul(L, i)))return ERROR;//
//	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))return ERROR;//
//	//s->data = e;
//	//s->prior = p->prior;
//	////*
//	////s->next=p->next;
//	////*repalce
//	//p->prior->next = s;
//	//s->next = p;
//	////end replace
//
//	//p->prior = s;
//
//	s->data = e;
//
//	s->prior = p->prior;
//	p->prior->next = s;
//
//	s->next = p;
//	p->prior = s;
//
//	//_U_u2 s1_S_s2 p1_P_
//	//s->prior = p->prior
//	//p->prior->next = s;
//	//s->next = p;
//	//p->prior = s;
//
//	return OK;
//}//ListInsert_DuL
//
//Status ListDelete_Dul(DuLinkList &L, int i, ElemType &e) {
//	//
//	DuLinkList p;
//	if (i<=1)
//	{
//		return ERROR;
//	}
//
//	if (!(p = GetElemP_Dul(L, i)))return ERROR;//
//	e = p->data;
//	p->prior->next = p->next;
//	p->next->prior = p->prior;
//	free(p);
//	return OK;
//}//ListDelete_Dul
//
//Status DestroyList_Dul(DuLinkList &L) {
//	//
//	if (L == NULL)return OK;
//	DuLinkList p = L, p2 = L;
//	int i = 0;
//	while (p != L || ++i == 1) {
//		p = p->next;
//		free(p2);
//		p2 = p;
//	}
//	L = NULL;
//	return OK;
//}//ClearList_Dul
//
//Status Append(DuLinkList &La, DuLinkList &Lb) {
//	//
//	if (!La || !Lb)return ERROR;
//	DuLinkList p = Lb->prior;;
//	Lb->prior->next = La;
//	Lb->prior = La->prior;
//	La->prior->next = Lb;
//	La->prior = p;
//	return OK;
//}//Append
//
//int main(void) {
//	DuLinkList L, p;
//	int i = 0, n;
//	printf("Input list number:");
//	scanf_s("%d", &n);
//	CreatList_DuL(L, n, input);
//	p = L;
//
//	ElemType ep;
//	ep.age = 100;
//	//ep.name = "Test";
//	memcpy(ep.name, "Test", 5);
//	ListInsert_DuL(L,1,ep);
//	ep.age = 101;
//	ListInsert_DuL(L, 1, ep);
//	ep.age = 102;
//	ListInsert_DuL(L, 1, ep);
//
//	ListDelete_Dul(L, 1, ep);
//	printf("Length is %d\n", ListLength(L));
//
//	printf("\nThe result is\n");
//
//	while (p != L || i++ == 0) {
//		printf("%s => %d\n", p->data.name, p->data.age);
//		p = p->next;
//	}//while
//	printf("\nGetElem:\n");
//	for (i = 1; i <= ListLength(L); i++) {
//		p = GetElemP_Dul(L, i);
//		printf("%dth name_%s => age_%d\n", i, p->data.name, p->data.age);
//	}
//
//	printf("\nResult End!\n");
//	system("pause");
//	return 0;
//}
//////////
#include <malloc.h>

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link, *Position;

typedef struct {
	Link head, tail;
	int len;
}LinkList;

///DS_C implement
Status MakeNode(Link &p, ElemType e)
{
	p->data = e;
	p->next = NULL;

	return OK;
}

///Other way implement
Position MakeNode_LL(ElemType e)
{
	//
	Link p = NULL;

	p = (Link)malloc(sizeof(LNode));
	if (!p)return ERROR;
	else
	{
		p->data = e;
		p->next = NULL;
	}
	return p;
}

///
void FreeNode_LL(Link &p)
{
	//
	free(p);
}

////
Status InitList_LL(LinkList &L)
{
	//
	Link head = (Link)malloc(sizeof(LNode));
	MakeNode(head, 3);

	ElemType ep;
	ep = 100;
	/*L.head = MakeNode_LL(ep);*/
	L.head = head;

	L.head->next = NULL;
	L.tail = L.head;
	L.len = 0;
	return OK;
}
///

Status ListInsert_LL(LinkList &L, Link s)
{
	//
	s->next = L.head->next;
	if (!L.head->next)
	{
		L.tail = s;
	}

	L.head->next = s;
	L.len++;

	return OK;
}

///
Status DestroyList(LinkList &L) //
{

	return OK;
}
///////////

///
Status ClearList_LL(LinkList &L) //set empty
{
	return OK;
}
///////////

///
Status InsFirst_LL(Link h, Link s)
{
	return OK;
}
///////////

///
Status DelFir_LL(Link h, Link &q)
{
	return OK;
}
///////////

///
Status Append_LL(LinkList &L, Link &q)
{
	return OK;
}
///////////

///
Status InsBefore_LL(LinkList &L, Link &q, Link s)
{
	return OK;
}
///////////

///
Status InsAfter_LL(LinkList &L, Link &q, Link s)
{
	return OK;
}
///////////

///
Status SetCurElem_LL(Link &p, ElemType e)
{
	return OK;
}
///////////

///
ElemType GetCurElem_LL(Link p)
{
	return 1;
}
////////////

///
Status ListEmpty_LL(LinkList L)
{
	return 1;
}
////////////

///
int ListLength_LL(LinkList L)
{
	return 1;
}
////////////


///
//Position GetHead_LL(LinkList L)
//{
//	Position p;
//	return p;
//}
//////////////

/////
//Position GetLast_LL(LinkList L)
//{
//	Position p;
//	return p;
//}
//////////////


/////
//Position PrioPos_LL(LinkList L, Link p)
//{
//	Position p;
//	return p;
//}
//////////////

///
//Position NextPos_LL(LinkList L, Link p)
//{
//	Position p;
//	return p;
//}
//////////////

///
Status LocalPos_LL(LinkList L, int i, Link &p)
{
	return OK;
}
////////////

///
//Position LocateElem_LL(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
//{
//	Position p;
//	return p;
//}
//////////////

/////
Status ListTraverse_LL(LinkList L, Status(*visit)())
{
	return OK;
}
//////////////////

//Status MergeList_LL(LinkList &La, LinkList &Lb, LinkList &Lc)
//{
//
//	if (!InitList_LL(Lc)) {
//		/* code */
//		return ERROR;
//	}
//
//	Position ha = GetHead_LL(La);  //
//	Position hb = GetHead_LL(Lb);  //
//	Position pa = NextPos_LL(La, ha);
//	Position pb = NextPos_LL(Lb, hb);
//
//	while (pa && pb) {
//		ElemType a = GetCurElem_LL(pa);
//		ElemType b = GetCurElem_LL(pb
//		if ((*compare)(a, b) <= 0) {
//			DelFir_LL(ha, q);
//			Append_LL(Lc, q);
//			pa = NextPos_LL(La, ha);
//		}
//		else
//		{
//			DelFir_LL(hb, q);
//			Append_LL(Lc, q);
//			pb = NextPos_LL(Lb, hb);
//		}
//	}
//
//	if (pa) {
//		Append_LL(Lc, pa);
//	}
//	else{
//		Append_LL(Lc, pb);
//	}
//
//	FreeNode_LL(ha);
//	FreeNode_LL(hb);
//
//	return OK;
//}

int main()
{
	//
	LinkList lp;
	InitList_LL(lp);
	Link l1 = (Link)malloc(sizeof(Link));
	l1->data = 101;
	l1->next = NULL;

	ListInsert_LL(lp, l1);

	return 0;
}
