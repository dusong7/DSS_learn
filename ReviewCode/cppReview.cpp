#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

//#include <thread>
using namespace std;


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

    return 0;
}
