typedef char ElemType
 
//结点类型
typedef struct LNode
{
    char data;
    struct LNode *next;
}*Link,*Position;
 
//链表类型
typedef struct
{
    Link head,tail;
    int len;
}LinkList;
 
 
/*======================================================*/
/*=======一些在其他函数定义中会调用的函数===============*/
/*======================================================*/
 
/*---compare---比较两个元素的大小关系*/
int Compare(char a,char b)
{ 
    return a-b;
}
 
/*---visit---*/
int Visit(Link p)
{
    if(...)
        return 1;
    else
        return 0;
     
}
 
/*---length---求链的长度*/
int Length(Link s)
{
    int i=0;
    Link p=NULL;
    p=s;
    while(p->next!=NULL)
    {
        p=p->next;
        i++;
    }
    return i;
}
 
/*---print---在屏幕上输出链表的所有元素*/
void Print(LinkList L)
{    
    Link p=NULL;
    p=L.head;
    if(!p->next)
    {
        printf("\nThe LinkList is empty.\n\n");
        return ;
    }
    printf("The List:");
    while(p)
    {
        printf("%c-",p->data);
        p=p->next;
    }
}
 
/*======================================================*/
/*==========对带头结点的单链线性表进行操作的函数的定义==*/
/*======================================================*/
 
/*---分配由p指向的结点并赋值为e---*/
Position MakeNode(ElemType e)
{      
    Link p=NULL;
    p=(Link)malloc(sizeof(struct LNode));
    if(p)
    {
        p->data=e;
        p->next=NULL;
    }
    else return;
    return p;
}
 
/*---释放p所指向的结点-*/
void FreeNode(Link p)
{         
    free(p);
}
 
 
/*---构造一个由L指向的空的线性表-*/
void InitList(LinkList *L)
{     
    L->head=MakeNode('L');//生成头结点
    L->head->next=NULL;/*不是l->head=NULL*/
    L->tail=L->head;
    L->len=0;
}
 
/*----------销毁由L指向的线性表---------*/
void DestroyList(LinkList *L)
{  
    Link p;
    p=(*L).tail;
    while(p!=(*L).head)
    {
        p=PriorPos(*L,p);
        FreeNode(p->next);
    }
    FreeNode((*L).head);
}
 
/*将线性表L置为空表，并释放原链表的头结点*/
void ClearList(LinkList *L)
{    
    Link p;
    p=(*L).tail;
    while(p!=(*L).head)
    {
        p=PriorPos(*L,p);
        FreeNode(p->next);
    }
    FreeNode((*L).head);
}
 
/*---将s指向的结点插入线性链表的第一个结点之前-*/
void InsFirst(LinkList *L,Link s)
{   
    s->next=L->head->next;
    if(!L->head->next)
        L->tail=s;       /*当向一个空的线性表执行该操作时*/
    L->head->next=s;
    L->len++;
}
 
/*---删除表中第一个结点并以q返回-*/
void DelFirst(LinkList *L,Link q)
{   
    if(!L->head->next)
    {
        printf("\nThe LinkList is empty,can not delete..\n");
        return 0;
    }
    q=L->head->next;
    L->head->next=L->head->next->next;
}
 
/*---将指针s所的一串结点链接在线性表L的最后一个结点-*/
void Append(LinkList *L,Link s)
{ 
    Link q;
    q=L->head;
    if(!L->tail)
    {/*考虑到链表为空的情况*/
        L->head->next=s;
        while(q->next)
            q=q->next;/*尾结点的处理*/
        L->tail=q;
    }
    L->tail->next=q=s;
    while(q->next)
        q=q->next;/*不能忘了对尾结点的处理*/
    L->tail=q;
    L->len+=Length(s);
}
 
/*---删除线性表l中的尾结点-*/
void Remove(LinkList *L,Link q)
{  
    if(!L->tail)
    {
        printf("\nthe LinkList is empty,can not remonde..\n");
        return 0;
    }
    q=L->tail;                     
    L->tail=PriorPos(*L,q);
    L->tail->next=NULL;
}
 
/*---将s所指向结点插入在p所指结点之前-*/
void InsBefore(LinkList *L,Link p,Link s)
{  
    Link q;
    q=PriorPos(*L,p);
    s->next=p;
    q->next=s;
}
 
/*---将s所指向结点插入在p所指结点之后-*/
void InsAfter(LinkList *L,Link p,Link s)
{   
    s->next=p->next;
    p->next=s;
}
 
/*---用e更新p所指向的当前结点-*/
void SetCurElem(Link p,ElemType e)
{        
    p->data=e;
}
 
/*---返回p所指结点中元素的值-*/
ElemType GetCurElem(Link p)
{       
    return p->data;
}
 
 
int Listempty(LinkList L)
{         /*---若线性表为空表则返回1，否则返回0-*/
    if(L.head==L.tail)
        return 1;
    return 0;
}
 
 
int Listlength(LinkList L)
{      /*---返回线性表中元素个数-*/
    return L.len;
}
 
 
Position GetHead(LinkList L)
{     /*---返回线性表l中头结点的位置-*/
    return L.head;
}
 
 
Position GetLast(LinkList L)
{      /*-----返回线性表l中最后一个结点的位置-------*/
    return L.tail;
}
 
 
/*---返回p所指结点的直接前驱的位置-*/
Position PriorPos(LinkList L,Link p)
{   
    Link q;
    q=L.head;
    if(q->next==p)
        return 0;
    while(q->next!=p)  
        q=q->next;
    return q;
}
 
/*-----返回p所指结点的直接后继的位置-------*/
Position NextPos(Link p)
{    
    Link q;
    q=p->next;
    return q;
}
 
/*-----用p返回线性表l中第i个结点的位置，并返回ok-------*/
void LocatePos(LinkList L,int i,Link p)
{   
    p=L.head;
    if(i<=0||i>Listlength(L))  
        return 0;
    while(i)
    {
        p=p->next;
        i--;
    }
}
 
/*----返回表中第一个与e满足一定函数关系的结点次序位置----*/
int LocatElem(LinkList L,ElemType e)
{    
    int i=0;
    Link p;
    p=L.head->next;
    while(compare(p->data,e)&&p)
    {
        p=p->next;
        ++i;
    }
    if(!p)
    {/*考虑到查找不到指定元素的情况*/
        printf("\nthere's no '%c' in this LinkList.",e);
        return 0;
    }
    return i;
}
 
/*----用一个函数遍历表中所有结点-------*/
void ListTraverse(LinkList L)
{        
    Link p;
    p=L.head;
    while(!visit(p)) 
        p=p->next;  
}

Status MergeList_L(NLinkList &La, NLinkList &Lb, NLinkList &Lc,
                   int (*compare)(ElemType, ElemType))
{ 
    // 算法2.21
    // 已知单链线性表La和Lb的元素按值非递减排列。
    // 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
    NLink ha, hb;
    Position pa, pb, q;
    ElemType a, b;
    if (!InitList(Lc))
        return ERROR;  // 存储空间分配失败
    ha = GetHead(La);      // ha和hb分别指向La和Lb的头结点
    hb = GetHead(Lb);
    pa = NextPos(La, ha);  // pa和pb分别指向La和Lb中当前结点
    pb = NextPos(Lb, hb);
    while (pa && pb)
    {     // La和Lb均非空
        a = GetCurElem(pa);  // a和b为两表中当前比较元素
        b = GetCurElem(pb);
        if ((*compare)(a, b)<=0)
        {  // a≤b
            DelFirst(ha, q);  Append(Lc, q);  pa = NextPos(La, pa); 
        }
        else
        {   // a＞b
            DelFirst(hb, q);  Append(Lc, q);  pb = NextPos(Lb, pb); 
        }
    } // while
    if (pa)
        Append(Lc, pa);        // 链接La中剩余结点
    else
        Append(Lc, pb);        // 链接Lb中剩余结点
    FreeNode(ha);  
    FreeNode(hb);              // 释放La和Lb的头结点
    return OK;
} // MergeList_L
