//
//  ThreadBinTree.h
//  chapt_2_3
//
//  Created by apple on 16/11/14.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef ThreadBinTree_h
#define ThreadBinTree_h

#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef enum
{
    SubTree = 0,
    Thread
}NodeFlag;  //subchild type , is a threaded, or a child point.

typedef struct ThreadTree
{
    DATA data;
    NodeFlag lflag;   //left and right if is 1 is Threaded.
    NodeFlag rflag;
    struct ThreadTree * left;
    struct ThreadTree * right;
}ThreadBinTree;



void BinTreeThreading_LDR(ThreadBinTree * bt);  //generare ThreadBinTree.
ThreadBinTree* BinTreeInit(ThreadBinTree *node);
int BinTreeAddNode(ThreadBinTree *rt, ThreadBinTree *node, int pos);
ThreadBinTree *InitRoot();
ThreadBinTree* BinTreeFind(ThreadBinTree *bt, DATA data);  //Find brefore generate Threaded BinTree
void AddNode(ThreadBinTree *bt, int n);
ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt);  //next
void ThreadBinTree_LDR(ThreadBinTree *bt);  //view throuth all , also can set find function here/(..*bt, ..data)

#endif /* ThreadBinTree_h */
