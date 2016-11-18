//
//  HuffMan.c
//  HuffmanTree
//
//  Created by apple on 16/11/19.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "HuffMan.h"

void selectN(HuffmanTree *hf, int n, int *bt1, int *bt2)
{
    //
    int i = 0;
    int min;
    for (i = 1; i <= n; i++)
    {
        if (hf[i].parent == 0)
        {
            min = i;
            break;
        }
    }

    for (i = 1; i <= n; i++)
    {
        if (hf[i].parent == 0)
        {
            if (hf[i].weight < hf[min].weight)
            {
                min = i;
            }
        }
    }

    *bt1 = min;
    for (i = 1; i <= n; i++)
    {
        if (hf[i].parent == 0 && i != (*bt1))
        {
            min = i;
            break;
        }
    }

    for (i = 1; i <= n; i++)
    {
        if (hf[i].parent == 0 && i != (*bt1))
        {
            if (hf[i].weight < hf[min].weight)
            {
                min = i;
            }
        }
    }

    *bt2 = min;
}

void SelectNode(HuffmanTree *hf, int n, int *bt1, int *bt2)
{
    int i;
    HuffmanTree *ht1, *ht2, *t;
    ht1 = ht2 = NULL;
    for (i = 1; i <= n; ++i)  //i++
    {
        if (hf[i].parent == 0)
        {
            if (ht1 == NULL)
            {
                ht1 = hf + i;
                continue;
            }
            if (ht2 == NULL)
            {
                ht2 = hf + i;
                if (ht1->weight > ht2->weight)
                {
                    t = ht2;
                    ht2 = ht1;
                    ht1 = t;
                }
                continue;
            }
            if (ht1 && ht2)
            {
                if (hf[i].weight <= ht1->weight)
                {
                    ht2 = ht1;
                    ht1 = hf + i;
                }
                else if (hf[i].weight < ht2->weight)
                {
                    ht2 = hf + i;
                }
            }
        }
    }
    ////
    if (ht1 > ht2)
    {
        *bt1 = ht1 - hf;
        *bt2 = ht2 - hf;
    }
    else
    {
        *bt2 = ht1 - hf;
        *bt1 = ht2 - hf;
    }
}

void CreateTree(HuffmanTree *hf, int n, int w[])  //hf point hfmantree, n, leaf, w, weight value
{
    int i;
    int m = 2 * n - 1;
    int bt1 = 0;
    int bt2 = 0;

    if (n <= 1)
    {
        return;
    }

    for (i = 1; i <= n; ++i)  //i++
    {
        hf[i].weight = w[i - 1];
        hf[i].parent = 0;
        hf[i].left = 0;
        hf[i].right = 0;
        printf("%d__w\n", hf[i].weight);
    }

    for (; i <= m; ++i)  //i++
    {
        hf[i].weight = 0;
        hf[i].parent = 0;
        hf[i].left = 0;
        hf[i].right = 0;
    }
    //
    for (i = n + 1; i <= m; i++) //i++ cause Error
    {
        SelectNode(hf, i - 1, &bt1, &bt2);
        //select(hf, i - 1, &bt1, &bt2);
        hf[bt1].parent = i;
        hf[bt2].parent = i;
        hf[i].left = bt1;
        hf[i].right = bt2;
        hf[i].weight = hf[bt1].weight + hf[bt2].weight;

        printf("%d_%d_%d__\n", hf[i].weight, hf[bt1].weight, hf[bt2].weight);
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
    for (i = 1; i <= n; i++)
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
        
        strcpy(hc[i - 1], &cd[start]);
        printf("%s_%d_\n", hc[i - 1], hf[i].weight);
    }
    free(cd);
}

void Encode(HuffmanCode *hc, char *alphabet, char *str, char *code)
{
    int len = 0;
    int i = 0;
    int j = 0;
    code[0] = '\0';
    while (str[i])
    {
        j = 0;
        while (alphabet[j] != str[i])
        {
            j++;
        }
        strcpy(code + len, hc[j]);
        len = len + strlen(hc[j]);
        i++;
    }
    code[len] = '\0';
}
