////
////  main.cpp
////  tempCodePjCpp
////
////  Created by apple on 17/2/5.
////  Copyright © 2017年 apple. All rights reserved.
////
//
//#include <iostream>
//
//
//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAXSIZE 100
//
//typedef int ElemType;
//
//typedef struct {
//    ElemType data;
//    int cur;
//}compont, SLinkList[MAXSIZE];
//
//int comp(ElemType e1, ElemType e2)
//{
//    //return e1 == e2 ? 1 : 0;
//    if (e1 == e2)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//void InitSpace_SL(SLinkList &space)
//{
//    int i;
//    for (i = 0; i <MAXSIZE-1; i++)
//    {
//        space[i].cur = i+1;
//    }
//    space[MAXSIZE - 1].cur = 0;
//}
//
//void Free_SL(SLinkList &space, int i)
//{
//    space[i].cur = space[0].cur;
//    space[0].cur = i;
//}
//
//int Malloc_SL(SLinkList &space)
//{
//    int i = space[0].cur;
//    if (space[0].cur)
//    {
//        space[0].cur = space[i].cur;
//    }
//
//    return i;
//}
//
//void difference(SLinkList &space, int &S, int(*compare)(ElemType, ElemType))
//{
//    //
//    int m, n, i, j, r, p, k;
//    ElemType b;
//    InitSpace_SL(space);
//    r = S = Malloc_SL(space); //
//    printf("Please input m of A, n of B set size\n");
//    scanf("%d,%d", &m, &n);
//
//    for (j = 1; j <= m; j++)
//    {
//        i = Malloc_SL(space);
//        scanf("%d", &space[i].data);
//        space[r].cur = i;
//        r = i;
//    }
//
//    space[r].cur = 0;
//    printf("\nB:\n");
//    for (j = 1; j <= n; j++)
//    {
//        scanf("%d", &b);
//        //TODO:
//        p = S;
//        k = space[S].cur;
//
//        while (k != space[r].cur && !compare(space[k].data, b))
//        {
//            p = k;
//            k = space[k].cur;
//        }
//
//        if (k == space[r].cur)
//        {
//            //
//            i = Malloc_SL(space);
//            space[i].data = b;
//            space[i].cur = space[r].cur;
//            space[r].cur = i;
//        }
//        else
//        {
//            space[p].cur = space[k].cur;
//            Free_SL(space, k);
//            if (r == k)
//            {
//                r = p;
//            }
//        }
//    }
//    
//}
//
//int main()
//{
//    //
//    SLinkList space;
//    int s;
//    difference(space, s, comp);
//    printf("\nThe result is:\n\n");
//    while ((s = space[s].cur) != 0) {
//        printf("=> %d\n", space[s].data);
//    }
//    
//    printf("\nResult End!\n");
//    system("pause");
//    return 0;
//}

#include <iostream>
using namespace std;

typedef int ElemType;
typedef int States;

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

int InitList_DuL(DuLinkList &L, int n)
{
    L = NULL;
    if (n<1) {
        return 0;
    }

    L = (DuLinkList)malloc(sizeof(DuLNode));
    L->prior = L;
    L->next = L;
    L->data = 0;

    scanf("%d", &L->data);

    DuLinkList p;

    for (int i=n-1; i>0; --i) {
        p = (DuLinkList)malloc(sizeof(DuLNode));
        scanf("%d", &p->data);
        L->prior->next = p;
        p->prior = L->prior;
        p->next = L;
        L = p;
    }
    //for
    return 1;
}

int GetLength_DuL(DuLinkList L)
{
    int i = 0;

    if (L == NULL) {
        return 0;
    }

    DuLinkList p = L;
    while (p->next != L && ++i) {
        p = p->next;
    }

    return i;
}

int InsertList_DuL(DuLinkList &L, int i, ElemType e)
{

    return 1;
}


int main()
{

//    cout<<"HH";
    DuLinkList list;
    InitList_DuL(list, 3);
    cout<<list->data;
    cout<<GetLength_DuL(list);
    cout<<endl;
    return 0;
}
