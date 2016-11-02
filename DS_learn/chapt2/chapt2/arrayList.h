//
//  arrayList.h
//  chapt2
//
//  Created by apple on 16/10/31.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef arrayList_h
#define arrayList_h

#include <stdio.h>



void showTest();

#define MAXSIZE 100

typedef struct{
    char key[15];
    char name[15];
    int age;
}DATA;

typedef int Elem;

typedef struct{
    DATA ListData[MAXSIZE + 1];
    int listLen;
}List;


void IniList(List *L);
int ListLength(List *L);
int ListAdd(List *L, DATA data);
int ListInsert(List *L, int Position, DATA data);
int ListDelete(List *L, int Postion);
DATA *searchByNumber(List L, int Position);
#endif /* arrayList_h */
