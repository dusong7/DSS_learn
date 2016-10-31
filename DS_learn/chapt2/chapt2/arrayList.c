//
//  arrayList.c
//  chapt2
//
//  Created by apple on 16/10/31.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "arrayList.h"

void showTest()
{
    printf("Test\n");
}


void IniList(List *L)
{
    //
    //printf("initList\n");
    L->listLen = 0;
}

int ListLength(List *L)
{
    return L->listLen;
}

int ListAdd(List *L, DATA data)
{
    if(L->listLen > MAXSIZE)
    {
        printf("OUT \n");
        return 0;
    }

    L->ListData[++L->listLen] = data;

    return 1;
}

int ListInsert(List *L, int Position, DATA data)
{
    //首先判断表的长度，是否小于0是否大于当前长度，是否大于总长度
    for (size_t i = L->listLen+1; i > Position; i--)
    {
        L->ListData[i] = L->ListData[i - 1];
    }
    L->ListData[Position] = data;
    L->listLen ++;

    return 1;
}

int ListDelete(List *L, int Postion)
{
    for (size_t i = Postion; i < L->listLen; i++)
    {
        L->ListData[i] = L->ListData[i + 1];
    }
    L->listLen--;

    return 1;
}

DATA *searchByNumber(List L, int Position)
{
    DATA  *data = NULL;
    //
    return data;
}
