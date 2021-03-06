#ifndef CHAINLIST_H
#define CHAINLIST_H


#include <stdio.h>
#include <stdlib.h>


void showTest();

typedef struct {
	char key[20];
	char name[20];
	int  age;
}DATA;

typedef struct Node {
	DATA data;
	struct Node *next;
}ChainListType;

int   InitChainlist(ChainListType *head);
ChainListType *chainlistAddEnd(ChainListType *head, DATA data);
ChainListType *chainlistAddFirst(ChainListType *head, DATA data);
ChainListType *chainlistFind(ChainListType *head, char *key);
ChainListType *chainlistInsert(ChainListType *head, char * findKey, DATA data);
int chainlistDelete(ChainListType *head, char *key);
int chainlistLength(ChainListType *head);
void chainListShow(ChainListType *head);
#endif // !CHAINLIST_H
