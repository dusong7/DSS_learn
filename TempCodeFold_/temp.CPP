
void funcCur(char *src, char *target)
{
	char *sor, *s1, *s2;
	sor = target;
	s1 = src;
	s2 = target;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			*s2++;
			if (*s1 != *s2)
			{
				*s2++;
				if (*s1 != *s2)
				{
					//printf("%c3_\n", *s2);
					vecChar.push_back(*s1);
					s2 = sor;
				}
				else
				{
					s2 = sor;
				}
			}
			else
			{
				s2 = sor;
			}
		}
		else
		{
			s2 = sor;
		}
		*s1++;
		printf("%c\n", *s1);
	}

	for (size_t i = 0; i < vecChar.size(); i++)
	{
		printf("%c", vecChar[i]);
	}
	printf("\n");
}

// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
struct Table
	{
		int num;
		bool isTre;
	};

	int TNumber = 0;
	int randTable[] = { 10, 4, 8, 9, 9, 4, 7, 6, 1, 9, 1, 1, 8, 10, 10, 3, 2, 5, 4, 6, 6, 5, 7, 7, 4, 3, 10, 9, 4, 5, 2, 3, 8, 4, 3, 3, 3, 6, 5, 1, 10, 9, 6, 7, 5, 3, 2};
	Table tb[10];

	for (size_t i = 0; i < 10; i++)
	{
		tb[i].isTre = false;
	}
	for (size_t i = 0; i < 47; i++)
	{
		//printf("% d#", i);
		if (!tb[randTable[i]-1].isTre)
		{
			tb[randTable[i]-1].isTre = true;
			TNumber++;
			printf("%d_hit\t", randTable[i]);
		}
		if (TNumber == 10)
		{
			printf("%dth_Val %d\n", i+1, randTable[i]);
			//break;
		}
	}

// rrr.cpp : Defines the entry point for the console application.
//
定义一个数组char a[10];
怎么给这个数组赋值呢？
1、定义的时候直接用字符串赋值
char a[10]="hello";
注意：不能先定义再给它赋值，如char a[10]; a[10]="hello";这样是错误的！
2、对数组中字符逐个赋值
char a[10]={'h','e','l','l','o'};
3、利用strcpy
char a[10]; strcpy(a, "hello");
易错情况：
1、char a[10]; a[10]="hello";//一个字符怎么能容纳一个字符串？况且a[10]也是不存在的！
2、char a[10]; a="hello";//这种情况容易出现，a虽然是指针，但是它已经指向在堆栈中分配的10个字符空间，现在这个情况a又指向数据区中的hello常量，这里的指针a出现混乱，不允许！
main() 
{ 
char s[30]; 
strcpy(s, "Good News!"); /*给数组赋字符串*/ . 
} 
上面程序在编译时, 遇到char s[30]这条语句时, 编译程序会在内存的某处留出连续30个字节的区域, 并将第一个字节的地址赋给s。当遇到strcpy( strcpy 为Turbo C2.0的函数)时, 首先在目标文件的某处建立一个"Good News!/0" 的字符串。其中/0表示字符串终止, 终止符是编译时自动加上的, 然后一个字符一个字符地复制到s所指的内存区域。因此定义字符串数组时, 其元素个数至少应该比字符串的长度多1。
#include "stdafx.h"
typedef struct
{
	char name_[15];
	char home_[20];
}Base;


typedef struct
{
	Base nameInfo[10];
	int length;
}NAME;

void add(NAME *n, Base base)
{
	n->nameInfo[n->length++] = base;
}

int main(int argc, char* argv[])
{
	NAME nm;
	nm.length = 0;

	Base bName;
	for (size_t i = 0; i < 5; i++)
	{
		scanf_s("%s%s", bName.home_, 10, bName.name_, 10);
		//scanf_s("%s", bName.name_, 10);
		printf("%s,%s\n", bName.name_, bName.home_);

		add(&nm, bName);
	}

	int numTable[6] = { 1, 2, 3, 4, 5 };
	
	for (size_t i = 5; i >= 3; i--)
	{
		numTable[i] = numTable[i - 1];
	}

	for (size_t i = 0; i < 6; i++)
	{
		printf("%d__", numTable[i]);
	}
	return 0;
}




#include "stdafx.h"
#include "Header.h"
#include <string.h>
////Chapter 2 exercise///


int _tmain(int argc, _TCHAR* argv[])
{
	//
	//showMessage();
	//showCurTest();

	List L;
	IniList(&L);

	for (size_t i = 0; i < 10; i++)
	{
		DATA data;
		char key[10] = "";
		sprintf_s(key,10 ,"000%d", i);

		char name[10] = "";
		sprintf_s(name, 10, "Cur%d", i);

		data.age = 10+i;
		//data.key = key;
		//data.name = name;
		strcpy_s(data.key, key);
		strcpy-s(data.name, name);
		ListAdd(&L, data);
	}


	
	char *l[10];
	for(int i=0;i<5;i++)
	{
	    char name[10] = "";
	    sprintf_s(name, 10, "Cur%d",i);
	    l[i] = name;
	}
	
	
	
	
	DATA insert;
	strcpy_s(insert.key, "Insert");
	strcpy_s(insert.name, "inName");
	insert.age = 99;
	L.ListData[2] = insert;


	for (size_t i = 0; i < 11; i++)  // re
	{
		DATA Result = *searchByNumber(&L, i);

		printf("%s_%s_%d\n", Result.key, Result.name, Result.age);
	}

	DATA insert;
	strcpy_s(insert.key, "Insert");
	strcpy_s(insert.name, "inName");
	insert.age = 99;
	//L.ListData[2] = insert;
	ListInsert(&L, 3, insert);



	for (size_t i = 0; i < L.listLen; i++)  // re
	{
		DATA Result = *searchByNumber(&L, i);

		printf("%s_%s_%d\n", Result.key, Result.name, Result.age);
	}

	ListDelete(&L, 5);

	for (size_t i = 0; i < L.listLen; i++)  // re
	{
		DATA Result = *searchByNumber(&L, i);

		printf("%s_%s_%d\n", Result.key, Result.name, Result.age);
	}
	
	return 0;
}


#include "stdafx.h"
#include "Header.h"

void showCurTest()
{
	printf("Cur\n");
}

void IniList(List *L)
{
	//
	//printf("initList\n");
	L->listLen = 0;
}

int ListLength(List *L)
{
	return L->listLen;
}

int ListAdd(List *L, DATA data)
{
	if(L->listLen > MAXSIZE)
	{
		printf("OUT \n");
		return 0;
	}

	L->ListData[++L->listLen] = data;

	return 1;
}
int ListInsert(List *L, int Position, DATA data)
{
	//首先判断表的长度，是否小于0是否大于当前长度，是否大于总长度
	for (size_t i = L->listLen+1; i > Position; i--)
	{ 
		L->ListData[i] = L->ListData[i - 1];
	}
	L->ListData[Position] = data;
	L->ListLength ++;
	
	return 1;
}
int ListDelete(List *L, int Postion)
{
	for (size_t i = Postion; i < L->listLen; i++)
	{
		L->ListData[i] = L->ListData[i + 1];
	}
	L->listLen--;

	return 1;
}
DATA *searchByNumber(List L, int Position)
{
	DATA  *data = NULL;
	//
	return data;
}


#ifndef HEADER_H
#define HEADER_H
#endif

#include "stdafx.h"
#include <stdio.h>

#define MAXSIZE 100

typedef struct{
	char key[15];
	char name[15];
	int age;
}DATA;

typedef int Elem;

typedef struct{
	DATA ListData[MAXSIZE + 1];
	int listLen;
}List;

void showCurTest();

void IniList(List *L);
int ListLength(List *L);
int ListAdd(List *L, DATA data);
int ListInsert(List *L, int Position, DATA data);
int ListDelete(List *L, int Postion);
DATA *searchByNumber(List L, int Position);


///#################
///########Chain List declare file  #########
///#################

#ifndef CHAINLIST_H
#define CHAINLIST_H
#endif

void showMsg();

typedef struct{
	char key[20];
	char name[20];
	int  age;
}DATA;

typedef struct Node{
	DATA data;
	struct Node *next;
}ChainListType;

int   InitChainlist(ChainListType *head);
ChainListType *chainlistAddEnd(ChainListType *head, DATA data);
ChainListType *chainlistAddFirst(ChainListType *head, DATA data);
ChainListType *chainlistFind(ChainListType *head, char *key);
ChainListType *chainlistInsert(ChainListType *head, char * findKey, DATA data);
int chainlistDelete(ChainListType *head, DATA data);
int chainlistLength(ChainListType *head);
void chainListShow(ChainListType *head);


///#################
///########Chain List implement file  #########
///#################
#include "stdafx.h"
#include "chainList.h"
#include <stdlib.h>

void showMsg()
{
	printf("Msg");
}

int   InitChainlist(ChainListType *head)
{
	/*DATA *dt;
	dt = (DATA*)malloc(sizeof(DATA));*/
	ChainListType *node;

	node = (ChainListType*)malloc(sizeof(ChainListType));
	head->next = NULL;

	return 1;
}

ChainListType *chainlistAddEnd(ChainListType *head, DATA data)
{
	ChainListType *node;
	ChainListType	*h;

	node =(ChainListType*) malloc(sizeof(ChainListType));

	node->data = data;
	node->next = NULL;

	if (head == NULL)
	{
		//
	}

	h = head;
	while (h->next != NULL)
	{
		h = h->next;
	}
	h->next = node;

	return head;
}

ChainListType *chainlistAddFirst(ChainListType *head, DATA data)
{
	return head;
}

ChainListType *chainlistFind(ChainListType *head, char *key)
{
	return head;
}

ChainListType *chainlistInsert(ChainListType *head, char * findKey, DATA data)
{
	return head;
}

int chainlistDelete(ChainListType *head, DATA data)
{
	return 1;
}

int chainlistLength(ChainListType *head)
{
	ChainListType *h;
	int length = 0;
	h = head->next;
	while (h)
	{
		length++;
		h = h->next;
	}
	return length;
}

void chainListShow(ChainListType *head)
{

}

// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
///#################
///#########TSET List File  ######
/////////////

#include "stdafx.h"
//#include "Header.h"
#include "chainList.h"
#include <string.h>


////Chapter 2 exercise///

//typedef struct{
//	char key[10];
//	char name[10];
//	int age;
//}DATA;

//
//List L;
//IniList(&L);
//
//for (size_t i = 0; i < 9; i++)
//{
//	DATA data;
//	char key[10] = "";
//	sprintf_s(key, 10, "000%d", i);
//
//	char name[10] = "";
//	sprintf_s(name, 10, "Cur%d", i);
//
//	data.age = 10 + i;
//
//	strcpy_s(data.key, key);
//	strcpy_s(data.name, name);
//
//	ListAdd(&L, data);
//
//}
//
////DATA dataTemp;
////for (size_t i = 9; i >= 5; i++)
////{
////	dataTemp = L.ListData[i];
////}
//
////for (size_t i = 10; i > 2; i--)
////{
////	L.ListData[i] = L.ListData[i -1];
////}
//
//DATA insert;
//strcpy_s(insert.key, "Insert");
//strcpy_s(insert.name, "inName");
//insert.age = 99;
////L.ListData[2] = insert;
//ListInsert(&L, 3, insert);
//
//showElem(&L);
//
//ListDelete(&L, 5);
//
////for (size_t i = 0; i < L.listLen; i++)  // re
////{
////	DATA Result = *searchByNumber(&L, i);
//
////	printf("%s_%s_%d\n", Result.key, Result.name, Result.age);
////}
//showElem(&L);


int _tmain(int argc, _TCHAR* argv[])
{
	showMsg();


	ChainListType list;
	InitChainlist(&list);

	for (size_t i = 0; i < 10; i++)
	{
		DATA dt;
		dt.age = 10+i;
		strcpy_s(dt.key, "key");
		strcpy_s(dt.name, "name");

		chainlistAddEnd(&list, dt);
			 
	}

	printf("Length _ %d", chainlistLength(&list));

	return 0;
}
////////Common exercise///////
	ChainListType *node, *h;
	if (!(node = (ChainListType *)malloc(sizeof(ChainListType))))
	{
		//
		printf("Alloc Failure\n");
	}

	node->data = data;
	node->next = NULL;

	if (head == NULL)
	{
		head = node;
		head->next = NULL;
	}

	h = head;
	while (h->next != NULL)
	{
		h = h->next;
	}

	h->next = node;
	return head;

/////////////////////////////////

////
// ConsoleQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SeqQueue.h"
#include "CycQueue.h"
#include <string.h>
#include <time.h>
#include <Windows.h>

int randomTable[] = { 1717
,2154
,2845
,1305
,1204
,386
,1759
,462
,2777 
,2334
,1139
,1246
,950
,326
,2628
,2361
,420
,2377
,2458 };


void TimeWaste(int n)
{
	double value = 0.0;
	double sigma = 1.23333333;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			value += (double)(i+j) / sigma;
			char strDes[1000];
			char * strSrc = "This is test for waste time,,,,,,,,,,,,,,,,,,,,,,,,,,,";
			strcpy_s(strDes, strSrc);
		}
		Sleep(1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	CycQueue *cycqueue;
	cycqueue = CycQueueInit();

	SeqQueue *sequeue;
	sequeue = SeqQueueInit();
	for (size_t i = 0; i < 14; i++)
	{
		DATA dt;
		dt.number = randomTable[i];
		char name[10];
		sprintf_s(name, "name%d", i);
		strcpy_s(dt.name, name);
		CycQueueIn(cycqueue, dt);
	}
    
	for (size_t i = 0; i < 15; i++)
	{
		TimeWaste(cycqueue->data[i+1].number);
		printf("%s__is Out\n", cycqueue->data[i+1].name);
		CycQueueOut(cycqueue);
		printf("head_%d_tail_%d_\n", cycqueue->head, cycqueue->tail);
		//TimeWaste(randomTable[i]);
		//printf("Time___%d\n", clock());
	}

	return 0;
}

/////////////////////////Test for cycqueue///////////////////////////
////////////////Simple Stack exe////////////////////////
#pragma once

#ifndef SEQSTACK_H
#define SEQSTACK_H

#define SIZE 50

//typedef struct
//{
//	int number;
//	char name[10];
//}DATA;

typedef int DATA;


typedef struct stack
{
	DATA data[SIZE + 1];
	int top;
}SeqStack;

SeqStack *SeqStackInit();
int SeqStackPush(SeqStack *q, DATA data);
DATA SeqStackPop(SeqStack *q);
DATA SeqStackPeak(SeqStack *q);
void SeqStachFree(SeqStack *q);
#endif


#include "stdafx.h"
#include "SeqStack.h"
#include <stdlib.h>

SeqStack *SeqStackInit()
{
	//
	SeqStack *q;

	if ((q = (SeqStack *)malloc(sizeof(SeqStack))))
	{
		//
		q->top = 0; 
		return q;
	}
	else
	{
		return NULL;
	}

	return NULL;
}

int SeqStackPush(SeqStack *q, DATA data)
{
	/////Stack save data from 1, isnot 0, array is 0.
	if ((q->top +1) ==  SIZE)
	{
		printf("Stack is FULL \n");
		return 0;
	}
	q->data[++q->top] = data;
	return 1;
}


DATA SeqStackPop(SeqStack *q)
{
	if (q->top == 0)
	{
		printf("Stack is Empty\n");
	}
	return (q->data[q->top--]);
}

DATA SeqStackPeak(SeqStack *q)
{
	if (q->top == 0)
	{
		printf("Stack is EMPTY \n");
		exit(0);
	}
	else
	{
		return (q->data[q->top]);
	}
}

void SeqStachFree(SeqStack *q)
{
	if (q != NULL)
	{
		free(q);
	}
}


// ConsoleQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "SeqQueue.h"
//#include "CycQueue.h"
#include <string.h>
//#include <time.h>
//#include <Windows.h>
#include "SeqStack.h"

int randomTable[] = { 1717
,2154
,2845
,1305
,1204
,386
,1759
,462
,2777 
,2334
,1139
,1246
,950
,326
,2628
,2361
,420
,2377
,2458 };


int IsOperator(char c)
{
	switch (c)
	{
	case '+':
	case '*':
	case'(':
	case')':
		return 1;
	default:
		return 0;
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//SeqStack * stack;
	//stack = SeqStackInit();

	//for (size_t i = 0; i < 6; i++)
	//{
	//	DATA dt;
	//	strcpy_s(dt.name, "name");
	//	dt.number = randomTable[i];
	//	SeqStackPush(stack, dt);
	//}
	//
	//for (size_t i = 0; i < 3; i++)
	//{
	//	printf("%d_\n", SeqStackPop(stack).number);
	//}
	////SeqStachFree(stack);
	//printf("%d_Peak\n", SeqStackPeak(stack).number);
	////printf("%d_Peak2\n", SeqStackPeak(stack).number);
	return 0;
}

////////////////Simple Stack exe////////////////////////








