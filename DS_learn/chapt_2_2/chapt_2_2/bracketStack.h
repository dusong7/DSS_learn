//
//  bracketStack.h
//  chapt_2_2
//
//  Created by apple on 16/11/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef bracketStack_h
#define bracketStack_h

#define SIZE_ 50
//typedef int DATA;

#include <stdio.h>
#include "SeqStack.h"

int isOperate(char c);
int PRI(char oper1, char oper2);
int Calc(int a, char oper, int b);
int CalcExp(char exp[]);
#endif /* bracketStack_h */
