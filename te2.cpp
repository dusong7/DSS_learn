// ConsoleBinTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

#define MAX 100
typedef int DATA;

typedef struct ChainTree{
	DATA data;
	struct ChainTree *left;
	struct ChainTree *right;
	//struct ChainTree *parent;
	
}ChainBinTree;

ChainBinTree *root = NULL;

ChainBinTree *BinTreeInit(ChainBinTree *node)
{
	if (node != NULL)
	{
		return node;
	}
	else
	{
		return NULL;
	}
}

ChainBinTree *InitRoot()
{
	ChainBinTree *node;
	if (node = (ChainBinTree *)malloc(sizeof(ChainBinTree)))
	{
		node->data = 100;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else
	{
		return NULL;
	}
}

int BinTreeAddNode(ChainBinTree *bt, ChainBinTree *node, int n)
{
	if (bt == NULL)
	{ 
		printf("Parent is NULL \n");
	}

	switch (n)
	{
	case 1:
		if (bt->left)
		{
			printf("Left isnot NULL\n");
		}
		else
		{
			bt->left = node;
		}
		break;
	case 2:
		if (bt->right)
		{
			printf("Right isnot NULL\n");
		}
		else
		{
			bt->right = node;
		}
		break;
	default:
		printf("Param Error\n");
		return 0;
	}
	return 1;
}

ChainBinTree *BinTreeLeft(ChainBinTree *bt)
{
	if (bt)
	{
		return bt->left;
	}
	else
	{
		return NULL;
	}
}

ChainBinTree *BinTreeRight(ChainBinTree *bt)
{
	if (bt)
	{
		return bt->right;
	}
	else
	{
		return NULL;
	}
}

void AddNode(ChainBinTree *bt)
{
	ChainBinTree *node, *parent;
	DATA data;
	char select;

	if (node = (ChainBinTree *)malloc(sizeof(ChainBinTree)))
	{
		node->data = 101;
		node->left = NULL;
		node->right = NULL;

		BinTreeAddNode(bt, node, 1);

		node->data = 102;
		BinTreeAddNode(bt, node, 2);
	}

}

int BinTreeDepth(ChainBinTree *bt)
{
	int dep1 = 0;
	int dep2 = 0;
	if (bt == NULL)
	{
		return 0;
	}
	else
	{
		dep1 = BinTreeDepth(bt->left);
		dep2 = BinTreeDepth(bt->right);

		if (dep1>dep2)
		{
			return dep1 + 1;
		}
		else
		{
			return dep2 + 1;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	ChainBinTree *root = NULL;
	root = InitRoot();
	AddNode(root);

	ChainBinTree *left = BinTreeLeft(root);

	printf("%d__", BinTreeDepth(root));
	return 0;
}
