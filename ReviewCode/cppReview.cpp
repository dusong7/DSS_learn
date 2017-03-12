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

//Before Main()
//
////    const volatile int
////    volatile int i = 10;
////    int a = i;
////    printf("i = %d_\n", a);
//////    time_t  time1;
//////    time(&time1);
//////    i = time1;
////    __asm{
////        mov dword ptr [ebp-4], 20h
////    }
////    int b = i;
////    printf("i=%d \n", b);
////test for extern, always in multiply files.
//extern int first, last;
////    printf("%d_%d", first, last);
////
//
////r
//register int number; //save varity in CPU memory, fast eg.for loop()
////    int &num = first; reference init first
//wchar_t cha;
//cha = L'W'; //wchar_t not in C language
////    printf("\a");
////    funcConv();
//
////test for %#, %*.*
////    printf("%x, %#x\n", 10,10);
////    printf("%*.*f", 10,4,1234.44); //10, wideth, precise //_1234.4400
////    a, 0xa
////    12.4460
//    char str[2][3] = {{'1','2','2'},{'3','3','3'}}; //2hang2lie
//    char str[2][3]  = {"2","3"}; //str[0][0] = "2",str[1][0] = "3",

//sample


//may showed up

class nm
{
private:
    void shownmPri();
    friend class employee;
public:
//    void showIn(){employee e;e.showPrivateInfo();}

};

class employee
{
    char name[80]; //default private
    friend class fri;
    friend class nm;
    friend int sum();
public:
    employee();

    void putname(char *n);
    void getname(char *n);

public:
    void putwage(double w);
    double getage();

private:
    double wage;
    void showPrivateInfo();
};


void employee::getname(char *n) {
    //
    wage = 10.0;
//    fri fri1;
//    fri1.showPrivate();
//    nm n;
//    n.shownmPri();
}

//
int sum()
{
    employee ep;
    ep.wage = 10;
}
//

class Fri{
public:

    void showClass();
    void showInfo();
    friend class employee;

private:
    void showPrivate();


};

employee::employee() {
    //
}

inline void Fri::showInfo()   //
{
    //

//    ep.wage = 10.0;
    cout<<"Show info__"<<endl;

}
//2+1 //AND{2**n-1} +1
//2+4+1
//
int f1(int x)
{
    int s = 0;
    while((x--)>0)
    {
        cout<<"s_"<<s<<endl;
        cout<<"x_"<<x<<endl;
        s+=f1(x);

    }

    return max(s,1);
}

union show
{
    int name;
    void showInfo();
    void showName();
    void showAge();
};



class shared{
    static int a;
    int b;
public:
    void set(int i, int j){a=i;b=j;}
    void show();
};

int shared::a;

void shared::show() {
    cout<<"a_ "<<a<<endl;
}

//test for Class
//    Fri F;
//    F.showInfo();
//
//    test for static variable
//    shared sa,sb;
//    sa.set(1,1);
//    sa.show();
//    sb.set(2,2);
//    sb.show();
//    sa.show();
//    a_ 1
//    a_ 2
//    a_ 2

int main() {
    std::cout << "Hello, World!" << std::endl;

//
    return 0;
}


///
////
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


