#include <iostream>

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

///
/// \param p

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

//
///

Status InitList_LL(LinkList &L)
{
    //
    Link head = (Link)malloc(sizeof(LNode));


    ElemType ep;
    ep.expn = 1.0;
    ep.coef = 1;
//    MakeNode(head, ep);
    L.head = MakeNode_LL(ep);
    L.head = head;

    L.head->next = NULL;
    L.tail = L.head;
    L.len = 0;
    return OK;
}
///
Position GetHead_LL(LinkList L)
{
    //Position p = (Position)malloc(sizeof(Position));

    return L.head;
}

/// \param P
/// \param m

void CreadPoly(polynomail &P, int m)
{
    //
    InitList_LL(P);

}

void DestroyPoly(polynomail &P)
{
//
}

void PrintPoly(polynomail &P)
{
//
}

void PolyLength(polynomail &P)
{
//
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
    polynomail pl;
    CreadPoly(pl, 1);
    Link head = GetHead_LL(pl);

    return 0;
}
