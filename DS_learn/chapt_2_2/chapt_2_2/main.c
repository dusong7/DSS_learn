//
//  main.c
//  chapt_2_2
//
//  Created by apple on 16/11/2.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
#include "SeqQueue.h"
#include "CycQueue.h"


int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    showTest();

    SeqQueue *queue;
    queue =  SeqQueueInit();

    for (int i = 0; i<10; i++)
    {
        DATA dt;
        dt.number = 10*i+1;
        char name[10];
        sprintf(name, "name%d",i+10);
        strcpy(dt.name, name);

        SeqQueueIn(queue, dt);
    }

    printf("Length_%d\n", SeqQueueLength(queue));
    SeqQueueOut(queue);  // out 1st
    DATA *result = SeqQueueOut(queue); // out 2ed

    printf("%s_%d\n", result->name, result->number);
    printf("Length_%d\n", SeqQueueLength(queue));
///////////////////////////////////////////////////////
    CycQueue *cycqueue;
    cycqueue = CycQueueInit();

    for (size_t i = 0; i < 30; i++)
    {
	DATA dt;
	dt.number = 101 + i;
	strcpy_s(dt.name, "Insetr");
	CycQueueIn(cycqueue, dt);
    }
///////////////////////////////////////////////////////


    return 0;
}
