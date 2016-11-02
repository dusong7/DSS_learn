//
//  SeqQueue.c
//  chapt_2_2
//
//  Created by apple on 16/11/2.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "SeqQueue.h"
#include <stdlib.h>

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
