/*
	图 十字链表
*/

#include"head.h"
int LocateVex(OLGraph G,int u){//判断位置信息
	int i;
	for(i=0;i<G.vexnum;++i)if(G.xlist[i].data==u)return i;
	return ERROR;
}
Status InputIncINFO(InfoType *info){//输入弧的其他信息
	info=(InfoType *)malloc(sizeof(InfoType));
	printf("输入弧长:");
	scanf("%d%f",&info->length);
	return OK;
}
Status CreatDG(OLGraph &G){
	//采用十字链表存储，构造有向图G
	int IncInfo;
	printf("输入图的当前顶点和弧度:");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	printf("是否含弧度信息:(1/0)");
	scanf("%d",&IncInfo);

	int i,j,k;
	for(i=0;i<G.vexnum;++i){
		printf("输入顶点数据 %d :",i);
		scanf("%d",&G.xlist[i].data);
		//初始化指针
		G.xlist[i].firstin=NULL;
		G.xlist[i].firstout=NULL;
	}
	int v1,v2;
	ArcBox *p;
	for(k=0;k<G.arcnum;++k){
		printf("输入弧的始点和终点:");
		scanf("%d%d",&v1,&v2);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		p=(ArcBox *)malloc(sizeof(ArcBox));
		
		//结点赋值
		p->tailvex=i;
		p->headvex=j;
		p->hlink=G.xlist[j].firstin;
		p->tlink=G.xlist[i].firstout;
		p->info=NULL;

		G.xlist[j].firstin=G.xlist[i].firstout=p;
		if(IncInfo)InputIncINFO(p->info);
	}
	return OK;
}

void printDG(OLGraph G){
	//输出图信息
	int i;
	printf("\n出度:");
	ArcBox *p;
	for(i=0;i<G.vexnum;++i){
		printf("\n顶点 %d:",G.xlist[i].data);
		p=G.xlist[i].firstout;
		while(p){
			printf(" %d ",G.xlist[p->headvex].data);
			p=p->tlink;
		}
	}

	printf("\n\n入度:");
	for(i=0;i<G.vexnum;++i){
		printf("\n顶点 %d:",G.xlist[i].data);
		p=G.xlist[i].firstin;
		while(p){
			printf(" %d ",G.xlist[p->tailvex].data);
			p=p->hlink;
		}
	}
	printf("\n\n");
}

void DFSTraverse(OLGraph G,Status (* Visit)(OLGraph G,int v),int visited[MAX_VERTEX_NUM]){
	//对图进行深度优先遍历
	int v;
	for(v=0;v<G.vexnum;++v)visited[v]=FALSE;
	for(v=0;v<G.vexnum;++v)
		if(!visited[v])DFS(G,v,visited,Visit);
}

void DFS(OLGraph G,int v,int visited[MAX_VERTEX_NUM],Status (* Visit)(OLGraph G,int v)){
	//从第V个顶点出发递归地进行深度遍历
	visited[v]=TRUE;
	Visit(G,v);//访问结点
	int w;
	for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
		if(!visited[w])DFS(G,w,visited,Visit);
}
int FirstAdjVex(OLGraph G,int v){
	//获取v结点周围的第一个结点
	//不存在时返回-1
	int list[MAX_VERTEX_NUM];
	list[0]=-1;
	GetAdhVex(G,v,list);
	return list[0];
}

int NextAdjVex(OLGraph G,int v,int w){
	//获取v结点周围w结点之后的结点
	//不存在时返回-1
	int list[MAX_VERTEX_NUM];
	int i,n,flag=0;
	n=GetAdhVex(G,v,list);
	for(i=0;i<n;i++){
		if(list[i]==w){
			flag=1;
			break;
		}
	}
	if(flag==0 || i+1>=n)return -1;
	else return list[i+1];
}

int GetAdhVex(OLGraph G,int v,int list[MAX_VERTEX_NUM]){
	//获取v结点周围的结点的数组
	ArcBox *p;
	int i=0,j,k;

	p=G.xlist[v].firstout;
	while(p){
		list[i++]=p->headvex;
		p=p->tlink;
	}
	p=G.xlist[v].firstin;
	k=i;
	while(p){
		for(j=0;j<k;j++){
			if(list[j]==p->tailvex)break;
		}
		if(j==k)list[i++]=p->tailvex;
		p=p->hlink;
	}
	return i;
}

void BFSTraverse(OLGraph G,Status (* Visit)(OLGraph G,int v),int visited[MAX_VERTEX_NUM]){
	//按广度优先非递归遍历图，使用队列Q
	LinkQueue Q;
	int v,u,w;
	for(v=0;v<G.vexnum;++v)visited[v]=FALSE;
	InitQueue(Q);
	for(v=0;v<G.vexnum;++v){
		if(!visited[v]){

			visited[v]=TRUE;
			Visit(G,v);
			EnQueue(Q,v);
			while(!QueueEmpty(Q)){
				DeQueue(Q,u);//对头元素出队并置为u
				for(w=FirstAdjVex(G,u);
					w>=0;
					w=NextAdjVex(G,u,w)){
					if(!visited[w]){
						visited[w]=TRUE;
						Visit(G,w);
						EnQueue(Q,w);
					}//if
				}
			}//while

		}//if
	}
}