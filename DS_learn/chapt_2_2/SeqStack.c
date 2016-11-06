//
//  SeqStack.c
//  chapt_2_2
//
//  Created by apple on 16/11/3.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "SeqStack.h"

#include <stdlib.h>
SeqStack *SeqStackInit()
{
    //
    SeqStack *q;

    if ((q = (SeqStack *)malloc(sizeof(SeqStack))))
    {
        //
        q->top = 0;
        return q;
    }
    else
    {
        return NULL;
    }

    return NULL;
}

int SeqStackPush(SeqStack *q, DATA data)
{
    /////Stack save data from 1, isnot 0, array is 0.
    if ((q->top +1) ==  SIZE)
    {
        printf("Stack is FULL \n");
        return 0;
    }
    q->data[++q->top] = data;
    return 1;
}


DATA SeqStackPop(SeqStack *q)
{
    if (q->top == 0)
    {
        printf("Stack is Empty\n");
    }
    return (q->data[q->top--]);
}

DATA SeqStackPeek(SeqStack *q)
{
    return q->data[q->top];
}

void SeqStackFree(SeqStack *q)
{
    if (q != NULL) {
        free(q);
    }
}
