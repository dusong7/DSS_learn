//
//  main.c
//  chapt2
//
//  Created by apple on 16/10/31.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
#include "arrayList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    showTest();

    List L;
    IniList(&L);

    for (int i = 0; i < 10; i++)
    {
        DATA data;
        char key[10] = "";
        sprintf(key,"000%d", i);

        char name[10] = "";
        sprintf(name, "Cur%d", i);

        data.age = 10 + i;
        //data.key = key;
        //data.name = name;
        strcpy(data.key, key);
        strcpy(data.name, name);
        ListAdd(&L, data);
    }

//    for (size_t i = 0; i < 11; i++)  // re
//    {
//        DATA Result = *searchByNumber(&L, i);
//
//        printf("%s_%s_%d\n", Result.key, Result.name, Result.age);
//    }

    return 0;
}
