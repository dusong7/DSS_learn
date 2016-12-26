#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdlib.h>

struct adjNode{
    int node;
    struct adjNode *next;
};


/*ͼ�ľ����ʾ���ڽӱ��ʾ��ת��*/
void matrixToAdjlist(int *matrix, adjNode *adjList, int n){
    int i, j;
    adjNode *tempNode;
    for(i=0; i<n; ++i){
        adjList[i].node=i;
        adjList[i].next=NULL;

        for(j=n-1; j>=0; j--){
            if(*(matrix+i*n+j)== 1){
                tempNode=(adjNode *)malloc(sizeof(adjNode));
                tempNode->next=adjList[i].next;
                tempNode->node=j;
                adjList[i].next=tempNode;
            }
        }
    }
}

/*�ͷ��ڽӱ��з���Ŀռ�*/
void freeAdjList(adjNode *adjList, int n){
    int i;
    adjNode *tempNode;

    for(i=0; i<n; ++i){
        tempNode=adjList[i].next;
        while(tempNode != NULL){
            adjList[i].next=tempNode->next;
            free(tempNode);
            tempNode=adjList[i].next;
        }
    }

    free(adjList);
}


#endif // HEAD_H_INCLUDED
