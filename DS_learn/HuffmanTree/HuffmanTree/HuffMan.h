//
//  HuffMan.h
//  HuffmanTree
//
//  Created by apple on 16/11/19.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef HuffMan_h
#define HuffMan_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int weight;
    int left;
    int right;
    int parent;
}HuffmanTree;

typedef char HuffmanCode;

void selectN(HuffmanTree *hf, int n, int *bt1, int *bt2);
void SelectNode(HuffmanTree *hf, int n, int *bt1, int *bt2);
void CreateTree(HuffmanTree *hf, int n, int w[]);  //hf point hfmantree, n, leaf, w, weight value
void HuffmanCoding(HuffmanTree *hf, int n, HuffmanCode *hc);
void Encode(HuffmanCode *hc, char *alphabet, char *str, char *code);

#endif /* HuffMan_h */
