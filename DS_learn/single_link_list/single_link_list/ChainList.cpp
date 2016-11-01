#include "ChainList.h"

//
void showTest()
{
	printf("Hello\n");
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

	node = (ChainListType*)malloc(sizeof(ChainListType));

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
