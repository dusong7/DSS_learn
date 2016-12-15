// 
// 登录 | 注册
// TODD911的专栏
// 夯实基础，循序渐进
// 目录视图摘要视图订阅
// 程序员12月书讯，写书评领书啦~        在 IBM Container 中运行 Swift 应用程序的 10 个 步骤        免费的知识库，你的知识库
// 关闭
//  图之图的深度优先遍历
// 2016-11-25 23:15 39857人阅读 评论(15) 收藏 举报
//  分类： 算法（22）  
// 版权声明：本文为博主原创文章，未经博主允许不得转载。
// 深度优先遍历是连通图的一种遍历策略。其基本思想如下：
// 设x是当前被访问顶点，在对x做过访问标记后，选择一条从x出发的未检测过的边(x，y)。若发现顶点y已访问过，则重新选择另一条从x出发的未检测过的边，否则沿边(x，y)到达未曾访问过的y，对y访问并将其标记为已访问过；然后从y开始搜索，直到搜索完从y出发的所有路径，即访问完所有从y出发可达的顶点之后，才回溯到顶点x，并且再选择一条从x出发的未检测过的边。上述过程直至从x出发的所有边都已检测过为止。
// 例如下图中：
// 
// 1.从0开始，首先找到0的关联顶点3
// 2.由3出发，找到1；由1出发，没有关联的顶点。
// 3.回到3，从3出发，找到2；由2出发，没有关联的顶点。
// 4.回到4，出4出发，找到1，因为1已经被访问过了，所以不访问。
// 所以最后顺序是0,3,1,2,4
// c语言实现如下：（使用邻接矩阵存储）
[cpp] view plain copy
#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 5  
  
void createGraph(int (*edge)[VERTEXNUM], int start, int end);  
void displayGraph(int (*edge)[VERTEXNUM]);  
void DFT(int (*edge)[VERTEXNUM],int* vertexStatusArr);  
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr);  
  
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
        //深度优先遍历  
        DFT(edge,vertexStatusArr);  
  
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
//深度优先遍历  
void DFT(int (*edge)[VERTEXNUM], int* vertexStatusArr){  
        printf("start BFT graph:\n");  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                DFTcore(edge,i,vertexStatusArr);  
        }  
        printf("\n");  
}  
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr){  
        if(vertexStatusArr[i] == 1){  
                return;  
        }  
        printf("%d ",i);  
        vertexStatusArr[i] = 1;  
  
        int j;  
        for(j=0;j<VERTEXNUM;j++){  
                if(edge[i][j] == 1){  
                        DFTcore(edge, j, vertexStatusArr);  
                }  
        }  
}  


C语言实现如下：（使用邻接表存储）
[cpp] view plain copy
#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 5  
//存放顶点的邻接表元素    
typedef struct edge{  
        int vertex;  
        struct edge* next;  
}st_edge;  
  
void createGraph(st_edge** edge, int start, int end);  
void displayGraph(st_edge** edge);  
void delGraph(st_edge** edge);  
void DFT(st_edge** edge,int* vertexStatusArr);  
void DFTcore(st_edge** edge,int i,int* vertexStatusArr);  
  
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
        //深度优先遍历   
        DFT(edge,vertexStatusArr);  
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
//深度优先遍历   
void DFT(st_edge** edge,int* vertexStatusArr){  
        printf("start BFT graph:\n");  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                DFTcore(edge,i,vertexStatusArr);  
        }  
        printf("\n");  
}  
  
void DFTcore(st_edge** edge,int i,int* vertexStatusArr){  
        if(vertexStatusArr[i] == 1){  
                return;  
        }  
        printf("%d ",i);  
        vertexStatusArr[i] = 1;  
        st_edge* p = *(edge+i);  
        while(p != NULL){  
                DFTcore(edge, p->vertex, vertexStatusArr);  
                p = p->next;  
        }  
}  


