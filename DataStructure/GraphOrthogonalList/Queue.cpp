/*
	队列操作
	
	//列队操作
	typedef struct QNode{
		QElemType data;//数据
		struct QNode *next;//下一个结点
	}QNode,*QueuePtr;
	typedef struct{
		QueuePtr front;//队列头
		QueuePtr rear;//队列尾
	}LinkQueue;

	//队列操作
	Status InitQueue(LinkQueue &Q);//初始化
	Status DestroyQueue(LinkQueue &Q);//销毁列队
	Status EnQueue(LinkQueue &Q,QElemType e);//增加元素
	Status DeQueue(LinkQueue &Q,QElemType &e);//删除元素
	int QueueLength(LinkQueue q);//队列长度
	Status QueueEmpty(LinkQueue q);//队列为空
	Status GetHead(LinkQueue Q,QElemType &e);//返回队列头
*/

#include "head.h"
Status InitQueue(LinkQueue &Q){
	//初始化
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	//销毁列队
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e){
	//增加元素
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e){
	//删除元素
	QueuePtr p;
	if(Q.front==Q.rear)return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;
	free(p);
	return OK;
}

int QueueLength(LinkQueue q){
	QueuePtr p=q.front->next;
	int i=0;
	while(p){
		++i;
		p=p->next;
	}
	return i;
}
Status QueueEmpty(LinkQueue q){
	if(q.front->next)return ERROR;
	return OK;
}
Status GetHead(LinkQueue Q,QElemType &e){
	if(Q.front->next==NULL)return ERROR;
	e=Q.front->next->data;
	return OK;
}
