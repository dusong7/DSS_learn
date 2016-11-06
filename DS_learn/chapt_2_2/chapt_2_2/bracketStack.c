//
//  bracketStack.c
//  chapt_2_2
//
//  Created by apple on 16/11/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "bracketStack.h"
#include <stdlib.h>

int isOperate(char c)
{
    ///skip for other -,/.(,).  //
    switch (c) {
        case '+':
        case '*':
            return 1;
            break;

        default:
            return 0;
            break;
    }
}

int PRI(char oper1, char oper2)
{
    ///oper1 > oper2 return 1
    ///oper1 < oper2 return -1
    ///oper1 > oper2 is left and right bracket return 0, skip
    int pri;
    switch (oper2) {
        case '+':
        case '-':
            if (oper1 == '(' || oper1 == '=') {
                pri = -1;
            }else
            {
                pri = 1;
            }
            break;
        case '*':
        case '/':
            if (oper1 == '*' || oper1 == '/' || oper1 == ')') {
                pri = 1;
            }
            else{
                pri = -1;
            }
            break;
        case '(':
            if (oper1 == ')') {
                printf("Error__\n");
                exit(0);
            }
            else
            {
                pri = -1;
            }
            break;
        case ')':
            if (oper1 == '(') {
                pri = 0;
            }
            else if (oper1 == '=')
            {
                printf("NOT COMPARED");
                exit(0);
            }
            else
            {
                pri = 1;
            }
            break;
        case '=':
            if (oper1 == '(') {
                printf("NOT COMPARED\n");
                exit(0);
            }
            else if (oper1 == '=')
            {
                pri = 0;
            }
            else
            {
                pri = 1;
            }
            break;

        default:
            break;
    }


    return pri;
}

int Calc(int a, char oper, int b)
{
    ////skip for some //
    switch (oper) {
        case '+':
            return a + b;

        case '*':
            return a*b;

        default:
            return 0;
            break;
    }
}

int CalcExp(char exp[])
{
    SeqStack *StackOper, *StackData;
    int i = 0;
    int flag = 0;
    DATA a, b, q, x,t,oper;
    char c;  // split a charater
    // a
    // b
    // c
    // q
    // x
    // t
    // oper

    StackData = SeqStackInit();
    StackOper = SeqStackInit();

    q = 0;
    x  = '=';
    SeqStackPush(StackOper, x);
    c = exp[i++];

    while (c != '=' || x != '=') {
        if (isOperate(c)) {
            if (flag) {
                SeqStackPush(StackData, q);
                q = 0;
                flag = 0;
            }
            switch (PRI(x, c)) {
                case -1:
                    SeqStackPush(StackOper, c);
                    c = exp[i++];
                    break;
                case 0:
//                    SeqStackPush(StackOper, <#DATA data#>)
                    SeqStackPop(StackOper);
                    c = exp[i++];
                    break;
                case 1:
                    oper = SeqStackPop(StackOper);
                    b = SeqStackPop(StackData);
                    a = SeqStackPop(StackData);
                    t = Calc(a, oper, b);
                    SeqStackPush(StackData, t);
                    break;
                default:
                    break;
            }
        }else if (c>='0' && c<='9')
        {
            c -= '0';
            q  = q * 10 + c;
            flag = 1;
            c = exp[i++];
        }
        else
        {
            printf("Input Error__\n");
            getchar();
            exit(0);
        }
        x = SeqStackPeek(StackOper);
    }

    q = SeqStackPop(StackData);
    SeqStackFree(StackOper);
    SeqStackFree(StackData);

    return q;
}
