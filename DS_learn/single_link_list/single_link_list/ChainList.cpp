#include "ChainList.h"
#include <string.h>

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
    ///deal head and end point .
	//ChainListType *node;
	//ChainListType	*h;

    // Init new node

   // if (!(node = (ChainListType*)malloc(sizeof(ChainListType)))) {
    //    printf("Alloc Failure \n");
   //     return NULL;
  //  }

    //save data, and end is NULL
	//node->data = data;
	//node->next = NULL;


    ///if hede is null , initial new node .
	//if (head == NULL)
	//{
		//
    //    head = node;
   //     return head;
//	}

    //   h = head;                                 //save head point

//	while (h->next != NULL) // point next is not NULL
//	{
//		h = h->next;        // point next
//	}
//	h->next = node;         // old end  point to new
//
//	return head;            // return  head point.
	
	
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
	else
	{
		h = head;
		while (h->next != NULL)
		{
			h = h->next;
		}

		h->next = node;
	}
	
	return head;
}

ChainListType *chainlistAddFirst(ChainListType *head, DATA data)
{
	ChainListType *node;
	if(!(node = (ChainListType *)malloc(sizeof(ChainListType))))
	{
		printf("malloc Failure");
	}
	//交换
	node->data = data;
	
	node->next = head;
	head = node;
	return head;
}

ChainListType *chainlistFind(ChainListType *head, char *key)
{
	ChainListType *h;
	ChainListType *result;
	result = (ChainListType *)malloc(sizeof(ChainListType));
	h = head;

	while (h->next)
	{
		if ( strcmp( h->data.key,"key1") == 0)
		{
			result = h;
		}
		h = h->next;
	}

	return result;
}

ChainListType *chainlistInsert(ChainListType *head, char * findKey, DATA data)
{
	ChainListType *node;
	node = (ChainListType *)malloc(sizeof(ChainListType));
	ChainListType *h;

	node->data = data;
	node->next = NULL;

	h = head;

	while (h)
	{
		if (strcmp(h->data.key, "key5") == 0)
		{
			//
			node->next = h->next;
			h->next = node;
			head = h;
			return head;
		}
		h = h->next;
	}

	return NULL;
}

int chainlistDelete(ChainListType *head, DATA data)
{
	ChainListType *node, *h;

	node = h = head;

	while (h)
	{
		if (strcmp(h->data.key, "key7") == 0)
		{
			node->next = h->next;
			free(h);
			return 1;
		}
		else
		{
			node = h;    //两路保存，使一个比较靠前
			h = h->next;
		}
	}

	return 0;
}

int chainlistLength(ChainListType *head)
{
	ChainListType *h;
	int length = 0;
	h = head;
	while (h)
	{
		length++;
		h = h->next;
	}
	return length;
}

void chainListShow(ChainListType *head)
{

    ChainListType *h;
    h = head;
    while (h)
    {
        printf("%s_%s_%d\n", h->data.name,h->data.key,h->data.age);
        h = h->next;
    }
}
