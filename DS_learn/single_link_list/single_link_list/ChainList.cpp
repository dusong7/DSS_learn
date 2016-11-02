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
	ChainListType *node, h;
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
