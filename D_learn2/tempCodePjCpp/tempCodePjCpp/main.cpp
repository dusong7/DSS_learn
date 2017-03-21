#include <iostream>

using namespace std;

#define OVERFLOW -2
#define INFEASIBLE -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct {
    char name[20];
    int age;
}ElemType;

typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;

void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &));
int ListLength(DuLinkList L);
DuLinkList GetElemP_Dul(DuLinkList L,int i);//
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e);//
Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e);//
Status DestroyList_Dul(DuLinkList &L);//
Status Append(DuLinkList &La,DuLinkList &Lb);//

//Other funciton
void input(ElemType &e);//input

void input(ElemType &e){
    printf("Input name:");
    scanf("%s",e.name);
    printf("Input age:");
    scanf("%d",&e.age);
}


void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &)){
    //
    L=NULL;
    if(n<1)return;//

    L=(DuLinkList)malloc(sizeof(DuLNode));
    L->prior=L;
    L->next=L;
    InputData(L->data);//
    printf("Initied\n");
   /* DuLinkList p;
    for(int i=n-1;i>0;--i){
        p=(DuLinkList)malloc(sizeof(DuLNode));
        InputData(p->data);
        L->prior->next=p;
        p->prior=L->prior;
        p->next=L;
        L=p;
    }//for*/ //Err
}//CreatList

int ListLength(DuLinkList L){

    int i=1;
    if(L==NULL)return 0;
    DuLinkList p=L;
    printf("L_%d_\n", L->data.age);

    while(p->next!=L && ++i )
    {
        p=p->next;
    }
    return i;
}//ListLength

DuLinkList GetElemP_Dul(DuLinkList L,int i){
    if(L==NULL)return NULL;
    DuLinkList p=L;
    int j=0;
    while(++j!=i){
        if(j!=1)if(p->next==L)break;
        p=p->next;
    }//while
    if(j!=i)return NULL;
    else return p;
}//GetElemP_Dul

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){

    DuLinkList p,s;
    if(!(p=GetElemP_Dul(L,i)))return ERROR;//
    if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))return ERROR;//
    s->data=e;
    s->prior=p->prior;
    //*
    //s->next=p->next;
    //*repalce
    p->prior->next = s;
    s->next=p;
    //end replace

    p->prior=s;

//_U_u2 s1_S_s2 p1_P_
//s->prior = p->prior
//p->prior->next = s;
//s->next = p;
//p->prior = s;
    
    return OK;
}//ListInsert_DuL

Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e){
    //
    DuLinkList p;
    if(!(p=GetElemP_Dul(L,i)))return ERROR;//
    e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    return OK;
    
    //U_u2 p1_P_p2 n1_N 
    //p->prior->next = p->next
    //p->next->prior=p->prior
}//ListDelete_Dul

Status DestroyList_Dul(DuLinkList &L){
    //
    if(L==NULL)return OK;
    DuLinkList p=L,p2=L;
    int i=0;
    while(p!=L || ++i==1){
        p=p->next;
        free(p2);
        p2=p;
    }
    L=NULL;
    return OK;
}//ClearList_Dul

Status Append(DuLinkList &La,DuLinkList &Lb){
    //
    if(!La || !Lb )return ERROR;
    DuLinkList p=Lb->prior;;
    Lb->prior->next=La;
    Lb->prior=La->prior;
    La->prior->next=Lb;
    La->prior=p;
    return OK;
}//Append


//
//#include <malloc.h>
//
//typedef int ElemType;
//typedef int State;
//
//typedef struct LNode
//{
//    ElemType data;
//    struct LNode *next;
//}*Link, *Position;
//
//typedef struct {
//    Link head, tail;
//    int len;
//}LinkList;
//
//Position MakeNode_LL(ElemType e)
//{
//    //
//    Link p = NULL;
//
//    p = (Link)malloc(sizeof(LNode));
//    if (!p)return ERROR;
//    else
//    {
//        p->data = e;
//        p->next = NULL;
//    }
//    return p;
//}
//
//void FreeNode_LL(Link &p)
//{
//    //
//    free(p);
//}
//
//State InitList_LL(LinkList &L)
//{
//    //
//    ElemType ep;
//    ep = 100;
//    L.head = MakeNode_LL(ep);
//    L.head->next = NULL;
//    L.tail = L.head;
//    L.len = 0;
//    return OK;
//}
//
//State ListInsert_LL(Link &L, int i, ElemType e)
//{
//    //
//    return OK;
//}
//
/////////////
//
//int main()
//{
//    //
//    LinkList lp;
//    InitList_LL(lp);
//    
//    return 0;
//}

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
////  ep.name = "Test";
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

typedef int EleType;

typedef struct LNode
{
    EleType data;
    struct LNode *next;
}*Link, *Position;

typedef struct {
    Link head, tail;
    int len;
}LinkList;

Status MakeNode(Link &p, EleType e)
{
    p->data = e;
    p->next = NULL;

    return OK;
}

Status InitList_LL(LinkList &L)
{
    //
    EleType e = 101;
    Link h = (Link)malloc(sizeof(Link));
    MakeNode(h, e);

    L.head = h;
    L.head->next = NULL;
    L.tail = h;
    L.len = 0;

    return OK;
}

Status ListInsert_LL(LinkList &L, int i, EleType e)
{
    //
    return OK;
}

///Node linklist
///End NodeLinkList

int main()
{
    //
    return 0;
}
