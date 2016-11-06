//
//  SeqStack.h
//  chapt_2_2
//
//  Created by apple on 16/11/3.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef SeqStack_h
#define SeqStack_h

#include <stdio.h>

#define SIZE 10

typedef int DATA;
//typedef struct
//{
//    int number;
//    char name[10];
//}DATA;

typedef struct stack
{
    DATA data[SIZE + 1];
    int top;
}SeqStack;

SeqStack *SeqStackInit();
int SeqStackPush(SeqStack *q, DATA data);
DATA SeqStackPop(SeqStack *q);
DATA SeqStackPeek(SeqStack *q);
void SeqStackFree(SeqStack *q);


#endif /* SeqStack_h */
