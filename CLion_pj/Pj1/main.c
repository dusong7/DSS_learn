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

//#define CPPTYPEFILE

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
    int i = 0;
    for (i = 0; i < L.length; i++)
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
    int i = 0;
    for (i = 0; i < lengthLa; i++)
    {
        InsertList_sq(Lc, 1, La.elem[i]);
    }

    for (i = 0; i < lengthLb; i++)
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
//

//implement LocateElem_SL
int LocateElem_SL(SLinkList S, ElemType e, int(*compare)(ElemType, ElemType)) {
    //find first value is e, yes return location,else return 0

    int i = S[0].cur;
    while (i && !compare(S[i].data, e))i = S[i].cur;
    return i;
}//LocateElem_SL

//implement InitSpace_SL
void InitSpace_SL(SLinkList *space) {
    //make array ,spare list, space[0],cur is head pointer
    //space = (SLinkList*)malloc(sizeof(SLinkList));

    int i;
    for (i = 0; i<MAXSIZE - 1; ++i)
        (*space)[i].cur = i + 1;
    (*space)[MAXSIZE - 1].cur = 0;
}//InitSpace_SL

// implement Malloc_SL

int Malloc_SL(SLinkList *space) {
    //if spare list not null, return node subscrip else return 0

    int i = (*space)[0].cur;
    if ((*space)[0].cur)
        (*space)[0].cur = (*space)[i].cur;
    return i;
}//Malloc_SL

// implement Free_SL
void Free_SL(SLinkList *space, int i) {/**<  */
    //make subscribe is i 's space as spare space
    (*space)[i].cur = (*space)[0].cur;
    (*space)[0].cur = i;
}//Free_SL

//implement difference
void difference(SLinkList *space, int *S, int(*compare)(ElemType, ElemType)) {
    //A-B）U (B-A), space[0].cur is head pointer
    int m, n, i, j, r, p, k;
    ElemType b;
    InitSpace_SL(space);
    r = *S = Malloc_SL(space);
    printf("Input m and n of A and B number:");
    scanf("%d,%d", &m, &n);
    printf("\nA:\n");
    for (j = 1; j <= m; ++j) {//input set A
        i = Malloc_SL(space);//alloc node
							 //InputData(space[i].data);
        scanf("%d", &(*space)[i].data);
        (*space)[r].cur = i;//tail insert
        r = i;
    }//for
    (*space)[r].cur = 0;//set tail pointer empty
    
    printf("\nB:\n");
    for (j = 1; j <= n; ++j) {//input set B
        //InputData(b);//input elem b
        scanf("%d", &b);
        //compare avoid 244	
        p = *S;
        k = (*space)[*S].cur;//K point A first node
        while (k != (*space)[r].cur && !compare((*space)[k].data, b)) {//serach
            p = k;
            k = (*space)[k].cur;
        }//while
        if (k == (*space)[r].cur) {//if elem no exist, insert after r point, r position not change
            i = Malloc_SL(space);
            (*space)[i].data = b;
            (*space)[i].cur = (*space)[r].cur;
            (*space)[r].cur = i;
        }
        else {//if not exist , delete
            (*space)[p].cur = (*space)[k].cur;
            Free_SL(space, k);
            if (r == k)r = p;//delete ,modify tails
        }//else
    }//for
}//difference


//Test for Static Link list
//SLinkList space;
//int s;
//difference(&space, &s, com);
//printf("\nThe result is:\n\n");
//while ((s = space[s].cur) != 0) {
//	printf("=> %d\n", space[s].data);
//}
////input 1235, 244 ERR
////set array , compare, if !isExit contine 
///End Static Link list

//Double link list

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

//initlist
Status InitList_DuL(DuLinkList *list)
{
    //
    *list = (DuLinkList)malloc(sizeof(DuLNode));

    (*list)->data = 0;
    (*list)->prior = NULL;
    (*list)->next = NULL;

    return OK;
}

int GetLength_DuL(DuLinkList L)
{
    int i = 0;
    DuLinkList p = L->next;

    while (p != L) {
        ++i;
        p = p->next;
    }
    return i; //return length;
}

DuLinkList GetElem_DuL(DuLinkList L, int i)
{
    if (L == NULL) {
        return NULL;
    }
    DuLinkList p = L;
    int j = 0;
    while (++j != i) {
        if (j!=1) {
            if (p->next == L) {
                break;
            }
        }
    }

    if (j != i) {
        return NULL;
    }
    else{
        return p;
    }
}

Status ListInsert_DuL(DuLinkList L, int i, ElemType e)
{
    //
    DuLinkList p = L;
    DuLinkList  s;
//    int j = 0;
    if (i<1 || i>GetLength_DuL(L) + 1) {
        exit(0);
    }
    p = GetElem_DuL(L, i);
    s = (DuLinkList)malloc(sizeof(DuLNode));

    //core exchange
    //
    s->data = e;
    s->prior = p->prior; 
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    //


    return OK;
}


//void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &));
//int ListLength(DuLinkList L);
//DuLinkList GetElemP_Dul(DuLinkList L,int i);//
//Status ListInsert_DuL(DuLinkList &L,int i,ElemType e);//
//Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e);//
//Status DestroyList_Dul(DuLinkList &L);//
//Status Append(DuLinkList &La,DuLinkList &Lb);//

//Other funciton
//void input(ElemType &e);//input
//
//void input(ElemType &e){
//    printf("Input name:");
//    scanf("%s",e.name);
//    printf("Input age:");
//    scanf("%d",&e.age);
//}
//
//
//void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &)){
//    //
//    L=NULL;
//    if(n<1)return;//
//
//    L=(DuLinkList)malloc(sizeof(DuLNode));
//    L->prior=L;
//    L->next=L;
//    InputData(L->data);//
//    printf("Initied\n");
//    /* DuLinkList p;
//     for(int i=n-1;i>0;--i){
//     p=(DuLinkList)malloc(sizeof(DuLNode));
//     InputData(p->data);
//     L->prior->next=p;
//     p->prior=L->prior;
//     p->next=L;
//     L=p;
//     }//for*/ //Err
//}//CreatList
//
//int ListLength(DuLinkList L){
//
//    int i=1;
//    if(L==NULL)return 0;
//    DuLinkList p=L;
//    printf("L_%d_\n", L->data.age);
//
//    while(p->next!=L && ++i )
//    {
//        p=p->next;
//    }
//    return i;
//}//ListLength
//
//DuLinkList GetElemP_Dul(DuLinkList L,int i){
//    if(L==NULL)return NULL;
//    DuLinkList p=L;
//    int j=0;
//    while(++j!=i){
//        if(j!=1)if(p->next==L)break;
//        p=p->next;
//    }//while
//    if(j!=i)return NULL;
//    else return p;
//}//GetElemP_Dul
//
//Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){
//
//    DuLinkList p,s;
//    if(!(p=GetElemP_Dul(L,i)))return ERROR;//
//    if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))return ERROR;//
//    s->data=e;
//    s->prior=p->prior;
//    //*
//    //s->next=p->next;
//    //*repalce
//    p->prior->next = s;
//    s->next=p;
//    //end replace
//
//    p->prior=s;
//
//    return OK;
//}//ListInsert_DuL
//
//Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e){
//    //
//    DuLinkList p;
//    if(!(p=GetElemP_Dul(L,i)))return ERROR;//
//    e=p->data;
//    p->prior->next=p->next;
//    p->next->prior=p->prior;
//    free(p);
//    return OK;
//}//ListDelete_Dul
//
//Status DestroyList_Dul(DuLinkList &L){
//    //
//    if(L==NULL)return OK;
//    DuLinkList p=L,p2=L;
//    int i=0;
//    while(p!=L || ++i==1){
//        p=p->next;
//        free(p2);
//        p2=p;
//    }
//    L=NULL;
//    return OK;
//}//ClearList_Dul
//
//Status Append(DuLinkList &La,DuLinkList &Lb){
//    //
//    if(!La || !Lb )return ERROR;
//    DuLinkList p=Lb->prior;;
//    Lb->prior->next=La;
//    Lb->prior=La->prior;
//    La->prior->next=Lb;
//    La->prior=p;
//    return OK;
//}//Append
//
//test for double link list
//

//int main(void){
//    DuLinkList L,p;
//    int i=0,n;
//    printf("Input list number:");
//    scanf("%d",&n);
//    CreatList_DuL(L,n,input);
//    p=L;
//
//    ElemType ep;
//    ep.age = 100;
//    //    ep.name = "Test";
//    memcpy(ep.name, "Test", 5);
//    ListInsert_DuL(L,1,ep);
//    ep.age = 101;
//    ListInsert_DuL(L,1,ep);
//    ep.age = 102;
//    ListInsert_DuL(L,1,ep);
//
//    //ListDelete_Dul(L, 2, ep);
//    printf("Length is %d\n", ListLength(L));
//
//    printf("\nThe result is\n");
//    while(p!=L || i++==0){
//        printf("%s => %d\n",p->data.name,p->data.age);
//        p=p->next;
//    }//while
//    printf("\nGetElem:\n");
//    for(i=1;i<=ListLength(L);i++){
//        p=GetElemP_Dul(L,i);
//        printf("%dth name_%s => age_%d\n",i,p->data.name,p->data.age);
//    }
//
//    printf("\nResult End!\n");
//    system("pause");
//    return 0;
//}


//DuLinkList list;
//InitList_DuL(&list);
//
//printf("%d\n", list->data);
//End Double link list

int main()
{
    //

    return 0;
}
