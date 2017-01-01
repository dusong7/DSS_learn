//
//  main.cpp
//  TeCpp0x
//
//  Created by apple on 16/12/25.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main()
{

    priority_queue<int> prQueBig;
    priority_queue<int,vector<int>,greater<int> > prQueSmall;


    int nTestTime = 0;
    cin>>nTestTime;

    for (int i=0; i<nTestTime; i++) {

    int numberIn = 0;
    cin>>numberIn;
    int numberTemp;
    int numberOut = 0;
    int nCalTimes = 0;
//
    while (1) {
        numberTemp = numberIn;
        while (numberTemp) {
            int out = numberTemp % 10;
            prQueSmall.push(out);
            prQueBig.push(out);
            numberTemp/=10;
        }

        int numberBig = 0;
        int numberSmall = 0;
        int curDivide = 1000;

        while (!prQueSmall.empty()) {
            numberBig += prQueBig.top() * curDivide;
            prQueBig.pop();

            numberSmall += prQueSmall.top() * curDivide;
            prQueSmall.pop();
            
            curDivide /= 10;
        }

        nCalTimes ++;

//        cout<<NumberSmall<<endl;
//        cout<<NumberBig<<endl;

        numberOut = numberBig - numberSmall;

        if (numberOut == numberIn) {
            break;
        }

        numberIn = numberOut;
    }

    cout<<nCalTimes<<endl;
 }

    return 0;
}
