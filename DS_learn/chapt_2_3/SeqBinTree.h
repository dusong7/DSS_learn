//
//  SeqBinTree.h
//  chapt_2_3
//
//  Created by apple on 16/11/6.
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
	struct ChainTree *parent;
	
}ChainTreeType;

ChainTreeType *root = NULL;

#endif /* SeqBinTree_h */
