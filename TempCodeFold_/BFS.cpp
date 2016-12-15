// 
//版权声明：本文为博主原创文章，未经博主允许不得转载。
//广度优先遍历是连通图的一种遍历策略。其基本思想如下：
//1、从图中某个顶点V0出发，并访问此顶点；
//2、从V0出发，访问V0的各个未曾访问的邻接点W1，W2，…,Wk;然后,依次从W1,W2,…,Wk出发访问各自未被访问的邻接点；
//3、重复步骤2，直到全部顶点都被访问为止。
//
//例如下图中：
//
//1.从0开始，首先找到0的关联顶点3,4
//2.由3出发，找到1，2；由4出发，找到1，但是1已经遍历过，所以忽略。
//3.由1出发，没有关联顶点；由2出发，没有关联顶点。
//所以最后顺序是0,3,4,1,2
//c语言实现如下：（使用邻接矩阵存储）
[cpp] view plain copy
#include <stdio.h>  
#include <malloc.h>  
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
void displayGraph(int (*edge)[VERTEXNUM]);  
void BFT(int (*edge)[VERTEXNUM],int* vertexStatusArr);  
void BFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr);  
void putQueue(int vertex);  
int* getQueue();  
void putRelatedInQueue(int (*edge)[VERTEXNUM], int vertex);  
  
int main(void){  
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
  
        printf("after create:\n");  
        displayGraph(edge);  
          
        //广度优先遍历  
        BFT(edge,vertexStatusArr);  
  
        free(edge);  
        return 0;  
}  
  
//创建图  
void createGraph(int (*edge)[VERTEXNUM], int start, int end){  
        edge[start][end] = 1;  
}  
  
//打印存储的图  
void displayGraph(int (*edge)[VERTEXNUM]){  
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


c语言实现如下：（使用邻接表存储）
[cpp] view plain copy
#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 5  
  
//存放顶点的邻接表元素  
typedef struct edge{  
        int vertex;  
        struct edge* next;  
}st_edge;  
  
//队列的元素  
typedef struct qElement{  
        int value;  
        struct qElement* pre;  
        struct qElement* next;  
}st_qElement;  
  
//队列的前端和后端，最后一个入队列的元素为rear，第一个出队列的元素为front  
st_qElement* front = NULL;  
st_qElement* rear = NULL;  
  
void createGraph(st_edge** edge, int start, int end);  
void displayGraph(st_edge** edge);  
void delGraph(st_edge** edge);  
void BFT(st_edge** edge,int* vertexStatusArr);  
void BFTcore(st_edge** edge,int i,int* vertexStatusArr);  
void putQueue(int vertex);  
int* getQueue();  
void putRelatedInQueue(st_edge** edge, int vertex);  
  
int main(void){  
        //动态创建存放边的指针数组   
        st_edge** edge = (st_edge**)malloc(sizeof(st_edge*)*VERTEXNUM);  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                edge[i] = NULL;  
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
  
        printf("after create:\n");  
        displayGraph(edge);  
          
        //广度优先遍历  
        BFT(edge,vertexStatusArr);  
          
        //释放邻接表占用的内存  
        delGraph(edge);  
        edge = NULL;  
        free(vertexStatusArr);  
        vertexStatusArr = NULL;  
        return 0;  
}  
  
//创建图  
void createGraph(st_edge** edge, int start, int end){  
        st_edge* newedge = (st_edge*)malloc(sizeof(st_edge));  
        newedge->vertex = end;  
        newedge->next = NULL;  
        edge = edge + start;  
        while(*edge != NULL){  
                edge = &((*edge)->next);  
        }  
        *edge = newedge;  
}  
  
//打印存储的图  
void displayGraph(st_edge** edge){  
        int i;  
        st_edge* p;  
        for(i=0;i<VERTEXNUM;i++){  
                printf("%d:",i);  
                p = *(edge+i);  
                while(p != NULL){  
                        printf("%d ",p->vertex);  
                        p = p->next;  
                }  
                printf("\n");  
        }  
}  
  
//释放邻接表占用的内存  
void delGraph(st_edge** edge){  
        int i;  
        st_edge* p;  
        st_edge* del;  
        for(i=0;i<VERTEXNUM;i++){  
                p = *(edge+i);  
                while(p != NULL){  
                        del = p;  
                        p = p->next;  
                        free(del);  
                }  
                edge[i] = NULL;  
        }  
        free(edge);  
}  
  
//广度优先遍历  
void BFT(st_edge** edge,int* vertexStatusArr){  
        printf("start BFT graph:\n");  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                BFTcore(edge,i,vertexStatusArr);  
        }  
        printf("\n");  
}  
  
void BFTcore(st_edge** edge,int i,int* vertexStatusArr){  
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
void putRelatedInQueue(st_edge** edge, int vertex){  
        st_edge* p = *(edge+vertex);  
        while(p != NULL){  
                putQueue(p->vertex);  
                p = p->next;  
        }  
}  
顶
10
踩
0
 
 
