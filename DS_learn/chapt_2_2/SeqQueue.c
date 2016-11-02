//
//  SeqQueue.c
//  chapt_2_2
//
//  Created by apple on 16/11/2.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "SeqQueue.h"


void showTest()
{
    printf("Test Info \n");
}

SeqQueue *SeqQueueInit()
{
    SeqQueue *q;
    if ((q = (SeqQueue *)malloc(sizeof(SeqQueue)))) {
        q->head = 0;
        q->tail = 0;
        return q;
    }
    else
    {
        return NULL;
    }

}

void SeqQueueFree(SeqQueue *q)
{
    if (q != NULL) {
        free(q);
    }
}


int SeqQueueIn(SeqQueue *q, DATA data)
{
    if (q->tail == QUEUEMAX) {
        printf("Queue is FULL\n");
        return 0;
    }else
    {
        q->data[q->tail++] = data;   //Push in
        return 1;
    }
}

int SeqQueueLength(SeqQueue *q)
{
    return (q->tail - q->head);
}

DATA *SeqQueueOut(SeqQueue *q)
{
    if (q->head == q->tail) {
        printf("Queue is Empty\n");
        return NULL;
    }
    else{
        return &(q->data[q->head++]);  // Pop out
    }
}

DATA *SeqQueuePeak(SeqQueue *q)
{
    if (q->head == q->tail) {
        printf("Queue is Empty\n");
        return NULL;
    }
    else{
        return &(q->data[q->head]);  // Pop out first, peak
    }
}
