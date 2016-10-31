// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

// rrr.cpp : Defines the entry point for the console application.
//

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


	return 0;
}




#include "stdafx.h"
#include "Header.h"
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
		data.key = key;
		data.name = name;
		ListAdd(&L, data);
	}


	
	char *l[10];
	for(int i=0;i<5;i++)
	{
	    char name[10] = "";
	    sprintf_s(name, 10, "Cur%d",i);
	    l[i] = name;
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

	return 1;
}
int ListDelete(List *L, int Postion)
{
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
	char *key;
	char *name;
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
