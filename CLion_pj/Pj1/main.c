#include <stdio.h>


#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int State;

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

//State InitList_DuL(DuLinkList list)
//{
//
//    return 1;
//}


int main() {
    printf("Hello, World!\n");
    return 0;
}