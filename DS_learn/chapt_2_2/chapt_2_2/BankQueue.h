//
//  BankQueue.h
//  chapt_2_2
//
//  Created by apple on 16/11/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef BankQueue_h
#define BankQueue_h


typedef struct{
    int num;  // custom number
    long time; // enter queue time
}DATA_;

#include <stdio.h>
#include "CycQueue.h"
int num;

void add(CycQueue *q);  // new costom queue
void next(CycQueue *q); //notifition next custom
///


#endif /* BankQueue_h */
