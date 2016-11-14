// ConsoleThreadedBinTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

typedef int DATA;

typedef enum
{
	SubTree,
	Thread
}NodeFlag;  //subchild type , is a threaded, or a child point.

typedef struct ThreadTree
{
	DATA data;
	NodeFlag lflag;
	NodeFlag rflag;
	struct ThreadTree * left;
	struct ThreadTree * right;
}ThreadBinTree;

ThreadBinTree *Previous = NULL;

void BinTreeThreading_LDR(ThreadBinTree * bt)
{
	if (bt)
	{
		BinTreeThreading_LDR(bt->left);
		bt->lflag = (bt->left) ? SubTree : Thread;
		bt->rflag = (bt->right) ? SubTree : Thread;

		if (Previous)
		{
			if (Previous->rflag == Thread)
			{
				Previous->right = bt;
			}
			if (bt->lflag == Thread)
			{
				bt->left = Previous;
			}
		}
		Previous = bt;
		BinTreeThreading_LDR(bt->left);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//
	return 0;
}

