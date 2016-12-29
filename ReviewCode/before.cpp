
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

typedef struct{
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

    if (L->length >= L->listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L->elem,sizeof(ElemType) * L->listsize+LINSTINCREMENT); //realloc ERROR
        L->elem = newbase;
        L->listsize += LINSTINCREMENT;
    }
    //simple assign

    int j = 0;
    for (j = L->length; j >= i; j--) {
            //
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i]=e;
    L->length++;

    return OK;
}
/////////


////////Implement ListTraverse
void ListTraverse(Sqlist *L)
{
    int i;
    if (L->length !=0)
    {
        for (i = 0; i < L->length; ++i)
        {
            printf("%d_\n",L->elem[i]);
        }
    }
}
/////////////////

///////Implement isListEmpty
bool isListEmpty(Sqlist *L)
{
    if (L->length==0)
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
    if (L!=NULL)
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
}
/// \return

int main()
{
    Sqlist myList;

    Init_list(&myList);
//    int i = 0;
//    for (i=0; i<LIST_INIT_SIZE;i++)
//    {
//        printf("%d_\n", myList.elem[i]);
//    }
    int i = 0;
    for (i = 0; i < 113; ++i) {
        InsertList(&myList, i,i+10);
    }
//    InsertList(&myList, 0,10);
//    InsertList(&myList, 1,30);
//    InsertList(&myList, 2,40);
    ListTraverse(&myList);
//
//    for (i=0; i<LIST_INIT_SIZE;i++)
//    {
//        printf("%d_\n", myList.elem[i]);
//    }
    return 0;
}
