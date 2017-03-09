//
// Created by admini on 17-3-9.
//
#include <stdio.h>
#include <iostream>
using namespace std;

#ifndef TESTDSS_TESHOW_H
#define TESTDSS_TESHOW_H

#define INFEASIBLE -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int Status;


typedef struct {
    float coef;
    int expn;
}term , ElemType;

//typedef int ElemType;
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

typedef LinkList polynomail;

class teShow {
public:
    void show();
    Position MakeNode_LL(ElemType e);
    Status InitList_LL(LinkList &L);
    void creadPoly(polynomail &P, int m);
    void DestroyPoly(polynomail &P);
    void PrintPoly(polynomail &P);
    void PolyLength(polynomail &P);
    Status MakeNode(Link &p, ElemType e);


private:
    int version;
};


#endif //TESTDSS_TESHOW_H
