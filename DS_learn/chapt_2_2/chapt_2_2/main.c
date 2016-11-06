//
//  main.c
//  chapt_2_2
//
//  Created by apple on 16/11/2.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
//#include "SeqQueue.h"
//#include "CycQueue.h"
#include "SeqStack.h"
#include "bracketStack.h"


int randomTable[] = { 1717
    ,2154
    ,2845
    ,1305
    ,1204
    ,386
    ,1759
    ,462
    ,2777
    ,2334
    ,1139
    ,1246
    ,950
    ,326
    ,2628
    ,2361
    ,420
    ,2377
    ,2458 };

//    printf("Hello, World!\n");
//    showTest();
//
//    SeqQueue *queue;
//    queue =  SeqQueueInit();
//
//    for (int i = 0; i<10; i++)
//    {
//        DATA dt;
//        dt.number = 10*i+1;
//        char name[10];
//        sprintf(name, "name%d",i+10);
//        strcpy(dt.name, name);
//
//        SeqQueueIn(queue, dt);
//    }
//
//    printf("Length_%d\n", SeqQueueLength(queue));
//    SeqQueueOut(queue);  // out 1st
//    DATA *result = SeqQueueOut(queue); // out 2ed
//
//    printf("%s_%d\n", result->name, result->number);
//    printf("Length_%d\n", SeqQueueLength(queue));
/////////////////////////////////////////////////////////
//    CycQueue *cycqueue;
//    cycqueue = CycQueueInit();
//
//    for (int i = 0; i < 30; i++)
//    {
//	DATA dt;
//	dt.number = 101 + i;
//	strcpy(dt.name, "Insetr");
//	CycQueueIn(cycqueue, dt);    // i++ is dif ++i, Cyc is move to Next, and SeqQueue is current
//    }
/////////////////////test For stack//////////////////////////////////
//
//        SeqStack * stack;
//        stack = SeqStackInit();
//
//        for (size_t i = 0; i < 6; i++)
//        {
//            DATA dt;
//            strcpy(dt.name, "name");
//            dt.number = randomTable[i];
//            SeqStackPush(stack, dt);
//        }
//
//        for (size_t i = 0; i < 5; i++)
//        {
//            printf("%d_\n", SeqStackPop(stack).number);
//        }
////////////////////////test For stack///////////////////////////////


#include<stdio.h>

int char2number(char c)
{
    switch(c){
        case '0':return 0;
        case '1':return 1;
        case '2':return 2;
        case '3':return 3;
        case '4':return 4;
        case '5':return 5;
        case '6':return 6;
        case '7':return 7;
        case '8':return 8;
        case '9':return 9;
        default:
            return 0;
    }
}

int is_operator(char c){
    return (c=='*' || c=='+' || c=='-' ||c=='/');
}

int count(int a,int b,char opt){
    switch(opt){
        case '*':return a*b;
        case '+':return a+b;
        case '-':return a-b;
        case '/':return a/b;
        default:
            return 0;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
//////////Test for bracket_Excption/////////////////////
//    char exp[10] = "(2+4)*8=";
//
//    printf("%s%d\n", exp,CalcExp(exp));

//////////Test for bracket_Excption/////////////////////

    int number[2]; //存放运算数
    char str[10]; ///表达式
    char opt = '\0'; //操作符

    while(1){
        fgets(str,10,stdin);

        int i=0;
        int j=0;
        int res;

        //相当于一个简单的字符串分析，从中提取出数字和运算符
        while(str[i] && str[i]!='\n'){
            if(!is_operator(str[i])){
                number[i-j] =char2number(str[i]);
            }else{
                opt =str[i];
                j++; //碰到运算符，需要记录。因为运算符并不存储在number数组中，
                //比如 3*5 分析到字符5时，i为2但是number数组中只记录了3即number[0]所以5应该在number[1]，
                //所以上面使用number[i-j]来记录数字
            }
            i++;
        }
        res=count(number[0],number[1],opt);
        printf("=%d\n",res);
    }

    return 0;
}
