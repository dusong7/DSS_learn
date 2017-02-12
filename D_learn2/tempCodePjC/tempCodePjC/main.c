//
//  main.c
//  tempCodePjC
//
//  Created by apple on 17/2/5.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>

typedef int ElemType;
typedef int States;

#define OK 1
#define ERROR -1

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;


States InitList_DuL(DuLinkList *L)
{
    (*L)->data = 0;
    (*L)->next = NULL;
    (*L)->prior = NULL;s

    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    DuLinkList list;
    InitList_DuL(&list);

    printf("%d", list->data);
    return 0;
}
