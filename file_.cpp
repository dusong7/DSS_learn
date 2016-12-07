// ConsoleReadAnd_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string line;

	ifstream in("rand.txt");
	if (in)
	{
		while (getline(in, line))
		{
			//cout << line << endl;
			int num = atoi(line.c_str());
			printf("%d\n", num);
		}
	}
	return 0;
}



//
//  main.c
//  DSGraph
//
//  Created by apple on 16/11/20.
//  Copyright © 2016年 apple. All rights reserved.
//
//###############  x==x is FALSE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...

    float x = 0xffffffff;

    if (x == x) {
        printf("Equal\n");
    }
    else {
        printf("Not equal\n");
    }

    if (x >= 0) {
        printf("x(%f) >= 0\n", x);
    }
    else if (x < 0) {
        printf("x(%f) < 0\n", x);
    }

    int a = 0xffffffff;
    memcpy(&x, &a, sizeof(x));
    if (x == x) {
        printf("Equal\n");
    }
    else {
        printf("Not equal\n");
    }

    if (x >= 0) {
        printf("x(%f) >= 0\n", x);
    }
    else if (x < 0) {
        printf("x(%f) < 0\n", x);
    }
    else {
        printf("Surprise x(%f)!!!\n", x);
    }
    return 0;
}

