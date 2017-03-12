#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include "main.h"

//#include <thread>
using namespace std;

//test for
#define SIZE 100  //
int *pl; //
int *tos; //
//


void push(int i);

int pop(void);

void delay(volatile uint32_t n )  //volatile keyword 直接存取原始内存地址
{
    //
    while (-n);
}

int cal(volatile int *ptr)
{
    //
    int a;
    a = *ptr;
    return (a * a);

    //
//    int a, b;
//    a = *ptr;
//    b = *ptr;     //may a, b have not equal value//


}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    const volatile int
//    volatile int i = 10;
//    int a = i;
//    printf("i = %d_\n", a);
////    time_t  time1;
////    time(&time1);
////    i = time1;
//    __asm{
//        mov dword ptr [ebp-4], 20h
//    }
//    int b = i;
//    printf("i=%d \n", b);
    //test for extern, always in multiply files.
    extern int first, last;
    printf("%d_%d", first, last);
    //

//r
    register int number; //save varity in CPU memory, fast eg.for loop()
//    int &num = first; reference init first
    wchar_t cha;
    cha = L'W'; //wchar_t not in C language
//    printf("\a");
//    funcConv();
    return 0;
}


void push(int i)
{
    //
    pl++;
    if (pl==tos+SIZE)
    {
        printf("STACK overflow");
    }
    *pl = i;

}

int pop(void)
{
    //
    pl--;
    return *(pl+1);
}


int x;
char ch;
float f;
void funcConv(void)
{
    ch = x;
    x = f;
    f = x;
    f= ch;
    //

}

//test for extern
int first = 10;
int last = 20;
//


