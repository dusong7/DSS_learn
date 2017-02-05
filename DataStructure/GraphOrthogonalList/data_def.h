/*
	数据结构类型定义
*/

#define MAX_VERTEX_NUM 20

typedef struct{
	int length;//长度
}InfoType;

typedef struct ArcBox{
	int tailvex;//弧的尾顶点
	int headvex;//弧的头顶点
	struct ArcBox *hlink;//指向弧头相同的下一条弧
	struct ArcBox *tlink;//指向弧尾相同的下一条弧
	InfoType *info;
}ArcBox;

typedef int VertexType;

typedef struct VexNode{
	VertexType data;
	ArcBox *firstin;//指向该顶点的入弧
	ArcBox *firstout;//指向该顶点的出弧
}VexNode;

typedef struct{
	VexNode xlist[MAX_VERTEX_NUM];//表头向量
	int vexnum;//顶点数
	int arcnum;//弧数
}OLGraph;

typedef int QElemType ;

//列队操作
typedef struct QNode{
	QElemType data;//数据
	struct QNode *next;//下一个结点
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;//队列头
	QueuePtr rear;//队列尾
}LinkQueue;