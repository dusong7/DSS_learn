#include <stdafx.h>
#include <stdio.h>
#include <stdlib.h>


#define LINK_LIST_SIZE 2
#define LISTINCREMENT 10
#define OK 1
#define OVERFLLOW -1
#define ERROR 0

typedef int ElemType;

typedef struct{
  ElemType elem;
  int length;
  int listsize;
}Sqlist;

int InitList(Sqlist &l)  // reference  contained in cpp 
{
  l.elem = (ElemType *)malloc(LINK_LIST_SIZE*sizeof(Sqlist));
  if(!l.elem)
  {
    return OVERFLOW;
  }
  
  l.length = 0;
  l.listsize = LIST_LIST_SIZE;
}

void ListInsert(Sqlist &L, int position, ElemType e)
{
  *(L.elem+position-1) = e; //赋值而已
  L.length ++;
}

int main()
{
  //
  return 0;
}
