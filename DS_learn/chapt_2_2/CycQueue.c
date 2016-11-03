//
//  CycQueue.c
//  chapt_2_2
//
//  Created by apple on 16/11/3.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "CycQueue.h"

CycQueue *CycQueueInit()
{
	CycQueue *q;
	q = (CycQueue *)malloc(sizeof(CycQueue));   // you can adjust is OK or NOT

	q->head = 0;
	q->tail = 0;

    return q;
}

void CycQueueFree()
{
	//
}

int CycQueueIn(CycQueue *q, DATA data)
{
	q->tail = (q->tail + 1) % QUEUEMAX;
	q->data[q->tail] = data;
    return 1;
}
DATA *CycQueueOut(CycQueue *q)
{
	q->head = (q->head + 1) % QUEUEMAX;
	return &(q->data[q->head]);
	return NULL;
}
