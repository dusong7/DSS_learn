//
//  main.c
//  chapt_2_2
//
//  Created by apple on 16/11/2.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
//#include "SeqQueue.h"
//#include "CycQueue.h"
#include "SeqStack.h"
#include "bracketStack.h"


int randomTable[] = { 1717
    ,2154
    ,2845
    ,1305
    ,1204
    ,386
    ,1759
    ,462
    ,2777
    ,2334
    ,1139
    ,1246
    ,950
    ,326
    ,2628
    ,2361
    ,420
    ,2377
    ,2458 };

//    printf("Hello, World!\n");
//    showTest();
//
//    SeqQueue *queue;
//    queue =  SeqQueueInit();
//
//    for (int i = 0; i<10; i++)
//    {
//        DATA dt;
//        dt.number = 10*i+1;
//        char name[10];
//        sprintf(name, "name%d",i+10);
//        strcpy(dt.name, name);
//
//        SeqQueueIn(queue, dt);
//    }
//
//    printf("Length_%d\n", SeqQueueLength(queue));
//    SeqQueueOut(queue);  // out 1st
//    DATA *result = SeqQueueOut(queue); // out 2ed
//
//    printf("%s_%d\n", result->name, result->number);
//    printf("Length_%d\n", SeqQueueLength(queue));
/////////////////////////////////////////////////////////
//    CycQueue *cycqueue;
//    cycqueue = CycQueueInit();
//
//    for (int i = 0; i < 30; i++)
//    {
//	DATA dt;
//	dt.number = 101 + i;
//	strcpy(dt.name, "Insetr");
//	CycQueueIn(cycqueue, dt);    // i++ is dif ++i, Cyc is move to Next, and SeqQueue is current
//    }
/////////////////////test For stack//////////////////////////////////
//
//        SeqStack * stack;
//        stack = SeqStackInit();
//
//        for (size_t i = 0; i < 6; i++)
//        {
//            DATA dt;
//            strcpy(dt.name, "name");
//            dt.number = randomTable[i];
//            SeqStackPush(stack, dt);
//        }
//
//        for (size_t i = 0; i < 5; i++)
//        {
//            printf("%d_\n", SeqStackPop(stack).number);
//        }
////////////////////////test For stack///////////////////////////////

int main(int argc, const char * argv[]) {
    // insert code here...
//////////Test for bracket_Excption/////////////////////
    char exp[10] = "(2+4)*8=";

    printf("%s%d\n", exp,CalcExp(exp));

//////////Test for bracket_Excption/////////////////////
    return 0;
}
