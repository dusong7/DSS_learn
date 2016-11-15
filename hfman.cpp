// HuffmanTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	int weight;
	int left;
	int right;
	int parent;
}HuffmanTree;

typedef char *HuffmanCode;

void CreateTree(HuffmanTree *hf, int n, int *w)  //hf point hfmantree, n, leaf, w, weight value
{
	int i;
	int m = 2 * n - 1;
	int bt1, bt2;

	if (n<=1)
	{
		return;
	}

	for ( i = 1; i <= n; i++)
	{
		hf[i].weight = w[i - 1];
		hf[i].parent = 0;
		hf[i].left = 0;
		hf[i].right = 0;
	}
	for (; i <= m; i++)
	{
		hf[i].weight = 0;
		hf[i].parent = 0;
		hf[i].left = 0;
		hf[i].right = 0;
	}

	for ( i = n+1; i <= m; i++)
	{
		//SelectNode(ht, i-1, &bt1, &bt2);
		hf[bt1].parent = i;
		hf[bt2].parent = i;
		hf[i].left = bt1;
		hf[i].right = bt2;
		hf[i].weight = hf[bt1].weight + hf[bt2].weight;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

