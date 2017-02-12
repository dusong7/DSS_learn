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

void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &));//创建链表 向链表头之前插入
int ListLength(DuLinkList L);
//返回数据长度,由于判断为下一个地址的比较，故缺少一个值，因此从1开始计数
//L必须是经过初始化的数据
DuLinkList GetElemP_Dul(DuLinkList L,int i);//返回第i个结点
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e);//在第i个位置之前插入元素e
Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e);//删除L链表中头结点的第i 个元素
Status DestroyList_Dul(DuLinkList &L);//销毁链表
Status Append(DuLinkList &La,DuLinkList &Lb);//将链表Lb链接到La之后

//其他操作函数
void input(ElemType &e);//输入数据

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
    DuLinkList p;
    for(int i=n-1;i>0;--i){
        p=(DuLinkList)malloc(sizeof(DuLNode));
        InputData(p->data);
        L->prior->next=p;
        p->prior=L->prior;
        p->next=L;
        L=p;
    }//for
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

int main(void){
    DuLinkList L,p;
    int i=0,n;
    printf("Input list number:");
    scanf("%d",&n);
    CreatList_DuL(L,n,input);
    p=L;

    ElemType ep;
    ep.age = 100;
//    ep.name = "Test";
    memcpy(ep.name, "Test", 5);
   // ListInsert_DuL(L,2,ep);
    //ListDelete_Dul(L, 2, ep);
    printf("Length is %d\n", ListLength(L));

    printf("\nThe result is\n");
//    while(p!=L || i++==0){
//        printf("%s => %d\n",p->data.name,p->data.age);
//        p=p->next;
//    }//while
//    printf("\nGetElem:\n");
//    for(i=1;i<=n;i++){
//        p=GetElemP_Dul(L,i);
//        printf("%dth name_%s => age_%d\n",i,p->data.name,p->data.age);
//    }
    
    printf("\nResult End!\n");
    system("pause");
    return 0;
}
