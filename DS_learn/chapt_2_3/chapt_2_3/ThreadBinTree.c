//
//  ThreadBinTree.c
//  chapt_2_3
//
//  Created by apple on 16/11/14.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "ThreadBinTree.h"
ThreadBinTree *Previous = NULL;   //before define in head file, move implement file.

void BinTreeThreading_LDR(ThreadBinTree * bt)  //generare ThreadBinTree.
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
        BinTreeThreading_LDR(bt->right);
    }
}


ThreadBinTree* BinTreeInit(ThreadBinTree *node)
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


int BinTreeAddNode(ThreadBinTree *rt, ThreadBinTree *node, int pos)
{
    if (rt != NULL)
    {
        switch (pos)
        {
            case 1:
                if (rt->left)
                {
                    printf("Left is NOT NULL\n");
                }
                else
                {
                    rt->left = node;
                }
                break;

            case 2:
                if (rt->right)
                {
                    printf("Right is NOT NULL\n");
                }
                else
                {
                    rt->right = node;
                }
                break;

            default:
                printf("ERROR \n");
                break;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}


ThreadBinTree *InitRoot()
{
    ThreadBinTree *node;
    if ((node = (ThreadBinTree *)malloc(sizeof(ThreadBinTree))))
    {
        node->data = 100;
        node->left = NULL;
        node->right = NULL;
        return BinTreeInit(node);
    }
    return NULL;
}


ThreadBinTree* BinTreeFind(ThreadBinTree *bt, DATA data)  //
{
    //printf("%d__\n", bt->data);

    ThreadBinTree *p;
    if (bt == NULL)
    {
        return NULL;
    }
    else
    {
        if (bt->data == data)
        {
            return bt;
        }
        else
        {
            if ((p = BinTreeFind(bt->left, data)))
            {
                return p;
            }
            else if ((p = BinTreeFind(bt->right, data)))
            {
                return p;
            }
            else
            {
                return NULL;
            }
        }
    }    
}


void AddNode(ThreadBinTree *bt, int n)
{
    ThreadBinTree *node, *parent;
//    DATA data;
//    int select;

    if ((node = (ThreadBinTree*)malloc(sizeof(ThreadBinTree))))
    {
        node->data = 100+n;
        node->left = NULL;
        node->right = NULL;
        parent = BinTreeFind(bt, 100+n-1);
        if (parent)
        {
            int result = BinTreeAddNode(parent, node, 1 + n%2);
            /*node->data = 102;
             int result2 = BinTreeAddNode(parent, node, 2);*/
        }
    }
    else
    {
        return;
    }
    
}

ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt)  //next
{
    ThreadBinTree *nextNode;
    if (!bt)
    {
        return NULL;
    }
    if (bt->rflag == Thread)
    {
        return bt->right;
    }
    else
    {
        nextNode = bt->right;
        while (nextNode->lflag == SubTree)
        {
            nextNode = nextNode->left;
        }
        return nextNode;
    }
}

void ThreadBinTree_LDR(ThreadBinTree *bt)  //view throuth all , also can set find function here/(..*bt, ..data)
{
    if (bt)
    {
        while (bt->lflag == SubTree)
        {
            bt = bt->left;
        }
        do
        {
            printf("%d_", bt->data);
            bt = BinTreeNext_LDR(bt);
        } while (bt);
    }
}
