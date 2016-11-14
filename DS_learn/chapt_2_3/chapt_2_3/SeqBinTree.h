//
//  SeqBinTree.h
//  chapt_2_3
//
//  Created by apple on 16/11/10.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef SeqBinTree_h
#define SeqBinTree_h

#include <stdio.h>


#define MAX 100
typedef int DATA;

typedef struct ChainTree{
    DATA data;
    struct ChainTree *left;
    struct ChainTree *right;
    //struct ChainTree *parent;

}ChainBinTree;

int BinTreeDepth(ChainBinTree *bt);
void AddNode(ChainBinTree *bt, DATA data);
ChainBinTree *BinTreeRight(ChainBinTree *bt);
void BinTree_DLR(ChainBinTree *bt);
void oper(ChainBinTree *p);
ChainBinTree *BinTreeLeft(ChainBinTree *bt);
int BinTreeAddNode(ChainBinTree *bt, ChainBinTree *node, int n);
ChainBinTree *InitRoot();
ChainBinTree *BinTreeInit(ChainBinTree *node);


#endif /* SeqBinTree_h */
