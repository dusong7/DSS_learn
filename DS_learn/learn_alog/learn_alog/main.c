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
}
/////


////Test for convert function/////
//    char s[80];
//
//    int base = 2;
//    int old = 10;
//    convert(s, old, base);
//
//    printf("%s\n", s);
/////////


////Main Function Call ///
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

int show(int N)
{
    int sum = 0;
    if (0 == N) {
        return (1);
    }
    else
    {
        sum = N * show(N-1);
    }

    return sum;
}

int NumV = 0;
////simple recursion  test////
void digui(int m)
{
    if (m==1) {
        printf("%d>", NumV);
        return;
    }
    digui(m-1);
    NumV ++;
    printf("%d__", NumV);

}
    /////
//    gamecal(1, 8);
//
//    for (int i = 1; i<=8; i++) {
//        for (int j=1; j<=8; j++) {
//            printf("%d_", a[i][j]);
//        }
//        printf("\n");
//    }

//    printf("%d", show(5));
//    digui(5);

////////////calturate money change ////////////
///eg. 120 - == 100*1 + 10*2
#define MAXIN 9
int parValue[MAXIN] = { 10000, 5000, 1000, 500, 200, 100, 50, 20, 10};  // 
int num2[MAXIN] = { 0 };

int exchange(int n)
{
	int i=0;
	for ( i = 0; i < MAXIN; i++)
	{
		if (n>parValue[i])
		{
			break;
		}
	}

	while (n > 0 && i<MAXIN)
	{
		if (n>=parValue[i])
		{
			n -= parValue[i];
			num[i]++;
		}
		else if (n<10 && n>= 5)
		{
			num2[MAXIN - 1] ++;
			break;
		}
		else
		{
			i++;
		}
	}	
	return 0;
}
////////Test for  money exchange Function///////
//exchange(int(36.86 * 100));

//	for (size_t i = 0; i < MAXIN; i++)
//	{
//		if (num[i]>0)
//              {
//			printf("%6.2f:  %d\n", float(parValue[i] / 100.0), num[i]);
//		}
//	}
/////////////////////


///////Generate Lottery  Ticks Function/////////
///////eg. from 0-29 selset 7 numbers and unique/////////////
///////////////////
////////////////////////////////////////////////

int lottery[5] = {1,2,3,4,5};
int numC[3] = {1,2,3};

void lotteryGene(int n, int m)
{
	////
    int i;
    for (i=n; i>=m; i--) {
        numC[m-1] = lottery[i-1];

        if (m>1) {
            lotteryGene(i-1, m-1);
        }
        else
        {
            for (int i=0; i<3; i++) {
                printf("%d_", numC[i]);
            }
            printf("\n");
        }
    }

}

int main(int argc, const char * argv[])
{
    ////

    lotteryGene(5,3);

    return 0;
}
