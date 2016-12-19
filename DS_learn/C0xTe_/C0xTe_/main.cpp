//
//  main.cpp
//  C0xTe_
//
//  Created by apple on 16/12/18.
//  Copyright © 2016年 apple. All rights reserved.
//

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct dNumber{
//    int number1;
//    int number2;
//};
//
//vector<dNumber> vecVal;
//
//int inByte(int nFir, int nSec)
//{
//    int num = 0;
//
//    int naFir[3];
//    int naSec[3];
//
//    naFir[0] = nFir/100;
//
//    naFir[2] = nFir%10;
//    naFir[1] = nFir %100/10;
//
//    naSec[0] = nSec/100;
//
//    naSec[2] = nSec%10;
//    naSec[1] = nSec %100/10;
//
//    for (int i=0; i<3; i++) {
//        if (naFir[i]+naSec[i] >= 10) {
//            num++;
//        }
//    }
//
//    if (naFir[2]+naSec[2] >= 10) {
//        if (naFir[1]+naSec[1]==9) {
//            num++;
//        }
//    }
//
//    if (naFir[1]+naSec[1] >= 10) {
//        if (naFir[0]+naSec[0]==9) {
//            num++;
//        }
//    }
//
//    return num;
//}
//
//int main(int argc, const char * argv[])
//{
//    // insert code here...
//    int numFir;
//    int numSec;
//
//    cin>>numFir>>numSec;
//
//
//    for (; ; ) {
//        //
//        if (numFir==0 && numSec==0) {
//            break;
//        }
//        dNumber number;
//        number.number1 = numFir;
//        number.number2 = numSec;
//        vecVal.push_back(number);
//        //cout<<numFir<< " " <<numSec<<endl;
//        cin>>numFir>>numSec;
//    }
//
//    for (int i = 0; i<vecVal.size(); i++) {
//        //
//        cout<<inByte(vecVal[i].number1, vecVal[i].number2)<<endl;
//    }
//
//
//    return 0;
//}

#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,n,m,i;
    for(;;)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
            return 0;
        else
        {
            i=0;
            a=n/100;b=n%100/10;c=n%10;
            d=m/100;e=m%100/10;f=m%10;
            if(c+f>=10)
            {i+=1;b+=1;}
            if(b+e>=10)
            {i+=1;a+=1;}
            if(a+d>=10)
            {i+=1;}
            printf("%d\n",i);
        }
    }
    return 0;
}
