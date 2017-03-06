// testDss.cpp : Defines the entry point for the console application.
//

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
#include <malloc.h>
#include <algorithm>

using namespace std;

//#define OVERFLOW -2
#define INFEASIBLE -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0



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

///Finish
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


////
///get Known node ,proir node
Position PriorPos_LL(LinkList L, Link p)
{
	Link q = (Link)malloc(sizeof(Link));
	q = L.head;
	if (q->next == p)
	{
		return 0;
	}

	while (q->next->data != p->data)
	{
		if (q->next != NULL)
		{
			q = q->next;
		}
	}

	return q;
	//
}

///
Status DestroyList_LL(LinkList &L) //
{
	//
	return OK;
}
///////////

///Same as DestroyList//
Status ClearList_LL(LinkList &L) //set empty
{
	//
	return OK;
}
///////////

///
Status InsFirst_LL(Link h, Link s)
{
	//
	return OK;
}
///////////

///
Status DelFir_LL(Link h, Link &q)
{
	//
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
	int nLength = 0;
	Link p = L.head;

	while (p)
	{
		p = p->next;
		nLength++;
	}
	return nLength;
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

//
Status visit(Link p)
{
	//
	printf("%d_  ", p->data);

	return OK;
}

/////
Status ListTraverse_LL(LinkList L, Status(*visit)(Link))
{
	Link p = NULL;
	p = L.head;

	if (!p->next)
	{
		printf("\nThe LinkList is Empty\n");
	}

	while (p)
	{
		//printf("%d_\t", p->data);
		visit(p); //alway can use visit function...
		p = p->next;
	}

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

	for (size_t i = 0; i < 5; i++)
	{
		Link ltemp = (Link)malloc(sizeof(Link));
		ltemp->data = 200+i;
		ltemp->next = NULL;

		ListInsert_LL(lp, ltemp);
	}

	ListTraverse_LL(lp, visit);
	Link lTarger = (Link)malloc(sizeof(Link));
	lTarger->data = 202;
	lTarger->next = NULL;

	Link lResult = PriorPos_LL(lp, lTarger);


	return 0;
}
