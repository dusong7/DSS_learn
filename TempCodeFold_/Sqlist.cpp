#include "stdafx.h"
//INCLUDE_COMMON_DEFINE//
#include<stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIABLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

#define CPPTYPEFILE

#ifndef CPPTYPEFILE
typedef int bool;
#endif
/////////////////////////

/////////////////////////
#define LIST_INIT_SIZE 100//
#define LINSTINCREMENT 10 //

////////////////////

//
//FUNCTION_DS_C_language_
//##
// common function()://
// InitList(&L)
// DestroyList(&L)
// ClearList(&L)
// InsertList(&L, i, e)
// ListLength(L)
// ListEmpty(L)
// GetElem(L, i, &e)
// LocateElem(L, e, compare())
// PriorElem(L, cur_e, &pre_e)
// NextElem(L, cur_e, &next_e)
// ListDelete(&L, i, &e)
// ListTraverse(L, visit())
//
//##
/////////Begin Single List//////////////
typedef struct {
	ElemType *elem;
	int     length;
	int     listsize;
}Sqlist;
//
///implement InitList//
Status Init_list_sq(Sqlist *L)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (!L->elem)
	{
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;

	//simple assign value
	/*
	int i = 0;
	for (i=0; i<LIST_INIT_SIZE;i++)
	{
	L->elem[i]=i;
	//info[i].IDNumber = i;
	//memcpy(info[i].name,"Tindu",sizeof("Tindu"));
	}
	*/

	return OK;
}
//

///Implement InsertaList//
Status InsertList_sq(Sqlist *L, int i, ElemType e)
{
	//over maxsize
	//    if (L->length>LIST_INIT_SIZE || LIST_INIT_SIZE<i<0)
	//    {
	//        exit(OVERFLOW);
	//    }

	ElemType *q;
	ElemType *p;

	if (L->length >= L->listsize)
	{
		ElemType *newbase = (ElemType *)realloc(L->elem,
			sizeof(ElemType) * (L->listsize + LINSTINCREMENT));
		L->elem = newbase;
		L->listsize += LINSTINCREMENT;
	}
	//simple assign
	//
	//    int j = 0;
	//    for (j = L->length; j>=i; j--) {
	//        //
	//        L->elem[j + 1] = L->elem[j];
	//    }
	//
	//    L->elem[i] = e;
	//    L->length++;

	q = &(L->elem[i - 1]);
	for (p = &(L->elem[L->length - 1]); p >= q; --p) {
		*(p + 1) = *p;
	}

	*q = e;
	++L->length;
	return OK;

}
/////////

////////Implement ListTraverse///
Status ListTraverse_sq(Sqlist *L)
{
	if (!L->elem)
	{
		return ERROR;
	}

	int i;
	if (L->length != 0)
	{
		for (i = 0; i < L->length; ++i)
		{
			printf("%d_\n", L->elem[i]);
		}
	}
}
/////////////////

///////Implement isListEmpty
bool isListEmpty_sq(Sqlist *L)
{
	if (L->length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
////

////implement ListLength
Status ListLength_sq(Sqlist *L)
{
	if (L != NULL)
	{
		return (L->length);
	}

	return ERROR;
}
////

/// implement GetElement
int GetElement_sq(Sqlist *L, int i, ElemType *e)
{
	//
	if (!L->elem)
	{
		return INFEASIABLE;
	}
	else if (1<i || i<L->length)
	{
		return ERROR;
	}

	*e = (L->elem[i]);
	return OK;
}
/// \return

///implement locateElement_sq
int LocateElement_sq(Sqlist *L, ElemType e,
	Status(*compare)(ElemType, ElemType))
{
	//
	ElemType  *p;
	int i = 1;
	p = L->elem;
	while (i <= L->length && !(*compare)(*p++, e))
	{
		++i;
	}
	if (i <= L->length)
	{
		return i;
	}
	else
	{
		return 0;
	}
}
/////////////////

/////////implement isExistAlready

int isExistAlready(Sqlist L, ElemType e)
{
	for (size_t i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			return 1;
		}
	}

	return 0;
}
////////////

//////////////implement listMerge
void ListMerge_sq(Sqlist La, Sqlist Lb, Sqlist *Lc)
{
	//
	int lengthLa = La.length;
	int lengthLb = La.length;

	for (size_t i = 0; i < lengthLa; i++)
	{
		InsertList_sq(Lc, 1,La.elem[i]);
	}

	for (size_t i = 0; i < lengthLb; i++)
	{
		if (!isExistAlready(La,Lb.elem[i]))
		{
			InsertList_sq(Lc, 1, Lb.elem[i]);
		}
	}
}
/////

///implement MergeList
void MergeList_sq(Sqlist La, Sqlist Lb, Sqlist *Lc)
{
	ElemType *pa = La.elem;
	ElemType *pb = Lb.elem;

	Lc->listsize = Lc->length = La.length + Lb.length;
	ElemType *pc = Lc->elem = (ElemType *)malloc(sizeof(ElemType) *
		Lc->listsize);
	if (!Lc->elem)
	{
		exit(OVERFLOW);
	}

	ElemType *pa_last = La.elem + La.length - 1;
	ElemType *pb_last = Lb.elem + Lb.length - 1;

	while (pa <= pa_last && pb<=pb_last)
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}

	while (pa<=pa_last)
	{
		*pc++ = *pa++;
	}

	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}
}

////implement ListDelete
Status ListDelete_sq(Sqlist *L, int i, ElemType *e)
{
	//
	ElemType *p;
	ElemType *q;

	if (i<1 || i>L->length)
	{
		return ERROR;
	}
	p = &(L->elem[i - 1]);
	e = p;
	q = L->elem + L->length - 1;
	for (++p; p <= q; p++)
	{
		*(p - 1) = *p;
	}
	--L->length;

	return OK;
}

//////
Status compare(ElemType e1, ElemType e2)
{
	if (e1 == e2)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/////

//implement ClearList_sq
Status ClearList_sq(Sqlist *L)
{
	if (!L)
	{
		return ERROR;
	}
	L->length = 0;
	return OK;
}
/////


///implement DestroyList_sq
Status DestroyList_sq(Sqlist *L)
{
	if (!L)
	{
		return ERROR;
	}
	free(L->elem);
	L->elem = NULL;

	return OK;
}
///
/////#Test Contenyt for Sqlist___
//#
//Sqlist myList;
//Init_list_sq(&myList);
//
//int i = 0;
//for (i = 0; i < 5; ++i) {
//	InsertList_sq(&myList, 1, i + 10);
//}
//ListTraverse_sq(&myList);
/////////////////////////////////////
//Sqlist myList2;
//Init_list_sq(&myList2);
//
//for (i = 3; i < 7; ++i) {
//	InsertList_sq(&myList2, 1, i + 10);
//}
//ListTraverse_sq(&myList2);
/////////////////////////////////////
//
//int x = LocateElement_sq(&myList, 14, compare);
//printf("Locate _%d\n", x);
//
////    ElemType *eCur = (ElemType *)malloc(sizeof(ElemType));
////    for (size_t i = 2; i < 10; i++)
////    {
////        GetElement(&myList, 2*i, eCur);
////        printf("%d_cur\n", *eCur);
////    }
////    ListDelete(&myList, 4, eCur);
////    printf("%d_Del\n", *eCur);
////    printf("List Length %d_\n", ListLength(&myList));
//
//Sqlist listMerge;
//Init_list_sq(&listMerge);
////ListMerge(myList, myList2, &listMerge);
//MergeList_sq(myList, myList2, &listMerge);
//
//ListTraverse_sq(&myList);
//DestroyList_sq(&myList);
//
//ListTraverse_sq(&myList);
//ListTraverse_sq(&listMerge);
////
/////End _Test Contenyt for Sqlist___

/////////End Single List//////////////

///////Begin Link List////////
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//////Common function
//IniList_L
//InsertList_L
//TravevseList_L
//DeleteElem_L
//GetPreElem_L
//ClearList_L
//DestroyList_L
//MergeList_L
//GetLength_L
////End Common function
//

/////implement GetPreElem_L
Status GetPreElem_L(LinkList L, ElemType eCur, ElemType *ePre)
{
	//
	return OK;
}
/////


////implement GetLength_L
Status GetLength_L(LinkList L)
{
	int i = 0;
	LNode *p = L->next;

	while (p)
	{
		i++;
		p = p->next;
	}

	return i;
}
///
/////Implement iniList_L
LNode* IniList_L(LNode *L)
{
	//
	LNode *head;
	head = (LNode *)malloc(sizeof(LNode));
	if (!head)
	{
		return false;
	}
	else
	{
		//printf("Head node position %x\n", head);
		head->data = 0;
		head->next = NULL;
		return head;
	}
}
//////

///implement TravevseList_L
void TravevseList_L(LinkList L)
{
	printf("Cur list length %d_\n", GetLength_L(L));

	LNode *p = L->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

////

////implement GetElem_L
Status GetElem_L(LinkList L,int i,  ElemType *e)
{
	LNode *p = L->next;  //can asign =L,
	int j = 1;

	while (p&& j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
	{
		return ERROR;
	}
	*e = p->data;

	return OK;
}
///

///Implement ListInsert_L
Status ListInsert_L(LinkList L, int i, ElemType e)
{
	//
	LNode *p = L;
	int j = 0;

	while (p && j<i - 1)
	{
		p = p->next;
		++j;
	}

	if (!p || j>1)
	{
		return ERROR;
	}

	LNode *pTemp = (LNode *)malloc(sizeof(LNode));

	pTemp->data = e;
	pTemp->next = p->next;
	p->next = pTemp;

	return OK;
}
/////////////

///implement MergeList_L
void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{
	//
	LNode *pa = La->next;
	LNode *pb = Lb->next;

	while (pa)
	{
		ListInsert_L(Lc, 1, pa->data);
		pa = pa->next;
	}

	while (pb)
	{
		ListInsert_L(Lc, 1, pb->data);
		pb = pb->next;
	}

}
///



///////End Link List//////////



///
int main()
{
	////list0
	LinkList list;
	LNode L;
	list = IniList_L(&L);
	
	for (size_t i = 2; i < 8; i++)
	{
		ListInsert_L(list, 1, i);
	}

	TravevseList_L(list);

	/////////////////list1
	LinkList list1;
	//LNode L;
	list1 = IniList_L(&L);

	for (size_t i = 10; i < 15; i++)
	{
		ListInsert_L(list1, 1, i);
	}

	TravevseList_L(list1);

	///Length
	//printf("%d_%d\n", GetLength_L(list), GetLength_L(list1));
	
	////MergeList 
	LinkList listMerge;
	listMerge = IniList_L(&L);

	MergeList_L(list, list1, listMerge);
	
	TravevseList_L(listMerge);

	return 0;
}
