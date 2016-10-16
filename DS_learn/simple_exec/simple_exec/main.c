//
//  main.c
//  simple_exec
//
//  Created by apple on 16/9/25.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>

#define arrisize 40
#define MAXINT 65535

void  buble_sort(int nArray[], int n)
{
    for (int i = n-1; i>=0; i--) {
        for (int j = 0; j<i; j++) {
            if (nArray[j] > nArray[j+1]) {
                int nTemp;
                nTemp = nArray[j];
                nArray[j] = nArray[j+1];
                nArray[j+1] = nTemp;

                for (int i = 0; i<5; i++) {
                    printf("%d\t", nArray[i]);
                }
                printf("\n");
            }
        }
    }
}

void buble_sort2(int a[], int n)
{
    int i, j, temp;
    for (j = 0; j < n - 1; j++)
        for (i = 0; i < n - 1 - j; i++)
        {
            if(a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");

    int array[5] = {121, 111, 6, 3, 1};
    buble_sort2(array, 5);

    for (int i = 0; i<5; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
