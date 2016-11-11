//
//  main.c
//  chapt_2_3
//
//  Created by apple on 16/11/3.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
#include "SeqBinTree.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    ChainBinTree *root = NULL;
    root = InitRoot();
    AddNode(root, 1);
    AddNode(root, 2);
    AddNode(root->left,3);
    AddNode(root->left, 4);
    AddNode(root->right,5);
    AddNode(root->right, 6);
    AddNode(root->left->left, 7);
    AddNode(root->left->left, 8);
    AddNode(root->left->right, 9);
    AddNode(root->left->right, 10);

    printf("%d__", BinTreeDepth(root));
    
    BinTree_DLR(root);
    
    //add menu to choose add and show
    //
    return 0;
}
