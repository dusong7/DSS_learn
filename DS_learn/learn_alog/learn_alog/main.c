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
//////////gamecal Function////////
#define MAXIN 64
int a[MAXIN+1][MAXIN+1]  = {0};

void gamecalT(int N)
{
    //
    //
    int i = 0;
    int j = 0;

    if(N <=1)
    {
        printf("Less than 2 people!");
        return;
    }

    N -= 2;  // base people is 2, over 2

    int nXBase = 1;
    int nYBase = 2;

    int nBase[2][2] = {0};

    while(N >= 0)
    {
        nBase[0][0] = nXBase + N;
        nBase[0][1] = nYBase + N;
        nBase[1][0] = nYBase + N;
        nBase[1][1] = nXBase + N;

        for(i=0; i<2; i++)
     {
        for(j=0;j<2;j++)
        {
            printf("%d__", nBase[i][j]);
        }
     }
     N -=2;
    }
}
/////////////////////////////
//////
void gamecal(int k, int n)
{
        int i, j;
        if(n == 2)
        {
            a[k][1] = k;
            a[k][2] = k+1;
            a[k+1][1] = k +1;
            a[k+1][2] = k;
        }
        else
        {
            gamecal(k, n/2);
            gamecal(k+n/2, n/2);
            for(i=k;i<k+n/2;i++)
            {
                for(j=n/2+1;j<=n;j++)
                {
                    a[i][j] = a[i+n/2][j-n/2];
                }
            }

            for(i=k+n/2;i<k+n;i++)
            {
                for(j=n/2+1;j<=n;j++)
                {
                    a[i][j] = a[i-n/2][j-n/2];
                }
            }
        }
}
//////
//////////not　ＷＥＬＬ　Delete////////////////
int numBase[2][2] = {1,2,2,1};
int NumShow[10][10] = {0};
int num[2] = {1,0};
void showValue(int N)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= N; i++)
	{
	    if(i<=N/2)  ////
        {
        for (j = 1; j <= N; j++)
		{
            int adNum = 0;
            if (j%2) {
                adNum = j-1;
            }
            else{
                adNum = j-2;
            }

			int Temp = numBase[num[i % 2]][num[j % 2]];
            printf("%d_%d_ ", Temp,adNum);
			//numBase[]
			NumShow[i][j] = numBase[num[i % 2]][num[j % 2]] + adNum;
		}
        }
        else
        {
             for (j = 1; j <= N; j++)
            {
		        NumShow[i][j] = NumShow[N+1-i][N+1-j];
            }
        }
		printf("\n");
}
/////
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
///
//    int N =8;
//    printf("Please input N, n is 2^N, not Zero\n");
//    gamecal(1,N);
//    int  i = 0;
//    int j = 0;

//    for(i=1;i<=N;i++)
//    {
//        for(j=1;j<=N;j++)
//        {
//            printf("%d\t",a[i][j]);
//        }
//    }
///12->0;34->2;56->4.....
//    for (int i = 1; i<=10; i++) {
//        if (i%2) {
//            printf("%d", i-1);
//        }
//        else{
//            printf("%d", i-2);
//        }
//        //printf("_%d ", i);
//    }

//////showValue(4); not WELL



    return 0;
}
