/*
	���ݽṹ���Ͷ���
*/

#define MAX_VERTEX_NUM 20

typedef struct{
	int length;//����
}InfoType;

typedef struct ArcBox{
	int tailvex;//����β����
	int headvex;//����ͷ����
	struct ArcBox *hlink;//ָ��ͷ��ͬ����һ����
	struct ArcBox *tlink;//ָ��β��ͬ����һ����
	InfoType *info;
}ArcBox;

typedef int VertexType;

typedef struct VexNode{
	VertexType data;
	ArcBox *firstin;//ָ��ö�����뻡
	ArcBox *firstout;//ָ��ö���ĳ���
}VexNode;

typedef struct{
	VexNode xlist[MAX_VERTEX_NUM];//��ͷ����
	int vexnum;//������
	int arcnum;//����
}OLGraph;

typedef int QElemType ;

//�жӲ���
typedef struct QNode{
	QElemType data;//����
	struct QNode *next;//��һ�����
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;//����ͷ
	QueuePtr rear;//����β
}LinkQueue;