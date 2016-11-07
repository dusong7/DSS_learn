//
//  SeqBinTree.c
//  chapt_2_3
//
//  Created by apple on 16/11/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "SeqBinTree.h"
// ConsoleBinTree.cpp : Defines the entry point for the console application.
//
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

int _tmain(int argc, _TCHAR* argv[])
{
	ChainBinTree *bintree;
	
	bintree = InitRoot();

	return 0;
}
