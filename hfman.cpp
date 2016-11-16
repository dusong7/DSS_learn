// ConsoleHuffmanTree.cpp : Defines the entry point for the console application.
//

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

void SelectNode(HuffmanTree *hf, int n, int *bt1, int *bt2)
{
	int i;
	HuffmanTree *ht1, *ht2, *t;
	ht1 = ht2 = NULL;
	for (i = 1; i <= n; i++)
	{
		if (!hf[i].parent)
		{
			if (ht1 == NULL)
			{
				ht1 = hf + 1;
				continue;
			}
			if (ht2 == NULL)
			{
				ht2 = hf + 1;
				if (ht1->weight > ht2->weight)
				{
					t = ht2;
					ht2 = ht1;
					ht1 = t;
				}
				continue;
			}
			if (ht1 &&ht2)
			{
				if (hf[i].weight <= ht1->weight)
				{
					ht2 = ht1;
					ht1 = hf + 1;
				}
				else if (hf[i].weight < ht2->weight)
				{
					ht2 = hf + i;
				}
			}
		}
	}
	//////////
	if (ht1 > ht2)
	{
		*bt2 = ht1 - hf;
		*bt1 = ht2 - hf;
	}
	else
	{
		*bt1 = ht1 - hf;
		*bt2 = ht2 - hf;
	}
}

void CreateTree(HuffmanTree *hf, int n, int *w)  //hf point hfmantree, n, leaf, w, weight value
{
	int i;
	int m = 2 * n - 1;
	int bt1 = 0;
	int bt2 = 0;

	if (n <= 1)
	{
		return;
	}

	for (i = 1; i <= n; i++)
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

	for (i = n + 1; i <= m; i++)
	{
		SelectNode(hf, i-1, &bt1, &bt2);
		hf[bt1].parent = i;
		hf[bt2].parent = i;
		hf[i].left = bt1;
		hf[i].right = bt2;
		hf[i].weight = hf[bt1].weight + hf[bt2].weight;
	}
}



void HuffmanCoding(HuffmanTree *hf, int n, HuffmanCode *hc)
{
	char *cd;
	int start, i;
	int current, parent;
	cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	//
	for (i = 0; i < n; i++)
	{
		start = n - 1;
		current = i;
		parent = hf[current].parent;
		while (parent)
		{
			if (current == hf[parent].left)
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
			current = parent;
			parent = hf[parent].parent;
		}
		hc[i - 1] = (char*)malloc(sizeof(char*)*(n - start));
		strcpy_s(hc[i - 1], 100, &cd[start]);
	}
	free(cd);
}

void Encode(HuffmanCode *hc, char *alphabet, char *str, char *code)
{
	int len = 0;
	int i = 0;
	int j = 0;
	 
	while (str[i])
	{
		j = 0;
		while (alphabet[j] != str[i])
		{
			j++;
		}
		strcpy_s(code + len, 100, hc[j]);
		len = len + strlen(hc[j]);
		i++;
	}
	code[len] = '\0';
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	int n = 4;
	int m;

	char test[] = "DBDBDABDCBDABCDBDBCABCCBDD";
	char code[100], code1[100];
	char alphabet[] = { 'A', 'B', 'C', 'D' };
	int w[] = { 5, 7, 2, 13 };
	HuffmanTree *hf;
	HuffmanCode *hc;
	m = 2 * n - 1;
	hf = (HuffmanTree*)malloc(sizeof(HuffmanTree));
	hc = (HuffmanCode*)malloc(n * sizeof(char*));
	CreateTree(hf, n, w);
	//HuffmanCoding(hf, n, hc);
	char *cd;

	cd = (char *)malloc(n * sizeof(char));
	return 0;
}

