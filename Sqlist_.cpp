#include "stdafx.h"
///INCLUDE_COMMON_DEFINE//
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

typedef struct {
	ElemType *elem;
	int     length;
	int     listsize;
}Sqlist;
//
///implement InitList//
Status Init_list(Sqlist *L)
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
Status InsertList(Sqlist *L, int i, ElemType e)
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
void ListTraverse(Sqlist *L)
{
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
bool isListEmpty(Sqlist *L)
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
Status ListLength(Sqlist *L)
{
	if (L != NULL)
	{
		return (L->length);
	}

	return ERROR;
}
////

/// implement GetElement
void GetElement(Sqlist *L, int i, ElemType *e)
{
	//
	*e = (L->elem[i]);
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
void ListMerge(Sqlist La, Sqlist Lb, Sqlist *Lc)
{
	//
	int lengthLa = La.length;
	int lengthLb = La.length;

	for (size_t i = 0; i < lengthLa; i++)
	{
		InsertList(Lc, 1,La.elem[i]);
	}

	for (size_t i = 0; i < lengthLb; i++)
	{
		if (!isExistAlready(La,Lb.elem[i]))
		{
			InsertList(Lc, 1, Lb.elem[i]);
		}
	}
}
/////

////implement ListDelete
Status ListDelete(Sqlist *L, int i, ElemType *e)
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

//
int compare(ElemType e1, ElemType e2)
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
int main()
{
	Sqlist myList;
	Init_list(&myList);

	int i = 0;
	for (i = 0; i < 5; ++i) {
		InsertList(&myList, 1, i + 10);
	}
	ListTraverse(&myList);
	///////////////////////////////////
	Sqlist myList2;
	Init_list(&myList2);

	for (i =3; i < 7; ++i) {
		InsertList(&myList2, 1, i + 10);
	}
	ListTraverse(&myList2);
	///////////////////////////////////

	int x = LocateElement_sq(&myList, 14, compare);
	printf("Locate _%d\n", x);

	//    ElemType *eCur = (ElemType *)malloc(sizeof(ElemType));
	//    for (size_t i = 2; i < 10; i++)
	//    {
	//        GetElement(&myList, 2*i, eCur);
	//        printf("%d_cur\n", *eCur);
	//    }
	//    ListDelete(&myList, 4, eCur);
	//    printf("%d_Del\n", *eCur);
	//    printf("List Length %d_\n", ListLength(&myList));

	Sqlist listMerge;
	Init_list(&listMerge);
	ListMerge(myList, myList2, &listMerge);
	ListTraverse(&listMerge);
	//
	return 0;
}
