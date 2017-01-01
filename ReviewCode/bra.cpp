///##
///## Code for BracketMatch_Begin 12/25/2016_dusong7/////
/*
#include <iostram>
#include <stack>

using namespace std;

bool isLeft(char c)
{
	if(c =="(")
	{
		return true;
	}
	
	if(c == "{")
	{
		return true;
	}
}

bool isMatched(char right, char left)
{
	if(right == "{" && left == "}")
	{
		return true;
	}
	
	if(right == "(" &&left == ")")
	{
		return true;
	}
}

bool BracketMatch(char *str)
{
	char c;
	stack<char> stcChar;
	
	while(*str)
	{
		c = *str;
		if(isLeft(c))
		{
			stcChar.push(c);
		}
		else
		{
			if(stcChar.empty() || !isMatched(c, stcChar.top()))
			{
				return false;
			}
			stcChar.pop();
		}
		str++;
	}
	
	if(!stcChar.empty())
	{
		return false;
	}
	return true;
}

int main()
{
	char str[10000];
	cin>>str;
	cout<<BracketMatch(str);
	
	return 0;
}
*/
// /## Code for BracketMatch_End/////


///### Code for 6174 Begin _NYOJ_57

//
//  main.cpp
//  TeCpp0x
//
//  Created by apple on 16/12/25.
//  Copyright © 2016年 apple. All rights reserved.
//
/*
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
*/
///####End code for 6174



////##Code for DS_
//
//  main.c
//  TeCDs
//
//  Created by apple on 16/12/25.
//  Copyright © 2016年 apple. All rights reserved.
//
///////////////HEAD_FILE___AND__COMMON__DEFINE_
#include<stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIABLE -1
#define OVERFLOW -2
typedef int ElemType;

typedef int Status;
///////////////////
///////HEAD_FILE___AND__COMMON__DEFINE_BEFORE

////##Code for DS_ list_1_start_

//#define CPPTYPEFILE

#ifndef CPPTYPEFILE
typedef int bool;
#endif

/////////////////////////
#define LIST_INIT_SIZE 100//
#define LINSTINCREMENT 10 //

//////////////

//
//FUNCTION_DS_C_language_
//##
// common function()://
// InitList(&L)
// DestroyList(&L)
// ClearList(&L)
// InsertList(&L, i, e)
// ListLength(L)
// ListEmpty(L)
// GetElem(L, i, &e)
// LocateElem(L, e, compare())
// PriorElem(L, cur_e, &pre_e)
// NextElem(L, cur_e, &next_e)
// ListDelete(&L, i, &e)
// ListTraverse(L, visit())
//
//##

typedef struct{
    ElemType *elem;
    int     length;
    int     listsize;
}Sqlist;
//

///implement InitList//
Status Init_list(Sqlist *L)
{
    L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (!L->elem)
    {
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;

    //simple assign value
    /*
    int i = 0;
    for (i=0; i<LIST_INIT_SIZE;i++)
    {
        L->elem[i]=i;
        //info[i].IDNumber = i;
        //memcpy(info[i].name,"Tindu",sizeof("Tindu"));
    }
    */

    return OK;
}
//

///Implement InsertaList//
Status InsertList(Sqlist *L, int i, ElemType e)
{
    //over maxsize
    if (1<i || i>L->length+1) {
        return ERROR;
    }

    ElemType *newvalue;
    ElemType *q;
    ElemType *p;

    if (L->length >= L->listsize) {
        newvalue = (ElemType *)realloc(L->elem,
                                       sizeof(ElemType) * (L->length+LINSTINCREMENT));
        L->elem = newvalue;
        L->listsize = L->listsize+LINSTINCREMENT;
    }

    q = &(L->elem[i-1]);
    for (p=&(L->elem[L->length-1]); p>=q; p--) {
        *(p+1) = *p;
    }

    *q = e;
    ++L->length;

//#define ZDay
#ifdef ZDay
    int j = 0;
    for (j = L->length; j>=i; j--) {
        L->elem[j+1] = j->elem[j];
    }

    L->elem[i] = e;
    L->length++;
#endif
    return OK;
}
/////////


////////Implement ListTraverse
void ListTraverse(Sqlist *L)
{
    int i;
    if (L->length !=0)
    {
        for (i = 0; i < L->length; ++i)
        {
            printf("%d_\n",L->elem[i]);
        }
    }
}
/////////////////

///////Implement isListEmpty
bool isListEmpty(Sqlist *L)
{
    if (L->length==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
////

////implement ListLength
Status ListLength(Sqlist *L)
{
    if (L!=NULL)
    {
        return (L->length);
    }

    return ERROR;
}
////

/// implement GetElement
void GetElement(Sqlist *L, int i, ElemType *e)
{
    //
    *e = (L->elem[i]);
}
/// \return//

////
Status ListDelete(Sqlist *L, int i, ElemType *e)
{
    //
    ElemType *p;
    ElemType *q;

    if (i<1 || i>L->length)
    {
        return ERROR;
    }
    p = &(L->elem[i - 1]);
    e = p;
    q = L->elem + L->length - 1;  //elem position , end in last.
    for (++p; p<=q; p++)
    {
        *(p - 1) = *p;
    }
    --L->length;

    return OK;
}

////


////

int main()
{
    Sqlist myList;

    Init_list(&myList);

	//Insrt test
    int i = 0;
    for (i = 0; i<150; i++) {
         InsertList(&myList, 1,10+i);
    }
	//Traverse Test//
    ListTraverse(&myList);

    return 0;
}

////##Code for DS_ list_1_end_//
