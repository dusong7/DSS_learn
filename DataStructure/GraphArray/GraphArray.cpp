/*
	数组图操作
*/

#include "head.h"

Status CreateGraph(MGraph &G){
	//采用数组法构造图G
	G.kind=UDN;
	return CreateUDN(G);
}

Status CreateUDN(MGraph &G){
	//构造无向网G
	int IncINFO;
	printf("输入图的当前顶点和弧度:");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	printf("是否含弧度信息:(1/0)");
	scanf("%d",&IncINFO);
	int i,j,k;
	for(i=0;i<G.vexnum;++i){
		printf("输入顶点向量-%d:",i);
		scanf("%d",&G.vexs[i]);
	}
	for(i=0;i<G.vexnum;++i){//初始化邻接矩阵
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=INFINIY;
			G.arcs[i][j].info=NULL;
		}
	}
	int v1,v2,w;
	for(k=0;k<G.arcnum;++k){
		printf("输入一条边依附的顶点(1,2)及权值(w):");
		scanf("%d%d%d",&v1,&v2,&w);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j].adj=w;//权值
		if(IncINFO)InputIncINFO(G.arcs[i][j].info);//输入有关弧的信息	
		G.arcs[j][i]=G.arcs[i][j];//输入另一个信息
	}
	return OK;
}
Status InputIncINFO(InfoType *info){//输入弧的其他信息
	info=(InfoType *)malloc(sizeof(InfoType));
	printf("输入弧长和度数:");
	scanf("%d%f",&info->length,&info->angle);
	return OK;
}
int LocateVex(MGraph G,int u){//判断位置信息
	int i;
	for(i=0;i<G.vexnum;++i)if(G.vexs[i]==u)return i;
	return ERROR;
}

void PrintGraphArray(MGraph G){
	//打印图的数组
	int i,j;
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			if(G.arcs[i][j].adj==INFINIY)printf("%5d ",0);
			else printf("%5d ",G.arcs[i][j].adj);
		}
		printf("\n");
	}
}