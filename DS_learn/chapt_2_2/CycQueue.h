//
//  CycQueue.h
//  chapt_2_2
//
//  Created by apple on 16/11/3.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef CycQueue_h
#define CycQueue_h

#include <stdio.h>
#include "SeqQueue.h"

typedef struct{
    DATA data[QUEUEMAX];
    int head;
    int tail;
}CycQueue;

///// Common Fuction are as follow
CycQueue *CycQueueInit();
void CycQueueFree();
int CycQueueIn(CycQueue *q, DATA data);
DATA *CycQueueOut(CycQueue *q);

#endif /* CycQueue_h */
