//
//  main.c
//  single_link_list
//
//  Created by apple on 16/9/17.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChainList.h"

////////////Old execise/////////////////
//#define LINK_LIST_SIZE 10
//#define LISTINCREMENT 10
//#define OK 1
//#define OVERFLOW -1
//#define ERROR 0
//
//
//typedef int States;
//typedef int Element;
//
//typedef struct  {
//    Element *elem;
//    int length;
//    int listsize;
//}Sqlist;
//
//States InitSqlit(Sqlist &L)
//{
//    L.elem = (Element *)malloc(LINK_LIST_SIZE * sizeof(Sqlist));
//
//    if (!L.elem) {
//        return OVERFLOW;
//    }
//
//    L.length = 0;
//    L.listsize = LINK_LIST_SIZE;
//
//    return OK;
//}
//
//void listInsert(Sqlist &L,  int position, Element e)
//{
////    int j;
////    Element *newdb;
//
//    *(L.elem+position-1) = e;
//    L.length ++;
//}
//
//void list_traverse(Sqlist &L)
//{
//    for (int i = 0; i<L.length; i++) {
//        printf("%d\n", *(L.elem));
//    }
//}
//
//    // insert code here...
//
//    Sqlist list;
//    InitSqlit(list);
//    listInsert(list, 1, 10);
//    listInsert(list, 2, 4);
//    listInsert(list, 3, 8);
//
//    list_traverse(list);
//
//    printf("Hello, World!\n");
///////////////////////////////////////

///new exercise_ Chapter 2///
 int main(int argc, const char * argv[])
 {

//     char name[10];
//     strcpy(name,"namem");
//     printf("%s\n", name);

//     showTest();
//     ChainListType list;
//     InitChainlist(&list);
    ////test for insert 10 data
//     for (int i = 0; i < 10; i++)
//     {
//         DATA dt;
//         dt.age = 10 + i;
//         strcpy(dt.key, "key");
//         strcpy(dt.name, "name");

//         chainlistAddEnd(&list, dt);
//     }
     
//     printf("Length ->>> _ %d\n", chainlistLength(&list));

//     chainListShow(&list);

     //test for insert after show
//     DATA dt;
//     dt.age = 99;
//     strcpy(dt.key, "Insert");
//     strcpy(dt.name, "nameInse");

//     chainlistAddEnd(&list, dt);

//     printf("Length ->>> _ %d\n", chainlistLength(&list));
//     chainListShow(&list);

  
  	ChainListType *head = NULL;

	for (int i = 0; i < 10; i++)
	{
		DATA dt;
		dt.age = 10 + i;
		strcpy(dt.key, "key");
		strcpy(dt.name, "name");

		head = chainlistAddEnd(head, dt);	 
	}
	 
  	DATA dt;
	dt.age = 99;
	strcpy(dt.key, "End");
	strcpy(dt.name, "Endname");

	head = chainlistAddFirst(head, dt);
	chainListShow(head);

    return 0;
 }
