//
////nºóÎÊÌâ
////°Ë»ÊºóÎÊÌâ
//
//// Queen.cpp : ¶šÒå¿ØÖÆÌšÓŠÓÃ³ÌÐòµÄÈë¿Úµã¡£
////
//
//#include "stdio.h"
//
//class Queen {    //ÀàQueenŒÇÂŒœâ¿ÕŒäÖÐµÄœÚµãÐÅÏ¢
//    friend int nQueen(int);
//private:
//    bool Place(int k);    //ŒôÖŠº¯Êý
//    void Backtrack(int t);    //µÝ¹éº¯Êý
//    int n;    //»ÊºóžöÊý
//    int *x;    //µ±Ç°œâ
//    long sum;    //µ±Ç°¿ÉÐÐµÄ·œ°žÊý
//};
//
//int abs(int ab)//ÇóŸø¶ÔÖµ
//{
//    return ab>0 ? ab : -ab;
//}
//
//bool Queen::Place(int k)    //ŒôÖŠº¯Êý
//{
//    printf("%s_%d\n", __FUNCTION__, k);
//
//    for (int j = 1; j<k; j++)
//    {
//        //ŒôÖŠÌõŒþ£ºÈç¹ûÔÚÍ¬Ò»ÐÐ£¬Í¬Ò»ÁÐ»òÕßÍ¬Ð±ÏßÉÏ
//        if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
//            return false;
//    }
//    return true;
//}
//
//void Queen::Backtrack(int t)    //µÝ¹é»ØËÝºËÐÄ
//{
//    printf("%s_%d\n", __FUNCTION__, t);
//
//    if (t > n)
//    {
//        printf("Sum_%s_%d\n", __FUNCTION__, sum);
//        sum++;    //Èç¹û±éÀúµœÒ¶×Ó£¬ËµÃ÷Çó³öÁËÒ»žöœâ
//    }
//    else
//    {
//        for (int i = 1; i <= n; i++)
//        {
//            x[t] = i;
//            if (Place(t))
//            {
//                Backtrack(t + 1); //º¯ÊýPlaceÎªŒôÖŠº¯Êý
//            }
//        }
//    }
//}
//
//
//int nQueen(int n)//³õÊŒ»¯ÊýŸÝ
//{
//    Queen X;
//    X.n = n;
//    X.sum = 0;
//    int *p = new int[n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        p[i] = 0;
//    }
//    X.x = p;
//    X.Backtrack(1);
//    delete[]p;
//    return X.sum;
//}
//
//
//int main()
//{
//    printf("%d", nQueen(4));//Ž«Èë²ÎÊý8£¬ŒŽ°Ë»ÊºóÎÊÌâ
//    return 0;
//}


//#include "stdafx.h"
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
    return OK;
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
    for (int i = 0; i < L.length; i++)
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

    for (int i = 0; i < lengthLa; i++)
    {
        InsertList_sq(Lc, 1, La.elem[i]);
    }

    for (int i = 0; i < lengthLb; i++)
    {
        if (!isExistAlready(La, Lb.elem[i]))
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

    while (pa <= pa_last && pb <= pb_last)
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

    while (pa <= pa_last)
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
////    for (int i = 2; i < 10; i++)
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
    //    LNode *Pre = L;
    //    LNode *Cur = L->next;
    //    int nCurPosi = 0;
    //    int nPrePosi = 0;
    //    while (Cur)
    //    {
    //        if (Cur->data == eCur)
    //        {
    //            *ePre = Pre->data;
    //            return OK;
    //        }
    //        Cur = Cur->next;
    //        Pre = Pre->next;
    //    }
    //    *ePre = -99999;
    //    return INFEASIABLE;


    LNode *p = L->next; //point first node
    LNode *q;
    while (p->next)
    {
        q = p->next;
        if (q->data == eCur)
        {
            *ePre = p->data;
            return OK;
        }
        else
        {
            *p = *q;
        }
    }
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
        return NULL;
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
Status GetElem_L(LinkList L, int i, ElemType *e)
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
    LNode *pc = Lc;

    pc->next = pa;

    //    Lc = pc = pa;
    //
    //    while (pa)
    //    {
    //        ListInsert_L(Lc, 1, pa->data);
    //        pa = pa->next;
    //    }
    //
    //    while (pb)
    //    {
    //        ListInsert_L(Lc, 1, pb->data);
    //        pb = pb->next;
    //    }

    //Other
    //    while (pa  && pb) {
    //        //
    //        if (pa->data <=pb->data) {
    //            pc->next = pa;
    //            pc = pa;
    //            pa = pa->next;
    //        }
    //        else
    //        {
    //            pc->next = pb;
    //            pc = pb;
    //            pb = pb->next;
    //        }
    //    }
    //
    //pc->next = pa?pa:pb;
    while (pa  && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;

        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;

    //    free(Lb);
}
///

///
/// Test for LinkList
////list0
//LinkList list;
//LNode L;
//list = IniList_L(&L);
//
//for (int i = 2; i < 8; i++)
//{
//    ListInsert_L(list, 1, i);
//}
//
////TravevseList_L(list);

/////////////////list1
///LinkList list1;
//LNode L;
//list1 = IniList_L(&L);
//
//for (int i = 10; i < 15; i++)
//{
//    ListInsert_L(list1, 1, i);
//}
//
////TravevseList_L(list1);
//
/////Length
////printf("%d_%d\n", GetLength_L(list), GetLength_L(list1));
//
//////MergeList
//LinkList listMerge;
//listMerge = IniList_L(&L);
//
//MergeList_L(list, list1, listMerge);
//
//TravevseList_L(listMerge);
//
//ElemType *ePre = (ElemType *)malloc(sizeof(ElemType));
////GetPreElem_L(list, 5, ePre);
////printf("Pre elem is %d\n", *ePre);
//// End Test for LinkList
///////End Link List//////////

///Begin Static Link list
///

#define MAXSIZE 100

typedef struct {
    ElemType data;
    int cur;
}compoent, SLinkList[MAXSIZE];


///Common functions
//Init_Space_SL
//LocateElement_SL
//Malloc_SL
//Free_SL
//difference_SL
/////////////////

////Init_space_SL
void Init_space_SL(SLinkList space)
{
    int i = 0;
    for ( i = 0; i < MAXSIZE; i++)
    {
        (space[i].cur) = i+1;
    }
    space[MAXSIZE - 1].cur = 0;
}
///

///Malloc_SL
int Malloc_SL(SLinkList *space)
{
    //
    int i = space[0]->cur;
    if (space[0]->cur)
    {
        space[0]->cur = space[i]->cur;
    }

    return i;
}
///

///LocateElement_SL

////

///
///End Static Link list


///Double Link list
//
//#include <stdlib.h>
//#include <malloc.h>
//#include <stdio.h>
//
//struct DULNode
//{
//    int data;
//    struct DULNode * prior;
//    struct DULNode * next;
//};
//
//typedef struct DULNode * linklist;
//
//void InitList(linklist *L) //改变头指针
//{
//    *L = (linklist)malloc(sizeof(struct DULNode));
//    if (*L == NULL)
//        exit(0);
//    (*L)->data = 999; //head_data
//    (*L)->next = *L;
//    (*L)->prior = *L;
//}
//
//int GetElem(linklist L, int i, int *e)
//{
//    linklist p = L;
//    int j = 0;
//    if (i<1 || i>3)
//        exit(0);
//
//    while (j<i)   //找到第i个结点
//    {
//        ++j;
//        p = p->next;
//    }
//    *e = p->data;
//}
//
//int LocateElem(linklist L, int e)
//{
//    linklist p = L->next;
//    int j = 0;
//
//    while (p != L)
//    {
//        ++j;
//        if (p->data == e)
//            return j;
//    }
//    return -1;
//}
//
//void TravelListBack(linklist L)
//{
//    linklist p = L->prior;
//    while (p != L)
//    {
//        printf("%d ", p->data);
//        p = p->prior;
//    }
//    printf("\n");
//}
//
//
//int ListInsert(linklist L, int i, int e)
//{
//    linklist p = L; //p指向头结点
//    linklist q, s;
//    int j = 0;
//    if (i<1 || i>3 + 1)
//        exit(0);
//
//    while (j < i - 1) //找到第i-1个结点
//    {
//        ++j;
//        p = p->next;
//    }
//    q = p->next;  //q指向第i个结点
//
//    s = (linklist)malloc(sizeof(struct DULNode));
//    s->data = e;
//    
//    s->next = q;  //先改变向右的指针
//    p->next = s;
//    s->prior = p;  //改变向左的指针
//    q->prior = s;
//    return 0;
//}
//
//int main()
//{
//    //
//    linklist list;
//    InitList(&list);
//    ListInsert(list, 1, 2);
//    ListInsert(list, 1, 31);
//    
//    TravelListBack(list);
//    
//    return 0;
//}
///End Double Link list


int main()
{
    SLinkList list;
    Init_space_SL(list);

    typedef int Name[10];
    Name name;

    for (size_t i = 0; i < 10; i++)
    {
        name[i] = 100;
    }


    for (size_t i = 0; i < 10; i++)
    {
        printf("%d_\n", name[i]);
    }


    return 0;
}
