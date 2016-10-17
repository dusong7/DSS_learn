//
//  main.c
//  learn_alog
//
//  Created by apple on 16/10/16.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>

///number digital convert
//
void convert(char *s, int n , int b)
{
    char bit[] = {"0123456789ABCDEF"};
    int len;
    if (n == 0) {
        strcpy(s,"");
        return;
    }
    convert(s, n/b, b);
    len = strlen(s);
    s[len] = bit[n%b];
    s[len+1] = '\0';
}
//////
#include <stdio.h>
#include <stdlib.h>

#define MAXIN 64
int a[MAXIN+1][MAXIN+1]  = {0};

void gamecal(int N)
{
    //
    int i = 0;
    int j = 0;

    int nBase[2][2] = {1,2,2,1};

    for(i=0; i<2; i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d__", nBase[i][j]);
        }
    }
}


int main(int argc, const char * argv[]) {

////Test for convert function/////
//    char s[80];
//
//    int base = 2;
//    int old = 10;
//    convert(s, old, base);
//
//    printf("%s\n", s);
/////////

/////Test for gamecal/    
//    int N = 1;
//    printf("Please input N, n is 2^N, not Zero");
//    gamecal(N);

    return 0;
}
