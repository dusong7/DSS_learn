//
//  SeqBinTree.c
//  chapt_2_3
//
//  Created by apple on 16/11/10.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "SeqBinTree.h"


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
    if ((node = (ChainBinTree *)malloc(sizeof(ChainBinTree))))
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

void oper(ChainBinTree *p)
{
    printf("%d_\n", p->data);
    return;
}

///traversal   non-recursive inorder traversal of binary tree
void BinTree_DLR(ChainBinTree *bt)
{
    if (bt)
    {
        BinTree_DLR(bt->left);
        BinTree_DLR(bt->right);
        oper(bt);
    }
    return;
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
    ChainBinTree *node;
    //char select;
    
    if ((node = (ChainBinTree *)malloc(sizeof(ChainBinTree))))
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
