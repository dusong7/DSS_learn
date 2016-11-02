//
//  SeqQueue.h
//  chapt_2_2
//
//  Created by apple on 16/11/2.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef SeqQueue_h
#define SeqQueue_h

#include <stdio.h>



#define QUEUEMAX 15

typedef struct{
    int number;
    char name[10];
}DATA;

typedef struct{
    DATA data[QUEUEMAX];
    int head;
    int tail;
}SeqQueue;


SeqQueue *SeqQueueInit();
void SeqQueueFree(SeqQueue *q);

void showTest();

#endif /* SeqQueue_h */