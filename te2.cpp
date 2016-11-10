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
			printf("Left Add\n");
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
			printf("Right Add\n");
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


void AddNode(ChainBinTree *bt, DATA data)
{
	ChainBinTree *node, *parent;
	char select;

	if (node = (ChainBinTree *)malloc(sizeof(ChainBinTree)))
	{
		node->data = 100 + data;
		node->left = NULL;
		node->right = NULL;

		BinTreeAddNode(bt, node, 1 + (data+1) %2);
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
	AddNode(root, 1);
	AddNode(root, 2);
	AddNode(root->left,3);
	AddNode(root->left, 4);
	AddNode(root->right,5);
	AddNode(root->right, 6);
	AddNode(root->left->left, 7);
	AddNode(root->left->left, 8);
	AddNode(root->left->right, 9);
	AddNode(root->left->right, 10);

	ChainBinTree *left = BinTreeLeft(root);

	printf("%d__", BinTreeDepth(root));
	return 0;
}
