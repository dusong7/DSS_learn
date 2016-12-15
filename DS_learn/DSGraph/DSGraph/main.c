//
//  main.c
//  DSGraph
//
//  Created by apple on 16/11/20.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bfs_test.hpp"

#define VERTEXNUM 5

//队列的元素
typedef struct qElement{
    int value;
    struct qElement* pre;
    struct qElement* next;
}st_qElement;

//队列的前端和后端，最后一个入队列的元素为rear，第一个出队列的元素为front
st_qElement* front = NULL;
st_qElement* rear = NULL;

void createGraph(int (*edge)[VERTEXNUM], int start, int end);
void displayGraph_(int (*edge)[VERTEXNUM]);
void BFT(int (*edge)[VERTEXNUM],int* vertexStatusArr);
void BFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr);
void putQueue(int vertex);
int* getQueue();
void putRelatedInQueue(int (*edge)[VERTEXNUM], int vertex);

#define TEST //Test for BFS_

int main(void){

#ifdef TEST

    //动态创建存放边的二维数组
    int (*edge)[VERTEXNUM] = (int (*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);
    int i,j;
    for(i=0;i<VERTEXNUM;i++){
        for(j=0;j<VERTEXNUM;j++){
            edge[i][j] = 0;
        }
    }

    //存放顶点的遍历状态，0：未遍历，1：已遍历
    int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);
    for(i=0;i<VERTEXNUM;i++){
        vertexStatusArr[i] = 0;
    }

    printf("after init:\n");
    displayGraph(edge);
    //创建图
    createGraph(edge,0,3);
    createGraph(edge,0,4);
    createGraph(edge,3,1);
    createGraph(edge,3,2);
    createGraph(edge,4,1);
    createGraph(edge,4,2);

    printf("after create:\n");
    displayGraph_(edge);

    //广度优先遍历
    BFT(edge,vertexStatusArr);

    free(edge);
    
#else   //##
    //////Test For DFS
    //////
    printf("#################\nThis is Test for DFS__\n#################\n");
    Run();

#endif

    return 0;
}

//创建图
void createGraph(int (*edge)[VERTEXNUM], int start, int end){
    edge[start][end] = 1;
}

//打印存储的图
void displayGraph_(int (*edge)[VERTEXNUM]){
    int i,j;
    for(i=0;i<VERTEXNUM;i++){
        for(j=0;j<VERTEXNUM;j++){
            printf("%d ",edge[i][j]);
        }
        printf("\n");
    }
}

//广度优先遍历
void BFT(int (*edge)[VERTEXNUM], int* vertexStatusArr){
    printf("start BFT graph:\n");
    int i;
    for(i=0;i<VERTEXNUM;i++){
        BFTcore(edge,i,vertexStatusArr);
    }
    printf("\n");
}

void BFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr){
    putQueue(i);
    int* qeValue = NULL;
    while((qeValue = getQueue()) != NULL){
        if(vertexStatusArr[*qeValue] == 0){
            printf("%d ",*qeValue);
            vertexStatusArr[*qeValue] = 1;
            putRelatedInQueue(edge, *qeValue);
        }
        free(qeValue);
        qeValue = NULL;
    }
}

//将元素放到队列中
void putQueue(int vertex){
    st_qElement* qe = (st_qElement*)malloc(sizeof(st_qElement));
    qe->value = vertex;
    qe->next = NULL;
    qe->pre = NULL;
    if(front == NULL || rear == NULL){
        front = rear = qe;
    }else{
        rear->next = qe;
        qe->pre = rear;
        rear = qe;
    }
}

//从队列中获取一个元素
int* getQueue(){
    if(front == NULL || rear == NULL){
        return NULL;
    }else{
        int* res = (int*)malloc(sizeof(int));
        *res = front->value;

        st_qElement* p = front;
        front = front->next;
        if(front == NULL){
            rear = front;
        }else{
            front->pre = NULL;
        }
        free(p);
        p = NULL;
        return res;
    }
}
//将顶点关联的元素放到队列中
void putRelatedInQueue(int (*edge)[VERTEXNUM], int vertex){
    int i;
    for(i=0;i<VERTEXNUM;i++){
        if(edge[vertex][i] == 1){
            putQueue(i);
        }
    }
}
