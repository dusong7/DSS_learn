//PAST _CODE
////
////  main.cpp
////  TeCpp0x
////
////  Created by apple on 16/12/25.
////  Copyright © 2016年 apple. All rights reserved.
////
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main()
//{
//
//    priority_queue<int> prQueBig;
//    priority_queue<int,vector<int>,greater<int> > prQueSmall;
//
//
//    int nTestTime = 0;
//    cin>>nTestTime;
//
//    for (int i=0; i<nTestTime; i++) {
//
//    int numberIn = 0;
//    cin>>numberIn;
//    int numberTemp;
//    int numberOut = 0;
//    int nCalTimes = 0;
////
//    while (1) {
//        numberTemp = numberIn;
//        while (numberTemp) {
//            int out = numberTemp % 10;
//            prQueSmall.push(out);
//            prQueBig.push(out);
//            numberTemp/=10;
//        }
//
//        int numberBig = 0;
//        int numberSmall = 0;
//        int curDivide = 1000;
//
//        while (!prQueSmall.empty()) {
//            numberBig += prQueBig.top() * curDivide;
//            prQueBig.pop();
//
//            numberSmall += prQueSmall.top() * curDivide;
//            prQueSmall.pop();
//            
//            curDivide /= 10;
//        }
//
//        nCalTimes ++;
//
////        cout<<NumberSmall<<endl;
////        cout<<NumberBig<<endl;
//
//        numberOut = numberBig - numberSmall;
//
//        if (numberOut == numberIn) {
//            break;
//        }
//
//        numberIn = numberOut;
//    }
//
//    cout<<nCalTimes<<endl;
// }
//
//    return 0;
//}
//_END_PAST_CODE


#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType data;
    int cur;
}compont, SLinkList[MAXSIZE];

int comp(ElemType e1, ElemType e2)
{
    //return e1 == e2 ? 1 : 0;
    if (e1 == e2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InitSpace_SL(SLinkList &space)
{
    int i;
    for (i = 0; i<MAXSIZE; i++)
    {
        space[i].cur = i;
    }
    space[MAXSIZE - 1].cur = 0;
}

void Free_SL(SLinkList &space, int i)
{
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

int Malloc_SL(SLinkList &space)
{
    int i = space[0].cur;
    if (space[0].cur)
    {
        space[0].cur = space[i].cur;
    }

    return i;
}

void difference(SLinkList &space, int &S, int(*compare)(ElemType, ElemType))
{
    //
    int m, n, i, j, r, p, k;
    ElemType b;
    InitSpace_SL(space);
    r = S = Malloc_SL(space); //
    printf("Please input m of A, n of B set size\n");
    scanf("%d,%d", &m, &n);

    for (j = 1; j <= m; j++)
    {
        i = Malloc_SL(space);
        scanf("%d", &space[i].data);
        space[r].cur = i;
        r = i;
    }

    space[r].cur = 0;
    printf("\nB:\n");
    for (j = 1; j <= n; j++)
    {
        scanf("%d", &b);
        //TODO:
        p = S;
        k = space[S].cur;

        while (k != space[r].cur && !compare(space[k].data, b))
        {
            p = k;
            k = space[k].cur;
        }

        if (k == space[r].cur)
        {
            //
            i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[r].cur = i;
        }
        else
        {
            space[p].cur = space[k].cur;
            Free_SL(space, k);
            if (r == k)
            {
                r = p;
            }
        }
    }
    
}

int main()
{
    //
    SLinkList space;
    int s;
    difference(space, s, comp);
    printf("\nThe result is:\n\n");
    while ((s = space[s].cur) != 0) {
        printf("=> %d\n", space[s].data);
    }
    
    printf("\nResult End!\n");
    system("pause");
    return 0;
}
