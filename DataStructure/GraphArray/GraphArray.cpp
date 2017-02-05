/*
	����ͼ����
*/

#include "head.h"

Status CreateGraph(MGraph &G){
	//�������鷨����ͼG
	G.kind=UDN;
	return CreateUDN(G);
}

Status CreateUDN(MGraph &G){
	//����������G
	int IncINFO;
	printf("����ͼ�ĵ�ǰ����ͻ���:");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	printf("�Ƿ񺬻�����Ϣ:(1/0)");
	scanf("%d",&IncINFO);
	int i,j,k;
	for(i=0;i<G.vexnum;++i){
		printf("���붥������-%d:",i);
		scanf("%d",&G.vexs[i]);
	}
	for(i=0;i<G.vexnum;++i){//��ʼ���ڽӾ���
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=INFINIY;
			G.arcs[i][j].info=NULL;
		}
	}
	int v1,v2,w;
	for(k=0;k<G.arcnum;++k){
		printf("����һ���������Ķ���(1,2)��Ȩֵ(w):");
		scanf("%d%d%d",&v1,&v2,&w);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j].adj=w;//Ȩֵ
		if(IncINFO)InputIncINFO(G.arcs[i][j].info);//�����йػ�����Ϣ	
		G.arcs[j][i]=G.arcs[i][j];//������һ����Ϣ
	}
	return OK;
}
Status InputIncINFO(InfoType *info){//���뻡��������Ϣ
	info=(InfoType *)malloc(sizeof(InfoType));
	printf("���뻡���Ͷ���:");
	scanf("%d%f",&info->length,&info->angle);
	return OK;
}
int LocateVex(MGraph G,int u){//�ж�λ����Ϣ
	int i;
	for(i=0;i<G.vexnum;++i)if(G.vexs[i]==u)return i;
	return ERROR;
}

void PrintGraphArray(MGraph G){
	//��ӡͼ������
	int i,j;
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			if(G.arcs[i][j].adj==INFINIY)printf("%5d ",0);
			else printf("%5d ",G.arcs[i][j].adj);
		}
		printf("\n");
	}
}