/*
	数据结构类型定义
	
	数组存储数据元素（顶点）的信息和数据元素之间的关系（边或弧）的信息

*/

#define INFINIY INT_MAX //int 最大值
#define MAX_VERTEX_NUM 20//最大顶点个数

typedef int VRType;
typedef enum{
	DG,//有向图
	DN,//有向网
	UDG,//无向图
	UDN//无向网
}GraphKind;
typedef struct{
	int length;//长度
	float angle;//弧度
}InfoType;
typedef struct ArcCell{
	VRType adj;//VRType是顶点关系类型，对无权图，用1或0表示相邻否；有权图表示其权值类型
	InfoType *info;//该弧相关信息
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int VertexType;
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum;//顶点数
	int arcnum;//弧数
	GraphKind kind;//图的种类
}MGraph;